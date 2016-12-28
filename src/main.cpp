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
#include <QFileDialog>
#include <QCryptographicHash>
#include "../inc/scheduler.h"
#include "../inc/proxy.h"
#include "../inc/jobrecorder.h"
#include "../inc/useroperate.h"

QMutex JobLock;
QMutex UserLock;
UserOperate user;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    std::shared_ptr<Scheduler> scheduler;
    std::shared_ptr<Proxy> proxy = std::make_shared<Proxy>(); // the proxy is to deal with the interaction of scheduler and window
    JobRecorder jobRecorder; // the recorder is to record the status of job
    Login l;


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

    QObject::connect(&l, &Login::userSignInSignal,
                     [&](){

        w.show(); w.showGraph();
    });

    l.show();
//    if(true){
//        w.show();
//    }

//    QString str = QFileDialog::getOpenFileName();
//    if(str.isEmpty()){
//        return 0;
//    }
//    QFile file(str);
//    if(!file.open(QFile::ReadOnly)){
//        return 0;
//    }

//    QCryptographicHash hash(QCryptographicHash::Md5);
//    if(!file.atEnd()){
//        hash.addData(file.readAll());
//    }
//    qDebug() << hash.result().size();
//    QString md5;
//    md5.append(hash.result().toHex());
//    qDebug() << md5 << md5.size();

    return a.exec();
}
