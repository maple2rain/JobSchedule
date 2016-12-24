#ifndef PERSON_H
#define PERSON_H

#include <QWidget>
#include "ui_person.h"

namespace Ui {
class person;
}

class person : public QWidget, public Ui::person
{
    Q_OBJECT

public:
    explicit person(QWidget *parent = 0);
    ~person();

private:
};

#endif // PERSON_H
