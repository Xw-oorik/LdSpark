/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QPushButton *_stop_btn;
    QComboBox *comboBox;
    QPushButton *_add_btn;
    QPushButton *_remove_btn;
    QPushButton *_export_btn;
    QSpacerItem *verticalSpacer;
    QPushButton *_proxy_btn;
    QPushButton *_clean_btn;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QSplitter *splitter_3;
    QListWidget *_task_list;
    QSplitter *splitter;
    QChartView *_graph_view;
    QTableView *_table_view;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(870, 572);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMaximumSize(QSize(195, 16777209));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setFrameShape(QFrame::StyledPanel);
        label->setFrameShadow(QFrame::Sunken);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        _stop_btn = new QPushButton(groupBox);
        _stop_btn->setObjectName("_stop_btn");

        gridLayout_2->addWidget(_stop_btn, 4, 0, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        comboBox->setMinimumContentsLength(0);

        gridLayout_2->addWidget(comboBox, 2, 0, 1, 1);

        _add_btn = new QPushButton(groupBox);
        _add_btn->setObjectName("_add_btn");

        gridLayout_2->addWidget(_add_btn, 6, 0, 1, 1);

        _remove_btn = new QPushButton(groupBox);
        _remove_btn->setObjectName("_remove_btn");

        gridLayout_2->addWidget(_remove_btn, 7, 0, 1, 1);

        _export_btn = new QPushButton(groupBox);
        _export_btn->setObjectName("_export_btn");

        gridLayout_2->addWidget(_export_btn, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        _proxy_btn = new QPushButton(groupBox);
        _proxy_btn->setObjectName("_proxy_btn");

        gridLayout_2->addWidget(_proxy_btn, 3, 0, 1, 1);

        _clean_btn = new QPushButton(groupBox);
        _clean_btn->setObjectName("_clean_btn");

        gridLayout_2->addWidget(_clean_btn, 8, 0, 1, 1);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName("gridLayout_3");
        splitter_3 = new QSplitter(groupBox_2);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setOrientation(Qt::Horizontal);
        splitter_3->setHandleWidth(3);
        _task_list = new QListWidget(splitter_3);
        _task_list->setObjectName("_task_list");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(_task_list->sizePolicy().hasHeightForWidth());
        _task_list->setSizePolicy(sizePolicy2);
        _task_list->setMinimumSize(QSize(0, 0));
        _task_list->setMaximumSize(QSize(160, 16777215));
        _task_list->setBaseSize(QSize(0, 0));
        splitter_3->addWidget(_task_list);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Vertical);
        splitter->setHandleWidth(3);
        _graph_view = new QChartView(splitter);
        _graph_view->setObjectName("_graph_view");
        sizePolicy2.setHeightForWidth(_graph_view->sizePolicy().hasHeightForWidth());
        _graph_view->setSizePolicy(sizePolicy2);
        _graph_view->setMaximumSize(QSize(16777215, 16777215));
        splitter->addWidget(_graph_view);
        _table_view = new QTableView(splitter);
        _table_view->setObjectName("_table_view");
        splitter->addWidget(_table_view);
        splitter_3->addWidget(splitter);

        gridLayout_3->addWidget(splitter_3, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 870, 33));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; font-style:italic; color:#1c10d6;\">LdSpark</span></p><p align=\"center\"><span style=\" font-weight:700; font-style:italic; color:#1c10d6;\">\345\205\215\350\264\271\344\276\277\346\215\267\347\232\204HTTP\345\216\213\346\265\213\350\275\257\344\273\266</span></p><p align=\"center\"><span style=\" font-weight:700; font-style:italic; color:#9f2e22;\">\346\217\220\344\276\233\346\234\200\345\270\270\347\224\250\347\232\204\347\275\221\347\253\231\345\216\213\346\265\213\346\211\213\346\256\265</span></p><p align=\"center\"><span style=\" font-weight:700; font-style:italic; color:#21431e;\">\344\275\234\350\200\205\344\270\273\351\241\265:</span></p><p align=\"center\"><a href=\"https://www.potba.cn/\"><span style=\" font-weight:700; font-style:italic; text-decoration: underline; color:#094fd1;\">https://www.potba.cn/</span></a></p></body></html>", nullptr));
        _stop_btn->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\344\270\273\351\242\2301", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\344\270\273\351\242\2302", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\344\270\273\351\242\2303", nullptr));

        _add_btn->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        _remove_btn->setText(QCoreApplication::translate("MainWindow", "\347\247\273\351\231\244", nullptr));
        _export_btn->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\207\272", nullptr));
        _proxy_btn->setText(QCoreApplication::translate("MainWindow", "\344\273\243\347\220\206\350\256\276\347\275\256", nullptr));
        _clean_btn->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272", nullptr));
        groupBox_2->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
