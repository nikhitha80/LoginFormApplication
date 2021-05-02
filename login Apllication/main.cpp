#include "mainwindow.h"

#include <QApplication>

#include<QFile>
#include<QTextStream>
#include<QString>

QString readTextFile(QString path)
{
    QFile file(path);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream in(&file);
        return in.readAll();
    }
    return "";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString css=readTextFile("://styles/sheet (2).txt");
    if(css.length()>0)
    {
        a.setStyleSheet(css);
    }
    MainWindow w;
    w.show();
    return a.exec();
}
