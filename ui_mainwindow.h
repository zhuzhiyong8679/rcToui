/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTextEdit *textEditshow;
    QTextEdit *textEditRcKeyContent;
    QGridLayout *gridLayout;
    QLabel *_filepath;
    QPushButton *pushButton_2;
    QPushButton *pushButton_execute;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *selectAndHightPB;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QPushButton *pushButtonConvert;
    QLabel *label_3;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1920, 1082);
        MainWindow->setMinimumSize(QSize(1920, 1082));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textEditshow = new QTextEdit(centralwidget);
        textEditshow->setObjectName(QString::fromUtf8("textEditshow"));

        gridLayout_2->addWidget(textEditshow, 1, 0, 1, 1);

        textEditRcKeyContent = new QTextEdit(centralwidget);
        textEditRcKeyContent->setObjectName(QString::fromUtf8("textEditRcKeyContent"));

        gridLayout_2->addWidget(textEditRcKeyContent, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        _filepath = new QLabel(centralwidget);
        _filepath->setObjectName(QString::fromUtf8("_filepath"));

        gridLayout->addWidget(_filepath, 0, 2, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 5, 1, 1);

        pushButton_execute = new QPushButton(centralwidget);
        pushButton_execute->setObjectName(QString::fromUtf8("pushButton_execute"));

        gridLayout->addWidget(pushButton_execute, 0, 7, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 3, 1, 1);

        selectAndHightPB = new QPushButton(centralwidget);
        selectAndHightPB->setObjectName(QString::fromUtf8("selectAndHightPB"));

        gridLayout->addWidget(selectAndHightPB, 0, 6, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setLayoutDirection(Qt::RightToLeft);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        pushButtonConvert = new QPushButton(centralwidget);
        pushButtonConvert->setObjectName(QString::fromUtf8("pushButtonConvert"));

        horizontalLayout->addWidget(pushButtonConvert);


        gridLayout_2->addLayout(horizontalLayout, 0, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout_2->addWidget(tableWidget, 1, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        _filepath->setText(QCoreApplication::translate("MainWindow", "NULL", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "find", nullptr));
        pushButton_execute->setText(QCoreApplication::translate("MainWindow", "execute", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "openfile", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "KeyWord:BEGIN;END", nullptr));
        selectAndHightPB->setText(QCoreApplication::translate("MainWindow", "select And hight", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\345\244\204", nullptr));
        pushButtonConvert->setText(QCoreApplication::translate("MainWindow", "\350\257\206\345\210\253rc\350\275\254\344\270\272Qt\346\216\247\344\273\266\345\205\263\351\224\256\345\217\202\346\225\260", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\350\275\254\346\215\242\344\270\272UI", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "UI\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "UI\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "width", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "height", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
