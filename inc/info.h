#ifndef INFO_H
#define INFO_H

#include <string>

/* to record the info of sql operation */
class Info
{
public:
    Info(const std::string &msg = "failed", bool _status = false) :
        info(msg), status(_status){ }
    ~Info() {}

    /* setter */
    void setStatus(bool _status) { status = _status; }
    void setInfo(const std::string &_info) { info = _info; }

    /* getter */
    bool getStatus() { return status; }
    const std::string &getInfo() { return info; }
private:
    bool status;
    std::string info;
};

#endif // INFO_H
