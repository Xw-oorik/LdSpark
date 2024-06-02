#ifndef ADDPROXYWIDGET_H
#define ADDPROXYWIDGET_H

#include <QNetworkProxy>
#include <QProcess>
#include <QWidget>
namespace Ui {
class AddProxyWidget;
}

class AddProxyWidget : public QWidget {
  Q_OBJECT

public:
  explicit AddProxyWidget(QWidget *parent = nullptr);
  ~AddProxyWidget();
signals:
  void addProxySignal(QNetworkProxy proxy);
  void cancelProxySignal();
private slots:
  void addButtonClicked();
  void cancelButtonClicked();
  void onDefaultConfigClicked(bool click);
  void cancelDefaultConfigClicked(bool click);
private:
  Ui::AddProxyWidget *ui;
  QProcess *proxyProcess;
  void readTinyConfig();
};

#endif // ADDPROXYWIDGET_H
