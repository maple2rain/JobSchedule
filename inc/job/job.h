#ifndef JOB_H
#define JOB_H
#include <string>
#include "../inc/app_cfg.h"
#include <memory>

/* The Attribute of jobs */
class Job
{
    std::string     jobName;
            us16    jobID;
            us16    joinTime;
            us16    lastTime;
            us16    startTime;
            us16    runTime;
            us16    needTime;
            us16    deadLine;
            us16    finishedTime;
            us16    PrioOrSlice;
            float   turnoverTime;
            float   wTurnoverTime;

    //Prevent copy-construction & operator =
//    Job(Job&);
//    Job operator=(Job&);
public:
    typedef std::shared_ptr<Job> ptr; //smart pointer
    Job(const std::string &name,
        us16 _joinTime,
        us16 _lastTime,
        us16 _deadLine,
        us16 _PrioOrSlice = 0) :
        jobName(name),
        joinTime(_joinTime),
        lastTime(_lastTime),
        deadLine(_deadLine),
        PrioOrSlice(_PrioOrSlice)
    {
        startTime = 0;
        needTime = _lastTime;
        runTime = 0;
        finishedTime = 0;
        turnoverTime = 0;
        wTurnoverTime = 0;
    }

    Job() {}
    ~Job() {}

    /* getter */
    const us16 getJobID() const { return jobID; }
    const std::string& getJobName() const { return jobName; }
    const us16 getJoinTime() const { return joinTime; }
    const us16 getLastTime() const { return lastTime; }
    const us16 getStartTime() const { return startTime; }
    const us16 getRunTime() const { return runTime; }
    const us16 getNeedTime() const { return needTime; }
    const us16 getDeadLine() const { return deadLine; }
    const us16 getFinishedTime() const { return finishedTime; }
    const us16 getPrioOrSlice() const { return PrioOrSlice; }
    const us16 getTurnOverTime() const { return finishedTime - joinTime; }
    const float getWTurnoverTime() const { return wTurnoverTime; }

    /* setter */
    void addRunTime() { ++runTime; }
    void subNeedTime() { --needTime; }
    void setStartTime(const us16 _startTime) { startTime = _startTime; }
    void exec() { addRunTime(); subNeedTime(); }
    void setTurnoverTime() { turnoverTime = finishedTime - joinTime; }
    void setWTurnoverTime() { wTurnoverTime  = turnoverTime / lastTime; }
    void setTurnoverTime(const us16 _turnoverTime) { turnoverTime = _turnoverTime; }
    void setWTurnoverTime(const float _wTurnoverTime) { wTurnoverTime  = _wTurnoverTime; }
    void setJobID(const us16 _jobID) { jobID = _jobID; }
    void setJobName(const std::string& _jobName) { jobName = _jobName; }
    void setJoinTime(const us16 _joinTime) { joinTime = _joinTime; }
    void setLastTime(const us16 _lastTime) { lastTime = _lastTime; }
    void setRunTime(const us16 _runTime) { runTime = _runTime; }
    void setNeedTime(const us16 _needTime) { needTime = _needTime; }
    void setDeadLine(const us16 _deadLine) { deadLine = _deadLine; }
    void setFinishedTime(const us16 _finishedTime) { finishedTime = _finishedTime; }
    void setPrioOrSlice(const us16 _PrioOrSlice) { PrioOrSlice = _PrioOrSlice; }

    bool compareRule(const Job *l, const Job *r) {
        return l->getLastTime() < r->getLastTime();
    }

    bool operator ()(const Job *l, const Job *r) {
        return l->getLastTime() < r->getLastTime();
    }

    bool operator <(const Job* l){
        return lastTime < l->lastTime;
    }

    bool operator <(const ptr l){
        return lastTime < l->lastTime;
    }

    bool operator()(const ptr l, const ptr r){
        return l->getLastTime() < r->getLastTime();
    }
};

#endif // JOB_H
