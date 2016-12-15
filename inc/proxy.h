#ifndef PROXY_H
#define PROXY_H
#include <QObject>
#include <QString>
#include "scheduler.h"
#include "job.h"
class Proxy : public QObject{
    Q_OBJECT

public:
//    Proxy(QString name) : paperName(name) {}
    Proxy() {}
    void PaperSend()
    {
       emit PaperComing(paperName, true);//使用emit在恰当的位置发送信号
    }
    
    void sendReadyJob()
    {
        
    }

private:
    QString paperName;

public slots:
    void addWaitingJob(Job *job, std::shared_ptr<Scheduler> &scheduler);
    void addReadyJob(Job *job, std::shared_ptr<Scheduler> &scheduler);
    void addScheduler(const std::string &scheduleMethod, bool _isPM, bool _isPSA, std::shared_ptr<Scheduler> &scheduler);

signals://使用signals标记信号函数，信号是一个函数声明，返回void，不需要函数的实现代码
    void PaperComing(const QString &name, bool flag);
};
#endif // PROXY_H
