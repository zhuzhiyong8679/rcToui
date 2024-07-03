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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QGridLayout *gridLayout;
    QPushButton *selectAndHightPB;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *_filepath;
    QPushButton *pushButton_compile;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QPushButton *pushButton_clearTextedit;
    QPushButton *pushButtonConvert;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_clearTablewidget;
    QComboBox *comboBox;
    QPushButton *pushButton_exportSingleUI;
    QPushButton *pushButton_insertCurrent;
    QPushButton *pushButton_deleteCurrent;
    QPushButton *pushButton_check;
    QPushButton *pushButton_export;
    QHBoxLayout *horizontalLayout_3;
    QTextEdit *textEditshow;
    QTextEdit *textEditRcKeyContent;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1658, 447);
        MainWindow->setMinimumSize(QSize(0, 0));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        selectAndHightPB = new QPushButton(centralwidget);
        selectAndHightPB->setObjectName(QString::fromUtf8("selectAndHightPB"));

        gridLayout->addWidget(selectAndHightPB, 0, 6, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 5, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 3, 1, 1);

        _filepath = new QLabel(centralwidget);
        _filepath->setObjectName(QString::fromUtf8("_filepath"));

        gridLayout->addWidget(_filepath, 0, 2, 1, 1);


        horizontalLayout_4->addLayout(gridLayout);

        pushButton_compile = new QPushButton(centralwidget);
        pushButton_compile->setObjectName(QString::fromUtf8("pushButton_compile"));

        horizontalLayout_4->addWidget(pushButton_compile);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setLayoutDirection(Qt::RightToLeft);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        pushButton_clearTextedit = new QPushButton(centralwidget);
        pushButton_clearTextedit->setObjectName(QString::fromUtf8("pushButton_clearTextedit"));

        horizontalLayout->addWidget(pushButton_clearTextedit);

        pushButtonConvert = new QPushButton(centralwidget);
        pushButtonConvert->setObjectName(QString::fromUtf8("pushButtonConvert"));

        horizontalLayout->addWidget(pushButtonConvert);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_clearTablewidget = new QPushButton(centralwidget);
        pushButton_clearTablewidget->setObjectName(QString::fromUtf8("pushButton_clearTablewidget"));

        horizontalLayout_2->addWidget(pushButton_clearTablewidget);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        pushButton_exportSingleUI = new QPushButton(centralwidget);
        pushButton_exportSingleUI->setObjectName(QString::fromUtf8("pushButton_exportSingleUI"));

        horizontalLayout_2->addWidget(pushButton_exportSingleUI);

        pushButton_insertCurrent = new QPushButton(centralwidget);
        pushButton_insertCurrent->setObjectName(QString::fromUtf8("pushButton_insertCurrent"));

        horizontalLayout_2->addWidget(pushButton_insertCurrent);

        pushButton_deleteCurrent = new QPushButton(centralwidget);
        pushButton_deleteCurrent->setObjectName(QString::fromUtf8("pushButton_deleteCurrent"));

        horizontalLayout_2->addWidget(pushButton_deleteCurrent);

        pushButton_check = new QPushButton(centralwidget);
        pushButton_check->setObjectName(QString::fromUtf8("pushButton_check"));

        horizontalLayout_2->addWidget(pushButton_check);

        pushButton_export = new QPushButton(centralwidget);
        pushButton_export->setObjectName(QString::fromUtf8("pushButton_export"));

        horizontalLayout_2->addWidget(pushButton_export);


        horizontalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        textEditshow = new QTextEdit(centralwidget);
        textEditshow->setObjectName(QString::fromUtf8("textEditshow"));

        horizontalLayout_3->addWidget(textEditshow);

        textEditRcKeyContent = new QTextEdit(centralwidget);
        textEditRcKeyContent->setObjectName(QString::fromUtf8("textEditRcKeyContent"));

        horizontalLayout_3->addWidget(textEditRcKeyContent);

        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
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
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        horizontalLayout_3->addWidget(tableWidget);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "rc\346\226\207\344\273\266\350\275\254ui\346\226\207\344\273\266", nullptr));
        selectAndHightPB->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\224\256\345\255\227:BEGIN;END", nullptr));
        _filepath->setText(QCoreApplication::translate("MainWindow", "NULL", nullptr));
        pushButton_compile->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\345\271\266\347\274\226\350\257\221ui", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\345\244\204", nullptr));
        pushButton_clearTextedit->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\220\206\346\226\207\346\234\254", nullptr));
        pushButtonConvert->setText(QCoreApplication::translate("MainWindow", "\350\257\206\345\210\253rc\350\275\254\344\270\272Qt\346\216\247\344\273\266\345\205\263\351\224\256\345\217\202\346\225\260", nullptr));
        pushButton_clearTablewidget->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\220\206\350\241\250\346\240\274", nullptr));
        pushButton_exportSingleUI->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\207\272\345\215\225\344\270\252UI(\346\262\241\345\206\231)", nullptr));
        pushButton_insertCurrent->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\350\241\214\344\270\213\346\217\222\345\205\245", nullptr));
        pushButton_deleteCurrent->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\345\275\223\345\211\215", nullptr));
        pushButton_check->setText(QCoreApplication::translate("MainWindow", "check", nullptr));
        pushButton_export->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\207\272\346\211\200\346\234\211UI", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\346\226\207\346\234\254", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "width", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "height", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
