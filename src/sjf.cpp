#include "../inc/scheduler.h"

void SJF::schedule_NONE(us16 runtime, JobRecorder &jobRecorder)
{
    Scheduler::schedule_NONE(runtime, jobRecorder);
}


void SJF::schedule_PSA(us16 runtime, JobRecorder &jobRecorder)
{

}

void SJF::schedule_PM(us16 runtime, JobRecorder &jobRecorder)
{

}

void SJF::schedule_PM_PSA(us16 runtime, JobRecorder &jobRecorder)
{

}

void SJF::sortJobNone()
{
    if(execableJobNum == readyJobNum){
        readyJobs.sort([](const ptr l, const ptr r){
                            return l->getLastTime() < r->getLastTime(); });
    }
}
