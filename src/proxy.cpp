#include "../inc/proxy.h"
#include <QReadWriteLock>

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
    extern QReadWriteLock waitingJobLock;
    QWriteLocker locker(&waitingJobLock);
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

void Proxy::addReadyJob(Job *job, std::shared_ptr<Scheduler> &scheduler)
{

}

void Proxy::toSchedule(std::shared_ptr<Scheduler> &scheduler, JobRecorder &jobRecorder, us16 runtime)
{
    jobRecorder.clear();
    scheduler->schedule(runtime, jobRecorder);
    statusSend(jobRecorder);
}
