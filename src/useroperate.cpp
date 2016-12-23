#include "../inc/useroperate.h"
#include <QDebug>
#include <QDate>
#include <string>

bool UserOperate::AddUser(const std::string &username, const std::string &passwd)
{
    QSqlDatabase con;
    bool status = false;
    con = ConnectionPool::openConnection();

    try{
        QSqlQuery query;

        /* check if it is on black list */
        query.prepare("Select * from blacklist where username = (:username) limit 1");
        query.bindValue(":username", username.c_str());
        if(query.exec()){
            if(query.next()){
                qDebug() << "user is on blacklist";
                status = false;
            }else{
                /* check if it it exists yet */
                query.prepare("Select * from user where username = (:username) limit 1");
                query.bindValue(":username", username.c_str());

                if(query.exec()){
                    if(query.next()){
                        qDebug() << "user is exists";
                        status = false;
                    }
                    else{
                        /* insert new user */
                        query.prepare("Insert Into user (username, passwd, signupdate) Values(:username, :passwd, :signupdate)");
                        QDate date = QDate::currentDate();
                        query.bindValue(":username", username.c_str());
                        query.bindValue(":passwd", passwd.c_str());
                        query.bindValue(":signupdate", date.toString("yyyy-MM-dd")); //only work when it is "yyyy-MM-dd"

                        if(query.exec()){
                            status = true;
                            qDebug() << "user insert success!";
                        }else{
                            qDebug() << "user insert failed!";
                        }
                    }
                }
            }
        }
    }catch(QSqlError e){
        qDebug() << e;
    }

    ConnectionPool::closeConnection(con);
    return status;
}

