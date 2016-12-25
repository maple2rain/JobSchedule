#include "../inc/person.h"
#include "ui_person.h"

Person::Person(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

Person::~Person()
{
}
