#include "addproxywidget.h"
#include "ui_addproxywidget.h"
#include <QDir>
#include <QMessageBox>
#include <QPushButton>
#include <QRegularExpression>
AddProxyWidget::AddProxyWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::AddProxyWidget) {
  ui->setupUi(this);
  connect(ui->_add_btn, &QPushButton::clicked, this,
          &AddProxyWidget::addButtonClicked);
  connect(ui->_cancel_btn, &QPushButton::clicked, this,
          &AddProxyWidget::cancelButtonClicked);
  connect(ui->radioButton, &QRadioButton::toggled, this,
          &AddProxyWidget::onDefaultConfigClicked);
  connect(ui->radioButton_2, &QRadioButton::toggled, this,
          &AddProxyWidget::cancelDefaultConfigClicked);
}

AddProxyWidget::~AddProxyWidget() { delete ui; }

void AddProxyWidget::addButtonClicked() {
  QString ip = ui->_hostname_lineedit->text();
  QString port = ui->_port_lineedit->text();
  QString username = ui->_username_lineedit->text();
  QString password = ui->_password_lineedit->text();
  if (ip.isEmpty() || port.isEmpty()) {
    QMessageBox::warning(this, "Warning", "请填写 IP 和端口号");
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

void AddProxyWidget::onDefaultConfigClicked(bool click) {
  if (click) {
    proxyProcess = new QProcess();
    // 获取工作目录
    QString curdir = QString(PROJECT_ROOT);

    qDebug() << curdir;
    // 获取tinyproxy配置路径
    QString tinypath = curdir + "/bin/tinyproxy";
    QString tinyconfigpath = curdir + "/etc/tinyproxy/tinyproxy.conf";
    // 准备命令参数
    QStringList argument;
    argument << "-d"
             << "-c" << tinyconfigpath;
    qDebug() << tinypath;
    qDebug() << argument;
    // 启动
    proxyProcess->start(tinypath, argument);
    if (!proxyProcess->waitForStarted()) {
      qDebug() << "Failed to start tinyproxy: " << proxyProcess->errorString();
      return;
    }

    connect(proxyProcess, &QProcess::readyReadStandardOutput, this,
            [this]() { qDebug() << proxyProcess->readAllStandardOutput(); });

    connect(proxyProcess, &QProcess::readyReadStandardError, this,
            [this]() { qDebug() << proxyProcess->readAllStandardError(); });

    connect(proxyProcess,
            QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished), this,
            [](int exitCode, QProcess::ExitStatus exitStatus) {
              qDebug() << "Tinyproxy finished with exit code:" << exitCode
                       << "and exit status:" << exitStatus;
            });

    qDebug() << "Tinyproxy started successfully.";

    // 读取配置文件中的 IP 和端口并更新 QLineEdit
    readTinyConfig();
  }
}
void AddProxyWidget::cancelDefaultConfigClicked(bool click) {
  if (click && proxyProcess->state() == QProcess::Running) {
    proxyProcess->terminate();
    if (proxyProcess->waitForFinished(2000)) { // 等待进程完成，最多等待2秒
      qDebug() << "Tinyproxy waitForFinished successfully.";
    } else {
      qDebug() << "Failed to stop Tinyproxy in a timely manner.";
      proxyProcess->kill(); // 如果等待超时，强制终止进程
    }
    qDebug() << "Tinyproxy stopped successfully.";

    // 清除 QLineEdit 中的内容
    ui->_hostname_lineedit->clear();
    ui->_port_lineedit->clear();
    emit cancelProxySignal();
    delete proxyProcess;
  }
}

void AddProxyWidget::readTinyConfig() {
  // 获取配置文件路径
  QString currentPath = QString(PROJECT_ROOT);
  QString configFilePath = currentPath + "/etc/tinyproxy/tinyproxy.conf";

  QFile configFile(configFilePath);
  if (!configFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qDebug() << "Failed to open config file: " << configFilePath;
    return;
  }

  QTextStream in(&configFile);
  QString ip;
  QString port;

  // 读取配置文件内容
  while (!in.atEnd()) {
    QString line = in.readLine();
    while (!line.isNull()) {
      if (!line.contains("#")) { // 如果行中不包含 #
        if (line.contains("Bind")) {
          ip = line.split(QRegularExpression("\\s+")).last();
        } else if (line.contains("Port")) {
          port = line.split(QRegularExpression("\\s+")).last();
        }
      }
      line = in.readLine();
    }
  }

  configFile.close();
  // 更新 QLineEdit
  ui->_hostname_lineedit->setText(ip);
  ui->_port_lineedit->setText(port);
}