#include "../inc/person.h"
#include "../inc/useroperate.h"
#include "../inc/personmodify.h"
#include <QPixmap>
#include <QMovie>
#include <QFileDialog>
#include <QMessageBox>
#include <QByteArray>
#include <QCryptographicHash>
#include "../inc/graph.h"
#include "../inc/gif.h"


Person::Person(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    setUserData();
    showGraph();
    showGif();

    GraphLbl->installEventFilter(this);
    GifLbl->installEventFilter(this);
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
