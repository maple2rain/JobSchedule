#include "../../inc/scheduler.h"

void HRRN::schedule_NONE(us16 runtime, JobRecorder &jobRecorder)
{
    sortJobNone(runtime);
    std::cout << "HRRN: schedule_NONE" << std::endl;
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
                readyJob = selectFirstJob();
                readyJob->setStartTime(runtime);
                readyJob->exec();   //execute the first job
                subReadyJobNum();
                AddRecord(jobRecorder, readyJob, Ready2Run);
            }
        }else{
            if(runningJob->getRunTime() == 0){  //first run
                runningJob->setStartTime(runtime);
                AddRecord(jobRecorder, runningJob, Ready2Run);
                subReadyJobNum();
                runningJob->exec();
            }else{//without next job, it needn't swap out
                AddRecord(jobRecorder, runningJob, Run2Run);
                runningJob->exec();
            }

            DEBUG_PRINT("running job is ", runningJob->getJobName(), "it needs ", runningJob->getNeedTime());
        }
    }
    for(auto it = readyJobs.begin(); it != readyJobs.end(); ++it){
        AddRecord(jobRecorder, *it, Ready2Ready);
    }
    DEBUG_PRINT("ready job num is", readyJobNum);
}


void HRRN::schedule_PSA(us16 runtime, JobRecorder &jobRecorder)
{

}

void HRRN::schedule_PM(us16 runtime, JobRecorder &jobRecorder)
{

}

void HRRN::schedule_PM_PSA(us16 runtime, JobRecorder &jobRecorder)
{

}

void HRRN::sortJobNone(us16 runtime)
{
    if(execableJobNum == readyJobNum){
        sortReadyJob(runtime);
    }else if(execableJobNum - readyJobNum == 1){

        /* swap out first job which doesn't need to be sorted */
        ptr firstJob = readyJobs.front();
        readyJobs.pop_front();
            sortReadyJob(runtime);
        readyJobs.push_front(firstJob);
    }else{
        std::cout << "counting error , execablenum is " << execableJobNum << " readyJobNum is " << readyJobNum << std::endl;
    }
}

void HRRN::sortReadyJob(us16 runtime)
{
    changePrio(runtime);
    readyJobs.sort([](const ptr &l, const ptr &r){
        return (l->getPrioOrSlice() - r->getPrioOrSlice()) > 0.000001;
    });
}

void HRRN::changePrio(us16 runtime)
{
    for(auto it = readyJobs.begin(); it != readyJobs.end(); ++it){
        float value = (float)(runtime - (*it)->getStartTime() + (*it)->getNeedTime()) / (*it)->getNeedTime();
        (*it)->setPrioOrSlice(value);
    }
}
