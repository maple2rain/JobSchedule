#include "../../inc/scheduler.h"

void EDF::schedule_NONE(us16 runtime, JobRecorder &jobRecorder)
{
    Scheduler::schedule_NONE(runtime, jobRecorder);//call none
}


void EDF::schedule_PSA(us16 runtime, JobRecorder &jobRecorder)
{
    Scheduler::schedule_NONE(runtime, jobRecorder); //call none
}

void EDF::schedule_PM(us16 runtime, JobRecorder &jobRecorder)
{

}

void EDF::schedule_PM_PSA(us16 runtime, JobRecorder &jobRecorder)
{

}

void EDF::sortJobNone()
{
    struct Comp {
        bool operator()(const ptr l, const ptr r)
        {
            return l->getDeadLine() < r->getDeadLine();
        }
    };

    std::cout << "On EDF_NONE sort,execablenum is " << execableJobNum << " readyJobNum is " << readyJobNum << std::endl;
    Scheduler::sort(Comp());
}

void EDF::sortJobPM()
{

}


void EDF::sortJobPSA()
{
    struct Comp {
        bool operator()(const ptr l, const ptr r)
        {
            return l->getDeadLine() < r->getDeadLine() ||
                    l->getDeadLine() == r->getDeadLine() && l->getPrioOrSlice() < r->getPrioOrSlice();
        }
    };

    std::cout << "On EDF_PSA sort,execablenum is " << execableJobNum << " readyJobNum is " << readyJobNum << std::endl;
    Scheduler::sort(Comp());
}

void EDF::sortJobPM_PSA()
{

}
