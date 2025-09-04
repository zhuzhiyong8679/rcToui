#pragma once

#include <QMainWindow>
#include "QMap"
#include <QString>
#include "QtWidgets"
#include "ui/ui_mainwindow.h"

struct DialogMes
{
public:
    
    QString id=0;
    QString font;
    QString fontsize;
  
    QString x;
    QString y;
    QString width;
    QString heigth;
    QString text;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
void highlightLines( int startLine, int endLine, const QColor& color);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

  

    void on_selectAndHightPB_clicked();

    void on_textEditshow_cursorPositionChanged();
    void on_pushButtonConvert_clicked();
    void exportUIfile();
    void checkContent();
    

    void clearTextedit();
    void clearTableWidget();
    void addTablewidgetItem();
    void deleteTableWidgetItem();
    void compileopenfile();
private:
    void initRcToUi();
    void addInfoToQTableWidget(QString& type, QString& id, QString& textContent, QString& x, QString& y, QString& width, QString& height);
    void SplitContent(QString& str);

    void SpitStrAndExportUiTextEdit(QString str);
    void outToUitextedit(QString& type, QString& id, QString& textContent, QString& x, QString& y, QString& width, QString& height);
    void outDialogMessage(QString& ID, QString& Font, QString& size, QString& _text, QString& x, QString& y, QString& _width, QString& _height);
    void converDialog(QString str);
    
private:
    Ui::MainWindow *ui;
  
    int last_begin=0,last_end=0;
    int current_begin=0,current_end=0;
    QMap<QString,QString> m_RcToUiMap;
    DialogMes current_dialogmessage;
    DialogMes last_dialogmessage;
    void ExportUItoFile(QString& filename,QString&str);
    
    //开始组装最后的qt ui
    QString Start_the_assembly(QString type, QString Id, QString text, QString x, QString y, QString width, QString height);

    QString setHeadfilestrQDialog(DialogMes&current_message);
    QString setHeadfilestrQWidget(DialogMes& current_message);
    QString setEndfilestr();
    QMap<QString, QString>mfcToQtUiMessage;
    QString currentUi;
};

