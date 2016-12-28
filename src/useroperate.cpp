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
}
