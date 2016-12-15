#ifndef WIDGET_H
#define WIDGET_H

#include <QTimer>
#include <QWidget>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include "ui_widget.h"
#include "../inc/scheduler.h"
#include "../inc/job.h"

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
    void methodMsgSend();
    void jobSend(Job *job);

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

    /* deal with radio button */
    void DisableRadioBtn(std::string exception);
    void EnableRadioBtn();

    /* deal with table */
    void Widget::TableAddJobItem(QTableWidget *table, Job *job);

    void initMap();
private:
    QTimer *timer;
    std::string scheduleMethod;
    bool    isRun;
    bool    isPSA;
    bool    isPM;
    bool    isMethodFixed;
    static us16 runtime;
    std::vector<std::string> jobNames;

    /* To manage radio button to be enabled or disabled */
    std::vector<QRadioButton*> radioBtnVec;
    std::map<std::string, size_t> radioBtnMap;

signals://使用signals标记信号函数，信号是一个函数声明，返回void，不需要函数的实现代码
    void methodFixedSignal(const std::string &scheduleMethod, bool _isPM, bool _isPSA);
    void jobCommingSignal(Job* job);
};

#endif // WIDGET_H
