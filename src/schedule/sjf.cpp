#include "../../inc/scheduler.h"

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
    std::cout << "On SJF sort,execablenum is " << execableJobNum << " readyJobNum is " << readyJobNum << std::endl;
    if(execableJobNum == readyJobNum){
        readyJobs.sort([](const ptr l, const ptr r){
                            return l->getLastTime() < r->getLastTime(); });
    }else if(execableJobNum - readyJobNum == 1){

        /* swap out first job which doesn't need to be sorted */
        ptr firstJob = readyJobs.front();
        readyJobs.pop_front();
            readyJobs.sort([](const ptr l, const ptr r){
                return l->getLastTime() < r->getLastTime(); });
        readyJobs.push_front(firstJob);
    }else if(execableJobNum - readyJobNum == 2){

        /* swap out first and second job, which don't need to be sorted */
        ptr firstJob = readyJobs.front();
        readyJobs.pop_front();
        ptr secondJob = readyJobs.front();
        readyJobs.pop_front();
            readyJobs.sort([](const ptr l, const ptr r){
                return l->getLastTime() < r->getLastTime(); });
        readyJobs.push_front(secondJob);
        readyJobs.push_front(firstJob);
    }else{
        std::cout << "counting error , execablenum is " << execableJobNum << " readyJobNum is " << readyJobNum << std::endl;
//        DEBUG_PRINT("counting error , execablenum is ", execableJobNum, " readyJobNum is ", readyJobNum);
    }
}
