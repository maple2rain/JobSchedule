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
    const Info AddUser(const std::string &username, const std::string &passwd);
    const Info CheckUser(const std::string &username, const std::string &passwd);
    const Info CheckUser();
    const Info UpdateGraph(Graph &graph);
    const Info UpdateGif(Gif& gif);


    /* setter */
    void setUserName(const std::string &_username) { username = _username; }
    void setPassword(const std::string &_passwd) { passwd = _passwd; }

    /* getter */
    const std::string &getUserName() { return username; }
    const std::string &getPassword() { return passwd; }

private:
    std::string username;
    std::string passwd;
};


#endif // USEROPERATE_H
