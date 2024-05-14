#include "exportgraphwidget.h"
#include "ui_exportgraphwidget.h"
#include "task.h"
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
}

ExportGraphWidget::~ExportGraphWidget() { delete ui; }

void ExportGraphWidget::updateTask() {
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

}

void ExportGraphWidget::combIndexChanged(int index) {
  // 设置开始和结束时间
  QDateTime start = QDateTime::currentDateTime();
  QDateTime end = QDateTime::currentDateTime();
  // 判断压测是否结束
  if (index >= 0 && _tasks.size() > index) {
    auto select_task = _tasks[index];
    if (!select_task->isLoadingInProgress()) {
      QMessageBox::warning(this, tr("Warning"),
                           tr("The selected task is currently being load "
                              "tested. Please wait until it finishes."));
      // 把combobox设置成原来的选项，不做改变
      // ui->_task_comb->blockSignals(true); // 阻止 combobox 的信号
      // ui->_task_comb->setCurrentIndex(_tasks.indexOf(_selectedTask));
      // ui->_task_comb->blockSignals(false); // 解除 combobox 的信号阻止
      return;
    }
  }
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
  // 更新选中的任务
  // if (index >= 0 && index < _tasks.size()) {
  //   _selectedTask = _tasks[index];
  // } else {
  //   _selectedTask = nullptr;
  // }
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
