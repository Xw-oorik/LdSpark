#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "model.h"
#include "task.h"
#include "tasklistitem.h"
#include <QDebug>
#include <QDialog>
#include <QDir>
#include <QFile>
#include <QFormLayout>
#include <QLineEdit>
#include <QThreadPool>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setWindowTitle("LdSpark");
  ui->label->setOpenExternalLinks(true);
  connect(ui->_add_btn, &QPushButton::clicked, this,
          &MainWindow::addButtonClicked);
  connect(ui->_remove_btn, &QPushButton::clicked, this,
          &MainWindow::removeButtonClicked);
  connect(ui->_proxy_btn, &QPushButton::clicked, this,
          &MainWindow::proxyButtonClicked);
  connect(ui->_stop_btn, &QPushButton::clicked, this,
          &MainWindow::stopButtonClicked);
  connect(ui->_export_btn, &QPushButton::clicked, this,
          &MainWindow::exportButtonClicked);

  connect(ui->_task_list, &QListWidget::itemClicked, this,
          &MainWindow::taskListItemClicked);

  connect(ui->_task_list, &QListWidget::itemDoubleClicked, this,
          &MainWindow::showResponseInfo);
  connect(ui->_clean_btn, &QPushButton::clicked, this,
          &MainWindow::cleanListView);

  _addtask_window = new AddTaskWidget();
  _addproxy_window = new AddProxyWidget();
  _responseinfo_window = new ResponseInfoWidget();
  _exportgraph_window = new ExportGraphWidget(_tasks);

  connect(_addtask_window, &AddTaskWidget::addTask, this, &MainWindow::addTask);
  connect(_addproxy_window, &AddProxyWidget::addProxySignal, this,
          &MainWindow::addProxy);

  connect(_exportgraph_window, &ExportGraphWidget::exportPNGSignal, this,
          &MainWindow::exportPngSlot);

  connect(ui->comboBox, &QComboBox::currentIndexChanged, this,
          &MainWindow::comboBoxcurrentIndexChanged);

  comboBoxcurrentIndexChanged(); // 默认给主题1
  ui->_table_view->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);
  ui->_table_view->verticalHeader()->hide();

  _chart = new QChart();
  ui->_graph_view->setRenderHint(QPainter::Antialiasing);
  ui->_graph_view->setChart(_chart);
  ui->_graph_view->setInteractive(true); // 启用交互功能，包括平移和缩放
  ui->_graph_view->setRubberBand(
      QChartView::RectangleRubberBand); // 画个矩形区域进行缩放
  ui->_graph_view->setDragMode(QGraphicsView::ScrollHandDrag); // 手型 移动

  _requestSeries = new QSplineSeries();
  _requestSeries->setName("请求数");
  _requestSeries->setObjectName("request");
  _requestSeries->setColor(QColor(0, 255, 0));
  _requestSeries->setPointsVisible(true);

  _responseSeries = new QSplineSeries();
  _responseSeries->setObjectName("response");
  _responseSeries->setName("响应数");
  _responseSeries->setColor(QColor(255, 0, 0));
  _responseSeries->setPointsVisible(true);

  _timeoutSeries = new QSplineSeries();
  _timeoutSeries->setName("超时数");
  _timeoutSeries->setObjectName("timeout");
  _timeoutSeries->setColor(QColor(0, 0, 255));
  _timeoutSeries->setPointsVisible(true);

  _errorSeries = new QSplineSeries();
  _errorSeries->setName("错误数");
  _errorSeries->setObjectName("error");
  _errorSeries->setColor(QColor(255, 255, 0));
  _errorSeries->setPointsVisible(true);

  _responsetimeSeries = new QSplineSeries();
  _responsetimeSeries->setName("平均响应时间");
  _responsetimeSeries->setObjectName("responsetime");
  _responsetimeSeries->setColor(QColor(255, 0, 255));
  _responsetimeSeries->setPointsVisible(true);

  _chart->addSeries(_requestSeries);
  _chart->addSeries(_responseSeries);
  _chart->addSeries(_timeoutSeries);
  _chart->addSeries(_errorSeries);
  _chart->addSeries(_responsetimeSeries);

  _chart->legend()->setVisible(true);
  _chart->legend()->setAlignment(Qt::AlignTop);
}

MainWindow::~MainWindow() {
  QThreadPool::globalInstance()->waitForDone();
  delete ui;
}

void MainWindow::addButtonClicked() { _addtask_window->show(); }

void MainWindow::removeButtonClicked() {
  Task *task = nullptr;
  for (int i = 0; i < _tasks.size(); i++) {
    if (_tasks[i]->getId() == _currentTaskId) {
      task = _tasks[i];
      break;
    }
  }

  if (task) {
    task->stop();
    delete ui->_task_list->takeItem(_currentTaskId);
    _tasks.removeOne(task);
    delete task; // 删除任务对象
  }
  _currentTaskId = -1;
}

void MainWindow::proxyButtonClicked() { _addproxy_window->show(); }

void MainWindow::stopButtonClicked() {
  Task *task = nullptr;
  for (int i = 0; i < _tasks.size(); i++) {
    if (_tasks[i]->getId() == _currentTaskId) {
      task = _tasks[i];
      break;
    }
  }

  if (task) {
    auto item = ui->_task_list->item(_currentTaskId);
    TaskListItem *itemp = (TaskListItem *)(ui->_task_list->itemWidget(item));
    itemp->setTaskProgressBarStop(task);
    task->stop();
  }
}
void MainWindow::exportButtonClicked() {
  _exportgraph_window->updateTask();
  _exportgraph_window->show();
}

void MainWindow::addTask(Task *task) {
  task->setId(_tasks.size());
  if (task->getIsProxy()) {
    if (_proxy.hostName().isEmpty()) {
      QMessageBox::warning(this, "警告", "未设置代理，不设置代理");
    } else {
      task->setProxy(_proxy);
    }
  }
  _tasks.push_back(task);
  task->start();
  QListWidgetItem *pItem = new QListWidgetItem();
  ui->_task_list->addItem(pItem);
  TaskListItem *item = new TaskListItem(task->getId());
  pItem->setSizeHint(item->sizeHint());
  item->setInfo(formatTaskInfo(task));
  item->setName(task->getName());
  item->setTaskProgressBarStart(task);
  ui->_task_list->setItemWidget(pItem, item);
}

void MainWindow::cleanListView() {
  // 停止并删除所有任务
  for (Task *task : _tasks) {
    task->stop();
    delete task;
  }
  _tasks.clear(); // 清空任务列表

  // 清空列表视图
  ui->_task_list->clear();
  _currentTaskId = -1;
}

QString MainWindow::formatTaskInfo(Task *task) {
  // html format contain type and params
  QString info = "<p>type: ";
  switch (task->getType()) {
  case Task::Type::TIME:
    info += "time-";
    info += QString::number(task->getTimeInterval());
    break;
  case Task::Type::ONCE:
    info += "once";
    break;
  case Task::Type::LOOP:
    info += "loop-";
    info += QString::number(task->getLoopTime());
    break;
  }
  info += "</p>";
  return info;
}

void MainWindow::updateLineView(int id, QDateTime start, QDateTime end) {
  Task *task = nullptr;
  for (int i = 0; i < _tasks.size(); i++) {
    if (_tasks[i]->getId() == id) {
      task = _tasks[i];
      break;
    }
  }

  if (_chart && task) {
    auto data = task->getResult();
    if (data.size() == 0) {
      return;
    }

    _responseSeries->clear();
    _requestSeries->clear();
    _timeoutSeries->clear();
    _errorSeries->clear();
    _responsetimeSeries->clear();

    QList<QAbstractAxis *> axes = _chart->axes();
    for (QAbstractAxis *axis : axes) {
      _chart->removeAxis(axis);
      delete axis;
    }

    // 获取最早的开始时间和最晚的结束时间
    auto data_starttime = data.first().start;
    auto data_endtime = data.first().end;
    for (int i = 0; i < data.size(); i++) {
      if (data[i].start < data_starttime) {
        data_starttime = data[i].start;
      }
      if (data[i].end > data_endtime) {
        data_endtime = data[i].end;
      }
    }

    QDateTime starttime, endtime;
    if (start < data_starttime) {
      starttime = data_starttime;
    } else {
      starttime = start;
    }

    if (end > data_endtime) {
      endtime = data_endtime;
    } else {
      endtime = end;
    }

    // 计算每秒的请求数，响应数，错误数，超时数，错误数，平均响应时间
    int count = abs(endtime.secsTo(starttime)) + 2;
    QVector<QVector<float>> respdata(count, QVector<float>(5, 0));
    // 2d
    // 矩阵，第一列为请求数，第二列为响应数，第三列为超时数，第四列为错误数，第五列为平均响应时间
    QVector<float> resptime(count, 0);
    for (int i = 0; i < data.size(); i++) {
      // 获取每个结果的开始时间，结束时间
      auto start = data[i].start;
      auto end = data[i].end;
      int start_index = starttime.secsTo(start);
      int end_index = starttime.secsTo(end);

      // 统计每秒的请求数
      if (start_index < count) {
        respdata[start_index][0]++;
      }
      if (end_index < count) {
        // 累计每秒的响应时间
        resptime[end_index] += data[i].responseTime;
        // 统计每秒的响应数，错误数，超时数
        if (data[i].error == HttpError::NO_ERROR) {
          respdata[end_index][1]++;
        } else if (data[i].error == HttpError::TIMEOUT) {
          respdata[end_index][2]++;
        } else if (data[i].error == HttpError::ERROR) {
          respdata[end_index][3]++;
        }
      }
    }

    // 计算平均响应时间
    for (int i = 0; i < count; i++) {
      if (respdata[i][1] != 0) {
        respdata[i][4] = resptime[i] * 1.0 / respdata[i][1];
      }
    }

    // 设置横坐标为时间
    QCategoryAxis *_axisX = new QCategoryAxis();
    _axisX->setLabelsAngle(45);

    // 添加双纵坐标
    QValueAxis *_axisYLeft = new QValueAxis();
    _axisYLeft->setTitleText("次数");
    _chart->addAxis(_axisYLeft, Qt::AlignLeft);
    _responseSeries->attachAxis(_axisYLeft);
    _requestSeries->attachAxis(_axisYLeft);
    _timeoutSeries->attachAxis(_axisYLeft);
    _errorSeries->attachAxis(_axisYLeft);

    QValueAxis *_axisYRight = new QValueAxis();
    _axisYRight->setTitleText("时间(ms)");
    _chart->addAxis(_axisYRight, Qt::AlignRight);
    _responsetimeSeries->attachAxis(_axisYRight);

    qreal mincount = std::numeric_limits<qreal>::max();
    qreal maxcount = std::numeric_limits<qreal>::min();
    qreal mintime = std::numeric_limits<qreal>::max();
    qreal maxtime = std::numeric_limits<qreal>::min();

    for (int i = 0; i < count; i++) {
      if (respdata[i][0] > maxcount) {
        maxcount = respdata[i][0];
      }
      if (respdata[i][0] < mincount) {
        mincount = respdata[i][0];
      }
      if (respdata[i][4] > maxtime) {
        maxtime = respdata[i][4];
      }
      if (respdata[i][4] < mintime) {
        mintime = respdata[i][4];
      }
    }

    // 设置纵坐标范围
    _axisYLeft->setRange(-1, maxcount + 1);
    _axisYLeft->setTickCount(maxcount + 3);
    _axisYRight->setRange(mintime, maxtime + 1);
    _axisYRight->setTickCount(maxcount + 2);

    // 设置横坐标，如果横坐标超过 20,则简略显示
    _axisX->setRange(0, count);
    int ratio = 1;
    ratio = count / 20 + 1;
    for (int i = 0; i < count; i += ratio) {
      _axisX->append(starttime.addSecs(i).toString("hh:mm:ss"), i);
    }

    _chart->addAxis(_axisX, Qt::AlignBottom);
    _responsetimeSeries->attachAxis(_axisX);
    _responseSeries->attachAxis(_axisX);
    _requestSeries->attachAxis(_axisX);
    _timeoutSeries->attachAxis(_axisX);
    _errorSeries->attachAxis(_axisX);

    // 添加数据
    for (int i = 0; i < count; i++) {
      // 保证数据点不重叠
      qreal offsetY = i % 2 == 0 ? 0 : -0.1;
      _requestSeries->append(i, respdata[i][0] + offsetY);
      _responseSeries->append(i, respdata[i][1]);
      _timeoutSeries->append(i, respdata[i][2]);
      _errorSeries->append(i, respdata[i][3]);
      _responsetimeSeries->append(i, respdata[i][4]);
    }
  }
}
void MainWindow::taskListItemClicked(QListWidgetItem *item) {
  // 更新表格数据
  TaskListItem *task_item = (TaskListItem *)(ui->_task_list->itemWidget(item));
  int id = task_item->getId();
  if (task_item) {
    if (!_model) {
      _model = new Model(_tasks);
      ((Model *)_model)->loaddata(id);
      ui->_table_view->setModel(_model);
    } else {
      ((Model *)_model)->loaddata(id);
      ui->_table_view->setModel(_model);
    }
  }
  // 表格数据设置不可编辑
  ui->_table_view->setEditTriggers(QAbstractItemView::NoEditTriggers);
  // 交替背景色
  ui->_table_view->setAlternatingRowColors(true);

  // 更新图表数据
  updateLineView(id, QDateTime::fromSecsSinceEpoch(0),
                 QDateTime::currentDateTime());
  _currentTaskId = id;
}

void MainWindow::addProxy(QNetworkProxy proxy) {
  _proxy = proxy;
  QString info;
  info.append("host: ");
  info.append(_proxy.hostName());
  info.append(" port: ");
  info.append(QString::number(_proxy.port()));
  ui->statusbar->showMessage(info);
}

void MainWindow::showResponseInfo(QListWidgetItem *item) {
  TaskListItem *task_item = (TaskListItem *)(ui->_task_list->itemWidget(item));
  int id = task_item->getId();
  Task *task = nullptr;
  for (int i = 0; i < _tasks.size(); i++) {
    if (_tasks[i]->getId() == id) {
      task = _tasks[i];
      break;
    }
  }

  if (task) {
    _responseinfo_window->setTaskName(task->getName());
    QString content;
    auto results = task->getResult();
    // for (auto result : results) {
    //   content.append(result.data);
    //   content.append("\n");
    // }
    content.append(results[0].data);
    _responseinfo_window->setTaskContent(content); // 显示webview
  }
  _responseinfo_window->show();
}
void MainWindow::exportPngSlot(int id, QDateTime start, QDateTime end,
                               const QList<bool> &_ifchecked) {
  updateLineView(id, start, end);
  QString fileName = QFileDialog::getSaveFileName(this, tr("Save to PNG"), "",
                                                  tr("PNG files (*.png)"));

  if (!fileName.isNull()) {
    const auto dpr = ui->_graph_view->devicePixelRatioF();
    QPixmap buffer(ui->_graph_view->size() * dpr);
    buffer.setDevicePixelRatio(dpr / 2);
    buffer.fill(Qt::transparent);

    QPainter painter(&buffer);
    painter.setRenderHint(QPainter::Antialiasing); // 添加抗锯齿渲染
    painter.setPen(QColor(255, 34, 255, 255));

    for (int i = 0; i < _ifchecked.size(); ++i) {
      if (_ifchecked[i]) {
        switch (i) {
        case 0:
          // 导出请求数
          _requestSeries->setVisible(true);
          _responseSeries->setVisible(false);
          _errorSeries->setVisible(false);
          _timeoutSeries->setVisible(false);
          _responsetimeSeries->setVisible(false);
          ui->_graph_view->render(&painter);
          saveImage(fileName + "_request.png", buffer);
          break;
        case 1:
          // 导出响应数
          _requestSeries->setVisible(false);
          _responseSeries->setVisible(true);
          _errorSeries->setVisible(false);
          _timeoutSeries->setVisible(false);
          _responsetimeSeries->setVisible(false);
          ui->_graph_view->render(&painter);
          saveImage(fileName + "_response.png", buffer);
          break;
        case 2:
          // 导出超时数
          _requestSeries->setVisible(false);
          _responseSeries->setVisible(false);
          _errorSeries->setVisible(false);
          _timeoutSeries->setVisible(true);
          _responsetimeSeries->setVisible(false);
          ui->_graph_view->render(&painter);
          saveImage(fileName + "_timeout.png", buffer);
          break;
        case 3:
          // 导出错误数
          _requestSeries->setVisible(false);
          _responseSeries->setVisible(false);
          _errorSeries->setVisible(true);
          _timeoutSeries->setVisible(false);
          _responsetimeSeries->setVisible(false);
          ui->_graph_view->render(&painter);
          saveImage(fileName + "_error.png", buffer);
          break;
        case 4:
          // 导出平均响应
          _requestSeries->setVisible(false);
          _responseSeries->setVisible(false);
          _errorSeries->setVisible(false);
          _timeoutSeries->setVisible(false);
          _responsetimeSeries->setVisible(true);
          ui->_graph_view->render(&painter);
          saveImage(fileName + "_avgresponse.png", buffer);
          break;
        case 5:
          // 整体导出
          _requestSeries->setVisible(true);
          _responseSeries->setVisible(true);
          _errorSeries->setVisible(true);
          _timeoutSeries->setVisible(true);
          _responsetimeSeries->setVisible(true);
          ui->_graph_view->render(&painter);
          saveImage(fileName + "_summary.png", buffer);
          break;
        default:
          break;
        }
      }
    }
    buffer.fill(Qt::transparent);
    _requestSeries->setVisible(true);
    _responseSeries->setVisible(true);
    _errorSeries->setVisible(true);
    _timeoutSeries->setVisible(true);
    _responsetimeSeries->setVisible(true);
  }
}

void MainWindow::saveImage(const QString &fileName, const QPixmap &pixmap) {
  QFile file(fileName);
  if (file.open(QIODevice::WriteOnly)) {
    pixmap.save(&file, "PNG", 100);
    file.close();
  }
}
void MainWindow::comboBoxcurrentIndexChanged(int index) {
  qDebug() << index;
  // clear all previous qss
  for (QWidget *widget : this->findChildren<QWidget *>()) {
    style()->unpolish(this);
    widget->setStyleSheet("");
  }
  // according index to change qss
  QString qss;
  QFile qssFile1(":/qss/blacksoft.css");
  QFile qssFile(":/qss/flatgray.css");
  QFile qssFile2(":/qss/lightblue.css");

  if (index == 0) {
    qssFile.open(QFile::ReadOnly);
    if (qssFile.isOpen()) {
      // 用QTextStream读取样式文件不用区分文件编码 带bom也行
      QStringList list;
      QTextStream in(&qssFile);
      // in.setCodec("utf-8");
      while (!in.atEnd()) {
        QString line;
        in >> line;
        list << line;
      }
      qssFile.close();
      qss = list.join("\n");
      QString paletteColor = qss.mid(20, 7);
      qApp->setPalette(QPalette(paletteColor));
      // 用时主要在下面这句
      qApp->setStyleSheet(qss);
    }
  } else if (index == 1) {
    qssFile1.open(QFile::ReadOnly);
    if (qssFile1.isOpen()) {
      // 用QTextStream读取样式文件不用区分文件编码 带bom也行
      QStringList list;
      QTextStream in(&qssFile1);
      // in.setCodec("utf-8");
      while (!in.atEnd()) {
        QString line;
        in >> line;
        list << line;
      }
      qssFile.close();
      qss = list.join("\n");
      QString paletteColor = qss.mid(20, 7);
      qApp->setPalette(QPalette(paletteColor));
      // 用时主要在下面这句
      qApp->setStyleSheet(qss);
    }
  } else if (index == 2) {
    qssFile2.open(QFile::ReadOnly);
    if (qssFile2.isOpen()) {
      // 用QTextStream读取样式文件不用区分文件编码 带bom也行
      QStringList list;
      QTextStream in(&qssFile2);
      // in.setCodec("utf-8");
      while (!in.atEnd()) {
        QString line;
        in >> line;
        list << line;
      }
      qssFile.close();
      qss = list.join("\n");
      QString paletteColor = qss.mid(20, 7);
      qApp->setPalette(QPalette(paletteColor));
      // 用时主要在下面这句
      qApp->setStyleSheet(qss);
    }
  }
}
