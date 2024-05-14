/********************************************************************************
** Form generated from reading UI file 'tasklistitem.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKLISTITEM_H
#define UI_TASKLISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskListItem
{
public:
    QGridLayout *gridLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *_name_label;
    QProgressBar *_progressBar;
    QLabel *_info_label;

    void setupUi(QWidget *TaskListItem)
    {
        if (TaskListItem->objectName().isEmpty())
            TaskListItem->setObjectName("TaskListItem");
        TaskListItem->resize(482, 208);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TaskListItem->sizePolicy().hasHeightForWidth());
        TaskListItem->setSizePolicy(sizePolicy);
        TaskListItem->setMaximumSize(QSize(16777215, 16777215));
        TaskListItem->setStyleSheet(QString::fromUtf8("border-radius:15px"));
        gridLayout = new QGridLayout(TaskListItem);
        gridLayout->setObjectName("gridLayout");
        frame = new QFrame(TaskListItem);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        _name_label = new QLabel(frame);
        _name_label->setObjectName("_name_label");
        sizePolicy1.setHeightForWidth(_name_label->sizePolicy().hasHeightForWidth());
        _name_label->setSizePolicy(sizePolicy1);
        _name_label->setMouseTracking(false);
        _name_label->setFocusPolicy(Qt::NoFocus);
        _name_label->setFrameShape(QFrame::NoFrame);
        _name_label->setFrameShadow(QFrame::Plain);

        verticalLayout->addWidget(_name_label);

        _progressBar = new QProgressBar(frame);
        _progressBar->setObjectName("_progressBar");
        _progressBar->setMaximum(100);
        _progressBar->setValue(0);
        _progressBar->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(_progressBar);

        _info_label = new QLabel(frame);
        _info_label->setObjectName("_info_label");
        _info_label->setEnabled(true);
        sizePolicy1.setHeightForWidth(_info_label->sizePolicy().hasHeightForWidth());
        _info_label->setSizePolicy(sizePolicy1);
        _info_label->setFrameShape(QFrame::NoFrame);

        verticalLayout->addWidget(_info_label);


        gridLayout->addWidget(frame, 0, 0, 1, 1);


        retranslateUi(TaskListItem);

        QMetaObject::connectSlotsByName(TaskListItem);
    } // setupUi

    void retranslateUi(QWidget *TaskListItem)
    {
        TaskListItem->setWindowTitle(QString());
        _name_label->setText(QCoreApplication::translate("TaskListItem", "TextLabel", nullptr));
        _progressBar->setFormat(QCoreApplication::translate("TaskListItem", "%v/%m", nullptr));
        _info_label->setText(QCoreApplication::translate("TaskListItem", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskListItem: public Ui_TaskListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKLISTITEM_H
