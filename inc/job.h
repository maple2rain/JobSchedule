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

     const std::string& getJobName() { return jobName; }
     const us16 getJoinTime() { return joinTime; }
     const us16 getLastTime() { return lastTime; }
     const us16 getStartTime() { return startTime; }
     const us16 getRunTime() { return runTime; }
     const us16 getNeedTime() { return needTime; }
     const us16 getDeadLine() { return deadLine; }
     const us16 getPrioOrSlice() { return PrioOrSlice; }
     const bool IsFinished() { return isFinished; }

     void setRunTime(us16 _runTime) { runTime = _runTime; }
     void setNeedTime(us16 _needTime) { needTime = _needTime; }
     void setJobFinished() { isFinished = true; }
};

#endif // JOB_H
