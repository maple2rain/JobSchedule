#include "../inc/register.h"
#include "ui_register.h"
#include "../inc/useroperate.h"
#include "../inc/info.h"
#include <QMessageBox>

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
    extern UserOperate user;

    QString passwd = PasswdLineEdit->text();
    QString confirm = ConfirmLineEdit->text();

    if(passwd.compare(confirm) == 0){
        user.setUserName(std::string((const char*)UserNameLineEdit->text().toLocal8Bit()));
        user.setPassword(std::string((const char*)PasswdLineEdit->text().toLocal8Bit()));
        Info info = user.AddUser();//add user

        if(info.getStatus() == true){
            QMessageBox::warning(this, tr("Information"), tr(info.getInfo().c_str()));
            this->close();
        }else{
            QMessageBox::warning(this, tr("Warning"), tr(info.getInfo().c_str()));
        }

    }else{
        QMessageBox::warning(this, tr("Warning"), tr("The password and the confirmed is not the same!"));
    }

}

void Register::on_CancelBtn_clicked()
{
    this->close();
}
