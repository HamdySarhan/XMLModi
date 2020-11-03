#include "XmlModi.h"
#include <qpushbutton.h>
XmlModi::XmlModi(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
   // connect(ui.pbWrite, &QPushButton::clicked, this, &XmlModi::fWrite);
    connect(ui.pbRead, &QPushButton::clicked, this, &XmlModi::fRead);
    connect(ui.pbReplace, &QPushButton::clicked, this, &XmlModi::replace);
    //connect(ui.pbFind, &QPushButton::clicked, this, &XmlModi::fFind);

}

/*void XmlModi::fWrite() {

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

  /*  QFile file("AddiThink.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::critical(this, "Erorr", "Can't open this file!");
    }
    QTextStream out(&file);
    QString text = ui.plainTextEdit->toPlainText();
    out << text;

    //file.flush();
    file.close();



}*/
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

/*void XmlModi::fFind() {
    QString axisid = "<axis id=";
    char qot = '"';
    double val;


    QString id;
    QString para;
    QString line;
    id = ui.readA->text();
    para = ui.readP->text();
    QFile data("AddiThink.txt");
    data.open(QIODevice::Text | QIODevice::ReadOnly);
    QTextStream stream(&data);
    
    do
    {
        line = stream.readLine();
        if (line.contains(axisid+qot+id+qot, Qt::CaseSensitive)&&line.contains(para, Qt::CaseSensitive))
        {
            QMessageBox::information(this, "Info ", "Found");

            break;
        }
        
        
    } while (!line.isNull());
   




}*/

void XmlModi::replace()
{
   
    
    QString axisid = "<axis id=";
    char qot = '"';
    char gl = '=';
    double val;
    char le = ' ';


    QString id;
    QString para;
    
   
    //QString line2;
    id = ui.readA->text();
    para = ui.readP->text();
    QFile data("AddiThink.txt");
    data.open(QIODevice::Text | QIODevice::ReadOnly);
    //QString dataText = data.readAll();
    QTextStream stream(&data);
    
    QFile tempFile("test.txt");
    tempFile.open(QIODevice::Text | QIODevice::WriteOnly);
    QTextStream out(&tempFile);
   
    QString line;
    
   
   
    
   do
    {

      
        QString line2;
        line = stream.readLine();
        line2 = line;

        if (line2.contains(axisid + qot + id + qot, Qt::CaseSensitive) && line2.contains(para, Qt::CaseSensitive))
        {
            
            QString newLine;
            QStringList list;
            list = line2.split(' ');
            for (int i = 1; i < list.size(); i++) {


                if (list.at(i).contains(para + gl, Qt::CaseSensitive)) {
                    // QRegularExpression re(list.at(i));
                    // QString replacementText(para+gl+qot+ui.readV->text()+qot);
                    QString befor = list[i];
                    QString after = para + gl + qot + ui.readV->text() + qot;

                    list.replaceInStrings(befor, after, Qt::CaseSensitive);
                    QMessageBox::information(this, "Info", "Replaced successfully");

                    
                    for (int j = 0; j < list.size(); j++) {
                        newLine.append(list.at(j)+" ");


                    }
                    


                   break;
                   
                    

                }

                
               // break;
            }

            
           
           // break;
            
               
                out << newLine<<endl;
            
            
            
        
        }
        else
        {
           
                out << line<<endl;
            
            continue;
        }
        
            
           
            
        
        
        
       
        
    } while (!line.isNull());
   
        //out >> line;

    

   data.close();
   tempFile.close();
   data.remove();
   tempFile.rename("AddiThink.txt");
}
        

    
    //line.contains(("axis id=" + '"' + id + '"'), Qt::CaseInsensitive) && line.contains(para + "=", Qt::CaseInsensitive
   /* if{
       
           
            QRegularExpression re(para);
            QString replacementText(ui.readV->text());
            dataText.replace(re, replacementText);
            QMessageBox::information(this, "Info", "Replaced successfully");

        


    }*/
        
    
    

    

    /*QFile newData("test.txt");
    if (newData.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&newData);
        out << dataText;
    }
    newData.close();*/



