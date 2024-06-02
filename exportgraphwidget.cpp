#include "exportgraphwidget.h"
#include "task.h"
#include "ui_exportgraphwidget.h"
#include <QFileDialog>
#include <QMessageBox>

ExportGraphWidget::ExportGraphWidget(QList<Task *> &tasks, QWidget *parent)
    : QWidget(parent), _tasks(tasks), ui(new Ui::ExportGraphWidget) {
  ui->setupUi(this);
  _chart = new QChart();
  // 创建一个 QButtonGroup
  _buttonGroup = new QButtonGroup(this);
  _buttonGroup->setExclusive(false);
  _buttonGroup->addButton(ui->_requst_ck, 0);
  _buttonGroup->addButton(ui->_response_ck, 1);
  _buttonGroup->addButton(ui->_timeout_ck, 2);
  _buttonGroup->addButton(ui->_error_ck, 3);
  _buttonGroup->addButton(ui->_avgresp_ck, 4);
  _buttonGroup->addButton(ui->_summary_ck, 5);

  connect(ui->_task_comb, &QComboBox::currentIndexChanged, this,
          &ExportGraphWidget::combIndexChanged);
  connect(ui->_export_btn, &QPushButton::clicked, this,
          &ExportGraphWidget::exportClicked);
  connect(ui->_all_check, &QRadioButton::toggled, this,
          &ExportGraphWidget::selectAllToggled);
  last_id = -1;
}

ExportGraphWidget::~ExportGraphWidget() { delete ui; }

void ExportGraphWidget::updateTask() {
  disconnect(ui->_task_comb, &QComboBox::currentIndexChanged, this,
             &ExportGraphWidget::combIndexChanged);

  ui->_task_comb->clear();
  for (auto task : _tasks) {
    QString item;
    item.append(QString::number(task->getId()));
    item.append("|");
    item.append(task->getName());
    ui->_task_comb->addItem(item);
  }

  QDateTime start = QDateTime::currentDateTime();
  QDateTime end = QDateTime::currentDateTime();

  // 设置开始和结束时间
  if (_tasks.size() > 0) {
    auto task = _tasks.first();
    auto results = task->getResult();
    if (results.size() > 0) {
      start = results.first().start;
      end = results.first().end;
      // 找到开始和结束时间
      for (auto r : results) {
        if (r.start < start) {
          start = r.start;
        }

        if (r.end > end) {
          end = r.end;
        }
      }
    }
  }
  ui->_start_time->setDateTime(start);
  ui->_start_time->setDateTimeRange(start, end);
  ui->_endtime->setDateTime(end);
  ui->_endtime->setDateTimeRange(start, end);
  connect(ui->_task_comb, &QComboBox::currentIndexChanged, this,
          &ExportGraphWidget::combIndexChanged);
}

void ExportGraphWidget::combIndexChanged(int index) {
  // 判断压测是否结束
  qDebug() << "index :" << index;
  qDebug() << "size" << _tasks.size();
  if (index >= 0 && _tasks.size() > index) {
    auto select_task = _tasks[index];
    if (select_task->isLoadingInProgress()) {
      QMessageBox::warning(this, tr("Warning"),
                           tr("The selected task is currently being load "
                              "tested. Please wait until it finishes."));
      if (last_id >= 0 && last_id < _tasks.size()) {
        for (int i = 0; i < _tasks.size(); ++i) {
          if (_tasks[i]->getId() == last_id) {
            ui->_task_comb->setCurrentIndex(i);
            return;
          }
        }
      }
      return;
    }
  }
  // 设置开始和结束时间
  QDateTime start = QDateTime::currentDateTime();
  QDateTime end = QDateTime::currentDateTime();

  // 设置开始和结束时间
  if (index >= 0 && _tasks.size() > index) {
    auto task = _tasks[index];
    auto results = task->getResult();
    if (results.size() > 0) {
      start = results.first().start;
      end = results.first().end;
      // 找到开始和结束时间
      for (auto r : results) {
        if (r.start < start) {
          start = r.start;
        }

        if (r.end > end) {
          end = r.end;
        }
      }
    }
  }
  ui->_start_time->setDateTime(start);
  ui->_start_time->setDateTimeRange(start, end);
  ui->_endtime->setDateTime(end);
  ui->_endtime->setDateTimeRange(start, end);

  // 更新最新选中的任务ID
  if (index >= 0 && _tasks.size() > index) {
    last_id = _tasks[index]->getId();
  } else {
    last_id = -1; // 如果没有有效的任务被选中，重置last_id
  }
  qDebug()<<"last_id:"<<last_id;
}

void ExportGraphWidget::exportClicked() {
  getifchecked();
  emit exportPNGSignal(ui->_task_comb->currentIndex(),
                       ui->_start_time->dateTime(), ui->_endtime->dateTime(),
                       _ifchecked);
  close();
}

void ExportGraphWidget::selectAllToggled(bool checked) {
  // 设置所有按钮的状态
  QList<QAbstractButton *> _ckbtn = _buttonGroup->buttons();
  for (auto btn : _ckbtn) {
    btn->setChecked(checked);
  }
  if (checked) {
    ui->_all_check->setText("清空");
  } else {
    ui->_all_check->setText("全选");
  }
}
QList<bool> ExportGraphWidget::getifchecked() {
  _ifchecked.clear();
  for (auto btn : _buttonGroup->buttons()) {
    _ifchecked.append(btn->isChecked());
  }
  return _ifchecked;
}
