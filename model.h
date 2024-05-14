#ifndef MODEL_H__
#define MODEL_H__

#include "task.h"
#include <QList>
#include <QObject>
#include <QStandardItemModel>

class Model : public QStandardItemModel {
public:
  explicit Model(QList<Task*> &tasks);
  void loaddata(int id);

private:
  QList<Task*> &_tasks;
};

#endif