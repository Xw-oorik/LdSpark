/********************************************************************************
** Form generated from reading UI file 'addtask.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTASK_H
#define UI_ADDTASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddTaskWidget
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *_taskname_lineedit;
    QLabel *label_2;
    QLineEdit *_taskurl_lineedit;
    QLabel *label_3;
    QLineEdit *_task_thread_lineedit;
    QLabel *label_4;
    QLineEdit *_task_header_lineedit;
    QLabel *label_5;
    QLineEdit *_task_body_lineedit;
    QLabel *label_7;
    QComboBox *_httptype_comb;
    QLabel *label_6;
    QComboBox *_type_comb;
    QCheckBox *_proxy_check;
    QLineEdit *_para_lineedit;
    QHBoxLayout *horizontalLayout;
    QPushButton *_add_button;
    QPushButton *_cancel_button;

    void setupUi(QWidget *AddTask)
    {
        if (AddTask->objectName().isEmpty())
            AddTask->setObjectName("AddTask");
        AddTask->resize(213, 305);
        gridLayout_2 = new QGridLayout(AddTask);
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox_2 = new QGroupBox(AddTask);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(groupBox_2);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        _taskname_lineedit = new QLineEdit(groupBox_2);
        _taskname_lineedit->setObjectName("_taskname_lineedit");

        gridLayout->addWidget(_taskname_lineedit, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        _taskurl_lineedit = new QLineEdit(groupBox_2);
        _taskurl_lineedit->setObjectName("_taskurl_lineedit");

        gridLayout->addWidget(_taskurl_lineedit, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        _task_thread_lineedit = new QLineEdit(groupBox_2);
        _task_thread_lineedit->setObjectName("_task_thread_lineedit");

        gridLayout->addWidget(_task_thread_lineedit, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        _task_header_lineedit = new QLineEdit(groupBox_2);
        _task_header_lineedit->setObjectName("_task_header_lineedit");

        gridLayout->addWidget(_task_header_lineedit, 3, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        _task_body_lineedit = new QLineEdit(groupBox_2);
        _task_body_lineedit->setObjectName("_task_body_lineedit");

        gridLayout->addWidget(_task_body_lineedit, 4, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        _httptype_comb = new QComboBox(groupBox_2);
        _httptype_comb->addItem(QString());
        _httptype_comb->addItem(QString());
        _httptype_comb->addItem(QString());
        _httptype_comb->addItem(QString());
        _httptype_comb->addItem(QString());
        _httptype_comb->setObjectName("_httptype_comb");

        gridLayout->addWidget(_httptype_comb, 5, 1, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        _type_comb = new QComboBox(groupBox_2);
        _type_comb->addItem(QString());
        _type_comb->addItem(QString());
        _type_comb->addItem(QString());
        _type_comb->setObjectName("_type_comb");

        gridLayout->addWidget(_type_comb, 6, 1, 1, 1);

        _proxy_check = new QCheckBox(groupBox_2);
        _proxy_check->setObjectName("_proxy_check");
        _proxy_check->setEnabled(false);

        gridLayout->addWidget(_proxy_check, 7, 0, 1, 1);

        _para_lineedit = new QLineEdit(groupBox_2);
        _para_lineedit->setObjectName("_para_lineedit");

        gridLayout->addWidget(_para_lineedit, 7, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        _add_button = new QPushButton(AddTask);
        _add_button->setObjectName("_add_button");
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(_add_button->sizePolicy().hasHeightForWidth());
        _add_button->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(_add_button);

        _cancel_button = new QPushButton(AddTask);
        _cancel_button->setObjectName("_cancel_button");
        sizePolicy.setHeightForWidth(_cancel_button->sizePolicy().hasHeightForWidth());
        _cancel_button->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(_cancel_button);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(AddTask);

        QMetaObject::connectSlotsByName(AddTask);
    } // setupUi

    void retranslateUi(QWidget *AddTask)
    {
        AddTask->setWindowTitle(QCoreApplication::translate("AddTaskWidget", "\344\273\273\345\212\241", nullptr));
        groupBox_2->setTitle(QString());
        label->setText(QCoreApplication::translate("AddTaskWidget", "\344\273\273\345\212\241\345\220\215\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("AddTaskWidget", "URL", nullptr));
        label_3->setText(QCoreApplication::translate("AddTaskWidget", "\347\272\277\347\250\213\346\225\260", nullptr));
        label_4->setText(QCoreApplication::translate("AddTaskWidget", "Header", nullptr));
        label_5->setText(QCoreApplication::translate("AddTaskWidget", "Body", nullptr));
        label_7->setText(QCoreApplication::translate("AddTaskWidget", "HTTP", nullptr));
        _httptype_comb->setItemText(0, QCoreApplication::translate("AddTaskWidget", "GET", nullptr));
        _httptype_comb->setItemText(1, QCoreApplication::translate("AddTaskWidget", "POST", nullptr));
        _httptype_comb->setItemText(2, QCoreApplication::translate("AddTaskWidget", "PUT", nullptr));
        _httptype_comb->setItemText(3, QCoreApplication::translate("AddTaskWidget", "DELETE", nullptr));
        _httptype_comb->setItemText(4, QCoreApplication::translate("AddTaskWidget", "HEAD", nullptr));

        label_6->setText(QCoreApplication::translate("AddTaskWidget", "Type", nullptr));
        _type_comb->setItemText(0, QCoreApplication::translate("AddTaskWidget", "ONCE", nullptr));
        _type_comb->setItemText(1, QCoreApplication::translate("AddTaskWidget", "LOOP", nullptr));
        _type_comb->setItemText(2, QCoreApplication::translate("AddTaskWidget", "TIME", nullptr));

        _proxy_check->setText(QCoreApplication::translate("AddTaskWidget", "\344\273\243\347\220\206", nullptr));
        _add_button->setText(QCoreApplication::translate("AddTaskWidget", "\346\267\273\345\212\240", nullptr));
        _cancel_button->setText(QCoreApplication::translate("AddTaskWidget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTaskWidget: public Ui_AddTaskWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTASK_H
