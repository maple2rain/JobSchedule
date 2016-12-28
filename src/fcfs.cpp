#include "../inc/scheduler.h"

void FCFS::schedule_NONE(us16 runtime, JobRecorder &jobRecorder)
{
    std::cout << "FCFS: schedule_NONE" << std::endl;
    if(!readyJobs.empty()){
        ptr runningJob = selectFirstJob();
        if(runningJob->getNeedTime() == 0){
            /* move job from ready jobs list to finished jobs list */
            addFinishedJob(runningJob, runtime);
            readyJobs.remove(runningJob);
            setAverTurn(jobRecorder);
            AddRecord(jobRecorder, runningJob, Run2Finished);
            DEBUG_PRINT("running job is ", runningJob->getJobName(), "it quit ");

            if(!readyJobs.empty()){
                ptr readyJob = selectFirstJob();
                if(readyJob->getStartTime() == 0)
                    readyJob->setStartTime(runtime);

                readyJob->exec();   //execute the first job
                AddRecord(jobRecorder, readyJob, Next2Run);

                if(readyJobs.size() >= 2){
                    ptr nextJob = selectNextJob();  //if more than 2 job exists, then add it to next jobs list
                    AddRecord(jobRecorder, nextJob, Ready2Next);
                }
            }
        }else{
            if(runningJob->getRunTime() == 0){
                runningJob->setStartTime(runtime);
                AddRecord(jobRecorder, runningJob, Ready2Run);
            }else{
                AddRecord(jobRecorder, runningJob, Run2Run);
            }

            if(readyJobs.size() >= 2){
                ptr nextJob = selectNextJob();  //if more than 2 job exists, then add it to next jobs list
                AddRecord(jobRecorder, nextJob, Ready2Next);
            }

            runningJob->exec();

            DEBUG_PRINT("running job is ", runningJob->getJobName(), "it needs ", runningJob->getNeedTime());
        }
    }
}

void FCFS::schedule_PM(us16 runtime, JobRecorder &jobRecorder) { std::cout << "schedule_PM" << std::endl; }
void FCFS::schedule_PSA(us16 runtime, JobRecorder &jobRecorder) { std::cout << "schedule_PSA" << std::endl; }
void FCFS::schedule_PM_PSA(us16 runtime, JobRecorder &jobRecorder) { std::cout << "schedule_PM_PSA" << std::endl; }
