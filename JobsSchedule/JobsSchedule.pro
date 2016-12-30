#-------------------------------------------------
#
# Project created by QtCreator 2016-11-22T15:42:18
#
#-------------------------------------------------

QT       += core gui\
			sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JobsSchedule
TEMPLATE = app


SOURCES += \
    ../src/main.cpp \
    ../src/dbOperate/connectionpool.cpp \
    ../src/dbOperate/useroperate.cpp \
    ../src/schedule/edf.cpp \
    ../src/schedule/fcfs.cpp \
    ../src/schedule/sjf.cpp \
    ../src/ui/login.cpp \
    ../src/ui/person.cpp \
    ../src/ui/personmodify.cpp \
    ../src/ui/register.cpp \
    ../src/ui/widget.cpp \
    ../src/proxy.cpp \
    ../src/schedule/scheduler.cpp \
    ../src/schedule/rr.cpp \
    ../src/schedule/hrrn.cpp

HEADERS  += \
    ../inc/dbOperate/ConnectionPool.h \
    ../inc/dbOperate/gif.h \
    ../inc/dbOperate/graph.h \
    ../inc/dbOperate/info.h \
    ../inc/dbOperate/useroperate.h \
    ../inc/job/job.h \
    ../inc/job/jobrecorder.h \
    ../inc/ui/login.h \
    ../inc/ui/person.h \
    ../inc/ui/personmodify.h \
    ../inc/ui/register.h \
    ../inc/ui/widget.h \
    ../inc/app_cfg.h \
    ../inc/proxy.h \
    ../inc/require.h \
    ../inc/scheduler.h

RESOURCES += \
	rsc.qrc

RC_FILE =  appico.rc

FORMS += \
    widget.ui \
    login.ui \
    person.ui \
    register.ui
