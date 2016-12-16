#include "../inc/scheduler.h"

void FCFS::schedule_NONE(us16, JobRecorder &jobRecorder)
{
    std::cout << "FCFS: schedule_NONE" << std::endl;
    if(!readyJobs.empty()){
        ptr runningJob = selectFirstJob();
        if(runningJob->getNeedTime() == 0){
            /* move job from ready jobs list to finished jobs list */
            addFinishedJob(runningJob);
            readyJobs.remove(runningJob);
            AddRecord(jobRecorder, runningJob, Run2Finished);
            std::cout << "running job is" << runningJob->getJobName() << "it quit " << std::endl;

            if(!readyJobs.empty()){
                ptr readyJob = selectFirstJob();
                readyJob->exec();   //execute the first job
                if(readyJobs.size() == 1){
                    AddRecord(jobRecorder, readyJob, Next2Run);
                }
                if(readyJobs.size() >= 2){
                    ptr nextJob = selectNextJob();  //if more than 2 job exists, then add it to next jobs list
                    AddRecord(jobRecorder, nextJob, Ready2Next);
                }
            }
        }else{
            runningJob->exec();
            std::cout << "running job is" << runningJob->getJobName() << "it needs " << runningJob->getNeedTime() << std::endl;
            AddRecord(jobRecorder, runningJob, Run2Run);
        }
    }
}
void FCFS::schedule_PM(us16 runtime, JobRecorder &jobRecorder) { std::cout << "schedule_PM" << std::endl; }
void FCFS::schedule_PSA(us16 runtime, JobRecorder &jobRecorder) { std::cout << "schedule_PSA" << std::endl; }
void FCFS::schedule_PM_PSA(us16 runtime, JobRecorder &jobRecorder) { std::cout << "schedule_PM_PSA" << std::endl; }
