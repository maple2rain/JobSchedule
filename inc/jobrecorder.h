#ifndef JOBRECORDER_H
#define JOBRECORDER_H

#include "job.h"
#include "scheduler.h"

class JobRecorder
{
public:
    JobRecorder() { waitJobNum = readyJobNum = nextJobNum = runJobNum = 0; }
    ~JobRecorder() {}

    /* setter */
    void addWaitJobNum() { ++waitJobNum; }
    void addReadyJobNum() { ++readyJobNum; }
    void addNextJobNum() { ++nextJobNum; }
    void addRunJobNum() { ++runJobNum; }
    void addJob(Scheduler::ptr job) { recoders.push_back(job); }
    void clear() {
        waitJobNum = readyJobNum = nextJobNum = runJobNum = 0;
        recoders.clear();
    }

    /* getter */
    us16 getWaitJobNum()  { return waitJobNum; }
    us16 getReadyJobNum() { return readyJobNum; }
    us16 getNextJobNum() { return nextJobNum; }
    us16 getRunJobNum() { return runJobNum; }

private:
    us16 waitJobNum;
    us16 readyJobNum;
    us16 nextJobNum;
    us16 runJobNum;
    std::list<Scheduler::ptr> recoders;    // store the status-changed jobs
};

#endif // JOBRECORDER_H
