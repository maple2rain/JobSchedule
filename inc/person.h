#ifndef PERSON_H
#define PERSON_H

#include <QWidget>
#include "ui_person.h"

namespace Ui {
class Person;
}

class Person : public QWidget, public Ui::Person
{
    Q_OBJECT

public:
    explicit Person(QWidget *parent = 0);
    ~Person();
    void selectGraph();
    void selectGif();
    void showGraph();
    void showGif();

private slots:
    void on_ModifyBtn_clicked();
    void on_EchoChkBox_clicked(bool checked);

private:
    void setUserData();

public slots:
    void changeUserData() { setUserData(); }

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
};

#endif // PERSON_H
