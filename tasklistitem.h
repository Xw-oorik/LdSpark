#ifndef TASKLISTITEM_H
#define TASKLISTITEM_H

#include "task.h"
#include <QTimer>
#include <QWidget>
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
  void setId(int id);
  void setTaskProgressBarStart(Task *task);
  void setTaskProgressBarStop(Task *task);
  void setTaskProgressBarGoon(Task *task);

private:
  Ui::TaskListItem *ui;
  int _taskid;
  QTimer *progressbar_timer = nullptr;
};

#endif // TASKLISTITEM_H
