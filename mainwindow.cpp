#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QDebug"
#include "QTextDocument"
#include "QTextBlock"
#include <QRegularExpressionMatchIterator>
#include "QMessageBox"
#include <QProcess>
#include <QFileInfo>
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
    mfcToQtUiMessage["LTEXT"] = QString("QLabel");
    mfcToQtUiMessage["RTEXT"] = QString("QLabel");//CTEXT
    mfcToQtUiMessage["CTEXT"] = QString("QLabel");
    mfcToQtUiMessage["Button"] = QString("QPushButton");
    mfcToQtUiMessage["PUSHBUTTON"] = QString("QPushButton");
    mfcToQtUiMessage["DEFPUSHBUTTON"] = QString("QPushButton");//EDITTEXT
    mfcToQtUiMessage["EDITTEXT"] = QString("QTextEdit");//COMBOBOX
    mfcToQtUiMessage["COMBOBOX"] = QString("QComboBox");
    mfcToQtUiMessage["LISTBOX"] = QString("QListWidget");
    mfcToQtUiMessage["GROUPBOX"] = QString("QGroupBox");
    mfcToQtUiMessage["SysListView32"] = QString("QTableWidget");
    mfcToQtUiMessage["Static"] = QString("QLabel");
    //
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
    connect(ui->pushButton_export, &QPushButton::clicked, this, &MainWindow::exportUIfile);
    connect(ui->pushButton_check, &QPushButton::clicked, this, &MainWindow::checkContent);
    connect(ui->pushButton_clearTablewidget, &QPushButton::clicked, this, &MainWindow::clearTableWidget);
    connect(ui->pushButton_clearTextedit, &QPushButton::clicked, this, &MainWindow::clearTextedit);
    connect(ui->pushButton_insertCurrent,  &QPushButton::clicked, this, &MainWindow::addTablewidgetItem);
    connect(ui->pushButton_deleteCurrent, &QPushButton::clicked, this, &MainWindow::deleteTableWidgetItem);
    connect(ui->pushButton_compile, &QPushButton::clicked, this, &MainWindow::compileopenfile);
   // connect(ui->checkBox, &QCheckBox::stateChanged, this, &MainWindow::test);
    ui->comboBox->addItem(QString("QDialog"));
    ui->comboBox->addItem(QString("QWidget"));
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

void MainWindow::addInfoToQTableWidget(QString& type, QString& id, QString& textContent, QString& x, QString& y, QString& width, QString& height)
{
        int row_count = ui->tableWidget->rowCount();

      
     
        ui->tableWidget->insertRow(row_count);
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(type);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, item);

        QTableWidgetItem* item1 = new QTableWidgetItem();
        item1->setText(id);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, item1);

        QTableWidgetItem* item2 = new QTableWidgetItem();
        item2->setText(textContent);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, item2);

        QTableWidgetItem* item3 = new QTableWidgetItem();
        item3->setText(x);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 3, item3);
    

        QTableWidgetItem* item4 = new QTableWidgetItem();
        item4->setText(y);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 4, item4);
        QTableWidgetItem* item5 = new QTableWidgetItem();
        item5->setText(width);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 5, item5);
        QTableWidgetItem* item6 = new QTableWidgetItem();
        item6->setText(height);
        ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 6, item6);
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
            trimmedLine.startsWith("IDD")||
            trimmedLine.startsWith("CONTROL"))) 
        {
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
        if (entry.startsWith("IDD"))
        {
            converDialog(entry);
        }
        else
        {
            SpitStrAndExportUiTextEdit(entry);
        }
      
    }

}

void MainWindow::SpitStrAndExportUiTextEdit(QString str)
{
    //qDebug() << str << Qt::endl;
    str.replace("\n", "").replace("\r", "");
    //正确
    //能匹配到Listbox 和editbox combobox




    QRegularExpression re(R"((\w+)\s+(\w+),(\d+),(\d+),(\d+),(\d+),(.+))");
    QRegularExpressionMatchIterator i = re.globalMatch(str);

    while (i.hasNext())
    {
        QRegularExpressionMatch match = i.next();

        // 匹配 LISTBOX
        if (1) {
            QString controlType = match.captured(1);
            QString controlId = match.captured(2);
            QString x = match.captured(3);
            QString y = match.captured(4);
            QString width = match.captured(5);
            QString height = match.captured(6);
            QString str = "ISNULL";
            outToUitextedit(controlType, controlId, str, x, y, width, height);
      
            return;
        }
        
    }
   
    QRegularExpression re1(R"((PUSHBUTTON)\s+\"(.*)\",(\w+),(\d+),(\d+),(\d+),(\d+),(.+))");//能查中中文。//同时能找到defbutton
   
    QRegularExpressionMatchIterator i1 = re1.globalMatch(str);
    while (i1.hasNext())
    {
        QRegularExpressionMatch match = i1.next();
        if (match.captured(1) == "PUSHBUTTON") {
            QString controlType = match.captured(1);
            QString controlText = match.captured(2);
            QString controlId = match.captured(3);
            QString x = match.captured(4);
            QString y = match.captured(5);
            QString width = match.captured(6);
            QString height = match.captured(7);
            outToUitextedit(controlType, controlId, controlText, x, y, width, height);
        
            return;
        }
        
    }
    QRegularExpression re2(R"((CONTROL)\s+\"(.*)\",(\w+),\"(\w+)\",(.+),(\d+),(\d+),(\d+),(\d+))");
    QRegularExpressionMatchIterator i2 = re2.globalMatch(str);
    while (i2.hasNext())
    {
        QRegularExpressionMatch match = i2.next();
       if (match.captured(1) == "CONTROL") {
            QString controlType = match.captured(1);
            QString controlText = match.captured(2);
            QString controlId = match.captured(3);
            QString subControlType = match.captured(4);
            QString x = match.captured(6);
            QString y = match.captured(7);
            QString width = match.captured(8);
            QString height = match.captured(9);
            outToUitextedit(subControlType, controlId, controlText, x, y, width, height);
        
            return;
        }
    }
    QRegularExpression re3(R"((PUSHBUTTON)\s+\"(.?)\",(\w+),(\d+),(\d+),(\d+),(\d+),(.+))");//能查中button的空名字或者空的。
    QRegularExpressionMatchIterator i3 = re3.globalMatch(str);
    while (i3.hasNext())
    {
        QRegularExpressionMatch match = i3.next();
        if (match.captured(1) == "PUSHBUTTON") {
            QString controlType = match.captured(1);
            QString controlText = match.captured(2);
            QString controlId = match.captured(3);
            QString subControlType = match.captured(4);
            QString x = match.captured(5);
            QString y = match.captured(6);
            QString width = match.captured(7);
            QString height = match.captured(8);
            outToUitextedit(subControlType, controlId, controlText, x, y, width, height);
    
            return;
        }
    }
    QRegularExpression re4(R"((GROUPBOX)\s + \"(.*)\", (\w+), (\d+), (\d+), (\d+), (\d+), (.+))");//能查中button的空名字或者空的。
    QRegularExpressionMatchIterator i4 = re4.globalMatch(str);
    while (i4.hasNext())
    {
        QRegularExpressionMatch match = i4.next();
        if (match.captured(1) == "GROUPBOX") {
            QString controlType = match.captured(1);
            QString controlText = match.captured(2);
            QString controlId = match.captured(3);
            QString subControlType = match.captured(4);
            QString x = match.captured(5);
            QString y = match.captured(6);
            QString width = match.captured(7);
            QString height = match.captured(8);
            outToUitextedit(subControlType, controlId, controlText, x, y, width, height);
         
            return;
        }
    }
    QRegularExpression re5(R"((\w+)\s+\"(.*)\",(.*),(\d+),(\d+),(\d+),(\d+))");//Ltext Pushbutton Rtext
    QRegularExpressionMatchIterator i5 = re5.globalMatch(str);
    while (i5.hasNext())
    {
        QRegularExpressionMatch match = i5.next();
        if (match.captured(1)=="LTEXT"|| match.captured(1) == "RTEXT"|| match.captured(1) == "PUSHBUTTON"|| match.captured(1) == "DEFPUSHBUTTON") {
            QString controlType = match.captured(1);
            QString controlText = match.captured(2);
            QString controlId = match.captured(3);
            //QString subControlType = match.captured(4);
            QString x = match.captured(4);
            QString y = match.captured(5);
            QString width = match.captured(6);
            QString height = match.captured(7);
            outToUitextedit(controlType, controlId, controlText, x, y, width, height);
          
            return;
        }
    }
    ///LRText RText 和某些特殊的pushbutton//已经验证
    QRegularExpression re6(R"((\w+)\s+\"(.*)\",(\w+),(\d+),(\d+),(\d+),(\d+))");//Ltext Pushbutton Rtext
    QRegularExpressionMatchIterator i6 = re6.globalMatch(str);
    while (i6.hasNext())
    {
        QRegularExpressionMatch match = i6.next();
        if (1) {
            QString controlType = match.captured(1);
            QString controlText = match.captured(2);
            if (controlText.isEmpty())
            {
                controlText = QString("ISNULL");
            }
            QString controlId = match.captured(3);
            
            QString x = match.captured(4);
            QString y = match.captured(5);
            QString width = match.captured(6);
            QString height = match.captured(7);
            outToUitextedit(controlType, controlId, controlText, x, y, width, height);
          
            return;
        }
    }
    //(CONTROL)\s+"(.*)",(\w+),"(\w+)",(.+),(\d+),(\d),\n\s+(\d+),(\d+)
    QRegularExpression re7(R"((CONTROL)\s+\"(.*)\",(\w+),\"(\w+)\",(.+),(\d+),(\d),\s+(\d+),(\d+))");//Ltext Pushbutton Rtext
    QRegularExpressionMatchIterator i7 = re7.globalMatch(str);
    while (i7.hasNext())
    {
        QRegularExpressionMatch match = i7.next();
        if (match.captured(1)=="CONTROL") {
            QString controlType = match.captured(4);
            QString controlText = match.captured(2);
            if (controlText.isEmpty())
            {
                controlText = QString("ISNULL");
            }
            QString controlId = match.captured(3);

            QString x = match.captured(6);
            QString y = match.captured(7);
            QString width = match.captured(8);
            QString height = match.captured(9);
            outToUitextedit(controlType, controlId, controlText, x, y, width, height);

            return;
        }
    }
    return;
}

void MainWindow::outToUitextedit(QString& type, QString& id, QString& textContent, QString& x, QString& y, QString& _width, QString& _height)
{
    addInfoToQTableWidget(type, id, textContent, x, y, _width, _height);
}

void MainWindow::outDialogMessage(QString& ID, QString& Font, QString& size, QString& _text, QString& x, QString& y, QString& _width, QString& _height)
{
    QString dialogType = "DIALOG";
    addInfoToQTableWidget(dialogType, ID, _text, x, y, _width, _height);

}

void MainWindow::converDialog(QString str)
{
    
    //不带文本
    QRegularExpression re6(R"((.*)\s(DIALOG)\s(\w+)\s+(\d+),\s(\d+),\s(\d+),\s(\d+))");//Ltext Pushbutton Rtext
    QRegularExpressionMatchIterator i6 = re6.globalMatch(str);
    while (i6.hasNext())
    {
        QRegularExpressionMatch match = i6.next();
        if (1) {
            QString DialogID = match.captured(1);
           
            QString subControlType = match.captured(2);

            QString x = match.captured(4);
            QString y = match.captured(5);
            QString width = match.captured(6);
            QString height = match.captured(7);
            
           

            // 定义正则表达式匹配 FONT 关键字后面的内容
            QRegularExpression fontRegex(R"(FONT\s+(\d+),\s*\"([^\"]+)\")");
            QRegularExpressionMatch match = fontRegex.match(str);
            QString fontSize=9;
            QString fontName;
            if (match.hasMatch()) {
                 fontSize = match.captured(1);
                 fontName = match.captured(2);

                qDebug() << "Font Size:" << fontSize;
                qDebug() << "Font Name:" << fontName;
            }


            QString controlText = "ISNULL";
            QRegularExpression captionRegex1(R"(CAPTION\s+\"([^\"]+)\")");
            QRegularExpressionMatch match1 = captionRegex1.match(str);

            if (match1.hasMatch()) {
                controlText = match1.captured(1);

                qDebug() << "Caption Text:" << controlText;
            }
            else {
                
            }
            outDialogMessage(DialogID, fontName, fontSize, controlText, x, y, width, height);
            //ui->comboBox->addItem(DialogID);
            return;
        }
    }
    QRegularExpression re7(R"((IDD\w+)\s+(DIALOG|DIALOGEX)\s+(\d+),\s+(\d+),\s+(\d+),\s+(\d+))");
    QRegularExpressionMatchIterator i7 = re7.globalMatch(str);
    while (i7.hasNext())
    {
        QRegularExpressionMatch match = i7.next();
        if (1) {
            QString DialogID = match.captured(1);

            QString subControlType = match.captured(2);

            QString x = match.captured(3);
            QString y = match.captured(4);
            QString width = match.captured(5);
            QString height = match.captured(6);


            QString fontName;
            QString fontSize;
            QString controlText="ISNULL";
            outDialogMessage(DialogID, fontName, fontSize, controlText, x, y, width, height);
           // ui->comboBox->addItem(DialogID);
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
//输出文件
void MainWindow::exportUIfile()
{
    int rowCount = ui->tableWidget->rowCount();
    if (rowCount ==1)return;
    // 遍历每个文本块（行）
    /*doc->lineCount();
    doc.lin*/
    for (int i = 0; i < rowCount; ++i)
    {
        QString type=ui->tableWidget->item(i, 0)->text();
        if (type == "DIALOG")
        {
            current_dialogmessage.id = ui->tableWidget->item(i, 1)->text();
           // current_dialogmessage.font = strlist.at(2);
            //current_dialogmessage.fontsize = strlist.at(3);
            current_dialogmessage.text = ui->tableWidget->item(i, 2)->text();
            current_dialogmessage.x = ui->tableWidget->item(i, 3)->text();
            current_dialogmessage.y = ui->tableWidget->item(i, 4)->text();
            current_dialogmessage.width = ui->tableWidget->item(i, 5)->text();
            current_dialogmessage.heigth = ui->tableWidget->item(i, 6)->text();
            if (ui->comboBox->currentText() == QString("QDialog"))
            {

                if (current_dialogmessage.id != last_dialogmessage.id && last_dialogmessage.id != 0)
                {
                    QString all = setHeadfilestrQDialog(last_dialogmessage) + currentUi + setEndfilestr();
                    ExportUItoFile(last_dialogmessage.id, all);
                    currentUi.clear();
                }

            }
            else {
                if (current_dialogmessage.id != last_dialogmessage.id && last_dialogmessage.id != 0)
                {
                    QString all = setHeadfilestrQWidget(last_dialogmessage) + currentUi + setEndfilestr();
                    ExportUItoFile(last_dialogmessage.id, all);
                    currentUi.clear();
                }
            }
            last_dialogmessage = current_dialogmessage;
        }
        else
        {
            currentUi += Start_the_assembly(ui->tableWidget->item(i, 0)->text(), ui->tableWidget->item(i, 1)->text(), ui->tableWidget->item(i, 2)->text()
                , ui->tableWidget->item(i, 3)->text(), ui->tableWidget->item(i, 4)->text(),
                ui->tableWidget->item(i, 5)->text(), ui->tableWidget->item(i, 6)->text());
            if (ui->comboBox->currentText() == QString("QDialog"))
            {
                if (i == rowCount - 1)
                {
                    QString all = setHeadfilestrQDialog(current_dialogmessage) + currentUi + setEndfilestr();
                    //if (current_dialogmessage.id == 0)return;
                    ExportUItoFile(current_dialogmessage.id, all);
                    currentUi.clear();
                }
            }
            else
            {
                if (i == rowCount - 1)
                {
                    QString all = setHeadfilestrQWidget(current_dialogmessage) + currentUi + setEndfilestr();
                    //if (current_dialogmessage.id == 0)return;
                    ExportUItoFile(current_dialogmessage.id, all);
                    currentUi.clear();
                }
            }
        }
    }
   /* QMessageBox qb;
    qb.information(this, tr("提示"), tr("输出成功"));*/
    
}

void MainWindow::checkContent()
{
    int rowCount = ui->tableWidget->rowCount();
    for (int i = 1; i < rowCount; ++i)
    {
        bool ok=true;
       ui->tableWidget->item(i, 3)->text().toInt(&ok);
       ui->tableWidget->item(i, 4)->text().toInt(&ok);
       ui->tableWidget->item(i, 5)->text().toInt(&ok);
       ui->tableWidget->item(i, 6)->text().toInt(&ok);
       if (!ok)
       {
           QString str = QString::number(i) + QString(" row is error ");
           QMessageBox qb;
           qb.warning(this, "error", str);
           return;
       }
    }
    QMessageBox qb;
    qb.information(this, "suc", "no error");
}

void MainWindow::clearTextedit()
{
    ui->textEditRcKeyContent->clear();
}

void MainWindow::clearTableWidget()
{

    int rowNum = ui->tableWidget->rowCount();
    for (int i = 0; i < rowNum; i++)//清空列表
    {
        ui->tableWidget->removeRow(0);
    }
}

void MainWindow::addTablewidgetItem()
{
    int currentrow=ui->tableWidget->currentRow();
    ui->tableWidget->insertRow(currentrow+1);
    for (int i = 0; i < 5; i++)
    {
        QTableWidgetItem* item = new QTableWidgetItem();
        ui->tableWidget->setItem(currentrow + 1, i, item);

    }
}

void MainWindow::deleteTableWidgetItem()
{
    int currentRow=ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(currentRow);
}

void MainWindow::compileopenfile()
{
    QString filepath = QFileDialog::getOpenFileName(this, tr("选择ui文件"), "", tr("ui Files (*.ui)"));
    if (filepath.isEmpty())return;
    QFile file(filepath);
    QFileInfo fileInfo(filepath);
    QString filename_without_suffix = fileInfo.baseName();
    QString uiFile = filepath;

    QString hFile = QString("ui_") + filename_without_suffix + QString(".h");

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
        qb.information(this, "Generated", tr("与程序相同目录下") + uiFile);
        qDebug() << "Generated " << hFile << " from " << uiFile;
    }


}

