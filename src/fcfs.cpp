#include "../inc/scheduler.h"

void FCFS::schedule_NONE(us16 runtime, JobRecorder &jobRecorder)
{
    Scheduler::schedule_NONE(runtime, jobRecorder);
}

void FCFS::schedule_PM(us16 runtime, JobRecorder &jobRecorder) { std::cout << "schedule_PM" << std::endl; }

void FCFS::schedule_PSA(us16 runtime, JobRecorder &jobRecorder)
{
    std::cout << "FCFS: schedule_NONE" << std::endl;
    addReadyJobToPrio();
    if(execableJobNum != 0){
        ptr runningJob = selectFirstJobPrio();
        if(runningJob->getNeedTime() == 0){
            /* move job from ready jobs list to finished jobs list */
            addFinishedJob(runningJob, runtime);
            jobVec[runningJob->getPrioOrSlice()].remove(runningJob);
            setAverTurn(jobRecorder);
            AddRecord(jobRecorder, runningJob, Run2Finished);
            DEBUG_PRINT("running job is ", runningJob->getJobName(), "it quit ");

            if(execableJobNum >= 1 || !nextJobs.empty()){  //if there is any ready job on next or ready jobs list
                ptr readyJob;
                if(!nextJobs.empty()){
                    readyJob = nextJobs.front();
                    nextJobs.pop_front();
                    readyJob->exec();   //execute the first job
                    AddRecord(jobRecorder, readyJob, Next2Run);
                }else{
                    readyJob = selectFirstJobPrio();
                    readyJob->exec();   //execute the first job
                    AddRecord(jobRecorder, readyJob, Ready2Run);
                }

                if(readyJob->getStartTime() == 0)// first time to run, set its starttime
                    readyJob->setStartTime(runtime);

                if(nextJobs.empty() && readyJobNum >= 1){
                    ptr nextJob = selectNextJobPrio(readyJob);  //if more than 2 job exists, then add it to next jobs list
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
                ptr nextJob = selectNextJobPrio(runningJob);  //if more than 2 job exists, then add it to next jobs list
                AddRecord(jobRecorder, nextJob, Ready2Next);
            }

            runningJob->exec();

            DEBUG_PRINT("running job is ", runningJob->getJobName(), "it needs ", runningJob->getNeedTime());
        }
    }
    DEBUG_PRINT("ready job num is", readyJobNum);
}
void FCFS::schedule_PM_PSA(us16 runtime, JobRecorder &jobRecorder) { std::cout << "schedule_PM_PSA" << std::endl; }


