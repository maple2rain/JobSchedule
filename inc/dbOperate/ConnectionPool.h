#ifndef CONNECTIONPOOL_H
#define CONNECTIONPOOL_H

#include <QtSql>
#include <QQueue>
#include <QString>
#include <QMutex>
#include <QMutexLocker>
#include <QDebug>
#include <QSettings>

class ConnectionPool {

public:
    static void release();                                // close all the connection
    static QSqlDatabase openConnection();                 // get a connection from database
    static void closeConnection(QSqlDatabase connection); // put connection to connection-pool

    ~ConnectionPool();

private:
    static ConnectionPool& getInstance();

    ConnectionPool();
    ConnectionPool(const ConnectionPool &other);
    ConnectionPool& operator=(const ConnectionPool &other);
    QSqlDatabase createConnection(const QString &connectionName); // create a connection

    QQueue<QString> usedConnectionNames;   // store connections that have been used
    QQueue<QString> unusedConnectionNames; // store connections that haven't been used

    // the info of database
    QString hostName;
    QString databaseName;
    QString username;
    QString password;
    QString databaseType;

    bool    testOnBorrow;    // whether to check that the connection is valid
    QString testOnBorrowSql; // test sql

    int maxWaitTime;  // max wait time to wait for a valid connection
    int waitInterval; // wait time interval
    int maxConnectionCount; // max number of connection in this pool

    static QMutex mutex;
    static QWaitCondition waitConnection;
    static ConnectionPool *instance;

};

#endif // CONNECTIONPOOL_H
