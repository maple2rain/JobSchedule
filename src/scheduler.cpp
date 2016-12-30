#include "../inc/scheduler.h"
#include "../inc/dbOperate/useroperate.h"
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
    scheduler->addJobNum();
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
        scheduler->sortJobNone();
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
    require(readyJobNum >= 1, "The size of ready jobs list is less than 2!");
    auto it = readyJobs.begin();
    subReadyJobNum();
    nextJobs.push_back(*++it);
    return *it;
}

void Scheduler::addReadyJobToPrio()
{
    while(!readyJobs.empty()){
        ptr job = readyJobs.front();
        us16 prio = job->getPrioOrSlice();
        jobVec[prio].push_back(job);
        readyJobs.pop_front();
    }
}

Scheduler::ptr& Scheduler::selectFirstJobPrio()
{
    require(execableJobNum >= 1, "The size of ready jobs is less than 1");
    for(size_t i = 0; i <= MaxPrio; ++i){
        if(!jobVec[i].empty()){
            return jobVec[i].front();
        }
    }
}

Scheduler::ptr& Scheduler::selectNextJobPrio(ptr &job)
{
    require(readyJobNum >= 1, "The size of ready jobs is less than 1");
    int count = 0;
    for(size_t i = 0; i <= MaxPrio; ++i){
        if(!jobVec[i].empty()){
            if(++count == 2){
                subReadyJobNum();
                ptr _job = jobVec[i].front();
                if(job.get() == _job.get()){
                    --count;
                    continue;
                }
                nextJobs.push_back(jobVec[i].front());
                return jobVec[i].front();
            }else{
                if(jobVec[i].size() > 1){
                    auto it = jobVec[i].begin();

                    subReadyJobNum();
                    nextJobs.push_back(*++it);
                    return *it;
                }
            }
        }
    }
}

void Scheduler::addFinishedJob(ptr &jobs, us16 runtime)
{
    /* set time */
    jobs->setFinishedTime(runtime);
    jobs->setTurnoverTime();
    jobs->setWTurnoverTime();

    finishedJobs.push_back(jobs);
    subJobNum();
    subExecableJobNum();

    DEBUG_PRINT("add finished job" );
} //add finished job

void Scheduler::storeJobs()
{
    extern UserOperate user;
    user.InsertJobs(scheduler->getWaitingJobs(), "failed");
    user.InsertJobs(scheduler->getReadyJobs(), "failed");
    user.InsertJobs(scheduler->getNextJobs(), "failed");
    user.InsertJobs(scheduler->getFinishedJobs(), "finished");
    scheduler->clearAllJob();
}

void Scheduler::setAverTurn(JobRecorder &jobRecorder)
{
    float sum = 0, sumW = 0;
    for(auto it = finishedJobs.cbegin(); it != finishedJobs.cend(); ++it){
        sum += (*it)->getTurnOverTime();
        sumW += (*it)->getWTurnoverTime();
    }

    if(!finishedJobs.empty()){
        size_t size = finishedJobs.size();
        jobRecorder.setAverTurnover(sum / size);
        jobRecorder.setAverWTurnover(sumW / size);
    }
}

void Scheduler::clearAllJob()
{
    readyJobs.clear();
    waitingJobs.clear();
    nextJobs.clear();
    finishedJobs.clear();

    for(int i = 0; i <= MaxPrio; ++i)
        jobVec[i].clear();
}	//clear all the job

void Scheduler::schedule_NONE(us16 runtime, JobRecorder &jobRecorder)
{
    std::cout << "FCFS: schedule_NONE" << std::endl;
    if(execableJobNum != 0){
        ptr runningJob = selectFirstJob();
        if(runningJob->getNeedTime() == 0){
            /* move job from ready jobs list to finished jobs list */
            addFinishedJob(runningJob, runtime);
            readyJobs.remove(runningJob);
            setAverTurn(jobRecorder);
            AddRecord(jobRecorder, runningJob, Run2Finished);
            DEBUG_PRINT("running job is ", runningJob->getJobName(), "it quit ");

            if(execableJobNum >= 1){  //if there is any ready job on next or ready jobs list
                ptr readyJob;
                if(!nextJobs.empty()){
                    readyJob = nextJobs.front();
                    nextJobs.pop_front();
                    readyJob->exec();   //execute the first job
                    AddRecord(jobRecorder, readyJob, Next2Run);
                }else{
                    readyJob = selectFirstJob();
                    readyJob->exec();   //execute the first job
                    AddRecord(jobRecorder, readyJob, Ready2Run);
                }

                if(readyJob->getStartTime() == 0)// first time to run, set its starttime
                    readyJob->setStartTime(runtime);

                if(nextJobs.empty() && readyJobNum >= 1){
                    ptr nextJob = selectNextJob();  //if more than 2 job exists, then add it to next jobs list
                    AddRecord(jobRecorder, nextJob, Ready2Next);
                }
            }
        }else{
            if(runningJob->getRunTime() == 0){
                runningJob->setStartTime(runtime);
                AddRecord(jobRecorder, runningJob, Ready2Run);
                subReadyJobNum();
            }else{
                AddRecord(jobRecorder, runningJob, Run2Run);
            }

            if(nextJobs.empty() && readyJobNum >= 1){
                ptr nextJob = selectNextJob();  //if more than 2 job exists, then add it to next jobs list
                AddRecord(jobRecorder, nextJob, Ready2Next);
            }

            runningJob->exec();

            DEBUG_PRINT("running job is ", runningJob->getJobName(), "it needs ", runningJob->getNeedTime());
        }
    }
    DEBUG_PRINT("ready job num is", readyJobNum);
}
