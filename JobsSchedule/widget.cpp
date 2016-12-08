#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QString>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_Run_clicked()
{

}

void Widget::on_JobNameEdit_textEdited(const QString &arg1)
{

}
