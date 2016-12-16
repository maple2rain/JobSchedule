#ifndef JOBRECORDER_H
#define JOBRECORDER_H

#include "job.h"
#include <memory>
#include <list>

class JobRecorder
{
private:
    JobRecorder(JobRecorder&);
    JobRecorder operator=(JobRecorder&);
public:
    typedef std::shared_ptr<Job> ptr; //smart pointer
    enum Status{
        Wait2Ready, Ready2Next, Ready2Run, Next2Run, Next2Ready, Run2Next, Run2Ready, Run2Run, Run2Finished
    };
    JobRecorder() { wait2ready = ready2next = ready2run = next2run = next2ready = run2next = run2ready = run2run = run2finished = 0; }
    ~JobRecorder() { recorders.clear(); }

    /* setter */
    void addWait2Ready() { ++wait2ready; }
    void addReady2Next() { ++ready2next; }
    void addReady2Run() { ++ready2run; }
    void addNext2Run() { ++next2run; }
    void addNext2Ready() { ++next2ready; }
    void addRun2Next() { ++run2next; }
    void addRun2Ready() { ++run2ready; }
    void addRun2Run() { ++run2run; }
    void addRun2Finished() { ++run2finished; }
    void clear() {
        wait2ready = ready2next = ready2run = next2run = next2ready = run2next = run2ready = run2run = run2finished = 0;
        recorders.clear();
    }

    /* getter */
    us16 getWait2Ready() const { return wait2ready; }
    us16 getReady2Next() const { return ready2next; }
    us16 getReady2Run() const { return ready2run; }
    us16 getNext2Run() const { return next2run; }
    us16 getNext2Ready() const { return next2ready; }
    us16 getRun2Next() const { return run2next; }
    us16 getRun2Ready() const { return run2ready; }
    us16 getRun2Finished() const { return run2finished; }

    /* add job*/
    void addJob(ptr &job) { recorders.push_back(job); }


private:
    us16 wait2ready;
    us16 ready2next;
    us16 ready2run;
    us16 next2run;
    us16 next2ready;
    us16 run2next;
    us16 run2ready;
    us16 run2run;
    us16 run2finished;
    std::list<ptr> recorders;    // store the status-changed jobs
};

#define AddRecord(recorder, job, status) \
do{ \
    std::cout << "recorder add record" << std::endl;\
    recorder.##addJob(job);\
    recorder.add##status##();\
}while(0)

#endif // JOBRECORDER_H
