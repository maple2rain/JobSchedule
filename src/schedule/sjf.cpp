#include "../../inc/scheduler.h"
#include <utility>
#include <functional>
using namespace std;

void SJF::schedule_NONE(us16 runtime, JobRecorder &jobRecorder)
{
    Scheduler::schedule_NONE(runtime, jobRecorder);
}


void SJF::schedule_PSA(us16 runtime, JobRecorder &jobRecorder)
{
    Scheduler::schedule_NONE(runtime, jobRecorder);
}

void SJF::schedule_PM(us16 runtime, JobRecorder &jobRecorder)
{

}

void SJF::schedule_PM_PSA(us16 runtime, JobRecorder &jobRecorder)
{

}

void SJF::sortJobNone()
{
    struct Comp {
        bool operator()(const ptr l, const ptr r)
        {
            return l->getLastTime() < r->getLastTime();
        }
    };

    std::cout << "On SJF sort,execablenum is " << execableJobNum << " readyJobNum is " << readyJobNum << std::endl;
    Scheduler::sort(Comp());
}

void SJF::sortJobPM()
{
    Scheduler::sortJobPM();
}

void SJF::sortJobPSA()
{
    struct Comp {
        bool operator()(const ptr l, const ptr r)
        {
            return l->getLastTime() < r->getLastTime() ||
                    l->getLastTime() == r->getLastTime() && l->getPrioOrSlice() < r->getPrioOrSlice();
        }
    };

    std::cout << "On SJF_PSA sort,execablenum is " << execableJobNum << " readyJobNum is " << readyJobNum << std::endl;
    Scheduler::sort(Comp());
}

void SJF::sortJobPM_PSA()
{
    Scheduler::sortJobPM_PSA();
}
