#include "task.h"
#include <QCoreApplication>
#include <QMutexLocker>
#include <cassert>

Task::Task(QString task_name, QString task_url, int thread_num, Type type,
           HttpMethod http_type, QByteArray http_data) {
  this->_task_name = task_name;
  this->_task_url = task_url;
  this->_thread_num = thread_num;
  this->_type = type;
  this->_http_type = http_type;
  this->_http_data = http_data;
  _thread_pool = new QThreadPool();
  if (_thread_pool && _thread_num > 0) {
    _thread_pool->setMaxThreadCount(_thread_num);
  }
  _timer = new QTimer(this);
  mutex = new QMutex();
}

Task::~Task() {
  delete mutex;
  if (_thread_pool) {
    _thread_pool->waitForDone();
    delete _thread_pool;
  }
}

void Task::start() {
  switch (_type) {
  case Type::ONCE:
    startOnce();
    break;
  case Type::TIME:
    assert(_time_interval > 0 && "time interval must be greater than 0");
    startTimes();
    break;
  case Type::LOOP:
    assert(_loop_time > 0 && "loop time must be greater than 0");
    startLoop();
    break;
  default:
    break;
  }
}

void Task::startOnce() {
  isLoadTestingInProgress = true;
  // 只添加一共单独的任务
  HttpClient *client =
      new HttpClient(_http_type, QString(_task_url), _http_data);
  if (_is_proxy) {
    client->setProxy(_proxy);
  }
  _thread_pool->start(client);
  connect(client, &HttpClient::finished, this, &Task::finished);
  if (result.size()) {
    isLoadTestingInProgress = false;
  }
}

void Task::startTimes() {
  isLoadTestingInProgress = true;
  // 添加时间范围的任务
  _timer->start(10);                         // 每10毫秒，做任务
  QTimer *_elapsed_timer = new QTimer(this); // 用来判断到设置时间没有
  _elapsed_timer->setSingleShot(true);
  _elapsed_timer->start(_time_interval);

  connect(_timer, &QTimer::timeout, this, [=]() {
    HttpClient *client =
        new HttpClient(_http_type, QString(_task_url), _http_data);
    if (_is_proxy) {
      client->setProxy(_proxy);
    }
    _thread_pool->start(client);
    connect(client, &HttpClient::finished, this, &Task::finished);
  });
  connect(_elapsed_timer, &QTimer::timeout, this, [=]() {
    _timer->stop();
    _thread_pool->clear();
  });
}

void Task::startLoop() {
  isLoadTestingInProgress = true;
  for (int i = 0; i < _loop_time; i++) {
    HttpClient *client =
        new HttpClient(_http_type, QString(_task_url), _http_data);
    if (_is_proxy) {
      client->setProxy(_proxy);
    }
    _thread_pool->start(client);
    connect(client, &HttpClient::finished, this, &Task::finished);
  }
}

void Task::finished(HttpResponse response) {
  QMutexLocker locker(mutex);
  result.append(response);
  // 针对loop和time模式
  if (result.size() >= _loop_time || !_timer->isActive()) {
    isLoadTestingInProgress = false;
  }
}

void Task::setTimeInterval(qint64 time_interval) {
  _time_interval = time_interval;
}

void Task::setLoopTime(qint64 loop_time) { _loop_time = loop_time; }

void Task::stop() {
  if (_type == Type::TIME) {
    _timer->stop();
    _thread_pool->clear();
  } else {
    _thread_pool->clear();
  }
}

QList<HttpResponse> &Task::getResult() { return result; }

void Task::setId(int id) { _id = id; }

int Task::getId() { return _id; }

QString Task::getName() { return _task_name; }

QString Task::getUrl() { return _task_url; }

Task::Type Task::getType() { return _type; }

qint64 Task::getTimeInterval() { return _time_interval; }

qint64 Task::getLoopTime() { return _loop_time; }

void Task::setProxy(QNetworkProxy proxy) {
  _proxy = proxy;
  _is_proxy = true;
}

void Task::setIsProxy(bool is_proxy) { _is_proxy = is_proxy; }

bool Task::getIsProxy() { return _is_proxy; }
bool Task::isLoadingInProgress() {
  return isLoadTestingInProgress;
}