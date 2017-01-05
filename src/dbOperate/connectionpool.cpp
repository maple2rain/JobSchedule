#include "../../inc/dbOperate/ConnectionPool.h"

QMutex ConnectionPool::mutex;
QWaitCondition ConnectionPool::waitConnection;
ConnectionPool* ConnectionPool::instance = NULL;

ConnectionPool::ConnectionPool() {
    hostName     = "localhost"; //host name
    databaseName = "Jobs";      //the database that will be accessed
    username     = "root";      //user
    password     = "123456";    //password
    databaseType = "QMYSQL";    //database type

	testOnBorrow = true;
	testOnBorrowSql = "SELECT 1";

	maxWaitTime  = 1000;
	waitInterval = 200;
	maxConnectionCount  = 1000;
}

ConnectionPool::~ConnectionPool() {
    // destory all the connection when destruct
	foreach(QString connectionName, usedConnectionNames) {
		QSqlDatabase::removeDatabase(connectionName);
	}

	foreach(QString connectionName, unusedConnectionNames) {
		QSqlDatabase::removeDatabase(connectionName);
	}
    
    release();
}

ConnectionPool& ConnectionPool::getInstance() {
	if (NULL == instance) {
		QMutexLocker locker(&mutex);

		if (NULL == instance) {
			instance = new ConnectionPool();
		}
	}

	return *instance;
}

void ConnectionPool::release() {
	QMutexLocker locker(&mutex);
	delete instance;
	instance = NULL;
}

QSqlDatabase ConnectionPool::openConnection() {
	ConnectionPool& pool = ConnectionPool::getInstance();
    QString connectionName;

    //    qDebug()<<"available drivers:";
    //    QStringList drivers = QSqlDatabase::drivers();
    //    foreach(QString driver, drivers)
    //        qDebug() << driver;

	QMutexLocker locker(&mutex);

    //  the number of connection that have been created
	int connectionCount = pool.unusedConnectionNames.size() + pool.usedConnectionNames.size();

    // if there is not connection left, that wait each waitInterval ms for connection available, not more than maxWaitTime
	for (int i = 0;
		 i < pool.maxWaitTime
		 && pool.unusedConnectionNames.size() == 0 && connectionCount == pool.maxConnectionCount;
		 i += pool.waitInterval) {
		waitConnection.wait(&mutex, pool.waitInterval);

        // recount the number of connection
		connectionCount = pool.unusedConnectionNames.size() + pool.usedConnectionNames.size();
	}

	if (pool.unusedConnectionNames.size() > 0) {
        // reuserd unused connection
		connectionName = pool.unusedConnectionNames.dequeue();
	} else if (connectionCount < pool.maxConnectionCount) {
        // create new connection when there is not unused connection and the number of connection are less than max
		connectionName = QString("Connection-%1").arg(connectionCount + 1);
	} else {
		qDebug() << "Cannot create more connections.";
		return QSqlDatabase();
	}

    // create new connection
	QSqlDatabase db = pool.createConnection(connectionName);

    // put valid connection to usedConnectionNames
	if (db.isOpen()) {
		pool.usedConnectionNames.enqueue(connectionName);
        qDebug() << "create new connection.";
	}

	return db;
}

void ConnectionPool::closeConnection(QSqlDatabase connection) {
	ConnectionPool& pool = ConnectionPool::getInstance();
	QString connectionName = connection.connectionName();

    // if exists in used, then put it in unused
	if (pool.usedConnectionNames.contains(connectionName)) {
		QMutexLocker locker(&mutex);
		pool.usedConnectionNames.removeOne(connectionName);
		pool.unusedConnectionNames.enqueue(connectionName);
		waitConnection.wakeOne();
    }else{
        connection.close();
    }
}

QSqlDatabase ConnectionPool::createConnection(const QString &connectionName) {
    // if connection has been created, then reuse it
	if (QSqlDatabase::contains(connectionName)) {
		QSqlDatabase db1 = QSqlDatabase::database(connectionName);

		if (testOnBorrow) {
			qDebug() << "Test connection on borrow, execute:" << testOnBorrowSql << ", for" << connectionName;
			QSqlQuery query(testOnBorrowSql, db1);

			if (query.lastError().type() != QSqlError::NoError && !db1.open()) {
				qDebug() << "Open datatabase error:" << db1.lastError().text();
				return QSqlDatabase();
			}
		}

		return db1;
	}

    // create a new connection
	QSqlDatabase db = QSqlDatabase::addDatabase(databaseType, connectionName);
	db.setHostName(hostName);
	db.setDatabaseName(databaseName);
	db.setUserName(username);
	db.setPassword(password);
	//db.setPort(3306);

	if (!db.open()) {
		qDebug() << "Open datatabase error:" << db.lastError().text();
		return QSqlDatabase();
	}

	return db;
}
