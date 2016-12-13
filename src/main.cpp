#include "../inc/widget.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

//    qDebug()<<"available drivers:";
//    QStringList drivers = QSqlDatabase::drivers();
//    foreach(QString driver, drivers)
//        qDebug() << driver;

    w.show();
//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//        db.setHostName("localhost");
//        db.setDatabaseName("Jobs");
//        db.setUserName("root");
//        db.setPassword("123456");
//        if(!db.open()){
//        qDebug() << "sql failed";
//            db.close();
//        }



    return a.exec();
}
