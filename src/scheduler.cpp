#include "../inc/scheduler.h"
void Scheduler::addWaitingJob(ptr &job)
{
    auto it = scheduler->waitingJobs.begin();
    while(it != scheduler->waitingJobs.end()){ //add waiting job in ascending order
        if((*it)->getJoinTime() <= job->getJoinTime())
            ++it;
        else
            break;
    }
    scheduler->waitingJobs.insert(it, job);
    DEBUG_PRINT_JOB(waitingJobs, JoinTime);
}

void Scheduler::checkWaitingJob(us16 runtime, JobRecorder &jobRecorder)
{
    // if waiting job's join time up to runtime, then move it to ready jobs and job recorder
    for(auto it = scheduler->waitingJobs.begin(); it != scheduler->waitingJobs.end(); ){
        us16 joinTime = (*it)->getJoinTime();
        if(joinTime == runtime + 1){    //waiting job begin to ready when its jointime is less than runtime + 1
            AddRecord(jobRecorder, *it, Wait2Ready);    //add it to job recorder
            DEBUG_PRINT("waiting job is ", (*it)->getJobName(), " ,it become ready");
            ++it;
        }else if(joinTime == runtime){
            scheduler->addReadyJob(*it);   //add it to ready jobs list
            DEBUG_PRINT("ready job is ", (*it)->getJobName(), " ,it was added to ready jobs");
            it = scheduler->waitingJobs.erase(it); //remove it from waiting jobs list
        }else{
            break;
        }
    }
}

void Scheduler::schedule(us16 runtime, JobRecorder &jobRecorder)
{
    require(flag <= _PM_PSA, "flag is out of range!");

    if(scheduler->isJobNone()){
        jobRecorder.setJobEnd();
        return;
    }

    checkWaitingJob(runtime, jobRecorder);  //check if waiting can be a ready job

    //begin to schedule
    switch (flag)
    {
    case _NONE:
        scheduler->schedule_NONE(runtime, jobRecorder);
        break;
    case _PM:
        scheduler->schedule_PM(runtime, jobRecorder);
        break;
    case _PSA:
        scheduler->schedule_PSA(runtime, jobRecorder);
        break;
    case _PM_PSA:
        scheduler->schedule_PM_PSA(runtime, jobRecorder);
        break;
    default:
        break;
    }
}

bool Scheduler::statusChange(std::list<ptr> &srcJobs, std::list<ptr> &dstJobs, std::list<ptr> &changeJobs, unsigned short runtime)
{
    return true;
}

Scheduler::ptr& Scheduler::selectNextJob()
{
    require(readyJobs.size() >= 2, "The size of ready jobs list is less than 2!");
    auto it = readyJobs.begin();
    return *++it;
}
