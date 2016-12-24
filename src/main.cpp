#include "../inc/widget.h"
#include "../inc/login.h"
#include "../inc/register.h"
#include <QApplication>
#include <QMutexLocker>
#include <QDebug>
#include <memory>
#include <string>
#include <QObject>
#include <QTextStream>
#include "../inc/scheduler.h"
#include "../inc/proxy.h"
#include "../inc/jobrecorder.h"
#include "../inc/useroperate.h"

QMutex readyJobLock;
QMutex waitingJobLock;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    std::shared_ptr<Scheduler> scheduler;
    std::shared_ptr<Proxy> proxy = std::make_shared<Proxy>(); // the proxy is to deal with the interaction of scheduler and window
    JobRecorder jobRecorder; // the recorder is to record the status of job
    Login l;
    UserOperate user;
   // Login l;


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

    QObject::connect(&w, &Widget::timeRunningSignal,
                     [=, &scheduler, &jobRecorder](us16 runtime){
        proxy->toSchedule(scheduler, jobRecorder, runtime);//使用lambda表达式实现默认参数
    });

    QObject::connect(proxy.get(), &Proxy::jobStatusChangeSignal,
                     [&](const JobRecorder &jobRecorder){
        w.drawTable(jobRecorder);//使用lambda表达式实现默认参数
    });

    l.show();
//    if(true){
//        w.show();
//    }




    return a.exec();
}
