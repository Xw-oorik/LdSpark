#ifndef ADDPROXYWIDGET_H
#define ADDPROXYWIDGET_H

#include <QNetworkProxy>
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

private slots:
  void addButtonClicked();
  void cancelButtonClicked();

private:
  Ui::AddProxyWidget *ui;
};

#endif // ADDPROXYWIDGET_H
