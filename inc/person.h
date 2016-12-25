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

private:
};

#endif // PERSON_H
