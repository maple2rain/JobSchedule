#include "ui_widget.h"
#include "../../inc/ui/widget.h"
#include "../../inc/ui/person.h"
#include "../../inc/dbOperate/useroperate.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <iostream>
#include <QList>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QPixmap>
#include <QMovie>

us16 Widget::runtime = 0;
us16 Widget::waittime = 1000; // ms

void Widget::test()
{
    //    QByteArray bytes;
    //    QString imagePath = QFileDialog::getOpenFileName(this, tr("Open File"), "../JobsSchedule/images/graph", tr("Image (*.jpg *.png *.bmp *.gif)"));//打开文件路径，使用this为当前父窗口，“Open File”为对话框标题，“.”为默认目录，过滤器为“Text Files(*.txt)”
    //    if(!imagePath.isEmpty()) {
    //        QFile file(imagePath);

    //        if (!file.open(QIODevice::ReadOnly)) {//以只读方式打开text文件
    //            QMessageBox::warning(this, tr("Read File"), tr("Cannot open file:\n%1").arg(imagePath));
    //            return;
    //        }

    //        bytes = file.readAll();
    //        file.close();
    //    }

    //    QPixmap photo;
    //    photo.loadFromData(bytes, "JPG");
    //    qDebug() << imagePath;

    //    QMovie *movie = new QMovie(imagePath);
    //    graphLbl->setPixmap(photo);
    //    graphLbl->setMovie(movie);
    //    graphLbl->setScaledContents(true);
    //    movie->start();
}

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    setFixedSize(this->width(), this->height());
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=](){
        CurTimeClock->display(QString::number(++runtime));
        timeRun();
//                if(runtime == 1){
//                    addJob();
//                }

        qDebug() << "runtime is " << runtime ;
    });

    graphLbl->installEventFilter(this);

    InitModule();
    settooltip();
}

void Widget::InitModule()
{
    initStatus();
    initRadioBtnVec();
    initTableVec();
    initMap();
    initPalette();
    movie = new QMovie(this);
}

inline
void Widget::initPalette()
{
    CurTimeClock->setPalette(Qt::red);
}

inline
void Widget::initStatus()
{
    isPSA = isPM = isRun = isMethodFixed = false;
}

inline
void Widget::initRadioBtnVec()
{
    radioBtnVec = { FCFS, EDF, SJF, HRRN, MFQ, RR };
}

inline
void Widget::initTableVec()
{
    tableVec = { PreInputTbl, ReadyJobTbl, RunJobTbl, NextJobTbl, FinishedJobTbl };
}

void Widget::initMap()
{
    radioBtnMap[std::string("FCFS")] = 0;
    radioBtnMap[std::string("EDF")] = 1;
    radioBtnMap[std::string("SJF")] = 2;
    radioBtnMap[std::string("HRRN")] = 3;
    radioBtnMap[std::string("MFQ")] = 4;
    radioBtnMap[std::string("RR")] = 5;
}

void Widget::showPersonInfo()
{
    Person *person = new Person;
    connect(person, &Person::destroyed,
            this, &Widget::showGraph);
    person->setAttribute(Qt::WA_DeleteOnClose);
    person->setWindowModality(Qt::ApplicationModal);//set parent window to lock
    person->show();
}

void Widget::showGraph()
{
    extern QMutex UserLock;
    extern UserOperate user;
    QMutexLocker lockerWait(&UserLock);
    if(user.isHasGraph()){
        QPixmap photo;
        photo.loadFromData(user.getGraph().getGraph(), user.getGraph().getGraphType().c_str());
        graphLbl->setPixmap(photo);
    }
}

void Widget::showGif()
{
    extern QMutex UserLock;
    extern UserOperate user;
    QMutexLocker lockerWait(&UserLock);

    if(user.isHasGif()){
        movie->setFileName(QString(user.getGif().getGifName().c_str()));
        graphLbl->setMovie(movie);
        movie->start();
    }
}

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == graphLbl){
        if(event->type() == QEvent::MouseButtonPress){//press event
            showPersonInfo();
            return true;
        }else{
            return false;
        }
    }else{
        return QWidget::eventFilter(watched, event);
    }
}

void Widget::RemoveRowByName(QTableWidget *table, const std::string &name)
{
    QList<QTableWidgetItem*> list = table->findItems(name.c_str(), Qt::MatchExactly);

    if(list.size() > 0)
        table->removeRow(list.at(0)->row());  //excatly, there must be only one item
}

Widget::~Widget()
{

}

class Widget::ValidJob{
private:
    std::string jobName;
    std::string joinTimeStr;
    std::string lastTimeStr;
    std::string deadLineStr;
    std::string fault;

    us16 joinTime;
    us16 lastTime;
    us16 deadLine;
    us16 priorityOrSlice;
public:
    ValidJob() {}
    ~ValidJob() {}

    /* setter */
    void setJobName(std::string &_jobName) { jobName = _jobName; }
    void setJoinTimeStr(std::string &_joinTimeStr) { joinTimeStr = _joinTimeStr; }
    void setLastTimeStr(std::string &_lastTimeStr) { lastTimeStr = _lastTimeStr; }
    void setDeadLineStr(std::string &_deadLineStr) { deadLineStr = _deadLineStr; }
    void setJoinTime(us16 _joinTime) { joinTime = _joinTime; }
    void setLastTime(us16 _lastTime) { lastTime = _lastTime; }
    void setDeadLine(us16 _deadLine) { deadLine = _deadLine; }
    void setPriorityOrSlice(us16 _priorityOrSlice) { priorityOrSlice = _priorityOrSlice; }
    void setFault(std::string faultStr) { fault += faultStr; }

    /* getter */
    const std::string& getFault() const { return fault; }
    const std::string& getJobName() const { return jobName; }
    const std::string& getJoinTimeStr() const { return joinTimeStr; }
    const std::string& getLastTimeStr() const { return lastTimeStr; }
    const std::string& getDeadLineStr() const { return deadLineStr; }
    us16 getJoinTime() const { return joinTime; }
    us16 getLastTime() const { return lastTime; }
    us16 getDeadLine() const { return deadLine; }
    us16 getPriorityOrSlice() const { return priorityOrSlice; }

    bool checkJobValid();   //check if the committed job is valid
};

void Widget::on_ClearAllDataBtn_clicked()
{
    if(!isRun){
        isMethodFixed = false;
        ClearTable();
        EnableRadioBtn();
        sendClearSignal();
        clearLbl();
    }
}

void Widget::on_RunBtn_clicked()
{
    /* if it is not running, that initialize the operation and start the timer; */
    if(isMethodFixed && !isRun){
        runtime = -1;
        CurTimeClock->setPalette(Qt::green);
        timer->start(waittime);
        isRun = true;
        RunBtn->setDisabled(true);
        showGif();
    }
}

void Widget::on_PauseBtn_clicked()
{
    /* it only work when the jobs are running */
    if(isRun){
        static bool isPause = false;
        if(isPause){
            CurTimeClock->setPalette(Qt::green);
            timer->start(waittime);
//            PauseBtn->setText(tr("Pause"));     //change the text show on the button
            PauseBtn->setStyleSheet("border-image: url(:/images/images/icon/pause_128px_1200673_easyicon.net.ico);");
            isPause = false;
            movie->start();
        }else{
            timer->stop();
            CurTimeClock->setPalette(Qt::red);
//            PauseBtn->setText(tr("Continue"));  //change the text show on the button
            PauseBtn->setStyleSheet("border-image: url(:/images/images/icon/play_128px_1205833_easyicon.net.ico);");
            isPause = true;
            movie->stop();
        }
    }
}

void Widget::stopEvent()
{
    timer->stop();
    runtime = 0;
    CurTimeClock->display(0);
    movie->stop();

    //change status
    isRun = false;
    isMethodFixed = false;

    RunBtn->setEnabled(true);
//    PauseBtn->setText(tr("Pause"));     //change the text show on the button
    PauseBtn->setStyleSheet("border-image: url(:/images/images/icon/pause_128px_1200673_easyicon.net.ico);");
    EnableRadioBtn();
    
    bool isStore = QMessageBox::question(this,
                                         tr("Store"),
                                         tr("Do you want to store your job in DB?"),
                                         QMessageBox::Yes | QMessageBox::No,
                                         QMessageBox::Yes)
            == QMessageBox::Yes;
    showGraph();

    if(isStore)
        timeStop();
}

void Widget::on_StopBtn_clicked()
{
    if(isRun)
        stopEvent();
}

/* select schedule type */
void Widget::on_PSA_clicked(bool checked) { isPSA = checked; }
void Widget::on_PM_clicked(bool checked) { isPM = checked; }

/* select schedule method */
void Widget::on_FCFS_clicked() { scheduleMethod = "FCFS"; }
void Widget::on_MFQ_clicked() { scheduleMethod = "MFQ"; }
void Widget::on_RR_clicked() { scheduleMethod = "RR"; }
void Widget::on_SJF_clicked() { scheduleMethod = "SJF"; }
void Widget::on_HRRN_clicked() { scheduleMethod = "HRRN"; }
void Widget::on_EDF_clicked() { scheduleMethod = "EDF"; }

void Widget::DisableRadioBtn(std::string exception)
{
    for(auto it = radioBtnMap.begin(); it != radioBtnMap.end(); ++it){
        if(it->first != exception){
            radioBtnVec[it->second]->setDisabled(true);
        }
    }

    /* check and disable checkBox */
    PM->setChecked(isPM);
    PSA->setChecked(isPSA);
    PM->setDisabled(true);
    PSA->setDisabled(true);
}



void Widget::EnableRadioBtn()
{
    for(size_t i = 0; i < radioBtnVec.size(); ++i){
        radioBtnVec[i]->setEnabled(true);
    }

    /* enable check box */
    PM->setEnabled(true);
    PSA->setEnabled(true);
}

void Widget::ClearTable(QTableWidget* table)
{
    table->setRowCount(0);
    table->clearContents();
}

void Widget::ClearTable()
{
    for(size_t i = 0; i < tableVec.size(); ++i){
        ClearTable(tableVec[i]);
    }
}

void Widget::on_PriorityCombo_currentIndexChanged(int index)
{

}

void Widget::on_ClearInputBtn_clicked()
{
    /* clear input */
    JobNameEdit->clear();
    JoinTimeEdit->clear();
    LastTimeEdit->clear();
    DeadLineEdit->clear();
    PriorityCombo->setCurrentIndex(0);
    qDebug() << "clear data" ;
}


void Widget::on_CommitInputBtn_clicked()
{
    validJob = new ValidJob;

    /* set attribute of job */
    validJob->setJobName(std::string((const char*)JobNameEdit->text().toLocal8Bit()));
    validJob->setJoinTimeStr(std::string((const char*)JoinTimeEdit->text().toLocal8Bit()));
    validJob->setLastTimeStr(std::string((const char*)LastTimeEdit->text().toLocal8Bit()));
    validJob->setDeadLineStr(std::string((const char*)DeadLineEdit->text().toLocal8Bit()));
    validJob->setPriorityOrSlice(PriorityCombo->currentIndex());

    /* commit valid job */
    commitJob(validJob);

    delete validJob;
}

void Widget::dealWithJobFromFile(QTextStream &in)
{
    QString line = in.readLine();
    scheduleMethod = std::string((const char*)line.toLocal8Bit());
    radioBtnVec[radioBtnMap[scheduleMethod]]->setChecked(true);
    line = in.readLine();

    /* set task status */
    {
        char type = atoi(line.toLocal8Bit());
        isPM = (type & 0x01) != 0;
        isPSA = (type & 0x02) != 0;
        DEBUG_PRINT("isPM is ", isPM, "isPSA is ", isPSA);
    }

    while(!in.atEnd()){
        validJob = new ValidJob;
        line = in.readLine();
        std::string str = std::string((const char*)line.toLocal8Bit());

        us16 begin, end;
        begin = end = 0;

        while(end < str.size() && str[end] != '\t') ++end;
        validJob->setJobName(str.substr(begin, end - begin));
        begin = ++end;

        while(end < str.size() && str[end] != '\t') ++end;
        validJob->setJoinTimeStr(str.substr(begin, end - begin));
        begin = ++end;

        while(end < str.size() && str[end] != '\t') ++end;
        validJob->setLastTimeStr(str.substr(begin, end - begin));
        begin = ++end;

        while(end < str.size() && str[end] != '\t') ++end;
        validJob->setDeadLineStr(str.substr(begin, end - begin));
        begin = ++end;

        validJob->setPriorityOrSlice(atoi(str.substr(begin, str.size()).c_str()));

        commitJob(validJob);
        delete validJob;
    }
}

void Widget::commitJob(ValidJob *_validJob)
{
    if(false == _validJob->checkJobValid()){
        std::string warning =
                std::string("The job you committed is not valid!\n") +
                "The follow may be the error:\n" +
                _validJob->getFault();

        QMessageBox::warning(this, tr("Warning"), tr(warning.c_str()));
    }else{
        qDebug() << "commit success" << endl;
        if(!isMethodFixed){
            methodMsgSend();
            isMethodFixed = true;
            DisableRadioBtn(scheduleMethod);//disable button except the one decide the current method
        }

        Job *job =
                new Job(_validJob->getJobName(),
                        _validJob->getJoinTime(),
                        _validJob->getLastTime(),
                        _validJob->getDeadLine(),
                        _validJob->getPriorityOrSlice());

        TableAddJobItem(PreInputTbl, job);
        jobSend(job);//notify that add a new job
    }
}

void Widget::addJob()
{
    Job *job =
            new Job("x",
                    3,
                    2,
                    99,
                    0);

    TableAddJobItem(PreInputTbl, job);
    jobSend(job);//notify that add a new job
}

void Widget::TableAddJobItem(QTableWidget *table, Job *job)
{
    int rowCount = table->rowCount();
    table->setRowCount(rowCount + 1); //change row count

    /* add new item */
    //set as text
    QTableWidgetItem *jobNameItem = new QTableWidgetItem();
    jobNameItem->setText(job->getJobName().c_str());

    //set as data
    QTableWidgetItem *joinTimeItem = new QTableWidgetItem();
    joinTimeItem->setData(Qt::DisplayRole, job->getJoinTime());
    QTableWidgetItem *lastTimeItem = new QTableWidgetItem();
    lastTimeItem->setData(Qt::DisplayRole, job->getLastTime());
    QTableWidgetItem *deadLineItem = new QTableWidgetItem();
    deadLineItem->setData(Qt::DisplayRole, job->getDeadLine());
    QTableWidgetItem *currentIndexItem = new QTableWidgetItem();
    currentIndexItem->setData(Qt::DisplayRole, job->getPrioOrSlice());

    //if sorting enabled was true, that it will lose some item due to the sorting
    table->setSortingEnabled(false);

    /* set new item */
    table->setItem(rowCount, 0, jobNameItem);
    table->setItem(rowCount, 1, joinTimeItem);
    table->setItem(rowCount, 2, lastTimeItem);
    table->setItem(rowCount, 3, deadLineItem);
    table->setItem(rowCount, 4, currentIndexItem);

    //enable sorting again
    table->setSortingEnabled(true);

}

void Widget::TableSetRunOrNextJobItem(QTableWidget *table, Job *job)
{
    table->setRowCount(1);

    //set as text
    QTableWidgetItem *jobNameItem = new QTableWidgetItem();
    jobNameItem->setText(job->getJobName().c_str());

    //set as data
    QTableWidgetItem *joinTimeItem = new QTableWidgetItem();
    joinTimeItem->setData(Qt::DisplayRole, job->getJoinTime());
    QTableWidgetItem *lastTimeItem = new QTableWidgetItem();
    lastTimeItem->setData(Qt::DisplayRole, job->getLastTime());
    QTableWidgetItem *startTimeItem = new QTableWidgetItem();
    startTimeItem->setData(Qt::DisplayRole, job->getStartTime());
    QTableWidgetItem *runningTimeItem = new QTableWidgetItem();
    runningTimeItem->setData(Qt::DisplayRole, job->getRunTime());
    QTableWidgetItem *needTimeItem = new QTableWidgetItem();
    needTimeItem->setData(Qt::DisplayRole, job->getNeedTime());
    QTableWidgetItem *currentIndexItem = new QTableWidgetItem();
    currentIndexItem->setData(Qt::DisplayRole, job->getPrioOrSlice());


    /* set new item */
    table->setItem(0, 0, jobNameItem);
    table->setItem(0, 1, joinTimeItem);
    table->setItem(0, 2, lastTimeItem);
    table->setItem(0, 3, startTimeItem);
    table->setItem(0, 4, runningTimeItem);
    table->setItem(0, 5, needTimeItem);
    table->setItem(0, 6, currentIndexItem);

}

void Widget::DrawFinishedTable(Job *job)
{
    int rowCount = FinishedJobTbl->rowCount();
    FinishedJobTbl->setRowCount(rowCount + 1); //change row count

    /* add new item */
    //set as text
    QTableWidgetItem *jobNameItem = new QTableWidgetItem();
    jobNameItem->setText(job->getJobName().c_str());

    //set as data
    QTableWidgetItem *joinTimeItem = new QTableWidgetItem();
    joinTimeItem->setData(Qt::DisplayRole, job->getJoinTime());
    QTableWidgetItem *lastTimeItem = new QTableWidgetItem();
    lastTimeItem->setData(Qt::DisplayRole, job->getLastTime());
    QTableWidgetItem *startTimeItem = new QTableWidgetItem();
    startTimeItem->setData(Qt::DisplayRole, job->getStartTime());
    QTableWidgetItem *finishedTimeItem = new QTableWidgetItem();
    finishedTimeItem->setData(Qt::DisplayRole, job->getFinishedTime());
    QTableWidgetItem *deadLineItem = new QTableWidgetItem();
    deadLineItem->setData(Qt::DisplayRole, job->getDeadLine());
    QTableWidgetItem *turnoverItem = new QTableWidgetItem();
    turnoverItem->setData(Qt::DisplayRole, job->getTurnOverTime());
    QTableWidgetItem *wTurnoverItem = new QTableWidgetItem();
    wTurnoverItem->setData(Qt::DisplayRole, job->getWTurnoverTime());

    //if sorting enabled was true, that it will lose some item due to the sorting
    FinishedJobTbl->setSortingEnabled(false);

    /* set new item */
    FinishedJobTbl->setItem(rowCount, 0, jobNameItem);
    FinishedJobTbl->setItem(rowCount, 1, joinTimeItem);
    FinishedJobTbl->setItem(rowCount, 2, startTimeItem);
    FinishedJobTbl->setItem(rowCount, 3, finishedTimeItem);
    FinishedJobTbl->setItem(rowCount, 4, lastTimeItem);
    FinishedJobTbl->setItem(rowCount, 5, deadLineItem);
    FinishedJobTbl->setItem(rowCount, 6, turnoverItem);
    FinishedJobTbl->setItem(rowCount, 7, wTurnoverItem);

    //enable sorting again
    FinishedJobTbl->setSortingEnabled(true);
}


void Widget::on_OpenFile_clicked()
{
    if(isRun){
        QMessageBox::warning(this, tr("Warning"), tr("Can't commit job from file\n when it's running!"));
        return;
    }

    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), "../JobsSchedule/file", tr("Text Files(*.txt)"));//打开文件路径，使用this为当前父窗口，“Open File”为对话框标题，“.”为默认目录，过滤器为“Text Files(*.txt)”
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {//以只读方式打开text文件
        QMessageBox::warning(this, tr("Read File"), tr("Do not open any file!"));
        return;
    }

    QTextStream in(&file);//打开文件输入流
    if(!in.atEnd())
        dealWithJobFromFile(in);

    file.close();
}

void Widget::on_PauseBtn_pressed()
{
    //    PauseBtn->setStyleSheet("QPushButton:hover{background: red;}");//setting background to be red when hover
    //    PauseBtn->setToolTip(tr("Transfer File(s) from Left to Right"));//setting tool tip when hover
}

void Widget::settooltip()
{
    ClearAllDataBtn->setToolTip(tr("Clear All Data"));
    RunBtn->setToolTip(tr("Execute"));
    PauseBtn->setToolTip(tr("Pause"));
    StopBtn->setToolTip(tr("Stop"));
    ClearInputBtn->setToolTip(tr("Clear Input"));
    CommitInputBtn->setToolTip(tr("Commit Job"));
    OpenFile->setToolTip(tr("Open File"));
}

bool Widget::ValidJob::checkJobValid()
{
    bool flag = true;
    /* check job name */
    if("" == jobName){
        this->setFault("The job is without name!\n");
        flag = false;
    }

    std::stringstream ss;
    us16 time = -1;
    std::cout << "time is " << time << std::endl;

    /* check join time */
    ss.str(joinTimeStr);
    ss >> time;
    if(ss.fail() || time <= runtime){
        this->setFault("The number about the join time is invalid!\n");
        qDebug() << "join time is " << time << endl;
        qDebug() << ss.failbit;
        std::cout << "jointime is " << joinTimeStr << std::endl;
        std::cout << "time is " << time << " and runtime is " << runtime << std::endl;
        flag = false;
    }else{
        joinTime = time;
    }
    ss.clear();

    /* check last time */
    ss.str(lastTimeStr);
    ss >> time;
    if(ss.fail() || time < 0){
        this->setFault("The number about the last time is invalid!\n");
        qDebug() << "last time is " << time << endl;
        qDebug() << ss.failbit;
        std::cout << lastTimeStr << std::endl;
        flag = false;
    }else{
        lastTime = time;
    }
    ss.clear();

    /* check deadine */
    ss.str(deadLineStr);
    ss >> time;
    if(ss.fail() || time < joinTime + lastTime){
        this->setFault("The number about the deadline is invalid!\n");
        qDebug() << "deadline is " << time << endl;
        qDebug() << ss.failbit;
        std::cout << deadLineStr << std::endl;
        flag = false;
    }else{
        deadLine = time;
    }

    return flag;
}

void Widget::drawTable(const JobRecorder &jobRecorder)
{
    if(jobRecorder.isFinished()){
        stopEvent();
        return;
    }
    auto it = jobRecorder.getRecorder().cbegin();
    Job *job;

    /* waiting to ready */
    for(us16 count = jobRecorder.getWait2Ready(); count > 0; --count){
        job = (*it++).get();
        TableAddJobItem(ReadyJobTbl, job);
        DEBUG_PRINT("job Wait2Ready is to draw");
    }

    /* run to next */
    if(jobRecorder.getRun2Next() > 0){
        job = (*it++).get();
        RemoveRowByName(RunJobTbl, job->getJobName());
        TableSetRunOrNextJobItem(NextJobTbl, job);
        DEBUG_PRINT("job Run2Next is to draw");
    }

    /* run to ready */
    if(jobRecorder.getRun2Ready() > 0){
        job = (*it++).get();
        RemoveRowByName(RunJobTbl, job->getJobName());
        TableAddJobItem(ReadyJobTbl, job);
        DEBUG_PRINT("job Run2Ready is to draw");
    }

    /* run to finished */
    if(jobRecorder.getRun2Finished() > 0){
        job = (*it++).get();
        RemoveRowByName(RunJobTbl, job->getJobName());
        DrawFinishedTable(job);
        DEBUG_PRINT("job Run2Finished is to draw");
    }

    /* next to run */
    if(jobRecorder.getNext2Run() > 0){
        job = (*it++).get();
        RemoveRowByName(NextJobTbl, job->getJobName());
        TableSetRunOrNextJobItem(RunJobTbl, job);
        DEBUG_PRINT("job Next2Run is to draw");
    }

    /* ready to run */
    if(jobRecorder.getReady2Run() > 0){
        job = (*it++).get();
        RemoveRowByName(ReadyJobTbl, job->getJobName());
        TableSetRunOrNextJobItem(RunJobTbl, job);
        DEBUG_PRINT("job Ready2Run is to draw");
    }

    /* next to ready */
    if(jobRecorder.getNext2Ready() > 0){
        job = (*it++).get();
        RemoveRowByName(NextJobTbl, job->getJobName());
        TableSetRunOrNextJobItem(ReadyJobTbl, job);
        DEBUG_PRINT("job Next2Ready is to draw");
    }

    /* run to run */
    if(jobRecorder.getRun2Run() > 0){
        job = (*it++).get();
        TableSetRunOrNextJobItem(RunJobTbl, job);
        DEBUG_PRINT("job Run2Run is to draw");
    }

    /* ready to next */
    if(jobRecorder.getReady2Next() > 0){
        job = (*it++).get();
        RemoveRowByName(ReadyJobTbl, job->getJobName());
        TableSetRunOrNextJobItem(NextJobTbl, job);
        DEBUG_PRINT("job Ready2Next is to draw");
    }

    ATTValue->setText(QString::number(jobRecorder.getAverTurnover(), 'f'));
    WATTValue->setText(QString::number(jobRecorder.getAverWTurnover(), 'f'));
}

void Widget::clearLbl()
{
    ATTValue->setText("0");
    WATTValue->setText("0");
}
