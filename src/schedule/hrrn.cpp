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
    schedule_NONE(runtime, jobRecorder);
}

void HRRN::schedule_PM(us16 runtime, JobRecorder &jobRecorder)
{
    sortJobPM(runtime);
    std::cout << "HRRN: schedule_PM" << std::endl;
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
                lastJob = readyJob;
                AddRecord(jobRecorder, readyJob, Ready2Run);
            }
        }else{
            if(lastJob != runningJob){
                addReadyJobNum();
                AddRecord(jobRecorder, lastJob, Run2Ready);
                AddRecord(jobRecorder, runningJob, Ready2Run);
                subReadyJobNum();
            }else{
                if(runningJob->getRunTime() == 0){  //first run
                    runningJob->setStartTime(runtime);
                    AddRecord(jobRecorder, runningJob, Ready2Run);
                    subReadyJobNum();
                }else{//without next job, it needn't swap out
                    AddRecord(jobRecorder, runningJob, Run2Run);
                }
            }

            runningJob->exec();
            lastJob = runningJob;
            DEBUG_PRINT("running job is ", runningJob->getJobName(), "it needs ", runningJob->getNeedTime());
        }

    }

    for(auto it = readyJobs.begin(); it != readyJobs.end(); ++it){
        AddRecord(jobRecorder, *it, Ready2Ready);
    }
    DEBUG_PRINT("ready job num is", readyJobNum);
}

void HRRN::schedule_PM_PSA(us16 runtime, JobRecorder &jobRecorder)
{
    schedule_PM(runtime, jobRecorder);
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

void HRRN::sortJobPM(us16 runtime)
{
    if(execableJobNum == readyJobNum){
        if(readyJobNum != 0){
            sortReadyJob(runtime);
            lastJob = readyJobs.front();
        }
    }else if(execableJobNum - readyJobNum == 1){

        ptr firstJob = readyJobs.front();

        if(firstJob->getNeedTime() <= 1){
            /* swap out first job which doesn't need to be sorted */
            firstJob->setPrioOrSlice(runtime - firstJob->getStartTime() + 1);
            readyJobs.pop_front();
                sortReadyJob(runtime);
            readyJobs.push_front(firstJob);
        }else{
            sortReadyJob(runtime);
        }

    }else{
        std::cout << "counting error , execablenum is " << execableJobNum << " readyJobNum is " << readyJobNum << std::endl;
    }
}

void HRRN::sortJobPSA(us16 runtime)
{

}

void HRRN::sortJobPM_PSA(us16 runtime)
{

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
