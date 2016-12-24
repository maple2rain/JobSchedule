#include "../inc/useroperate.h"
#include <QDebug>
#include <QDate>
#include <QFileDialog>
#include <QMessageBox>
#include <string>

const Info UserOperate::AddUser(const std::string &username, const std::string &passwd)
{
    QSqlDatabase con;
    Info info;
    con = ConnectionPool::openConnection();

    try{
        QSqlQuery query(con);

        /* check if it is on black list */
        query.prepare("Select * from blacklist where username = (:username) limit 1");
        query.bindValue(":username", username.c_str());
        if(query.exec()){
            if(query.next()){
                info.setInfo("The user is on blacklist");
            }else{
                /* check if it it exists yet */
                query.prepare("Select * from user where username = (:username) limit 1");
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

const Info UserOperate::CheckUser(const std::string &username, const std::string &passwd)
{
    QSqlDatabase con;
    Info info;
    con = ConnectionPool::openConnection();

    try{
        QSqlQuery query(con);

        /* check if username valid or if user exists */
        query.prepare("Select username, passwd from user where username = (:username) limit 1");
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

void getFileName(const std::string &path, std::string &filename)
{
    std::string::size_type pos;
    pos = path.rfind("/");

    if(std::string::npos == pos){
        filename = path;
    }else{
        filename = path.substr(pos);
    }
}

void getFileType(const std::string &path, std::string &filetype)
{
    std::string::size_type pos;
    pos = path.rfind(".");

    if(std::string::npos == pos){
        filetype = "";
    }else{
        filetype = path.substr(pos);
    }
}

const Info UserOperate::UpdateGraph(Graph &graph)
{
    QSqlDatabase con;
    Info info;
    con = ConnectionPool::openConnection();

    try{
        QSqlQuery query(con);
        QVariant var(graph.getGraph());

        /* Insert */
        query.prepare("Insert Into user (username, graphName, graph, graphType) Values(:username, :graphName, :graph, :graphType)");
        query.bindValue(":username", graph.getUsername().c_str());
        query.bindValue(":graphName", graph.getGraphName().c_str());
        query.bindValue(":graph", var);
        query.bindValue(":graphType", graph.getGraphType().c_str());

        if(query.exec()){
            info.setStatus(true);
            info.setInfo("Update graph success!");
        }else{
            info.setInfo("Update graph failed!");
        }
    }catch(QSqlError e){
        qDebug() << e;
    }

    ConnectionPool::closeConnection(con);
    return info;
}

const Info UpdateGif(Gif& gif)
{
    QSqlDatabase con;
    Info info;
    con = ConnectionPool::openConnection();

    try{
        QSqlQuery query(con);

        /* Insert */
        query.prepare("Insert Into user (username, gifName) Values(:username, :gifName)");
        query.bindValue(":username", gif.getUsername().c_str());
        query.bindValue(":gifName", gif.getGifName().c_str());

        if(query.exec()){
            info.setStatus(true);
            info.setInfo("Update gif success!");
        }else{
            info.setInfo("Update gif failed!");
        }
    }catch(QSqlError e){
        qDebug() << e;
    }

    ConnectionPool::closeConnection(con);
    return info;
}
