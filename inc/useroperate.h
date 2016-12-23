#ifndef USEROPERATE_H
#define USEROPERATE_H

#include "ConnectionPool.h"

class UserOperate
{
private:
    UserOperate(UserOperate&);
    UserOperate operator=(UserOperate&);
public:
    UserOperate() {}
    ~UserOperate() {}

    bool AddUser(const std::string &username, const std::string &passwd);

};


#endif // USEROPERATE_H
