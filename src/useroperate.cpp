#include "../inc/useroperate.h"
#include <QDebug>
#include <QDate>
#include <QFileDialog>
#include <QMessageBox>
#include <string>

const Info UserOperate::GetUserID(const std::string &username)
{
    QSqlDatabase con;
    Info info;
    con = ConnectionPool::openConnection();
    
    try{
        QSqlQuery query(con);
        
        /* select user id */
        query.prepare("Select userID From user Where username = (:username)");
        query.bindValue(":username", username.c_str());
        
        if(query.exec()){
            if(query.next()){
                info.setStatus(true);
                setUserID(query.value("userID").toUInt());
                info.setInfo("Get UserID!");
            }else{
                info.setInfo("There is not such user whose username is " + username + "!");
            }
        }else{
            qDebug() << query.lastError();
            info.setInfo("Get UserID Failed!");
        }
    }catch(QSqlError e){
        qDebug() << e;
    }
    
    qDebug() << info.getInfo().c_str();
    
    ConnectionPool::closeConnection(con);
    return info;
}

const Info UserOperate::GetUserID()
{
    return GetUserID(username);
}

const Info UserOperate::AddUser(const std::string &username, const std::string &passwd)
{
    QSqlDatabase con;
    Info info;
    con = ConnectionPool::openConnection();
    
    try{
        QSqlQuery query(con);
        
        /* check if it is on black list */
        query.prepare("Select * From blacklist Where username = (:username) Limit 1");
        query.bindValue(":username", username.c_str());
        if(query.exec()){
            if(query.next()){
                info.setInfo("The user is on blacklist");
            }else{
                /* check if it it exists yet */
                query.prepare("Select * From user Where username = (:username) Limit 1");
                query.bindValue(":username", username.c_str());
                
                if(query.exec()){
                    if(query.next()){
                        info.setInfo("The user does exist!");
                    }
                    else{
                        /* insert new user */
                        query.prepare("Insert Into user (username, passwd, signupdate) Values(:username, :passwd, :signupdate)");
                        QDate date = QDate::currentDate();
                        query.bindValue(":username", username.c_str());
                        query.bindValue(":passwd", passwd.c_str());
                        query.bindValue(":signupdate", date.toString("yyyy-MM-dd")); //only work when it is "yyyy-MM-dd"
                        
                        if(query.exec()){
                            info.setStatus(true);
                            info.setInfo("Sign up success!");
                        }else{
                            qDebug() << query.lastError();
                            info.setInfo("Sign up failed!");
                        }
                    }
                }
            }
        }
    }catch(QSqlError e){
        qDebug() << e;
    }
    
    qDebug() << info.getInfo().c_str();
    
    ConnectionPool::closeConnection(con);
    return info;
}

const Info UserOperate::AddUser()
{
    return AddUser(username, passwd);
}

const Info UserOperate::UpdateUser(const std::string &username, const std::string &passwd, us16 uid)
{
    QSqlDatabase con;
    Info info;
    con = ConnectionPool::openConnection();
    
    try{
        QSqlQuery query(con);
        
        /* update user info */
        query.prepare("Update user Set username = ?, passwd = ? Where userID = ?");
        query.bindValue(0, username.c_str());
        query.bindValue(1, passwd.c_str());
        query.bindValue(2, uid);
        
        if(query.exec()){
            info.setStatus(true);
            info.setInfo("Modify success!");
        }else{
            qDebug() << query.lastError();
            info.setInfo("Modify failed!\n"
                         "Duplicate username!");
        }
    }catch(QSqlError e){
        qDebug() << e;
    }
    
    qDebug() << info.getInfo().c_str();
    
    ConnectionPool::closeConnection(con);
    return info;
}

const Info UserOperate::UpdateUser()
{
    return UpdateUser(username, passwd, uid);
}

const Info UserOperate::CheckUser(const std::string &username, const std::string &passwd)
{
    QSqlDatabase con;
    Info info;
    con = ConnectionPool::openConnection();
    
    try{
        QSqlQuery query(con);
        
        /* check if username valid or if user exists */
        query.prepare("Select username, passwd From user Where username = (:username) Limit 1");
        query.bindValue(":username", username.c_str());
        
        if(query.exec()){
            if(query.next()){
                std::string _passwd = std::string((const char*)query.value("passwd").toString().toLocal8Bit());
                if(passwd.compare(_passwd) == 0){
                    info.setStatus(true);
                    info.setInfo("Sign in success!");
                }else{
                    info.setInfo("Sign in failed!\n"
                                 "Password is not correct!");
                }
            }else{
                qDebug() << query.lastError();
                info.setInfo("The user does not exist!");
            }
        }
    }catch(QSqlError e){
        qDebug() << e;
    }
    
    ConnectionPool::closeConnection(con);
    return info;
}

const Info UserOperate::CheckUser()
{
    return CheckUser(username, passwd);
}

const Info UserOperate::InsertGraph(Graph &graph)
{
    QSqlDatabase con;
    Info info;
    con = ConnectionPool::openConnection();
    
    try{
        QSqlQuery query(con);
        QVariant var(graph.getGraph());
        
        /* Insert */
        query.prepare("Insert Into graph (graphID, graph, graphType) Values(:graphID, :graph, :graphType)");
        query.bindValue(":graphID", graph.getGraphID().c_str());
        query.bindValue(":graph", var);
        query.bindValue(":graphType", graph.getGraphType().c_str());
        
        if(query.exec()){
            info.setStatus(true);
            info.setInfo("Insert graph success!");
        }else{
            qDebug() << query.lastError();
            info.setInfo("Insert graph failed!");
        }
    }catch(QSqlError e){
        qDebug() << e;
    }
    
    ConnectionPool::closeConnection(con);
    return info;
}

const Info UserOperate::InsertGraph()
{
    return InsertGraph(graph);
}

const Info UserOperate::UserAddGraph(us16 uid, std::string& graphID)
{
    QSqlDatabase con;
    Info info;
    con = ConnectionPool::openConnection();
    
    try{
        QSqlQuery query(con);
        
        /* Insert */
        query.prepare("Insert Into user_graph (userID, graphID) Values(:userID, :graphID) "
                      "On Duplicate Key Update graphID = (:graphID)");
        query.bindValue(":userID", uid);
        query.bindValue(":graphID", graphID.c_str());
        
        if(query.exec()){
            info.setStatus(true);
            setHasGraph();
            info.setInfo("Insert user_graph success!");
        }else{
            qDebug() << query.lastError();
            info.setInfo("Insert user_graph failed!");
        }
    }catch(QSqlError e){
        qDebug() << e;
    }
    
    ConnectionPool::closeConnection(con);
    return info;
}

const Info UserOperate::UserAddGraph()
{
    return UserAddGraph(uid, graph.getGraphID());
}

const Info UserOperate::InsertGif(Gif& gif)
{
    QSqlDatabase con;
    Info info;
    con = ConnectionPool::openConnection();
    
    try{
        QSqlQuery query(con);
        
        /* Insert */
        query.prepare("Insert Into gif (gifName) Values(:gifName)");
        query.bindValue(":gifName", gif.getGifName().c_str());
        
        if(query.exec()){
            info.setStatus(true);
            info.setInfo("Insert gif success!");
        }else{
            qDebug() << query.lastError();
            info.setInfo("Insert gif failed!");
        }
    }catch(QSqlError e){
        qDebug() << e;
    }
    
    ConnectionPool::closeConnection(con);
    return info;
}

const Info UserOperate::InsertGif()
{
    return InsertGif(gif);
}

const Info UserOperate::GetGifID()
{
    QSqlDatabase con;
    Info info;
    con = ConnectionPool::openConnection();
    
    try{
        QSqlQuery query(con);
        
        /* get gif ID */
        query.prepare("Select gifID From gif where gifName = (:gifName)");
        query.bindValue(":gifName", gif.getGifName().c_str());
        
        if(query.exec()){
            if(query.next()){
                info.setStatus(true);
                gif.setGifID(query.value("gifID").toUInt());
                info.setInfo("Get gifID success!");
            }else{
                qDebug() << query.lastError();
                info.setInfo("Get gifID failed!");
            }
        }else{
            qDebug() << query.lastError();
            info.setInfo("Query error!");
        }
    }catch(QSqlError e){
        qDebug() << e;
    }
    
    ConnectionPool::closeConnection(con);
    return info;
}

const Info UserOperate::UserAddGif(us16 uid, us16 gifID)
{
    QSqlDatabase con;
    Info info;
    con = ConnectionPool::openConnection();
    
    try{
        QSqlQuery query(con);
        
        /* Insert */
        query.prepare("Insert Into user_gif (userID, gifID) Values(:userID, :gifID) "
                      "On Duplicate Key Update gifID = (:gifID)");
        query.bindValue(":userID", uid);
        query.bindValue(":gifID", gifID);
        
        if(query.exec()){
            info.setStatus(true);
            setHasGif();
            info.setInfo("Insert user_gif success!");
        }else{
            qDebug() << query.lastError();
            info.setInfo("Insert user_gif failed!");
        }
    }catch(QSqlError e){
        qDebug() << e;
    }
    
    ConnectionPool::closeConnection(con);
    return info;
}

const Info UserOperate::UserAddGif()
{
    GetGifID();
    return UserAddGif(uid, gif.getGifID());
}

const Info UserOperate::GetUserGraph()
{
    QSqlDatabase con;
    Info info;
    con = ConnectionPool::openConnection();
    
    try{
        QSqlQuery query(con);
        
        /* Insert */
        query.prepare("Select graph.graphID, graphType, graph From graph, user_graph "
                      "Where graph.graphID = user_graph.graphID and user_graph.userID = (:userID) Limit 1");
        query.bindValue(":userID", uid);
        if(query.exec()){
            if(query.next()){
                /* set info */
                graph.setGraphID(std::string((const char*)(query.value("graphID").toString().toLocal8Bit())));
                graph.setGraphType(std::string((const char*)(query.value("graphType").toString().toLocal8Bit())));
                graph.setGraph(query.value("graph").toByteArray());
                info.setStatus(true);
                setHasGraph();
                info.setInfo("Get user_graph success!");
                qDebug() << "Get user_graph success!";
            }else{
                info.setInfo("User doesn't has graph!");
                qDebug() << "User doesn't has graph!";
            }
        }else{
            qDebug() << query.lastError();
            info.setInfo("Get user_graph failed!");
        }
    }catch(QSqlError e){
        qDebug() << e;
    }
    
    ConnectionPool::closeConnection(con);
    return info;
}

const Info UserOperate::GetUserGif()
{
    QSqlDatabase con;
    Info info;
    con = ConnectionPool::openConnection();
    
    try{
        QSqlQuery query(con);
        
        /* Insert */
        query.prepare("Select gif.gifID, gifName From gif, user_gif "
                      "Where gif.gifID = user_gif.gifID and user_gif.userID = (:userID) Limit 1");
        query.bindValue(":userID", uid);
        if(query.exec()){
            if(query.next()){
                /* set info */
                gif.setGifID(query.value("gifID").toUInt());
                gif.setGifName(std::string((const char*)(query.value("gifName").toString().toLocal8Bit())));
                info.setStatus(true);
                setHasGif();
                qDebug() << "Get user_gif success!";
                info.setInfo("Get user_gif success!");
            }else{
                info.setInfo("User doesn't has gif!");
                qDebug() << "User doesn't has gif!";
            }
        }else{
            qDebug() << query.lastError();
            info.setInfo("Get user_gif failed!");
        }
    }catch(QSqlError e){
        qDebug() << e;
    }
    
    ConnectionPool::closeConnection(con);
    return info;
}


void UserOperate::getAllInfoFromDB()
{
    GetUserID();
    GetUserGraph();
    GetUserGif();
    GetMaxJobId();
}

const Info UserOperate::GetMaxJobId()
{
    QSqlDatabase con;
    Info info;
    con = ConnectionPool::openConnection();
    
    try{
        QSqlQuery query(con);
        
        /* get max Job ID */
        query.prepare("Select Max(jobID) From job where userID = (:userID)");
        query.bindValue(":userID", uid);
        
        if(query.exec()){
            if(query.next()){
                info.setStatus(true);
                setMaxJobId(query.value("Max(jobID)").toUInt());
                info.setInfo("Get job Max Id success!");
            }else{
                setMaxJobId(0);//if has no job, that the max id is 0
                qDebug() << query.lastError();
                info.setInfo("Get job Max Id failed!");
            }
        }else{
            qDebug() << query.lastError();
            info.setInfo("Query error!");
        }
    }catch(QSqlError e){
        qDebug() << e;
    }
    
    ConnectionPool::closeConnection(con);
    return info;
}

const Info UserOperate::InsertJobs(us16 uid, std::list<ptr> &jobs)
{
    Info info;
    if(jobs.empty())
        return info;
    
    QSqlDatabase con;
    con = ConnectionPool::openConnection();
    
    try{
        QSqlQuery query(con);
        
        /* Insert */
        query.prepare("Insert Into job "
                      "(jobID, userID, jobName, joinTime, lastTime, startTime, runTime, "
                      "needTime, deadline, PrioOrSlice, turnoverTime, weightTurnoverTime, finishedTime)"
                      "Values("
                      ":jobID, :userID, :jobName, :joinTime, :lastTime, :startTime, :runTime, "
                      ":needTime, :deadline, :PrioOrSlice, :turnoverTime, :weightTurnoverTime, :finishedTime)");
        QVariantList jobIDs, userIDs, jobNames, joinTimes, lastTimes, startTimes, runTimes, needTimes,
                deadlines, PrioOrSlices, turnoverTimes, weightTurnoverTime, finishedTimes;
        
        /* bind value */
        for(auto it = jobs.begin(); it != jobs.end(); ++it){
            (*it)->setJobID(getMaxJobId());
            jobIDs << (*it)->getJobID();
            userIDs << uid;
            jobNames << (*it)->getJobName().c_str();
            joinTimes << (*it)->getJoinTime();
            lastTimes << (*it)->getLastTime();
            startTimes << (*it)->getStartTime();
            runTimes << (*it)->getRunTime();
            needTimes << (*it)->getNeedTime();
            deadlines << (*it)->getDeadLine();
            PrioOrSlices << (*it)->getPrioOrSlice();
            turnoverTimes << (*it)->getTurnOverTime();
            weightTurnoverTime << (*it)->getWTurnoverTime();
            finishedTimes << (*it)->getFinishedTime();
        }
        query.bindValue(":jobID", jobIDs);
        query.bindValue(":userID", userIDs);
        query.bindValue(":jobName", jobNames);
        query.bindValue(":joinTime", joinTimes);
        query.bindValue(":lastTime", lastTimes);
        query.bindValue(":startTime", startTimes);
        query.bindValue(":runTime", runTimes);
        query.bindValue(":needTime", needTimes);
        query.bindValue(":deadline", deadlines);
        query.bindValue(":PrioOrSlice", PrioOrSlices);
        query.bindValue(":turnoverTime", turnoverTimes);
        query.bindValue(":weightTurnoverTime", weightTurnoverTime);
        query.bindValue(":finishedTime", finishedTimes);
        
        if(query.execBatch()){
            info.setStatus(true);
            info.setInfo("Insert jobs success!");
        }else{
            qDebug() << query.lastError();
            info.setInfo("Insert jobs failed!");
        }
    }catch(QSqlError e){
        qDebug() << e;
    }
    
    ConnectionPool::closeConnection(con);
    return info;
}

const Info UserOperate::InsertJobs(std::list<ptr> &jobs, const char *type)
{
    Info info;
    if(jobs.empty())
        return info;
    
    info = InsertJobs(uid, jobs);
    if(info.getStatus() == false){
        return info;
    }
    
    info.setStatus(false);
    
    QSqlDatabase con;
    con = ConnectionPool::openConnection();
    
    try{
        QSqlQuery query(con);
        
        /* Insert */
        query.prepare("Insert Into job" + QString(type) +
                      " (jobID, userID)"
                      " Values(:jobID, :userID)");
        QVariantList jobIDs, userIDs;
        
        /* bind value */
        for(auto it = jobs.begin(); it != jobs.end(); ++it){
            jobIDs << (*it)->getJobID();
            userIDs << uid;
        }
        query.bindValue(":jobID", jobIDs);
        query.bindValue(":userID", userIDs);
        
        if(query.execBatch()){
            info.setStatus(true);
            info.setInfo("Insert jobs success!");
        }else{
            qDebug() << query.lastError();
            info.setInfo("Insert jobs failed!");
        }
    }catch(QSqlError e){
        qDebug() << e;
    }
    
    ConnectionPool::closeConnection(con);
    return info;
}

const Info UserOperate::DeleteJobs(us16 uid, const std::vector<us16> &jobIDVec)
{
    Info info;
    if(jobIDVec.empty())
        return info;

    QSqlDatabase con;
    con = ConnectionPool::openConnection();

    try{
        QSqlQuery query(con);

        /* Delete */
        query.prepare("Delete From job Where jobID = (:jobID) and userID = (:userID)");
        QVariantList jobIDs, userIDs;

        /* bind value */
        for(auto it = jobIDVec.begin(); it != jobIDVec.end(); ++it){
            jobIDs << *it;
            userIDs << uid;
        }
        query.bindValue(":jobID", jobIDs);
        query.bindValue(":userID", userIDs);

        if(query.execBatch()){
            info.setStatus(true);
            info.setInfo("Insert jobs success!");
        }else{
            qDebug() << query.lastError();
            info.setInfo("Insert jobs failed!");
        }
    }catch(QSqlError e){
        qDebug() << e;
    }

    ConnectionPool::closeConnection(con);
    return info;
}

const Info UserOperate::DeleteJobs(const std::vector<us16> &jobIDVec)
{
    return DeleteJobs(uid, jobIDVec);
}

const Info UserOperate::GetJobs(us16 uid, std::list<ptr> &jobs, const char *type)
{
    QSqlDatabase con;
    Info info;
    con = ConnectionPool::openConnection();
    
    try{
        QSqlQuery query(con);
        
        /* get max Job ID */
        query.prepare("select * "
                      //                    "Select job.jobID, jobName, joinTime, lastTime, startTime, runTime, "
                      //                    "needTime, deadline, PrioOrSlice, turnoverTime, weightTurnoverTime, finishedTime "
                      "From job Left Outer Join job" + QString(type) + " "
                                                                       "Using (userID, jobID) "
                                                                       "where userID = (:userID) and job.jobID = job" + QString(type) + ".jobID");
        query.bindValue(":userID", uid);
        
        if(query.exec()){
            while(query.next()){
                ptr job = std::make_shared<Job>();
                job->setDeadLine(query.value("deadline").toUInt());
                job->setFinishedTime(query.value("finishedTime").toUInt());
                job->setJobID(query.value("jobID").toUInt());
                job->setJobName(std::string((const char*)(query.value("jobName").toString().toLocal8Bit())));
                job->setJoinTime(query.value("joinTime").toUInt());
                job->setLastTime(query.value("lastTime").toUInt());
                job->setNeedTime(query.value("needTime").toUInt());
                job->setPrioOrSlice(query.value("PrioOrSlice").toUInt());
                job->setRunTime(query.value("runTime").toUInt());
                job->setStartTime(query.value("startTime").toUInt());
                job->setTurnoverTime(query.value("turnoverTime").toUInt());
                job->setWTurnoverTime(query.value("weightTurnoverTime").toFloat());
                
                jobs.push_back(job);
            }
            info.setStatus(true);
            info.setInfo("Get job success!");
        }else{
            qDebug() << query.lastError();
            info.setInfo("Query error!");
        }
    }catch(QSqlError e){
        qDebug() << e;
    }
    
    ConnectionPool::closeConnection(con);
    return info;
}

const Info UserOperate::GetJobs(const std::string &type)
{
    if(type.compare("finished") == 0){
        return GetJobs(uid, finishedJobs, "finished");
    }else if(type.compare("failed") == 0){
        return GetJobs(uid, failedJobs, "failed");
    }else{
        qDebug() << "type error, there is not type of " << type.c_str();
    }
}

const Info UserOperate::GetJob()
{
    clearJobs();
    
    Info info;
    info = GetJobs("finished");
    if(info.getStatus() == false)
        return info;
    
    return GetJobs("failed");
}
