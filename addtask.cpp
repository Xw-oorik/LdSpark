#include "addtask.h"
#include "http.h"
#include "ui_addtask.h"
#include <QMessageBox>

AddTaskWidget::AddTaskWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::AddTaskWidget) {
  ui->setupUi(this);
  ui->_type_comb->setCurrentIndex(0);
  ui->_httptype_comb->setCurrentIndex(0);
  ui->_para_lineedit->setReadOnly(true);
  ui->_para_lineedit->setPlaceholderText("循环次数或持续时间(ms)");
  ui->_task_thread_lineedit->setPlaceholderText("并发数");
  ui->_proxy_check->setEnabled(true);

  // 在开始的时候，如果只有一次的话，loop 和 time 的参数是不可选的

  connect(ui->_type_comb, &QComboBox::currentIndexChanged, [=](int index) {
    if (index == 0) {
      ui->_para_lineedit->clear();
      ui->_para_lineedit->setReadOnly(true);
    } else {
      ui->_para_lineedit->setReadOnly(false);
    }
  });

  connect(ui->_add_button, &QPushButton::clicked, this,
          &AddTaskWidget::addTaskButtonClicked);
  connect(ui->_cancel_button, &QPushButton::clicked, this,
          &AddTaskWidget::cancelButtonClicked);
}

AddTaskWidget::~AddTaskWidget() { delete ui; }

void AddTaskWidget::addTaskButtonClicked() {
  // 检查类型
  int task_type = ui->_type_comb->currentIndex();
  QString para = ui->_para_lineedit->text();
  if (task_type != 0 && para.isEmpty()) {
    QMessageBox::warning(this, "警告", "参数不能为空");
    return;
  }

  // 检查其他参数
  QString task_name = ui->_taskname_lineedit->text();
  QString task_url = ui->_taskurl_lineedit->text();
  int http_method = ui->_httptype_comb->currentIndex();
  QString thread_num = ui->_task_thread_lineedit->text();
  QString body = ui->_task_body_lineedit->text();

  if (task_name.isEmpty() || task_url.isEmpty() || thread_num.isEmpty()) {
    QMessageBox::warning(this, "警告", "任务名、URL、线程数不能为空");
    return;
  }

  // 检查线程数是否为数字
  bool ok;
  int thread_num_int = thread_num.toInt(&ok);
  int para_int = 0;
  if (!ok) {
    QMessageBox::warning(this, "警告", "线程数必须为数字");
    return;
  }
  // 如果类型不是 ONCE 检查 Para 是否为数字
  if (task_type != 0) {
    para_int = para.toInt(&ok);
    if (!ok) {
      QMessageBox::warning(this, "警告", "参数必须为数字");
      return;
    }
  }

  // 构建 task
  // Task(QString task_name, QString task_url, int thread_num, Type type,
  //             HttpMethod http_type, QByteArray http_data = QByteArray());
  Task *task =
      new Task(task_name, task_url, thread_num_int, (Task::Type)task_type,
               (HttpMethod)http_method, body.toLocal8Bit());
  if (task_type == 1) {
    task->setLoopTime(para_int);
  } else if (task_type == 2) {
    task->setTimeInterval(para_int);
  }

  if (ui->_proxy_check->isChecked()) {
    task->setIsProxy(true);
  }

  // 发送信号
  emit addTask(task);
  close();
}
void AddTaskWidget::cancelButtonClicked() { close(); }
