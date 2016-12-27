#ifndef PERSONMODIFY_H
#define PERSONMODIFY_H

#include <QWidget>
#include "ui_register.h"

namespace Ui {
class Register;
}

class PersonModify : public QWidget, public Ui::Register
{
    Q_OBJECT

public:
    explicit PersonModify(QWidget *parent = 0);
    ~PersonModify();

private slots:
    void on_OkBtn_clicked();
    void on_CancelBtn_clicked();

private:
    void sendChangeUserDataSignal(){
        emit ChangeUserDataSignal();
    }

signals:
    void ChangeUserDataSignal();
};


#endif // PERSONMODIFY_H
