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
    ../src/widget.cpp \
    ../src/fcfs.cpp \
    ../src/scheduler.cpp \
    ../src/proxy.cpp \
    ../src/connectionpool.cpp \
    ../src/useroperate.cpp

HEADERS  += \
    ../inc/widget.h \
    ../build-JobsSchedule-Desktop_Qt_5_6_2_MSVC2015_64bit-Debug/ui_widget.h \
    ../inc/job.h \
    ../inc/scheduler.h \
    ../inc/producer.h \
    ../inc/proxy.h \
    ../inc/jobrecorder.h \
    ../inc/app_cfg.h \
    ../inc/require.h \
    ../inc/ConnectionPool.h \
    ../inc/jobsoperate.h \
    ../inc/useroperate.h

FORMS    += widget.ui

RESOURCES += \
    rsc.qrc
