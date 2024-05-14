#ifndef HTTP_H__
#define HTTP_H__
#include <QDateTime>
#include <QElapsedTimer>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>
#include <QPointer>
#include <QRunnable>
#include <QThread>
#include <QVariant>
#include <iostream>
#include <QNetworkProxy>

enum class HttpMethod : int { GET, POST, PUT, DELETE, HEAD };
enum class HttpError : int { NO_ERROR, TIMEOUT, ERROR };

QString HttpErrorToString(HttpError error);
QString HttpMethodToString(HttpMethod method);

struct HttpResponse {
  HttpMethod method;
  HttpError error;
  QByteArray data;
  qint64 responseTime;
  QDateTime start;
  QDateTime end;

  friend std::ostream &operator<<(std::ostream &os,
                                  const HttpResponse &response) {
    os << "Method: " << HttpMethodToString(response.method).toStdString()
       << std::endl;
    os << "Start: " << response.start.toString().toStdString() << std::endl;
    os << "Error: " << HttpErrorToString(response.error).toStdString()
       << std::endl;
    os << "Data: " << response.data.toStdString() << std::endl;
    os << "Response Time: " << response.responseTime << std::endl;
    return os;
  }
};

class HttpClient : public QObject, public QRunnable {
  Q_OBJECT
public:
  HttpClient(
      HttpMethod method, const QString &url, const QString &data = "",
      const QNetworkRequest::KnownHeaders &headertype =
          QNetworkRequest::ContentTypeHeader,
      const QVariant &header = QVariant("application/x-www-form-urlencoded"),
      qint64 timeout = 3000);
  void run() override;
  void setProxy(const QNetworkProxy &proxy);
signals:
  void finished(const HttpResponse response);

private:
  HttpMethod _method;
  QString _url;
  QString _data;
  QNetworkRequest::KnownHeaders _headertype;
  QVariant _header;
  qint64 _timeout;
  QNetworkProxy _proxy;
};

#endif