#pragma once
#include "job.h"
#include "jobrecorder.h"
#include "require.h"
#include <list>
#include <stdexcept>
#include <memory>
#include <iostream>

class Scheduler {
    Scheduler* scheduler; //envelope

    //Prevent copy-construction & operator =
    Scheduler(Scheduler&);
    Scheduler operator=(Scheduler&);
protected:
    Scheduler() { scheduler = 0; std::cout << "create scheduler" << std::endl; }
public:
    typedef std::shared_ptr<Job> ptr; //smart pointer

    void schedule(us16 runtime, JobRecorder &jobRecorder);
    void checkWaitingJob(us16 runtime, JobRecorder &jobRecorder);
    virtual void schedule_NONE(us16 runtime, JobRecorder &jobRecorder) { std::cout << "schedule_NONE" << std::endl; }
    virtual void schedule_PM(us16 runtime, JobRecorder &jobRecorder) { std::cout << "schedule_PM" << std::endl; }
    virtual void schedule_PSA(us16 runtime, JobRecorder &jobRecorder) { std::cout << "schedule_PSA" << std::endl; }
    virtual void schedule_PM_PSA(us16 runtime, JobRecorder &jobRecorder) { std::cout << "schedule_PM_PSA" << std::endl; }

    ptr &selectFirstJob() { return readyJobs.front(); }	//select the job to run, which is in the front of the readyJobs list
    ptr &selectNextJob();   //return next job, require detect the size of job-list by user

    void clearJob(std::list<ptr> &jobs) {
        jobs.clear();
        std::cout << "clear all the readyJobs" << std::endl;
    }	//clear all the readyJobs

    void eraseJob(std::list<ptr> &jobs) {
        jobs.pop_front();
        std::cout << "remove the finished job" << std::endl;
    }	//remove the finished job

    std::list<ptr> &getReadyJobs() { return readyJobs; }
    std::list<ptr> &getWaitingJobs() { return waitingJobs; }

    //as time goes by, jobs status will change
    bool statusChange(std::list<ptr> &srcJobs, std::list<ptr> &dstJobs, std::list<ptr> &changeJobs, unsigned short runtime);

    void addWaitingJob(ptr &job); //add waiting job
    void addFinishedJob(ptr &jobs) { finishedJobs.push_back(jobs); }
    void addReadyJob(ptr &job) { readyJobs.push_back(job); std::cout << "add ready job" << std::endl; }   //add ready job
    void clearAllJob() { readyJobs.clear(); waitingJobs.clear(); }	//clear all the job
    void setFlag(bool isPSA = false, bool isPM = false) { flag = 0; flag |= isPSA; flag <<= 1; flag |= isPM; }

    virtual ~Scheduler () {
        if (scheduler) {
            scheduler->clearAllJob();
        }
    }

public:
    class  BadSchedulerCreation : public std::logic_error
    {
    public:
        BadSchedulerCreation(const std::string& type)
            : logic_error("cannot create type " + type) {}
    };
    Scheduler(const std::string& type) throw(BadSchedulerCreation); //factory method which throw error of undefined type

protected:
    std::list<ptr> waitingJobs;	//list to store jobs whose committing time is older than current time
    std::list<ptr> readyJobs;	//list to store ready jobs
    std::list<ptr> nextJobs;    //list to store next job, thougn there is only one next job
    std::list<ptr> finishedJobs;//list to store finished jobs

//what flag mean is that :
#define _NONE	0x00
#define _PM		0x01
#define _PSA	0x02
#define _PM_PSA 0x03
    unsigned char flag;
};

/* FCFS, inherit from Scheduler */
class FCFS : public Scheduler
{
    //Prevent copy-construction & operator =
    FCFS(FCFS&);
    FCFS operator=(FCFS&);

    FCFS() { std::cout << "create FCFS scheduler" << std::endl; } //private constructor, prevent to be instanced by other operation
    friend class Scheduler;
public:
    ~FCFS() {}
    void schedule_NONE(us16, JobRecorder &jobRecorder);
    void schedule_PSA(us16 runtime, JobRecorder &jobRecorder);
    void schedule_PM(us16 runtime, JobRecorder &jobRecorder);
    void schedule_PM_PSA(us16 runtime, JobRecorder &jobRecorder);
};

inline
Scheduler::Scheduler(const std::string &type) {
    if (type == "FCFS")
        scheduler = new FCFS;
    else    throw BadSchedulerCreation(type);
}

/* debug print define */
#define DEBUG_ON 1
#if DEBUG_ON
    #define DEBUG_PRINT(jobs, type) \
    do{ \
        std::cout << "join time is: ";\
        for(auto it = jobs##.begin(); it != jobs##.end(); ++it)\
            std::cout << (*it)->get##type##() << " ";\
        std::cout << std::endl;  \
    }while(0)
#else
    #define DEBUG_PRINT(jobs, type) do{}while(0)
#endif
