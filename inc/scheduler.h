#pragma once
#include "job.h"
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
    void schedule();
    virtual void schedule_NONE() { std::cout << "schedule_NONE" << std::endl; }
    virtual void schedule_PM() { std::cout << "schedule_PM" << std::endl; }
    virtual void schedule_PSA() { std::cout << "schedule_PSA" << std::endl; }
    virtual void schedule_PM_PSA() { std::cout << "schedule_PM_PSA" << std::endl; }

    ptr selectFirstJob() { return readyJobs.front(); }	//select the job to run, which is in the front of the readyJobs list
    void clearJob(std::list<ptr> &jobs) { jobs.clear(); std::cout << "clear all the readyJobs" << std::endl; }		//clear all the readyJobs
    void eraseJob(std::list<ptr> &jobs) { jobs.pop_front(); std::cout << "remove the finished job" << std::endl; }	//remove the finished job

    void addJob(std::list<ptr> &jobs, ptr &job) {
        jobs.push_back(job);
        std::cout << "add a new job" << std::endl;
    }	//add a new job
    void addWaitingJob(ptr &job) {
        addJob(waitingJobs, job);
        std::cout << "add waiting job" << std::endl;
    }   //add waiting job

    void addReadyJob(ptr &job) { addJob(readyJobs, job); std::cout << "add ready job" << std::endl; }   //add ready job
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
    std::list<ptr> readyJobs;	//list to store ready jobs
    std::list<ptr> waitingJobs;	//list to store jobs whose committing time is older than current time

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
    void schedule_NONE();
    void schedule_PSA();
    void schedule_PM();
    void schedule_PM_PSA();
};
