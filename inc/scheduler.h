#pragma once
#include "job.h"
#include "jobrecorder.h"
#include "require.h"
#include "app_cfg.h"
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
    Scheduler() { scheduler = 0; DEBUG_PRINT("create scheduler"); }
public:
    typedef std::shared_ptr<Job> ptr; //smart pointer

    void schedule(us16 runtime, JobRecorder &jobRecorder);
    void checkWaitingJob(us16 runtime, JobRecorder &jobRecorder);
    virtual void schedule_NONE(us16 runtime, JobRecorder &jobRecorder) { DEBUG_PRINT("schedule_NONE"); }
    virtual void schedule_PM(us16 runtime, JobRecorder &jobRecorder) { DEBUG_PRINT("schedule_PM"); }
    virtual void schedule_PSA(us16 runtime, JobRecorder &jobRecorder) { DEBUG_PRINT("schedule_PSA"); }
    virtual void schedule_PM_PSA(us16 runtime, JobRecorder &jobRecorder) { DEBUG_PRINT("schedule_PM_PSA"); }

    ptr &selectFirstJob() { return readyJobs.front(); }	//select the job to run, which is in the front of the readyJobs list
    ptr &selectNextJob();   //return next job, require detect the size of job-list by user

    void clearJob(std::list<ptr> &jobs) {
        jobs.clear();
        DEBUG_PRINT("clear all the readyJobs");
    }	//clear all the readyJobs

    void eraseJob(std::list<ptr> &jobs) {
        jobs.pop_front();
        DEBUG_PRINT("remove the finished job");
    }	//remove the finished job

    std::list<ptr> &getReadyJobs() { return readyJobs; }
    std::list<ptr> &getWaitingJobs() { return waitingJobs; }

    //as time goes by, jobs status will change
    bool statusChange(std::list<ptr> &srcJobs, std::list<ptr> &dstJobs, std::list<ptr> &changeJobs, unsigned short runtime);
    bool isJobNone() { return readyJobs.empty() && waitingJobs.empty(); }
    void addWaitingJob(ptr &job); //add waiting job
    void addFinishedJob(ptr &jobs) { finishedJobs.push_back(jobs);  DEBUG_PRINT("add finished job" ); } //add finished job
    void addReadyJob(ptr &job) { readyJobs.push_back(job); DEBUG_PRINT("add ready job" ); }   //add ready job

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
    std::list<ptr> nextJobs;    //list to store next job, though there is only one next job
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

    FCFS() { DEBUG_PRINT("create FCFS scheduler"); } //private constructor, prevent to be instanced by other operation
    friend class Scheduler;
public:
    ~FCFS() {}
    void schedule_NONE(us16 runtime, JobRecorder &jobRecorder);
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


