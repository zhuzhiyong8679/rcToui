#pragma once
#include "mainwindow.h"
#include "QFile"
#include <QTextStream>
#include <QDebug>
#include "QTextDocument" 
#include "QMessageBox"
#include "QProcess"
void MainWindow::ExportUItoFile(QString&mfilename,QString &str)
{
    // 文件名
    QString fileName = mfilename + QString(".ui");

    // 创建并打开文件
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for writing:" << file.errorString();
        return ;
    }

    // 创建文本流
    QTextStream out(&file);
    out.setCodec("UTF-8");
    // 写入内容
    out << str << endl;
    
    // 关闭文件
    file.close();
    QString uiFile = fileName;
    QString hFile = QString("ui_")+mfilename+QString(".h");

    QProcess process;
    QStringList arguments;
    arguments << uiFile << "-o" << hFile;

    process.start("uic", arguments);

    if (!process.waitForFinished()) {
        QMessageBox qb;
        qb.warning(this, "Error", process.errorString());
        //qDebug() << "Error: " << process.errorString();
    }
    else {
        QMessageBox qb;
        qb.information(this, "Generated", hFile);
        qDebug() << "Generated " << hFile << " from " << uiFile;
    }
    
}

QString MainWindow::Start_the_assembly(QString type, QString Id, QString text, QString x, QString y, QString width, QString height)
{
    
    QString str=R"(<widget class="_type" name="_id">
   <property name="geometry">
    <rect>
     <x>_x</x>
     <y>_y</y>
     <width>_width</width>
     <height>_height</height>
    </rect>
   </property>
   <property name="text">
    <string>_contentText</string>
   </property>
  </widget>)";
    QString newtype;
    if(mfcToQtUiMessage.contains(type))
    {
        newtype = mfcToQtUiMessage.find(type).value();
    }
    else
    {
        QMessageBox qb;
        qb.information(this, tr("不存在的类型"), type);
        newtype = "QLable";
    }
    str.replace("_type", newtype)
        .replace("_id", Id)
        .replace("_x", x)
        .replace("_y", y)
        .replace("_width", width)
        .replace("_height", height)
        .replace("_contentText", text);

    return str;
}

QString MainWindow::setHeadfilestrQWidget(DialogMes&dialogmessage)
{
    QString str = 
        R"(<?xml version="1.0" encoding="UTF-8"?>
<ui version = "4.0" >
<class>QWidget</class>
<widget class = " QWidget" name = "MainWindow_name">"
<property name="geometry">
<rect>
<x>dialog_x</x>
<y>dialog_y</y>
 <width>dialog_width</width>
<height>dialog_height</height>
</rect>
</property>
<property name="font">
<font>
<family>Adobe 宋体 Std L</family>
<pointsize>9</pointsize>
</font>
</property>
<property name="windowTitle">
<string>_titleName</string>
</property>)";
    str.replace("MainWindow_name", dialogmessage.id).
        replace("dialog_x", dialogmessage.x)
        .replace("dialog_y", dialogmessage.y)
        .replace("dialog_width", dialogmessage.width)
        .replace("dialog_height", dialogmessage.heigth)  
        .replace("_titleName", dialogmessage.text);
    return str;
}

QString MainWindow::setHeadfilestrQDialog(DialogMes& dialogmessage)
{
    QString str =
        R"(<?xml version="1.0" encoding="UTF-8"?>
<ui version = "4.0" >
<class>QDialog</class>
<widget class = " QDialog" name = "MainWindow_name">"
<property name="geometry">
<rect>
<x>dialog_x</x>
<y>dialog_y</y>
 <width>dialog_width</width>
<height>dialog_height</height>
</rect>
</property>
<property name="font">
<font>
<family>Adobe 宋体 Std L</family>
<pointsize>9</pointsize>
</font>
</property>
<property name="windowTitle">
<string>_titleName</string>
</property>)";
    str.replace("MainWindow_name", dialogmessage.id).
        replace("dialog_x", dialogmessage.x)
        .replace("dialog_y", dialogmessage.y)
        .replace("dialog_width", dialogmessage.width)
        .replace("dialog_height", dialogmessage.heigth)
        .replace("_titleName", dialogmessage.text);
    return str;

}

QString MainWindow::setEndfilestr()
{
    QString str =
        R"(</widget>
<resources/>
<connections/>
</ui>)";
    
    return str;
}
