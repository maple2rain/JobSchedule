#ifndef USEROPERATE_H
#define USEROPERATE_H

#include "ConnectionPool.h"
#include "info.h"
#include "graph.h"
#include "gif.h"
#include "job.h"
#include <vector>
#include <string>
#include <memory>
#include <list>

class UserOperate
{
private:
    UserOperate(UserOperate&);
    UserOperate operator=(UserOperate&);
public:
    typedef std::shared_ptr<Job> ptr; //smart pointer
    UserOperate() {}
    UserOperate(const std::string &_username, const std::string &_passwd) :
        username(_username), passwd(_passwd) {
        hasGif = hasGraph = false;
    }
    ~UserOperate() {}

    /* sql operate */
    // user operate
    const Info GetUserID(const std::string &username);
    const Info GetUserID();
    const Info AddUser(const std::string &username, const std::string &passwd);
    const Info AddUser();
    const Info UpdateUser(const std::string &username, const std::string &passwd, us16 uid);
    const Info UpdateUser();
    const Info CheckUser(const std::string &username, const std::string &passwd);
    const Info CheckUser();

    // graph operate
    const Info InsertGraph(Graph &graph);
    const Info InsertGraph();
    const Info UserAddGraph(us16 uid, std::string &graphID);
    const Info UserAddGraph();
    const Info GetUserGraph();

    // gif operate
    const Info InsertGif(Gif& gif);
    const Info InsertGif();
    const Info UserAddGif(us16 uid, us16 gifID);
    const Info UserAddGif();
    const Info GetUserGif();
    const Info GetGifID();

    // job operate, type mean failed or finished job
    const Info InsertJobs(us16 uid, std::list<ptr> &jobs);
    const Info InsertJobs(std::list<ptr> &jobs, const char *type);
    const Info UserAddJobs(std::list<ptr> &jobs, std::string &type);
    const Info DeleteJobs(us16 uid, const std::vector<us16> &jobIDVec);
    const Info DeleteJobs(const std::vector<us16> &jobIDVec);
    const Info GetJobs(us16 uid, std::list<ptr> &jobs, const char *type);
    const Info GetJobs(const std::string &type);
    const Info GetJob();
    const Info GetMaxJobId();

    void getAllInfoFromDB();

    /* setter */
    void setUserName(const std::string &_username) { username = _username; }
    void setPassword(const std::string &_passwd) { passwd = _passwd; }
    void setUserID(const us16 _uid) { uid = _uid; }
    void setGraph(const Graph &_graph) { graph = _graph; }
    void setGif(const Gif &_gif) { gif = _gif; }
    void setHasGraph() { hasGraph = true; }
    void setHasGif() { hasGif = true; }
    void setMaxJobId(us16 _jobMaxId) { jobMaxId = _jobMaxId; }
    void clearJobs() { failedJobs.clear(); finishedJobs.clear(); }

    /* getter */
    const std::string &getUserName() { return username; }
    const std::string &getPassword() { return passwd; }
    const us16 getUserID() { return uid; }
    Graph& getGraph() { return graph; }
    Gif& getGif() { return gif; }
    bool isHasGraph() { return hasGraph; }
    bool isHasGif() { return hasGif; }
    us16 getMaxJobId() { return ++jobMaxId; }
    const std::list<ptr>& getFailedJobs() const { return failedJobs; }
    const std::list<ptr>& getFinishedJobs() const { return finishedJobs; }

private:
    us16 uid;                   //user ID
    us16 jobMaxId;              //the max job ID of user that user own since it sing up
    std::string username;       //user name
    std::string passwd;         //user password
    Graph graph;                //the graph belong to user
    Gif gif;                    //the gif belong to user which will show when jobs are running
    bool hasGraph;              //check if user has graph
    bool hasGif;                //check if user has gif
    std::list<ptr> finishedJobs;//list to store finished jobs
    std::list<ptr> failedJobs;  //list to store failed jobs
};


#endif // USEROPERATE_H
