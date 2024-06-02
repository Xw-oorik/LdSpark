#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "addproxywidget.h"
#include "addtask.h"
#include "exportgraphwidget.h"
#include "responseinfowidget.h"
#include "task.h"
#include <QChartView>
#include <QListWidgetItem>
#include <QMainWindow>
#include <QSplineSeries>
#include <QtCharts>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

private slots:
  void addButtonClicked();
  void removeButtonClicked();
  void goonButtonClicked();
  void stopButtonClicked();
  void exportButtonClicked();
  void proxyButtonClicked();
  void addTask(Task *task);
  void addProxy(QNetworkProxy proxy);
  void showResponseInfo(QListWidgetItem *item);
  void cancelProxy();
public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  void cleanListView();
  QString formatTaskInfo(Task *task);
  void extracted(int &id);
  void taskListItemClicked(QListWidgetItem *item);
  void updateLineView(int id, QDateTime start, QDateTime end);
  void saveImage(const QString &fileName, const QPixmap &pixmap);
  Task* getCurrentTask();
  void updateTaskUI(Task *task, bool isRunning);

protected:
  void exportPngSlot(int id, QDateTime start, QDateTime end,
                     const QList<bool> &_ifchecked);
  void comboBoxcurrentIndexChanged(int index = 0);

private:
  Ui::MainWindow *ui;
  AddTaskWidget *_addtask_window;   // 添加任务的小窗
  AddProxyWidget *_addproxy_window; // 代理的小窗
  ResponseInfoWidget *_responseinfo_window; // 双击task之后，弹出的response小窗
  ExportGraphWidget *_exportgraph_window; // 导出图像的小窗
  QList<Task *> _tasks;                   // 任务列表
  QStandardItemModel *_model =
      nullptr; // 表格的数据源model，和tableview要做绑定
  QChart *_chart = nullptr; // 图标的容器

  // 图表数据
  QSplineSeries *_requestSeries = nullptr;      // 请求
  QSplineSeries *_responseSeries = nullptr;     // 响应
  QSplineSeries *_errorSeries = nullptr;        // 错误
  QSplineSeries *_timeoutSeries = nullptr;      // 超时
  QSplineSeries *_responsetimeSeries = nullptr; // 平均响应时间
  // 网络代理
  QNetworkProxy _proxy;
  // 当前任务id
  int _currentTaskId = -1;
  // 是否点击了列表项
  bool _isclicked_task = false;
};
#endif // MAINWINDOW_H
