#ifndef TASKLISTITEM_H
#define TASKLISTITEM_H

#include "task.h"
#include <QWidget>
#include <QTimer>
namespace Ui {
class TaskListItem;
}

class TaskListItem : public QWidget {
  Q_OBJECT

public:
  explicit TaskListItem(int taskid, QWidget *parent = nullptr);
  ~TaskListItem();
  void setInfo(QString info);
  void setName(QString name);
  int getId();
  void setTaskProgressBarStart(Task *task);
  void setTaskProgressBarStop(Task *task);

private:
  Ui::TaskListItem *ui;
  int _taskid;
  QTimer * progressbar_timer;
};

#endif // TASKLISTITEM_H
