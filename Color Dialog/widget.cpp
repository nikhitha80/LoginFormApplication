#include "widget.h"
#include "ui_widget.h"
#include<QFont>
#include<QFontDialog>
#include<QMessageBox>
#include<QColorDialog>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_TEXTCOLOR_clicked()
{
    QPalette palette=ui->label->palette();
    QColor color=palette.color(QPalette::WindowText);
    QColor chosencolor=QColorDialog::getColor(color,this,"Choose text color");
    if(chosencolor.isValid())
    {
        palette.setColor(QPalette::WindowText,chosencolor);
        ui->label->setPalette(palette);
        qDebug()<<"User chosen a valid color";
    }
    else
    {
        qDebug()<<"User chosen an invalid color";
    }
}

void Widget::on_pushButton_BACKGROUNDCOLOR_clicked()
{
    QPalette palette=ui->label->palette();
    QColor color=palette.color(QPalette::Window);
    QColor chosencolor=QColorDialog::getColor(color,this,"Choose background color");
    if(chosencolor.isValid())
    {
        palette.setColor(QPalette::Window,chosencolor);
        ui->label->setPalette(palette);
        qDebug()<<"User chosen a valid color";
    }
    else
    {
        qDebug()<<"User chosen an invalid color";
    }
}

void Widget::on_pushButton_FONT_clicked()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok,QFont("Times new roman,10"),this);
    if(ok)
    {
        ui->label->setFont(font);
    }
    else
    {
        QMessageBox::information(this,"Message","User did not choose any font");
    }
}
