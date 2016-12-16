#ifndef JOB_H
#define JOB_H
#include <string>

typedef unsigned short us16;
/* The Attribute of jobs */
class Job
{
    std::string    jobName;
    us16 joinTime;
    us16 lastTime;
    us16 startTime;
    us16 runTime;
    us16 needTime;
    us16 deadLine;
    us16 PrioOrSlice;
    bool           isFinished;

    //Prevent copy-construction & operator =
    Job(Job&);
    Job operator=(Job&);
public:
    Job(const std::string &name,
        us16 _joinTime,
        us16 _lastTime,
        us16 _deadLine,
        us16 _PrioOrSlice = 0)
        : jobName(name),
          joinTime(_joinTime),
          lastTime(_lastTime),
          deadLine(_deadLine),
          PrioOrSlice(_PrioOrSlice)
    {
        startTime = 0;
        needTime = _lastTime;
        runTime = 0;
        isFinished = false;
    }

    /* getter */
    const std::string& getJobName() const { return jobName; }
    const us16 getJoinTime() const { return joinTime; }
    const us16 getLastTime() const { return lastTime; }
    const us16 getStartTime() const { return startTime; }
    const us16 getRunTime() const { return runTime; }
    const us16 getNeedTime() const { return needTime; }
    const us16 getDeadLine() const { return deadLine; }
    const us16 getPrioOrSlice() const { return PrioOrSlice; }
    const bool IsFinished() const { return isFinished; }

    /* setter */
    void addRunTime() { ++runTime; }
    void subNeedTime() { --needTime; }
    void exec() { addRunTime(); subNeedTime(); }
    void setJobFinished() { isFinished = true; }
};

#endif // JOB_H
