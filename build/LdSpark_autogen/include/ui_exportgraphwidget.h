/********************************************************************************
** Form generated from reading UI file 'exportgraphwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORTGRAPHWIDGET_H
#define UI_EXPORTGRAPHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExportGraphWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QDateTimeEdit *_start_time;
    QDateTimeEdit *_endtime;
    QLabel *label;
    QComboBox *_task_comb;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *_all_check;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QCheckBox *_requst_ck;
    QCheckBox *_response_ck;
    QCheckBox *_error_ck;
    QCheckBox *_avgresp_ck;
    QCheckBox *_summary_ck;
    QCheckBox *_timeout_ck;
    QHBoxLayout *horizontalLayout;
    QPushButton *_export_btn;

    void setupUi(QWidget *ExportGraphWidget)
    {
        if (ExportGraphWidget->objectName().isEmpty())
            ExportGraphWidget->setObjectName("ExportGraphWidget");
        ExportGraphWidget->resize(402, 342);
        verticalLayout_2 = new QVBoxLayout(ExportGraphWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        _start_time = new QDateTimeEdit(ExportGraphWidget);
        _start_time->setObjectName("_start_time");

        gridLayout->addWidget(_start_time, 1, 1, 1, 1);

        _endtime = new QDateTimeEdit(ExportGraphWidget);
        _endtime->setObjectName("_endtime");

        gridLayout->addWidget(_endtime, 2, 1, 1, 1);

        label = new QLabel(ExportGraphWidget);
        label->setObjectName("label");
        label->setFrameShape(QFrame::Box);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        _task_comb = new QComboBox(ExportGraphWidget);
        _task_comb->setObjectName("_task_comb");

        gridLayout->addWidget(_task_comb, 0, 1, 1, 1);

        label_2 = new QLabel(ExportGraphWidget);
        label_2->setObjectName("label_2");
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(ExportGraphWidget);
        label_3->setObjectName("label_3");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFrameShape(QFrame::Box);
        label_3->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        frame = new QFrame(ExportGraphWidget);
        frame->setObjectName("frame");
        frame->setFocusPolicy(Qt::NoFocus);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        _all_check = new QRadioButton(frame_3);
        _all_check->setObjectName("_all_check");

        horizontalLayout_2->addWidget(_all_check);


        verticalLayout->addWidget(frame_3);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        frame_2->setLayoutDirection(Qt::LeftToRight);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setObjectName("gridLayout_2");
        _requst_ck = new QCheckBox(frame_2);
        _requst_ck->setObjectName("_requst_ck");

        gridLayout_2->addWidget(_requst_ck, 0, 0, 1, 1);

        _response_ck = new QCheckBox(frame_2);
        _response_ck->setObjectName("_response_ck");

        gridLayout_2->addWidget(_response_ck, 0, 1, 1, 1);

        _error_ck = new QCheckBox(frame_2);
        _error_ck->setObjectName("_error_ck");

        gridLayout_2->addWidget(_error_ck, 1, 0, 1, 1);

        _avgresp_ck = new QCheckBox(frame_2);
        _avgresp_ck->setObjectName("_avgresp_ck");

        gridLayout_2->addWidget(_avgresp_ck, 3, 0, 1, 1);

        _summary_ck = new QCheckBox(frame_2);
        _summary_ck->setObjectName("_summary_ck");

        gridLayout_2->addWidget(_summary_ck, 3, 1, 1, 1);

        _timeout_ck = new QCheckBox(frame_2);
        _timeout_ck->setObjectName("_timeout_ck");

        gridLayout_2->addWidget(_timeout_ck, 1, 1, 1, 1);


        verticalLayout->addWidget(frame_2);


        verticalLayout_2->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        _export_btn = new QPushButton(ExportGraphWidget);
        _export_btn->setObjectName("_export_btn");

        horizontalLayout->addWidget(_export_btn);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(ExportGraphWidget);

        QMetaObject::connectSlotsByName(ExportGraphWidget);
    } // setupUi

    void retranslateUi(QWidget *ExportGraphWidget)
    {
        ExportGraphWidget->setWindowTitle(QCoreApplication::translate("ExportGraphWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("ExportGraphWidget", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        label_2->setText(QCoreApplication::translate("ExportGraphWidget", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("ExportGraphWidget", "\344\273\273\345\212\241\345\220\215\347\247\260", nullptr));
        _all_check->setText(QCoreApplication::translate("ExportGraphWidget", "\345\205\250\351\200\211", nullptr));
        _requst_ck->setText(QCoreApplication::translate("ExportGraphWidget", "\350\257\267\346\261\202\346\225\260", nullptr));
        _response_ck->setText(QCoreApplication::translate("ExportGraphWidget", "\345\223\215\345\272\224\346\225\260", nullptr));
        _error_ck->setText(QCoreApplication::translate("ExportGraphWidget", "\350\266\205\346\227\266\346\225\260", nullptr));
        _avgresp_ck->setText(QCoreApplication::translate("ExportGraphWidget", " \345\271\263\345\235\207\345\223\215\345\272\224", nullptr));
        _summary_ck->setText(QCoreApplication::translate("ExportGraphWidget", "\346\261\207\346\200\273", nullptr));
        _timeout_ck->setText(QCoreApplication::translate("ExportGraphWidget", "\351\224\231\350\257\257\346\225\260", nullptr));
        _export_btn->setText(QCoreApplication::translate("ExportGraphWidget", "\345\257\274\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExportGraphWidget: public Ui_ExportGraphWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORTGRAPHWIDGET_H
