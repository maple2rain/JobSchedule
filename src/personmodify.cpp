#include "../inc/personmodify.h"
#include "../inc/useroperate.h"
#include "../inc/info.h"
#include <QMessageBox>

PersonModify::PersonModify(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    setFixedSize(this->width(), this->height());
    setWindowTitle("Modify");
}

PersonModify::~PersonModify()
{
}

void PersonModify::on_OkBtn_clicked()
{
    extern QMutex UserLock;
    extern UserOperate user;
    QMutexLocker lockerWait(&UserLock);

    QString passwd = PasswdLineEdit->text();
    QString confirm = ConfirmLineEdit->text();

    if(passwd.compare(confirm) == 0){
        std::string oldName = user.getUserName();
        //can set newName constraint
        std::string newName = std::string((const char*)UserNameLineEdit->text().toLocal8Bit());

        if(!newName.empty()){
            user.setUserName(newName);
        }

        user.setPassword(std::string((const char*)PasswdLineEdit->text().toLocal8Bit()));
        Info info = user.UpdateUser();//add user

        if(info.getStatus() == true){
            QMessageBox::warning(this, tr("Information"), tr(info.getInfo().c_str()));
            sendChangeUserDataSignal();
            this->close();
        }else{
            user.setUserName(oldName);
            QMessageBox::warning(this, tr("Warning"), tr(info.getInfo().c_str()));
        }

    }else{
        QMessageBox::warning(this, tr("Warning"), tr("The password and the confirmed is not the same!"));
    }

}

void PersonModify::on_CancelBtn_clicked()
{
    this->close();
}
