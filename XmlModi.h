#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_XmlModi.h"
#include<QFileDialog>
#include <QFile>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
#include <QTextStream>
#include <qlineedit.h>
#include <string>
#include <QTextStream>
#include <QString>
#include <string>
#include <QFile>
#include <QBuffer>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QTextStream>
#include<QTemporaryFile>
#include <QVBoxLayout>
#include "ui_XmlModi.h"
#include <String>
#include <QStringList>

class XmlModi : public QMainWindow
{
    Q_OBJECT

public:
    XmlModi(QWidget *parent = Q_NULLPTR);
    //void fWrite();
    void fRead();
    void replace();
    //void fFind();
    //void readText();
private:
    Ui::XmlModiClass ui;
};
