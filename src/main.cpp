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

QReadWriteLock readyJobLock;
QReadWriteLock waitingJobLock;

void addWaitingJob(Scheduler &scheduler);
void addReadyJob(Scheduler &scheduler);
void addScheduler(const std::string &scheduleMethod, bool _isPM, bool _isPSA, Scheduler *scheduler);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    Scheduler *scheduler = NULL;

//    qDebug()<<"available drivers:";
//    QStringList drivers = QSqlDatabase::drivers();
//    foreach(QString driver, drivers)
//        qDebug() << driver
    QObject::connect(&w, &Widget::methodFixedSignal,
                     [=, &scheduler](const std::string &scheduleMethod, bool _isPM, bool _isPSA){
                        //Reader *read = new Reader("world");
                        ::addScheduler(scheduleMethod, _isPM, _isPSA, scheduler);//使用lambda表达式实现默认参数
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

void addScheduler(const std::string &scheduleMethod, bool _isPM, bool _isPSA, Scheduler *scheduler)
{
    try{
        scheduler = new Scheduler(scheduleMethod);  //remember to delete
    }catch(Scheduler::BadSchedulerCreation e){
        std::cout << e.what() << std::endl;
    }

    scheduler->setFlag(_isPSA, _isPM);
}

