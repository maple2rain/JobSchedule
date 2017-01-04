#include "../../inc/ui/login.h"
#include "../../inc/dbOperate/useroperate.h"
#include "../../inc/dbOperate/info.h"
#include "../../inc/ui/register.h"
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
    Info info;

    if(user.getUserName() == ""){// let null user login
        info.setStatus(true);
    }else{
        info = user.CheckUser(); // check if uers valid
    }

    if(info.getStatus() == true){
        if(user.getUserName() != "")
            user.getAllInfoFromDB();

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

void Login::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
        on_LoginBtn_clicked();
    }
}
