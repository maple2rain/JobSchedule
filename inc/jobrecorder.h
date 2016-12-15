#ifndef JOBRECORDER_H
#define JOBRECORDER_H

#include "job.h"
#include "scheduler.h"

class JobRecorder
{
private:
    JobRecorder(JobRecorder&);
    JobRecorder operator=(JobRecorder&);
public:
    enum status{
        Wait2Ready, Ready2Next, Ready2Run, Next2Run, Next2Ready, Run2Next, Run2Ready, Run2Finished
    };
    JobRecorder() { wait2ready = ready2next = ready2run = next2run = next2ready = run2next = run2ready = run2finished; }
    ~JobRecorder() { recoders.clear(); }

    /* setter */
    void addWait2Ready() { ++wait2ready; }
    void addReady2Next() { ++ready2next; }
    void addReady2Run() { ++ready2run; }
    void addNext2Run() { ++next2run; }
    void addNext2Ready() { ++next2ready; }
    void addRun2Next() { ++run2next; }
    void addRun2Ready() { ++run2ready; }
    void addRun2Finished() { ++run2finished; }
    void addJob(Scheduler::ptr job) { recoders.push_back(job); }
    void clear() {
        wait2ready = ready2next = ready2run = next2run = next2ready = run2next = run2ready = run2finished;
        recoders.clear();
    }

    /* getter */
    us16 getWait2Ready() { return wait2ready; }
    us16 getReady2Next() { return ready2next; }
    us16 getReady2Run() { return ready2run; }
    us16 getNext2Run() { return next2run; }
    us16 getNext2Ready() { return next2ready; }
    us16 getRun2Next() { return run2next; }
    us16 getRun2Ready() { return run2ready; }
    us16 getRun2Finished() { return run2finished; }

private:
    us16 wait2ready;
    us16 ready2next;
    us16 ready2run;
    us16 next2run;
    us16 next2ready;
    us16 run2next;
    us16 run2ready;
    us16 run2finished;
    std::list<Scheduler::ptr> recoders;    // store the status-changed jobs
};

#endif // JOBRECORDER_H
