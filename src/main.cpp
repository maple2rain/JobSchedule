#include "../inc/widget.h"
#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QReadWriteLock>
#include <QDebug>
#include <memory>
#include <string>
#include <QObject>
#include "../inc/scheduler.h"
#include "../inc/proxy.h"

QReadWriteLock readyJobLock;
QReadWriteLock waitingJobLock;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    std::shared_ptr<Scheduler> scheduler;
    std::shared_ptr<Proxy> proxy = std::make_shared<Proxy>(); // the proxy to deal with the interaction of scheduler and window

//    qDebug()<<"available drivers:";
//    QStringList drivers = QSqlDatabase::drivers();
//    foreach(QString driver, drivers)
//        qDebug() << driver;
    QObject::connect(&w, &Widget::methodFixedSignal,
                     [=, &scheduler](const std::string &scheduleMethod, bool _isPM, bool _isPSA){
                        proxy->addScheduler(scheduleMethod, _isPM, _isPSA, scheduler);//使用lambda表达式实现默认参数
                    });

    QObject::connect(&w, &Widget::jobCommingSignal,
                     [=, &scheduler](Job *job){
                        proxy->addWaitingJob(job, scheduler);//使用lambda表达式实现默认参数
                    });

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
