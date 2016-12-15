#include "../inc/scheduler.h"

void Scheduler::schedule()
{
    require(flag <= _PM_PSA, "flag is out of range!");

    switch (flag)
    {
    case _NONE:
        scheduler->schedule_NONE();
        break;
    case _PM:
        scheduler->schedule_PM();
        break;
    case _PSA:
        scheduler->schedule_PSA();
        break;
    case _PM_PSA:
        scheduler->schedule_PM_PSA();
        break;
    default:
        break;
    }
}

bool Scheduler::statusChange(std::list<ptr> &srcJobs, std::list<ptr> &dstJobs, std::list<ptr> &changeJobs, unsigned short runtime)
{
    return true;
}
