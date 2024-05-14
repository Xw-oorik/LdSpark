#ifndef TASK_H__
#define TASK_H__
#include "http.h"
#include <QMutex>
#include <QThreadPool>
#include <QTimer>

class Task : public QObject {
  Q_OBJECT
public:
  enum class Type : int { ONCE, LOOP, TIME };

  explicit Task(QString task_name, QString task_url, int thread_num, Type type,
                HttpMethod http_type, QByteArray http_data = QByteArray());

  ~Task();

public:
  void start();
  void setTimeInterval(qint64 time_interval);
  qint64 getTimeInterval();
  void setLoopTime(qint64 loop_time);
  qint64 getLoopTime();
  void stop();
  void setId(int id);
  QString getName();
  QString getUrl();
  Type getType();
  int getId();
  QList<HttpResponse> &getResult();
  void setProxy(QNetworkProxy proxy);
  void setIsProxy(bool is_proxy);
  bool getIsProxy();
  bool isLoadingInProgress();

private:
  void startOnce();
  void startTimes();
  void startLoop();

public slots:
  void finished(HttpResponse response);

private:
  int _id = 0;
  QString _task_name;
  QString _task_url;
  int _thread_num;
  QThreadPool *_thread_pool = nullptr;
  Type _type;
  qint64 _time_interval = 0;
  qint64 _loop_time = 0;
  HttpMethod _http_type = HttpMethod::GET;
  QByteArray _http_data;
  bool _isrunning = false;
  QTimer *_timer = nullptr;
  bool isDestroy = false;
  QList<HttpResponse> result;
  QNetworkProxy _proxy;
  bool _is_proxy = false;
  QMutex *mutex = nullptr;
  // 表示压测是否正在进行中
  bool isLoadTestingInProgress = false;
};

#endif