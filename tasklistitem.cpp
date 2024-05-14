#include "tasklistitem.h"
#include "ui_tasklistitem.h"
#include <QFile>
#include <QPalette>
TaskListItem::TaskListItem(int taskid, QWidget *parent)
    : QWidget(parent), ui(new Ui::TaskListItem) {
  ui->setupUi(this);
  _taskid = taskid;
  progressbar_timer = new QTimer(this);
}

TaskListItem::~TaskListItem() { delete ui; }

void TaskListItem::setInfo(QString info) { ui->_info_label->setText(info); }

void TaskListItem::setName(QString name) { ui->_name_label->setText(name); }

int TaskListItem::getId() { return _taskid; }

void TaskListItem::setTaskProgressBarStart(Task *task) {
  if (task->getType() == Task::Type::TIME) {
    progressbar_timer->start(10);
    ui->_progressBar->setTextVisible(false);
    auto timeval = task->getTimeInterval();
    ui->_progressBar->setMaximum(timeval);
    connect(progressbar_timer, &QTimer::timeout, this, [=]() {
      int current_val = ui->_progressBar->value();
      if (current_val >= timeval) {
        progressbar_timer->stop();
      } else {
        ui->_progressBar->setValue(current_val +
                                   5); //+10是根据task的timer定时器默认设置的
      }
    });
  } else if (task->getType() == Task::Type::LOOP) {
    progressbar_timer->start(1);
    ui->_progressBar->setTextVisible(false);
    auto loopval = task->getLoopTime() * 300;
    ui->_progressBar->setMaximum(loopval);
    connect(progressbar_timer, &QTimer::timeout, this, [=]() {
      int current_val = ui->_progressBar->value();
      if (current_val >= loopval) {
        progressbar_timer->stop();
      } else {
        ui->_progressBar->setValue(current_val + 1);
      }
    });
  } else {
    ui->_progressBar->setRange(0, 0);
  }
}

void TaskListItem::setTaskProgressBarStop(Task *task) {
  progressbar_timer->stop();
}