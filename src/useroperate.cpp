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

const Info UserOperate::UpdateGraph(const std::string &username)
{
    QSqlDatabase con;
    Info info;
    con = ConnectionPool::openConnection();

    try{
//        QString imagePath = QFileDialog::getOpenFileName(this, tr("Open File"), "../JobsSchedule/image/graph", tr("Image (*.jpg, *.png)"));//打开文件路径，使用this为当前父窗口，“Open File”为对话框标题，“.”为默认目录，过滤器为“Text Files(*.txt)”
//        if(!imagePath.isEmpty()) {
//            QFile file(imagePath);

//            if (!file.open(QIODevice::ReadOnly)) {//以只读方式打开text文件
//                QMessageBox::warning(this, tr("Read File"), tr("Cannot open file:\n%1").arg(path));
//                return;
//            }

//            QByteArray data = file.readAll();
//            file.close();

//            std::string path = std::string((const char*)(imagePath.toLocal8Bit()));
//            std::string graphName;
//            getFileName(path, graphName);
//            std::string graphType;
//            getFileType(path, graphType);

//            QVariant graph(data);
//            QSqlQuery query(con);

//            /* check if username valid or if user exists */
//            query.prepare("Insert Into user (username, graphName, graph, graphType) Values(:username, :graphName, :graph, :graphType)");
//            query.bindValue(":username", username);
//            query.bindValue(":graphName", graphName);
//            query.bindValue(":graph", graph);
//            query.bindValue(":graphType", graphType);

//            if(query.exec()){
//                info.setStatus(true);
//                info.setInfo("Sign up success!");
//            }else{
//                info.setInfo("Sign up failed!");
//            }

//        } else {
//            QMessageBox::warning(this, tr("Path"), tr("You did not select any file."));
//        }
    }catch(QSqlError e){
        qDebug() << e;
    }

    ConnectionPool::closeConnection(con);
    return info;
}


const Info UserOperate::UpdateGraph()
{
    return UpdateGraph(username);
}


