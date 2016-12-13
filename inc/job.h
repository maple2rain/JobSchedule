#ifndef JOB_H
#define JOB_H
#include <string>

/* The Attribute of jobs */
class Job
{
    std::string         jobName;
    unsigned short commitTime;
    unsigned short lastTime;
    unsigned short startTime;
    unsigned short runTime;
    unsigned short needTime;
    unsigned short PrioOrSlice;
    bool           isFinished;

    //Prevent copy-construction & operator =
    Job(Job&);
    Job operator=(Job&);
public:
    Job(const std::string &name,
        unsigned short _commitTime,
        unsigned short _lastTime,
        unsigned short _PrioOrSlice = 0)
        : jobName(name),
          commitTime(_commitTime),
          lastTime(_lastTime),
          PrioOrSlice(_PrioOrSlice)
    {
        startTime = 0;
        needTime = _lastTime;
        runTime = 0;
        isFinished = false;
    }

     const std::string& getJobName() { return jobName; }
     const unsigned short getCommitTime() { return commitTime; }
     const unsigned short getLastTime() { return lastTime; }
     const unsigned short getStartTime() { return startTime; }
     const unsigned short getRunTime() { return runTime; }
     const unsigned short getNeedTime() { return needTime; }
     const unsigned short getPrioOrSlice() { return PrioOrSlice; }
     const bool IsFinished() { return isFinished; }

     void setRunTime(unsigned short _runTime) { runTime = _runTime; }
     void setNeedTime(unsigned short _needTime) { needTime = _needTime; }
     void setJobFinished() { isFinished = true; }
};

#endif // JOB_H
