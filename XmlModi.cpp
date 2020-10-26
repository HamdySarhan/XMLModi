#include "XmlModi.h"
#include <qpushbutton.h>
XmlModi::XmlModi(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.pbWrite, &QPushButton::clicked, this, &XmlModi::fWrite);
    connect(ui.pbRead, &QPushButton::clicked, this, &XmlModi::fRead);
    connect(ui.pbReplace, &QPushButton::clicked, this, &XmlModi::replace);

}

void XmlModi::fWrite() {

    /*QFile data("C:/Users/H.Sarhan/Documents/Hamdy/XmlProjekt/AddiThink.txt");
    data.open(QIODevice::Text | QIODevice::ReadOnly);
    QString dataText = data.readAll();
    QRegularExpression re("axisssss");
    QString replacementText("axis");

    dataText.replace(re, replacementText);

    QFile newData("C:/Users/H.Sarhan/Documents/Hamdy/XmlProjekt/AddiThink.txt");
    if (newData.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&newData);
        out << dataText;
    }
    newData.close();*/

    QFile file("AddiThink.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::critical(this, "Erorr", "Can't open this file!");
    }
    QTextStream out(&file);
    QString text = ui.plainTextEdit->toPlainText();
    out << text;

    //file.flush();
    file.close();



}
/*void XmlModi::readText() {
    QLineEdit fir;
    

      


}*/

/*static QString loadTextFile()
{
    QFile inputFile("C:/Users/H.Sarhan/Documents/Hamdy/XmlProjekt/AddiThink.txt");
    inputFile.open(QIODevice::ReadOnly);
    QTextStream in(&inputFile);
    in.setCodec("UTF-8");
    return in.readAll();
}*/

void XmlModi::fRead(){

    QFile file("AddiThink.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::critical(this, "Erorr", "Can't open this file!");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui.plainTextEdit->setPlainText(text);
    
    file.close();



}
void XmlModi::replace() {
    QString id;
    QString para ;
    id = ui.readA->text();
    para = ui.readP->text();
    QFile data("AddiThink.txt");
    data.open(QIODevice::Text | QIODevice::ReadOnly);
    QString dataText = data.readAll();
    if(dataText.contains( id , Qt::CaseInsensitive)){
        if (dataText.contains(para, Qt::CaseInsensitive)) {
           
            QRegularExpression re(para);
            QString replacementText(para+ui.readV->text());
            dataText.replace(re, replacementText);
            QMessageBox::information(this, "Info", "Replaced successfully");

        }

    }
        
    
    

    

    QFile newData("test.txt");
    if (newData.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&newData);
        out << dataText;
    }
    newData.close();



}