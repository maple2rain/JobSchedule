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
    ../src/fcfs.cpp

HEADERS  += \
    ../inc/widget.h \
    ../build-JobsSchedule-Desktop_Qt_5_6_2_MSVC2015_64bit-Debug/ui_widget.h \
    ../inc/job.h \
    ../inc/scheduler.h \
    ../inc/producer.h

FORMS    += widget.ui

RESOURCES += \
    rsc.qrc
