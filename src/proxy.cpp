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
    extern QMutex JobLock;
    QMutexLocker locker(&JobLock);
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
    jobRecorder.clear();
    schedule(scheduler, jobRecorder, runtime);
    statusSend(jobRecorder);
}

void Proxy::schedule(std::shared_ptr<Scheduler> &scheduler, JobRecorder &jobRecorder, us16 runtime)
{
    extern QMutex JobLock;
    QMutexLocker lockerWait(&JobLock);
    scheduler->schedule(runtime, jobRecorder);
}

void Proxy::toStore(std::shared_ptr<Scheduler> &scheduler)
{
    extern QMutex JobLock;
    QMutexLocker lockerWait(&JobLock);
    scheduler->storeJobs();
}

void Proxy::clearScheduler(std::shared_ptr<Scheduler> &scheduler)
{
    extern QMutex JobLock;
    QMutexLocker lockerWait(&JobLock);
    scheduler->clear();
}
