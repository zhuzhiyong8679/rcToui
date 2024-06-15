#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMap"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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

    void on_pushButton_execute_clicked();

    void on_selectAndHightPB_clicked();

    void on_textEditshow_cursorPositionChanged();
    void on_pushButtonConvert_clicked();

private:
    void initRcToUi();
    void addInfoToQTableWidget();
    void SplitContent(QString& str);

    void test(QString str);
private:
    Ui::MainWindow *ui;

    int last_begin=0,last_end=0;
    int current_begin=0,current_end=0;
    QMap<QString,QString> m_RcToUiMap;
};
#endif // MAINWINDOW_H
