#include "../../inc/scheduler.h"

void RR::schedule_NONE(us16 runtime, JobRecorder &jobRecorder)
{
    std::cout << "Scheduler: schedule_NONE" << std::endl;
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
                    subReadyJobNum();
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
            if(runningJob->getRunTime() == 0){  //first run
                runningJob->setStartTime(runtime);
                AddRecord(jobRecorder, runningJob, Ready2Run);
                subReadyJobNum();
                runningJob->exec();
            }else{
                if(runningJob->getRunTime() % Slice != 0){
                    AddRecord(jobRecorder, runningJob, Run2Run);
                    runningJob->exec();
                }else{
                    if(!nextJobs.empty()){
                        readyJobs.pop_front();
                        readyJobs.push_back(runningJob);

                        ptr nextJob = nextJobs.front();
                        nextJobs.pop_front();

                        if(readyJobNum != 0){// if there is at least one ready job, then put running job to ready job
                            AddRecord(jobRecorder, runningJob, Run2Ready);
                            addReadyJobNum();
                        }else{//or, take it as next job
                            nextJobs.push_back(runningJob);
                            AddRecord(jobRecorder, runningJob, Run2Next);
                        }

                        if(nextJob->getRunTime() == 0)  //first run
                            nextJob->setStartTime(runtime);
                        nextJob->exec();
                        AddRecord(jobRecorder, nextJob, Next2Run);
                    }else{//without next job, it needn't swap out
                        AddRecord(jobRecorder, runningJob, Run2Run);
                        runningJob->exec();
                    }
                }
            }

            if(nextJobs.empty() && readyJobNum >= 1){
                ptr nextJob = selectNextJob();  //if more than 2 job exists, then add it to next jobs list
                AddRecord(jobRecorder, nextJob, Ready2Next);
            }

            DEBUG_PRINT("running job is ", runningJob->getJobName(), "it needs ", runningJob->getNeedTime());
        }
    }
    DEBUG_PRINT("ready job num is", readyJobNum);
}


void RR::schedule_PSA(us16 runtime, JobRecorder &jobRecorder)
{

}

void RR::schedule_PM(us16 runtime, JobRecorder &jobRecorder)
{

}

void RR::schedule_PM_PSA(us16 runtime, JobRecorder &jobRecorder)
{

}

void RR::sortJobNone()
{
    if(execableJobNum == readyJobNum){
        readyJobs.sort([](const ptr l, const ptr r){
            return l->getDeadLine() < r->getDeadLine(); });
    }else if(execableJobNum - readyJobNum == 1){

        /* swap out first job which doesn't need to be sorted */
        ptr firstJob = readyJobs.front();
        readyJobs.pop_front();

        readyJobs.sort([](const ptr l, const ptr r){
            return l->getDeadLine() < r->getDeadLine(); });

        readyJobs.push_front(firstJob);
    }else if(execableJobNum - readyJobNum == 2){

        /* swap out first and second job, which don't need to be sorted */
        ptr firstJob = readyJobs.front();
        readyJobs.pop_front();
        ptr secondJob = readyJobs.front();
        readyJobs.pop_front();

        readyJobs.sort([](const ptr l, const ptr r){
            return l->getDeadLine() < r->getDeadLine(); });

        readyJobs.push_front(secondJob);
        readyJobs.push_front(firstJob);
    }else{
        std::cout << "counting error , execablenum is " << execableJobNum << " readyJobNum is " << readyJobNum << std::endl;
    }
}
