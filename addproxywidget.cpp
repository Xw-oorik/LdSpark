#include "addproxywidget.h"
#include "ui_addproxywidget.h"
#include <QMessageBox>
#include <QPushButton>
AddProxyWidget::AddProxyWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::AddProxyWidget) {
  ui->setupUi(this);
  connect(ui->_add_btn, &QPushButton::clicked, this,
          &AddProxyWidget::addButtonClicked);
  connect(ui->_cancel_btn, &QPushButton::clicked, this,
          &AddProxyWidget::cancelButtonClicked);
}

AddProxyWidget::~AddProxyWidget() { delete ui; }

void AddProxyWidget::addButtonClicked() {
  QString ip = ui->_hostname_lineedit->text();
  QString port = ui->_port_lineedit->text();
  QString username = ui->_username_lineedit->text();
  QString password = ui->_password_lineedit->text();
  if (ip.isEmpty() || port.isEmpty()) {
    QMessageBox::warning(this, "Warning", "请填写 URL 和端口号");
    return;
  }
  QNetworkProxy proxy;
  proxy.setType(QNetworkProxy::HttpProxy);
  proxy.setHostName(ip);
  proxy.setPort(port.toInt());
  if (!username.isEmpty() && !password.isEmpty()) {
    proxy.setUser(username);
    proxy.setPassword(password);
  }
  emit addProxySignal(proxy);
  close();
}

void AddProxyWidget::cancelButtonClicked() { close(); }
