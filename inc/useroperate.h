#ifndef USEROPERATE_H
#define USEROPERATE_H

#include "ConnectionPool.h"
#include "info.h"
#include "graph.h"
#include "gif.h"
#include <string>

class UserOperate
{
private:
    UserOperate(UserOperate&);
    UserOperate operator=(UserOperate&);
public:
    UserOperate() {}
    UserOperate(const std::string &_username, const std::string &_passwd) :
        username(_username), passwd(_passwd) {}
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

    void getAllInfoFromDB();

    /* setter */
    void setUserName(const std::string &_username) { username = _username; }
    void setPassword(const std::string &_passwd) { passwd = _passwd; }
    void setUserID(const us16 _uid) { uid = _uid; }
    void setGraph(const Graph &_graph) { graph = _graph; }
    void setGif(const Gif &_gif) { gif = _gif; }

    /* getter */
    const std::string &getUserName() { return username; }
    const std::string &getPassword() { return passwd; }
    const us16 getUserID() { return uid; }
    const Graph& getGraph() { return graph; }
    const Gif& getGif() { return gif; }

private:
    us16 uid;
    std::string username;
    std::string passwd;
    Graph graph;
    Gif gif;
};


#endif // USEROPERATE_H
