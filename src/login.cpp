#include "../inc/login.h"
#include "ui_login.h"
#include "../inc/useroperate.h"
#include "../inc/info.h"
#include "../inc/register.h"
#include <QMessageBox>

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
    extern UserOperate user;

    /* set info about user */
    user.setUserName(std::string((const char*)UserNameLineEdit->text().toLocal8Bit()));
    user.setPassword(std::string((const char*)PasswdLineEdit->text().toLocal8Bit()));
    Info info = user.CheckUser(); // check if uers valid

    if(info.getStatus() == true){
        signInSignalSend();
        this->close();
    }else{
        QMessageBox::warning(this, tr("Warning"), tr(info.getInfo().c_str()));
    }
}

void Login::on_RegisterBtn_clicked()
{
    Register *r = new Register;
    r->setAttribute(Qt::WA_DeleteOnClose);
    r->setWindowModality(Qt::ApplicationModal);//set parent window to lock
    r->show();
}
