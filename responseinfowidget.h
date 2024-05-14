#ifndef RESPONSEINFOWIDGET_H
#define RESPONSEINFOWIDGET_H

#include <QWebEngineView>
#include <QWidget>
namespace Ui {
class ResponseInfoWidget;
}

class ResponseInfoWidget : public QWidget {
  Q_OBJECT

public:
  explicit ResponseInfoWidget(QWidget *parent = nullptr);
  ~ResponseInfoWidget();
  void setTaskName(QString taskName);
  void setTaskContent(QString taskContent);

private:
  Ui::ResponseInfoWidget *ui;
  QWebEngineView *_webview;
};

#endif // RESPONSEINFOWIDGET_H
