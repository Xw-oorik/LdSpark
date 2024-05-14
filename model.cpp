#include "model.h"
#include <QVector>
Model::Model(QList<Task *> &tasks) : _tasks(tasks) {}
void Model::loaddata(int id) {
  // Load data from tasks
  Task *task = nullptr;
  for (int i = 0; i < _tasks.size(); i++) {
    if (_tasks[i]->getId() == id) {
      task = _tasks[i];
      break;
    }
  }

  if (task != nullptr) {
    auto data = task->getResult();

    // 获取最早的开始时间和最晚的结束时间
    if (data.size() == 0) {
      return;
    }
    clear();

    auto starttime = data.first().start;
    auto endtime = data.first().end;
    for (int i = 0; i < data.size(); i++) {
      if (data[i].start < starttime) {
        starttime = data[i].start;
      }
      if (data[i].end > endtime) {
        endtime = data[i].end;
      }
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
      respdata[start_index][0]++;
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

    // 计算平均响应时间
    for (int i = 0; i < count; i++) {
      if (respdata[i][1] != 0) {
        respdata[i][4] = resptime[i] * 1.0 / respdata[i][1];
      }
    }

    // 填充数据
    setHorizontalHeaderLabels(QStringList()
                              << QString::fromLocal8Bit("时间")
                              << QString::fromLocal8Bit("请求数")
                              << QString::fromLocal8Bit("响应数")
                              << QString::fromLocal8Bit("超时数")
                              << QString::fromLocal8Bit("错误数")
                              << QString::fromLocal8Bit("平均响应时间(ms)"));

    for (int i = 0; i < count; i++) {
      // 检查一下是不是都是 0
      if (respdata[i][0] == 0 && respdata[i][1] == 0 && respdata[i][2] == 0 &&
          respdata[i][3] == 0 && respdata[i][4] == 0) {
        continue;
      }

      auto time = new QStandardItem(starttime.addSecs(i).toString("hh:mm:ss"));
      auto req = new QStandardItem(QString::number(respdata[i][0]));
      auto resp = new QStandardItem(QString::number(respdata[i][1]));
      auto timeout = new QStandardItem(QString::number(respdata[i][2]));
      auto error = new QStandardItem(QString::number(respdata[i][3]));
      auto avg = new QStandardItem(QString::number(respdata[i][4]));
      QList<QStandardItem *> row;
      row.append(time);
      row.append(req);
      row.append(resp);
      row.append(timeout);
      row.append(error);
      row.append(avg);

      appendRow(row);
    }
  }
}
