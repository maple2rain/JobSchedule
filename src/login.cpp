#include "../inc/login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    setFixedSize(this->width(), this->height());
}

Login::~Login()
{
}

void Login::on_LoginBtn_clicked()
{

}

void Login::on_RegisterBtn_clicked()
{

}
