#include "../../inc/scheduler.h"

void FCFS::sortJobNone()
{
    Scheduler::sortJobNone();
}

void FCFS::sortJobPM()
{
    Scheduler::sortJobPM();
}

void FCFS::sortJobPM_PSA()
{
    Scheduler::sortJobPM_PSA();
}

void FCFS::sortJobPSA()
{
    struct Comp {
        bool operator()(const ptr l, const ptr r)
        {
            return l->getJoinTime() < r->getJoinTime() ||
                    l->getJoinTime() == r->getJoinTime() && l->getPrioOrSlice() < r->getPrioOrSlice();
        }
    };

    std::cout << "On FCFS sort,execablenum is " << execableJobNum << " readyJobNum is " << readyJobNum << std::endl;
    Scheduler::sort(Comp());
}

void FCFS::schedule_NONE(us16 runtime, JobRecorder &jobRecorder)
{
    std::cout << "FCFS: schedule_NONE" << std::endl;
    Scheduler::schedule_NONE(runtime, jobRecorder);
}

void FCFS::schedule_PM(us16 runtime, JobRecorder &jobRecorder)
{
    std::cout << "FCFS: schedule_PM" << std::endl;
    Scheduler::schedule_NONE(runtime, jobRecorder);
}

void FCFS::schedule_PSA(us16 runtime, JobRecorder &jobRecorder)
{
    std::cout << "FCFS: schedule_PSA" << std::endl;
    Scheduler::schedule_NONE(runtime, jobRecorder);
}
void FCFS::schedule_PM_PSA(us16 runtime, JobRecorder &jobRecorder)
{
    std::cout << "schedule_PM_PSA" << std::endl;
    Scheduler::schedule_PM(runtime, jobRecorder);
}


