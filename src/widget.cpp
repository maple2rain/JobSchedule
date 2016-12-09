#include "../inc/widget.h"
#include <QLabel>
#include <QString>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    setWindowTitle("Jobs Scheduler");
    setFixedSize(this->width(), this->height());
}

Widget::~Widget()
{

}

void Widget::on_Run_clicked()
{
    qDebug() << "run";
}

void Widget::on_ClearAllDataBtn_clicked()
{

}

void Widget::on_PSA_clicked(bool checked)
{

}

void Widget::on_PM_clicked(bool checked)
{

}

void Widget::on_FCFS_clicked()
{

}

void Widget::on_MFQ_clicked()
{

}

void Widget::on_RR_clicked()
{

}

void Widget::on_SJF_clicked()
{

}

void Widget::on_HRRN_clicked()
{

}

void Widget::on_EDF_clicked()
{

}

void Widget::on_JoinTimeEdit_editingFinished()
{
    QString text = Ui_Widget::JoinTimeEdit->text();
    qDebug() << text;
}

void Widget::on_JobNameEdit_editingFinished()
{

}

void Widget::on_LastTimeEdit_editingFinished()
{

}

void Widget::on_DeadLineEdit_editingFinished()
{
    QString text = Ui_Widget::DeadLineEdit->text();
    qDebug() << text;
}

void Widget::on_PriorityCombo_currentIndexChanged(int index)
{

}

void Widget::on_ClearInputBtn_clicked()
{
    qDebug() << "clear" ;
}

void Widget::on_CommitInputBtn_clicked()
{

}

void Widget::on_OpenFile_clicked()
{

}
