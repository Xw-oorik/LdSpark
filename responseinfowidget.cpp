#include "responseinfowidget.h"
#include "ui_responseinfowidget.h"
#include <QHBoxLayout>
ResponseInfoWidget::ResponseInfoWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::ResponseInfoWidget) {
  ui->setupUi(this);
  _webview = new QWebEngineView(this);
  QHBoxLayout *webview_layout = new QHBoxLayout;
  webview_layout->addWidget(_webview);
  ui->_response_text->setLayout(webview_layout);
}

ResponseInfoWidget::~ResponseInfoWidget() { delete ui; }

void ResponseInfoWidget::setTaskName(QString taskName) {
  ui->_task_name->clear();
  ui->_task_name->setText(taskName);
}
void ResponseInfoWidget::setTaskContent(QString taskContent) {

  _webview->setHtml(taskContent);
}