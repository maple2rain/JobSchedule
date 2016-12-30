#ifndef JOBRECORDER_H
#define JOBRECORDER_H

#include "job.h"
#include "../inc/require.h"
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
        Wait2Ready, Ready2Next, Ready2Run, Next2Run, Next2Ready, Run2Next, Run2Ready, Run2Run, Run2Finished, Ready2Ready
    };
    JobRecorder() { ready2ready = wait2ready = ready2next = ready2run = next2run = next2ready = run2next = run2ready = run2run = run2finished = 0; isJobNone = false; }
    ~JobRecorder() { recorders.clear(); }

    /* setter */
    void addWait2Ready() { ++wait2ready; }
    void subWait2Ready() { --wait2ready; }
    void addReady2Next() { ++ready2next; }
    void addReady2Run() { ++ready2run; }
    void addNext2Run() { ++next2run; }
    void addNext2Ready() { ++next2ready; }
    void addRun2Next() { ++run2next; }
    void addRun2Ready() { ++run2ready; }
    void addRun2Run() { ++run2run; }
    void addRun2Finished() { ++run2finished; }
    void addReady2Ready() { ++ready2ready; }
    void setJobEnd() { isJobNone = true; }
    void setAverTurnover(const float _averTurnover) { averTurnover = _averTurnover; }
    void setAverWTurnover(const float _averWTurnover) { averWTurnOver = _averWTurnover; }
    void clear() {
        ready2ready = wait2ready = ready2next = ready2run = next2run = next2ready = run2next = run2ready = run2run = run2finished = 0;
        isJobNone = false;
        recorders.clear();
    }

    /* getter */
    us16 getReady2Ready() const { return ready2ready; }
    us16 getWait2Ready() const { return wait2ready; }
    us16 getReady2Next() const { return ready2next; }
    us16 getReady2Run() const { return ready2run; }
    us16 getNext2Run() const { return next2run; }
    us16 getNext2Ready() const { return next2ready; }
    us16 getRun2Next() const { return run2next; }
    us16 getRun2Run() const { return run2run; }
    us16 getRun2Ready() const { return run2ready; }
    us16 getRun2Finished() const { return run2finished; }
    size_t getJobNum() const { return recorders.size(); }
    bool isAnyJobRun() const { return run2run != 0 || ready2run != 0 || next2run != 0; }
    bool isFinished() const { return isJobNone; }
    float getAverTurnover() const { return averTurnover; }
    float getAverWTurnover() const { return averWTurnOver; }
    const std::list<ptr>& getRecorder() const { return recorders; }

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
    us16 ready2ready;
    bool isJobNone;
    float averTurnover;         //average turnover time
    float averWTurnOver;        //average weight turnover time
    std::list<ptr> recorders;    // store the status-changed jobs
};

#define AddRecord(recorder, job, status) \
do{ \
    std::cout << "recorder add record" << std::endl;\
    recorder.##addJob(job);\
    recorder.add##status##();\
}while(0)

#endif // JOBRECORDER_H
