#include "tasklistitem.h"
#include "ui_tasklistitem.h"
#include <QFile>
#include <QPalette>
TaskListItem::TaskListItem(int taskid, QWidget *parent)
    : QWidget(parent), ui(new Ui::TaskListItem),
      progressbar_timer(new QTimer(this)) {
  ui->setupUi(this);
  _taskid = taskid;
}

TaskListItem::~TaskListItem() { delete ui; }

void TaskListItem::setInfo(QString info) { ui->_info_label->setText(info); }

void TaskListItem::setName(QString name) { ui->_name_label->setText(name); }

int TaskListItem::getId() { return _taskid; }
void TaskListItem::setId(int id) {
  _taskid=id;
}
void TaskListItem::setTaskProgressBarStart(Task *task) {
  // Ensure timer is stopped before starting a new task
  progressbar_timer->stop();
  disconnect(progressbar_timer, &QTimer::timeout, nullptr, nullptr);

  if (task->getType() == Task::Type::TIME) {
    ui->_progressBar->setTextVisible(false);
    int timeval = task->getTimeInterval();
    ui->_progressBar->setMaximum(timeval);
    ui->_progressBar->setValue(0);
    progressbar_timer->start(10);
    connect(progressbar_timer, &QTimer::timeout, this, [=]() {
      int current_val = ui->_progressBar->value();
      if (current_val >= timeval) {
        progressbar_timer->stop();
      } else {
        ui->_progressBar->setValue(current_val + 10);
      }
    });
  } else if (task->getType() == Task::Type::LOOP) {
    ui->_progressBar->setTextVisible(false);
    int loopval = task->getLoopTime() * 400;
    ui->_progressBar->setMaximum(loopval);
    ui->_progressBar->setValue(0);
    progressbar_timer->start(1);
    connect(progressbar_timer, &QTimer::timeout, this, [=]() {
      int current_val = ui->_progressBar->value();
      if (current_val >= loopval) {
        progressbar_timer->stop();
      } else {
        ui->_progressBar->setValue(current_val + 1);
      }
    });
  } else {
    ui->_progressBar->setRange(0, 0); // Indeterminate progress
  }
}

void TaskListItem::setTaskProgressBarStop(Task *task) {
  progressbar_timer->stop();
}
void TaskListItem::setTaskProgressBarGoon(Task *task) {
  if (task->getType() == Task::Type::TIME) {
    int timeval = task->getTimeInterval();
    progressbar_timer->start(10);
    connect(progressbar_timer, &QTimer::timeout, this, [=]() {
      int current_val = ui->_progressBar->value();
      if (current_val >= timeval) {
        progressbar_timer->stop();
      } else {
        ui->_progressBar->setValue(current_val + 2);
      }
    });
  } else if (task->getType() == Task::Type::LOOP) {
    int loopval = task->getLoopTime() * 400;
    progressbar_timer->start(1);
    connect(progressbar_timer, &QTimer::timeout, this, [=]() {
      int current_val = ui->_progressBar->value();
      if (current_val >= loopval) {
        progressbar_timer->stop();
      } else {
        ui->_progressBar->setValue(current_val + 1);
      }
    });
  }
}