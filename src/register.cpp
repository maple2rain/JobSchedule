#include "../inc/register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    setFixedSize(this->width(), this->height());
}

Register::~Register()
{
}

void Register::on_OkBtn_clicked()
{

}

void Register::on_CancelBtn_clicked()
{

}
