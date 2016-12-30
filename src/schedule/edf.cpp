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
    }else if(execableJobNum - readyJobNum == 1){
        ptr firstJob = readyJobs.front();
        readyJobs.pop_front();
        readyJobs.sort([](const ptr l, const ptr r){
                            return l->getDeadLine() < r->getDeadLine(); });
        readyJobs.push_front(firstJob);
    }else if(execableJobNum - readyJobNum == 2){
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
