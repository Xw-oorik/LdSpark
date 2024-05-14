#ifndef EXPORTGRAPHWIDGET_H
#define EXPORTGRAPHWIDGET_H

#include "task.h"
#include <QButtonGroup>
#include <QChart>
#include <QWidget>
namespace Ui {
class ExportGraphWidget;
}

class ExportGraphWidget : public QWidget {
  Q_OBJECT

public:
  explicit ExportGraphWidget(QList<Task *> &tasks, QWidget *parent = nullptr);
  ~ExportGraphWidget();
  void updateTask();
  QList<bool> getifchecked();
  
signals:
  void exportPNGSignal(int id, QDateTime start, QDateTime end,
                       QList<bool> _ifchecked);

private slots:
  void combIndexChanged(int index);
  void exportClicked();
  void selectAllToggled(bool checked);
 
private:
  Ui::ExportGraphWidget *ui;
  QList<Task *> &_tasks;
  QChart *_chart;
  QButtonGroup *_buttonGroup;
  QList<bool> _ifchecked;
  Task *_selectedTask; // 跟踪之前的任务，在导出的时候任务压测没有结束的时候，恢复到他
};

#endif // EXPORTGRAPHWIDGET_H
