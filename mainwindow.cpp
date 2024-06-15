#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QDebug"
#include "QTextDocument"
#include "QTextBlock"

struct RCContent
{
public:
    RCContent(QString&_ui,QString&_name,int _x,int _y,int _width,int _height):Ui(_ui),
        name(_name),x(_x),y(_y),width(_width),height(_height){};
    QString Ui;
    QString name;
    int x;
    int y;
    int width;
    int height;
};


void clearHighlightsInRange(QTextEdit* textEdit, int startLine, int endLine) {
    QTextDocument* doc = textEdit->document();
    QTextCursor cursor(doc);

    QTextCharFormat defaultFormat;
    cursor.movePosition(QTextCursor::Start);

    // Move to the start line
    for (int i = 0; i < startLine ; ++i) {
        cursor.movePosition(QTextCursor::Down);
    }

    // Clear highlights from startLine to endLine
    for (int i = startLine; i <= endLine; ++i) {
        QTextBlock block = cursor.block();
        if (block.isValid()) {
            cursor.movePosition(QTextCursor::StartOfBlock);
            cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
            cursor.setCharFormat(defaultFormat);
        }
        cursor.movePosition(QTextCursor::Down);
    }
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // disconnect(ui->textEditshow,&QTextEdit::cursorPositionChanged,this,&MainWindow::on_textEditshow_cursorPositionChanged);
     QFile file("D://SSEdit.rc");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString line;
        QTextStream in(&file);  //用文件构造流
        
        line = in.readAll();//循环读取下行
            //line.contains
       // SplitContent(line);
        ui->textEditshow->append(line);
        
    }
    file.close();
    ui->textEditshow->moveCursor(QTextCursor::Start, QTextCursor::MoveAnchor);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //QFont font = QFont("Times New Roman",15,2);

    //ui->textEditshow->setFont(font);

    QString filepath=QFileDialog::getOpenFileName(this,tr("选择rc文件"),"D:/",tr("rc Files (*.rc)"));
    ui->_filepath->setText(filepath);
    QFile file(filepath);
   // QFile file("D://SSEdit.rc");
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QString line;
        QTextStream in(&file);  //用文件构造流
        line = in.readLine();//读取一行放到字符串里
        qDebug() << line;
        while(!line.isNull())//字符串有内容
        {
            line=in.readLine();//循环读取下行
            ui->textEditshow->append(line);
        }
    }
    file.close();
    ui->textEditshow ->moveCursor(QTextCursor::Start, QTextCursor::MoveAnchor);
}

void MainWindow::on_pushButton_2_clicked()
{


    //找到begin 和 end 并高亮
    if(!ui->textEditshow->toPlainText().isEmpty())
    {
        int m_begin=0,m_end=0;
        if(ui->textEditshow->find(QString("BEGIN"),QTextDocument::FindCaseSensitively))
        {
         QTextCursor tc = ui->textEditshow->textCursor(); //当前光标
         m_begin = tc.blockNumber()+1;
         }


       if( ui->textEditshow->find(QString("END"),QTextDocument::FindCaseSensitively))
       {
        QPalette palette1 = ui->textEditshow->palette();

         QTextCursor tc = ui->textEditshow->textCursor(); //当前光标


         m_end = tc.blockNumber()-1;
         current_begin=m_begin;
         current_end=m_end;


         //clearHighlightsInRange(ui->textEditshow,last_begin,last_end);
         highlightLines(m_begin, m_end, QColor(Qt::yellow));
        }
    }

}

void MainWindow::on_pushButton_execute_clicked()
{
      //current_begin,current_end;
}
void MainWindow::highlightLines(int startLine, int endLine, const QColor& color) {



    last_begin=startLine;
    last_end=endLine;

    QTextDocument* doc = ui->textEditshow->document();
    QTextCursor cursor(doc);

    QTextCharFormat format;
    format.setBackground(color);

    for (int i = startLine; i <= endLine; ++i) {
        QTextBlock block = doc->findBlockByNumber(i); // 行号从0开始
        if (block.isValid()) {
            cursor.setPosition(block.position());
            cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
            cursor.mergeCharFormat(format);
        }
    }
}

void MainWindow::on_selectAndHightPB_clicked()
{
      QTextCursor cursor=ui->textEditshow->textCursor();
      int start = cursor.selectionStart();
      int end = cursor.selectionEnd();

      QTextCursor startCursor = cursor;
      QTextCursor endCursor = cursor;
      startCursor.setPosition(start);
      endCursor.setPosition(end);

      int startLine = startCursor.blockNumber();
      int endLine = endCursor.blockNumber();

      for (int line = startLine; line <= endLine; ++line)
      {
          QTextBlock block = ui->textEditshow->document()->findBlockByNumber(line);

          ui->textEditRcKeyContent->append(block.text());
      }
}

void MainWindow::on_textEditshow_cursorPositionChanged()
{

}

void MainWindow::initRcToUi()
{
    //m_RcToUiMap.insert()
}

void MainWindow::addInfoToQTableWidget()
{

}

void MainWindow::SplitContent(QString&str)
{
    // 将内容按行分割
   
    QStringList lines = str.split('\n', QString::SkipEmptyParts);

    QStringList entries;
    QString currentEntry;

    for (const QString& line : lines) {
        QString trimmedLine = line.trimmed();
        if (!currentEntry.isEmpty() && (
            trimmedLine.startsWith("LISTBOX") || 
            trimmedLine.startsWith("PUSHBUTTON") || 
            trimmedLine.startsWith("EDITTEXT")|| 
            trimmedLine.startsWith("LTEXT")||
            trimmedLine.startsWith("GROUPBOX")||
            trimmedLine.startsWith("DEFPUSHBUTTON") ||
            trimmedLine.startsWith("RTEXT") ||
            trimmedLine.startsWith("COMBOBOX")||
            
            trimmedLine.startsWith("CONTROL"))) {
            entries.append(currentEntry.trimmed());
            currentEntry.clear();
        }
        if (!currentEntry.isEmpty()) {
            currentEntry += ' ';
        }
        currentEntry += trimmedLine;
    }

    if (!currentEntry.isEmpty()) {
        entries.append(currentEntry.trimmed());
    }

    for (const QString& entry : entries) {
        test(entry);
    }

}

void MainWindow::test(QString str)
{
    qDebug() << str << Qt::endl;
   
    //能匹配到Listbox 和editbox
    QRegularExpression re(R"((\w+)\s+(\w+),(\d+),(\d+),(\d+),(\d+),(.+))");
    QRegularExpressionMatchIterator i = re.globalMatch(str);

    while (i.hasNext())
    {
        QRegularExpressionMatch match = i.next();

        // 匹配 LISTBOX
        if (1) {
            QString controlType = match.captured(1);
            QString controlId = match.captured(2);
            int x = match.captured(3).toInt();
            int y = match.captured(4).toInt();
            int width = match.captured(5).toInt();
            int height = match.captured(6).toInt();

            qDebug() << "Control Type:" << controlType
                << ", Control ID:" << controlId
                << ", x:" << x
                << ", y:" << y
                << ", width:" << width
                << ", height:" << height;
            return;
        }
        
    }
   
    QRegularExpression re1(R"((PUSHBUTTON)\s+\"(.*)\",(\w+),(\d+),(\d+),(\d+),(\d+),(.+))");//能查中中文。//同时能找到defbutton
    QRegularExpression re1(R"((PUSHBUTTON)\s+\"(.?)\",(\w+),(\d+),(\d+),(\d+),(\d+),(.+))");//能查中button的空名字或者空的。
    QRegularExpressionMatchIterator i1 = re1.globalMatch(str);
    while (i1.hasNext())
    {
        QRegularExpressionMatch match = i1.next();
        if (match.captured(1) == "PUSHBUTTON") {
            QString controlType = match.captured(1);
            QString controlText = match.captured(2);
            QString controlId = match.captured(3);
            int x = match.captured(4).toInt();
            int y = match.captured(5).toInt();
            int width = match.captured(6).toInt();
            int height = match.captured(7).toInt();

            qDebug() << "Control Type:" << controlType
                << ", Control Text:" << controlText
                << ", Control ID:" << controlId
                << ", x:" << x
                << ", y:" << y
                << ", width:" << width
                << ", height:" << height;
            return;
        }
        
    }
    QRegularExpression re2(R"((CONTROL)\s+"\(.*)\", (\w + ), "\(\w+)\", (.+)(\d+), (\d+), (\d+), (\d+))");

    QRegularExpressionMatchIterator i2 = re2.globalMatch(str);
    while (i2.hasNext())
    {
        QRegularExpressionMatch match = i1.next();
       if (match.captured(1) == "CONTROL") {
            QString controlType = match.captured(1);
            QString controlText = match.captured(2);
            QString controlId = match.captured(3);
            QString subControlType = match.captured(4);
            int x = match.captured(5).toInt();
            int y = match.captured(6).toInt();
            int width = match.captured(7).toInt();
            int height = match.captured(8).toUInt();

            qDebug() << "Control Type:" << controlType
                << ", Control Text:" << controlText
                << ", Control ID:" << controlId
                << ", Sub Control Type:" << subControlType
                << ", x:" << x
                << ", y:" << y
                << ", width:" << width
                << ", height:" << height;
            return;
        }
    }
}

//分割字符串
void MainWindow::on_pushButtonConvert_clicked()
{
    if (ui->textEditRcKeyContent->toPlainText().isEmpty())return;
    QString str = ui->textEditRcKeyContent->toPlainText();
    SplitContent(str);
}

//(\w+)\s+"(.*)",(\w+),(\d+),(\d+),(\d+),(\d+)  能匹配绝大部分