#ifndef ADDTASK_H
#define ADDTASK_H

#include "task.h"
#include <QWidget>

namespace Ui {
class AddTaskWidget;
}

class AddTaskWidget : public QWidget {
  Q_OBJECT

public:
  explicit AddTaskWidget(QWidget *parent = nullptr);
  ~AddTaskWidget();
signals:
  void addTask(Task *task);

private slots:
  void addTaskButtonClicked();
  void cancelButtonClicked();

private:
  Ui::AddTaskWidget *ui;
};

#endif // ADDTASK_H
