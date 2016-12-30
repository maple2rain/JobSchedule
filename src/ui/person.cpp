#include "../../inc/ui/person.h"
#include "../../inc/dbOperate/useroperate.h"
#include "../../inc/ui/personmodify.h"
#include <QPixmap>
#include <QMovie>
#include <QFileDialog>
#include <QMessageBox>
#include <QByteArray>
#include <QCryptographicHash>
#include "../../inc/dbOperate/graph.h"
#include "../../inc/dbOperate/gif.h"


Person::Person(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    setFixedSize(this->width(), this->height());

    setUserData();
    showGraph();
    showGif();
    drawTable();
    drawTurnover();
    settooltip();
    GraphLbl->installEventFilter(this);
    GifLbl->installEventFilter(this);

}

void Person::settooltip()
{
    ModifyBtn->setToolTip(tr("Modify User Data"));
    DeleteBtn->setToolTip(tr("Delete Job"));
    EchoChkBox->setToolTip(tr("Echo Password"));
    WarningChkBox->setToolTip(tr("Delete Warning"));
}

void Person::drawTable()
{
    extern QMutex UserLock;
    extern UserOperate user;
    QMutexLocker lockerWait(&UserLock);

    user.GetJob();

    for(auto it = user.getFailedJobs().cbegin(); it != user.getFailedJobs().cend(); ++it){
        Job *job = (*it).get();
        drawFailedTable(job);
    }

    for(auto it = user.getFinishedJobs().cbegin(); it != user.getFinishedJobs().cend(); ++it){
        Job *job = (*it).get();
        drawFinishedTable(job);
    }
}

void Person::drawTurnover()
{
    extern QMutex UserLock;
    extern UserOperate user;
    QMutexLocker lockerWait(&UserLock);

    Info info = user.GetTurnOver();
    if(info.getStatus() == false){//if not record, then set time as 0
        ATTValue->setText("0");
        WATTValue->setText("0");
    }else{
        ATTValue->setText(QString::number(user.getAverTurnover(), 'f'));
        WATTValue->setText(QString::number(user.getAverWTurnover(), 'f'));
    }
}

Person::~Person()
{
}

void Person::on_ModifyBtn_clicked()
{
    PersonModify *p = new PersonModify;

    QObject::connect(p, &PersonModify::ChangeUserDataSignal,
                     this, &Person::changeUserData);

    p->setAttribute(Qt::WA_DeleteOnClose);
    p->setWindowModality(Qt::ApplicationModal);//set parent window to lock
    p->show();
}

void Person::setUserData()
{
    extern UserOperate user;
    UserNameLineEdit->setText(user.getUserName().c_str());
    PasswdLineEdit->setText(user.getPassword().c_str());
}

void Person::on_EchoChkBox_clicked(bool checked)
{
    if(checked){
        PasswdLineEdit->setEchoMode(QLineEdit::Normal);
    }else{
        PasswdLineEdit->setEchoMode(QLineEdit::Password);
    }
}

// get file name
const std::string getFileName(const std::string &path)
{
    std::string::size_type pos;
    pos = path.rfind("/");

    if(std::string::npos == pos){
        return path;
    }else{
        return path.substr(pos);
    }
}

// get file type
const std::string getFileType(const std::string &path)
{
    std::string::size_type pos;
    pos = path.rfind(".");

    if(std::string::npos == pos){
        return "";
    }else{
        return path.substr(pos + 1);
    }
}

void Person::selectGraph()
{
    QByteArray bytes;
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), "../JobsSchedule/images/graph", tr("Image (*.jpg *.png *.bmp *.gif)"));//打开文件路径，使用this为当前父窗口，“Open File”为对话框标题，“.”为默认目录，过滤器为“Text Files(*.txt)”
    if(!path.isEmpty()) {
        QFile file(path);

        if (!file.open(QIODevice::ReadOnly)) {//以只读方式打开text文件
            QMessageBox::warning(this, tr("Read File"), tr("Cannot open file:\n%1").arg(path));
            return;
        }
        bytes = file.readAll();
        file.close();

        /* set graph attribute */
        Graph graph;
        graph.setGraph(bytes);
        // set type
        std::string graphPath = std::string((const char*)path.toLocal8Bit());
        graph.setGraphType(getFileType(graphPath));

        /* show pircure */
        QPixmap photo;
        photo.loadFromData(graph.getGraph(), graph.getGraphType().c_str());
        GraphLbl->setPixmap(photo);

        /* set graph attribute */
        // set md5 hash value as GraphID
        QCryptographicHash hash(QCryptographicHash::Md5);
        hash.addData(bytes);
        graph.setGraphID(hash.result().toStdString());

        extern UserOperate user;
        user.setGraph(graph);
        user.InsertGraph();
        user.UserAddGraph();
    }
}

void Person::selectGif()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), "../JobsSchedule/images/gif", tr("Image (*.gif)"));//打开文件路径，使用this为当前父窗口，“Open File”为对话框标题，“.”为默认目录，过滤器为“Text Files(*.txt)”
    if(!path.isEmpty()) {
        /* set gif attribute */
        Gif gif;
        // set gif name
        gif.setGifName(std::string((const char*)path.toLocal8Bit()));

        /* show pircure */
        QMovie *movie = new QMovie(path, QByteArray(), this);

        //        movie->deleteLater();

        GifLbl->setMovie(movie);
        movie->start();

        /* set graph attribute */

        extern UserOperate user;
        user.setGif(gif);
        user.InsertGif();
        user.UserAddGif();
    }
}

bool Person::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == GraphLbl){
        if(event->type() == QEvent::MouseButtonPress){//press event
            selectGraph();
            return true;
        }else{
            return false;
        }
    }else if(watched = GifLbl){
        if(event->type() == QEvent::MouseButtonPress){//press event
            selectGif();
            return true;
        }else{
            return false;
        }
    }else{
        return QWidget::eventFilter(watched, event);
    }
}

void Person::showGraph()
{
    extern UserOperate user;
    if(user.isHasGraph()){
        QPixmap photo;
        photo.loadFromData(user.getGraph().getGraph(), user.getGraph().getGraphType().c_str());
        GraphLbl->setPixmap(photo);
    }
}

void Person::showGif()
{
    extern UserOperate user;
    if(user.isHasGif()){
        QMovie *movie = new QMovie(QString(user.getGif().getGifName().c_str()), QByteArray(), this);
        GifLbl->setMovie(movie);
        movie->start();
    }
}

void Person::drawFinishedTable(Job *job)
{
    int rowCount = FinishedJobTbl->rowCount();
    FinishedJobTbl->setRowCount(rowCount + 1); //change row count

    /* add new item */
    //set as text
    QTableWidgetItem *jobNameItem = new QTableWidgetItem();
    jobNameItem->setText(job->getJobName().c_str());

    //set as data
    QTableWidgetItem *jobIDItem = new QTableWidgetItem();
    jobIDItem->setData(Qt::DisplayRole, job->getJobID());
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
    QTableWidgetItem *priorityItem = new QTableWidgetItem();
    priorityItem->setData(Qt::DisplayRole, job->getPrioOrSlice());

    //if sorting enabled was true, that it will lose some item due to the sorting
    FinishedJobTbl->setSortingEnabled(false);

    /* set new item */
    FinishedJobTbl->setItem(rowCount, 0, jobIDItem);
    FinishedJobTbl->setItem(rowCount, 1, jobNameItem);
    FinishedJobTbl->setItem(rowCount, 2, joinTimeItem);
    FinishedJobTbl->setItem(rowCount, 3, startTimeItem);
    FinishedJobTbl->setItem(rowCount, 4, finishedTimeItem);
    FinishedJobTbl->setItem(rowCount, 5, lastTimeItem);
    FinishedJobTbl->setItem(rowCount, 6, deadLineItem);
    FinishedJobTbl->setItem(rowCount, 7, priorityItem);
    FinishedJobTbl->setItem(rowCount, 8, turnoverItem);
    FinishedJobTbl->setItem(rowCount, 9, wTurnoverItem);

    //enable sorting again
    FinishedJobTbl->setSortingEnabled(true);
}

void Person::drawFailedTable(Job *job)
{
    int rowCount = FailedJobTbl->rowCount();
    FailedJobTbl->setRowCount(rowCount + 1); //change row count

    /* add new item */
    //set as text
    QTableWidgetItem *jobNameItem = new QTableWidgetItem();
    jobNameItem->setText(job->getJobName().c_str());

    //set as data
    QTableWidgetItem *jobIDItem = new QTableWidgetItem();
    jobIDItem->setData(Qt::DisplayRole, job->getJobID());
    QTableWidgetItem *joinTimeItem = new QTableWidgetItem();
    joinTimeItem->setData(Qt::DisplayRole, job->getJoinTime());
    QTableWidgetItem *lastTimeItem = new QTableWidgetItem();
    lastTimeItem->setData(Qt::DisplayRole, job->getLastTime());
    QTableWidgetItem *startTimeItem = new QTableWidgetItem();
    startTimeItem->setData(Qt::DisplayRole, job->getStartTime());
    QTableWidgetItem *runTimeItem = new QTableWidgetItem();
    runTimeItem->setData(Qt::DisplayRole, job->getRunTime());
    QTableWidgetItem *deadLineItem = new QTableWidgetItem();
    deadLineItem->setData(Qt::DisplayRole, job->getDeadLine());
    QTableWidgetItem *priorityItem = new QTableWidgetItem();
    priorityItem->setData(Qt::DisplayRole, job->getPrioOrSlice());

    //if sorting enabled was true, that it will lose some item due to the sorting
    FailedJobTbl->setSortingEnabled(false);

    /* set new item */
    FailedJobTbl->setItem(rowCount, 0, jobIDItem);
    FailedJobTbl->setItem(rowCount, 1, jobNameItem);
    FailedJobTbl->setItem(rowCount, 2, joinTimeItem);
    FailedJobTbl->setItem(rowCount, 3, startTimeItem);
    FailedJobTbl->setItem(rowCount, 4, runTimeItem);
    FailedJobTbl->setItem(rowCount, 5, lastTimeItem);
    FailedJobTbl->setItem(rowCount, 6, deadLineItem);
    FailedJobTbl->setItem(rowCount, 7, priorityItem);

    //enable sorting again
    FailedJobTbl->setSortingEnabled(true);
}

void Person::on_DeleteBtn_clicked()
{
    if(WarningChkBox->isChecked() == true){
        bool isDelete = QMessageBox::question(this,
                                             tr("Warning"),
                                             tr("It will clear all information about the job!\n"
                                                "Are you sure to delete your job?"),
                                             QMessageBox::Yes | QMessageBox::No,
                                             QMessageBox::No)
                                                == QMessageBox::Yes;
        if(!isDelete)
            return;
    }

    deleteTableItem(FailedJobTbl);
    deleteTableItem(FinishedJobTbl);

}

void Person::deleteTableItem(QTableWidget *table)
{
    QList<QTableWidgetSelectionRange> ranges = table->selectedRanges();
    std::vector<us16> jobIDs;

    /* select selected range to delete */
    for(int i = 0; i < ranges.count(); ++i){
        int topRow = ranges.at(i).topRow();
        int bottomRow = ranges.at(i).bottomRow();

        /* get the value of first column of each selected row and remove it from table */
        for(int j = topRow; j <= bottomRow; ++j){
            QTableWidgetItem *item = table->item(topRow, 0);
            jobIDs.push_back(item->text().toUInt());
            table->removeRow(topRow);
        }

    }

    extern UserOperate user;
    user.DeleteJobs(jobIDs);

    if(table == FinishedJobTbl){
        drawTurnover();
    }
}
