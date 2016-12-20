#include "../inc/proxy.h"
#include "../inc/app_cfg.h"
#include <QMutexLocker>

void Proxy::addScheduler(const std::string &scheduleMethod, bool _isPM, bool _isPSA, std::shared_ptr<Scheduler> &scheduler)
{
    try{
        scheduler = std::make_shared<Scheduler>(scheduleMethod);
        scheduler->setFlag(_isPSA, _isPM);
    }catch(Scheduler::BadSchedulerCreation e){
        std::cout << e.what() << std::endl;
    }
}

void Proxy::addWaitingJob(Job *job, std::shared_ptr<Scheduler> &scheduler)
{
    extern QMutex waitingJobLock;
    QMutexLocker locker(&waitingJobLock);
    std::cout << "addWaitingJob" << std::endl;

    std::shared_ptr<Job> _job(job);
    try{
        if(scheduler)
            scheduler->addWaitingJob(_job);
        else
            std::cout << "scheduler is not exists" << std::endl;
    }catch(Scheduler::BadSchedulerCreation e){
        std::cout << e.what() << std::endl;
    }
}

void Proxy::toSchedule(std::shared_ptr<Scheduler> &scheduler, JobRecorder &jobRecorder, us16 runtime)
{
    extern QMutex waitingJobLock;
    extern QMutex readyJobLock;
    QMutexLocker lockerWait(&waitingJobLock);
    QMutexLocker lockerReady(&readyJobLock);

    jobRecorder.clear();
    scheduler->schedule(runtime, jobRecorder);
    statusSend(jobRecorder);
}
