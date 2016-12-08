#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "../inc/ui_jobs.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget, public Ui::Widget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    /* if PSA and PM chosed*/
    void on_PSA_clicked(bool checked);
    void on_PM_clicked(bool checked);

    void on_Run_clicked();
    void on_ClearAllDataBtn_clicked();

    /* choose schedule algorithm */
    void on_FCFS_clicked();
    void on_MFQ_clicked();
    void on_RR_clicked();
    void on_SJF_clicked();
    void on_HRRN_clicked();
    void on_EDF_clicked();

    /* save job info */
    void on_JoinTimeEdit_editingFinished();
    void on_JobNameEdit_editingFinished();
    void on_LastTimeEdit_editingFinished();
    void on_PriorityCombo_currentIndexChanged(int index);

    /* clear or commit a new job */
    void on_ClearInputBtn_clicked();
    void on_CommitInputBtn_clicked();

    /* add job from file */
    void on_OpenFile_clicked();


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
