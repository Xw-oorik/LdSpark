/********************************************************************************
** Form generated from reading UI file 'addproxywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPROXYWIDGET_H
#define UI_ADDPROXYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddProxyWidget
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *_hostname_lineedit;
    QLabel *label_2;
    QLineEdit *_port_lineedit;
    QLabel *label_3;
    QLineEdit *_username_lineedit;
    QLabel *label_4;
    QLineEdit *_password_lineedit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *_add_btn;
    QPushButton *_cancel_btn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *AddProxyWidget)
    {
        if (AddProxyWidget->objectName().isEmpty())
            AddProxyWidget->setObjectName("AddProxyWidget");
        AddProxyWidget->resize(261, 162);
        gridLayout_2 = new QGridLayout(AddProxyWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(AddProxyWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        _hostname_lineedit = new QLineEdit(AddProxyWidget);
        _hostname_lineedit->setObjectName("_hostname_lineedit");

        gridLayout->addWidget(_hostname_lineedit, 0, 1, 1, 1);

        label_2 = new QLabel(AddProxyWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        _port_lineedit = new QLineEdit(AddProxyWidget);
        _port_lineedit->setObjectName("_port_lineedit");

        gridLayout->addWidget(_port_lineedit, 1, 1, 1, 1);

        label_3 = new QLabel(AddProxyWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        _username_lineedit = new QLineEdit(AddProxyWidget);
        _username_lineedit->setObjectName("_username_lineedit");

        gridLayout->addWidget(_username_lineedit, 2, 1, 1, 1);

        label_4 = new QLabel(AddProxyWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        _password_lineedit = new QLineEdit(AddProxyWidget);
        _password_lineedit->setObjectName("_password_lineedit");

        gridLayout->addWidget(_password_lineedit, 3, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _add_btn = new QPushButton(AddProxyWidget);
        _add_btn->setObjectName("_add_btn");

        horizontalLayout->addWidget(_add_btn);

        _cancel_btn = new QPushButton(AddProxyWidget);
        _cancel_btn->setObjectName("_cancel_btn");

        horizontalLayout->addWidget(_cancel_btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(AddProxyWidget);

        QMetaObject::connectSlotsByName(AddProxyWidget);
    } // setupUi

    void retranslateUi(QWidget *AddProxyWidget)
    {
        AddProxyWidget->setWindowTitle(QCoreApplication::translate("AddProxyWidget", "\344\273\243\347\220\206", nullptr));
        label->setText(QCoreApplication::translate("AddProxyWidget", "URL", nullptr));
        label_2->setText(QCoreApplication::translate("AddProxyWidget", "\347\253\257\345\217\243", nullptr));
        label_3->setText(QCoreApplication::translate("AddProxyWidget", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("AddProxyWidget", "\345\257\206\347\240\201", nullptr));
        _add_btn->setText(QCoreApplication::translate("AddProxyWidget", "\346\267\273\345\212\240", nullptr));
        _cancel_btn->setText(QCoreApplication::translate("AddProxyWidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddProxyWidget: public Ui_AddProxyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPROXYWIDGET_H
