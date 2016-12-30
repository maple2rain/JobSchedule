#ifndef WIDGET_H
#define WIDGET_H

#include <QTimer>
#include <QMovie>
#include <QWidget>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <QTextStream>
#include "ui_widget.h"
#include "../inc/scheduler.h"
#include "../inc/job/job.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget, public Ui::Widget
{
    class ValidJob;
    ValidJob* validJob;
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void methodMsgSend() {
        emit methodFixedSignal(scheduleMethod, isPM, isPSA);
    }
    void jobSend(Job *job){
        emit jobCommingSignal(job);
    }
    void timeRun(){
        emit timeRunningSignal(runtime);
    }
    void timeStop(){
        emit timeStopSignal();
    }
    void sendClearSignal(){
        emit clearSignal();
    }

public slots:
    void drawTable(const JobRecorder &jobRecorder);
    void showGraph();

private slots:
    /* if PSA and PM chosed*/
    void on_PSA_clicked(bool checked);
    void on_PM_clicked(bool checked);

    /* action operate */
    void on_ClearAllDataBtn_clicked();

    /* choose schedule algorithm */
    void on_FCFS_clicked();
    void on_MFQ_clicked();
    void on_RR_clicked();
    void on_SJF_clicked();
    void on_HRRN_clicked();
    void on_EDF_clicked();

    /* save job info */
    void on_PriorityCombo_currentIndexChanged(int index);

    /* clear or commit a new job */
    void on_ClearInputBtn_clicked();
    void on_CommitInputBtn_clicked();

    /* add job from file */
    void on_OpenFile_clicked();

    void on_RunBtn_clicked();
    void on_PauseBtn_clicked();
    void on_StopBtn_clicked();
    void on_PauseBtn_pressed();

private:
    /* deal with radio button */
    void DisableRadioBtn(std::string exception);
    void EnableRadioBtn();

    /* deal with table */
    void TableAddJobItem(QTableWidget *table, Job *job);
    void TableSetRunOrNextJobItem(QTableWidget *table, Job *job);
    void DrawFinishedTable(Job *job);
    void RemoveRowByName(QTableWidget *table, const std::string &name);
    void ClearTable();
    void ClearTable(QTableWidget* table);

    /* init */
    void InitModule();//initialize all the module
    void initStatus();//initialize the initial status of the attribute
    void initRadioBtnVec();//initialize the radio button vec, add the buttons to vec
    void initTableVec();//initialize the table vec, add the tables to vec
    void initMap();//init the map of radio button
    void initPalette();

    /* test */
    void addJob();
    void commitJob(ValidJob *validJob);
    void dealWithJobFromFile(QTextStream &in);
    void stopEvent();
    void showPersonInfo();
    void test();
    void clearLbl();
    void showGif();
    void settooltip();

private:
    QTimer *timer;
    QMovie *movie;
    std::string scheduleMethod;
    bool    isRun;
    bool    isPSA;
    bool    isPM;
    bool    isMethodFixed;
    static us16 runtime;
    static us16 waittime;
    std::vector<std::string> jobNames;

    /* To manage radio button to be enabled or disabled */
    std::vector<QRadioButton*> radioBtnVec;
    std::map<std::string, size_t> radioBtnMap;
    std::vector<QTableWidget*> tableVec;

protected:
    bool eventFilter(QObject *watched, QEvent *event);

signals://使用signals标记信号函数，信号是一个函数声明，返回void，不需要函数的实现代码
    void methodFixedSignal(const std::string &scheduleMethod, bool _isPM, bool _isPSA);
    void jobCommingSignal(Job* job);
    void timeRunningSignal(us16 runtime);
    void timeStopSignal();
    void clearSignal();
};

#endif // WIDGET_H
