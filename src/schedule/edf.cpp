#include "../../inc/scheduler.h"

void EDF::schedule_NONE(us16 runtime, JobRecorder &jobRecorder)
{
    Scheduler::schedule_NONE(runtime, jobRecorder);
}


void EDF::schedule_PSA(us16 runtime, JobRecorder &jobRecorder)
{

}

void EDF::schedule_PM(us16 runtime, JobRecorder &jobRecorder)
{

}

void EDF::schedule_PM_PSA(us16 runtime, JobRecorder &jobRecorder)
{

}

void EDF::sortJobNone()
{
    if(execableJobNum == readyJobNum){
        readyJobs.sort([](const ptr l, const ptr r){
                            return l->getDeadLine() < r->getDeadLine(); });
    }
}
