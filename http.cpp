#include "http.h"
#include <QByteArray>
#include <QDateTime>
#include <QElapsedTimer>
#include <QEventLoop>
#include <QTimer>

QString HttpErrorToString(HttpError error) {
  switch (error) {
  case HttpError::NO_ERROR:
    return "NO_ERROR";
  case HttpError::TIMEOUT:
    return "TIMEOUT";
  case HttpError::ERROR:
    return "ERROR";
  default:
    return "UNKNOWN";
  }
}
// Path: http.cpp
HttpClient::HttpClient(QMutex *pausemutex, QWaitCondition *pausecond,
                       bool *ispause, HttpMethod method, const QString &url,
                       const QString &data,
                       const QNetworkRequest::KnownHeaders &headertype,
                       const QVariant &header, qint64 timeout)
    : pauseMutex(pausemutex), pauseCond(pausecond), isPaused(ispause),
      QRunnable() {
  this->_method = method;
  this->_url = url;
  this->_data = data;
  this->_timeout = timeout;
  this->_header = header;
  this->_headertype = headertype;
  setAutoDelete(true);
  setObjectName("HttpClient");
}

QString HttpMethodToString(HttpMethod method) {
  switch (method) {
  case HttpMethod::GET:
    return "GET";
  case HttpMethod::POST:
    return "POST";
  case HttpMethod::PUT:
    return "PUT";
  case HttpMethod::DELETE:
    return "DELETE";
  case HttpMethod::HEAD:
    return "HEAD";
  default:
    return "UNKNOWN";
  }
}

void HttpClient::run() {
  QMutexLocker locker(pauseMutex);
  while (*isPaused) {
    pauseCond->wait(pauseMutex);
  }
  locker.unlock();

  QNetworkAccessManager *manager = new QNetworkAccessManager();
  if (_proxy.hostName().size() > 0 && _proxy.port() > 0) {
    manager->setProxy(_proxy);
  }
  QNetworkRequest request = QNetworkRequest(QUrl(_url));
  request.setHeader(_headertype, _header);

  QEventLoop loop;
  QTimer timer;
  QElapsedTimer elapsedtimer;
  QByteArray postData;
  timer.setSingleShot(true);
  timer.start(_timeout);
  QDateTime time = QDateTime::currentDateTime();
  // 开始计时
  elapsedtimer.start();
  connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
  QNetworkReply *reply = nullptr;
  if (_method == HttpMethod::GET) {
    reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
  } else if (_method == HttpMethod::POST) {
    postData = _data.toUtf8();
    reply = manager->post(request, postData);
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
  } else if (_method == HttpMethod::PUT) {
    postData = _data.toUtf8();
    reply = manager->put(request, postData);
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
  } else if (_method == HttpMethod::DELETE) {
    reply = manager->deleteResource(request);
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
  } else if (_method == HttpMethod::HEAD) {
    reply = manager->head(request);
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
  } else {
    // 默认为 GET 方法
    reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
  }
  loop.exec(); // 阻塞，直至接收结束或者超时
  qint64 millseconds = elapsedtimer.elapsed(); // 结束计时， 获取经过的毫秒数
  HttpResponse response;
  response.responseTime = millseconds;
  response.start = time;
  response.method = _method;
  response.end = time.addMSecs(millseconds);

  if (timer.isActive()) {
    timer.stop();
    if (reply->error() == QNetworkReply::NoError) {
      QByteArray data = reply->readAll();
      response.data = data;
      response.error = HttpError::NO_ERROR;
    } else {
      response.error = HttpError::ERROR;
      response.data = reply->errorString().toUtf8();
    }
  } else {
    // timeout
    response.error = HttpError::TIMEOUT;
    response.data = reply->errorString().toUtf8();
  }

  disconnect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
  disconnect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
  reply->deleteLater();
  manager->deleteLater();
  emit finished(response);
}

void HttpClient::setProxy(const QNetworkProxy &proxy) { _proxy = proxy; }