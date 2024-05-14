/********************************************************************************
** Form generated from reading UI file 'responseinfowidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESPONSEINFOWIDGET_H
#define UI_RESPONSEINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResponseInfoWidget
{
public:
    QGridLayout *gridLayout;
    QLineEdit *_task_name;
    QWidget *_response_text;

    void setupUi(QWidget *ResponseInfoWidget)
    {
        if (ResponseInfoWidget->objectName().isEmpty())
            ResponseInfoWidget->setObjectName("ResponseInfoWidget");
        ResponseInfoWidget->resize(384, 230);
        gridLayout = new QGridLayout(ResponseInfoWidget);
        gridLayout->setObjectName("gridLayout");
        _task_name = new QLineEdit(ResponseInfoWidget);
        _task_name->setObjectName("_task_name");
        _task_name->setReadOnly(true);

        gridLayout->addWidget(_task_name, 0, 0, 1, 1);

        _response_text = new QWidget(ResponseInfoWidget);
        _response_text->setObjectName("_response_text");

        gridLayout->addWidget(_response_text, 1, 0, 1, 1);


        retranslateUi(ResponseInfoWidget);

        QMetaObject::connectSlotsByName(ResponseInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *ResponseInfoWidget)
    {
        ResponseInfoWidget->setWindowTitle(QCoreApplication::translate("ResponseInfoWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResponseInfoWidget: public Ui_ResponseInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESPONSEINFOWIDGET_H
