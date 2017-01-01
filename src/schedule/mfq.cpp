#include "../../inc/scheduler.h"
#include <cmath>

void MFQ::sortJobNone()
{
    for(auto it = readyJobs.begin(); it != readyJobs.end(); ++it){
        jobVec[0].push_back(*it);
    }
    readyJobs.clear();
}

void MFQ::schedule_NONE(us16 runtime, JobRecorder &jobRecorder)
{
    for(us16 i = 0; i <= MaxPrio; ++i){
        if(!jobVec[i].empty()){
            if(i != MaxPrio){
                ptr runningJob = jobVec[i].front();
                if(runningJob->getNeedTime() == 0){
                    /* move job from ready jobs list to finished jobs list */
                    addFinishedJob(runningJob, runtime);
                    jobVec[i].remove(runningJob);
                    setAverTurn(jobRecorder);
                    AddRecord(jobRecorder, runningJob, Run2Finished);
                    DEBUG_PRINT("running job is ", runningJob->getJobName(), "it quit ");
                    schedule_NONE(runtime, jobRecorder);
                }else{
                    us16 time = runningJob->getRunTime();
                    if(time == 0){  //first run
                        runningJob->setStartTime(runtime);
                        AddRecord(jobRecorder, runningJob, Ready2Run);
                        runningJob->exec();
                        subReadyJobNum();
                    }else{
                        if(time == std::pow(2, i)){
                            runningJob->setPrioOrSlice(i + 1);
                            jobVec[i + 1].push_back(runningJob);
                            jobVec[i].pop_front();
                            AddRecord(jobRecorder, runningJob, Run2Ready);
                            addReadyJobNum();
                            schedule_NONE(runtime, jobRecorder);    //call self
                        }else if(time == std::pow(2, i - 1)){
                            runningJob->exec();
                            subReadyJobNum();
                            AddRecord(jobRecorder, runningJob, Ready2Run);
                        }else{
                            runningJob->exec();
                            AddRecord(jobRecorder, runningJob, Run2Run);
                        }
                    }
                }
            }else{
                if(execableJobNum != 0){
                    ptr runningJob = selectFirstJob();
                    if(runningJob->getNeedTime() == 0){
                        /* move job from ready jobs list to finished jobs list */
                        addFinishedJob(runningJob, runtime);
                        jobVec[MaxPrio].remove(runningJob);
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

                            if(readyJob->getRunTime() == 0)// first time to run, set its starttime
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
                            us16 time = runningJob->getRunTime();
                            if(time % Slice != 0){
                                if(time == std::pow(2, i - 1)){
                                    AddRecord(jobRecorder, runningJob, Ready2Run);
                                    subReadyJobNum();
                                    runningJob->exec();
                                }else{
                                    AddRecord(jobRecorder, runningJob, Run2Run);
                                    runningJob->exec();
                                }
                            }else{
                                if(!nextJobs.empty()){
                                    jobVec[MaxPrio].pop_front();
                                    jobVec[MaxPrio].push_back(runningJob);

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
            }
            break;
        }
    }
}

Scheduler::ptr& MFQ::selectNextJob()
{
    require(readyJobNum >= 1, "The size of ready jobs list is less than 2!");
    auto it = jobVec[MaxPrio].begin();
    subReadyJobNum();
    nextJobs.push_back(*++it);
    return *it;
}
