﻿#ifndef PROXY_H
#define PROXY_H
#include <QObject>
#include <QString>
#include "scheduler.h"
#include "job.h"
#include "jobrecorder.h"
class Proxy : public QObject{
    Q_OBJECT

public:
//    Proxy(QString name) : paperName(name) {}
    Proxy() {}
    void statusSend(const JobRecorder &jobRecorder)
    {
        emit jobStatusChangeSignal(jobRecorder);
    }

private:
    QString paperName;

public slots:
    //when commit a new job, add it to waiting-job list
    void addWaitingJob(Job *job, std::shared_ptr<Scheduler> &scheduler);

    //when the joining time of the job is equal to the current time, that add it to ready-job list
    void addReadyJob(Job *job, std::shared_ptr<Scheduler> &scheduler);

    //when choose new method to schedule, add a new scheduler
    void addScheduler(const std::string &scheduleMethod, bool _isPM, bool _isPSA, std::shared_ptr<Scheduler> &scheduler);

    //when time goes on, continue to schedule
    void toSchedule(std::shared_ptr<Scheduler> &scheduler, JobRecorder &jobRecorder, us16 runtime);

signals://使用signals标记信号函数，信号是一个函数声明，返回void，不需要函数的实现代码
    //when the jobs-status change, send the information to the table view
    void jobStatusChangeSignal(const JobRecorder& jobRecorder);
};
#endif // PROXY_H
