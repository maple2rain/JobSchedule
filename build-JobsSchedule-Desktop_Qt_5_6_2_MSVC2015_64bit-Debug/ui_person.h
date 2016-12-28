/********************************************************************************
** Form generated from reading UI file 'person.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSON_H
#define UI_PERSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Person
{
public:
    QGroupBox *FinishedJob;
    QTableWidget *FinishedJobTbl;
    QWidget *layoutWidget;
    QHBoxLayout *ATTHL;
    QLabel *ATT;
    QLabel *ATTValue;
    QWidget *layoutWidget_2;
    QHBoxLayout *WATTHL;
    QLabel *WATT;
    QLabel *WATTValue;
    QGroupBox *PreInput;
    QTableWidget *FailedJobTbl;
    QLabel *FailLbl;
    QGroupBox *personBox;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *UserNameLbl;
    QLineEdit *UserNameLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *PasswdLbl;
    QLineEdit *PasswdLineEdit;
    QPushButton *ModifyBtn;
    QPushButton *DeleteBtn;
    QCheckBox *WarningChkBox;
    QCheckBox *EchoChkBox;
    QGroupBox *graphBox;
    QLabel *GraphLbl;
    QGroupBox *gifBox;
    QLabel *GifLbl;
    QFrame *frame;

    void setupUi(QWidget *Person)
    {
        if (Person->objectName().isEmpty())
            Person->setObjectName(QStringLiteral("Person"));
        Person->resize(985, 559);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/ico.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Person->setWindowIcon(icon);
        FinishedJob = new QGroupBox(Person);
        FinishedJob->setObjectName(QStringLiteral("FinishedJob"));
        FinishedJob->setGeometry(QRect(300, 240, 671, 301));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setBold(true);
        font.setWeight(75);
        FinishedJob->setFont(font);
        FinishedJobTbl = new QTableWidget(FinishedJob);
        if (FinishedJobTbl->columnCount() < 10)
            FinishedJobTbl->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        FinishedJobTbl->setObjectName(QStringLiteral("FinishedJobTbl"));
        FinishedJobTbl->setGeometry(QRect(20, 20, 631, 231));
        FinishedJobTbl->setAutoFillBackground(false);
        FinishedJobTbl->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        FinishedJobTbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        FinishedJobTbl->setSortingEnabled(true);
        FinishedJobTbl->horizontalHeader()->setCascadingSectionResizes(true);
        FinishedJobTbl->horizontalHeader()->setDefaultSectionSize(56);
        FinishedJobTbl->horizontalHeader()->setStretchLastSection(true);
        FinishedJobTbl->verticalHeader()->setDefaultSectionSize(25);
        layoutWidget = new QWidget(FinishedJob);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 270, 200, 16));
        ATTHL = new QHBoxLayout(layoutWidget);
        ATTHL->setObjectName(QStringLiteral("ATTHL"));
        ATTHL->setContentsMargins(0, 0, 0, 0);
        ATT = new QLabel(layoutWidget);
        ATT->setObjectName(QStringLiteral("ATT"));

        ATTHL->addWidget(ATT);

        ATTValue = new QLabel(layoutWidget);
        ATTValue->setObjectName(QStringLiteral("ATTValue"));

        ATTHL->addWidget(ATTValue);

        layoutWidget_2 = new QWidget(FinishedJob);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(320, 270, 230, 16));
        WATTHL = new QHBoxLayout(layoutWidget_2);
        WATTHL->setObjectName(QStringLiteral("WATTHL"));
        WATTHL->setContentsMargins(0, 0, 0, 0);
        WATT = new QLabel(layoutWidget_2);
        WATT->setObjectName(QStringLiteral("WATT"));

        WATTHL->addWidget(WATT);

        WATTValue = new QLabel(layoutWidget_2);
        WATTValue->setObjectName(QStringLiteral("WATTValue"));

        WATTHL->addWidget(WATTValue);

        PreInput = new QGroupBox(Person);
        PreInput->setObjectName(QStringLiteral("PreInput"));
        PreInput->setGeometry(QRect(300, 10, 671, 211));
        PreInput->setFont(font);
        FailedJobTbl = new QTableWidget(PreInput);
        if (FailedJobTbl->columnCount() < 8)
            FailedJobTbl->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font);
        FailedJobTbl->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font);
        FailedJobTbl->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font);
        FailedJobTbl->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font);
        FailedJobTbl->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font);
        FailedJobTbl->setHorizontalHeaderItem(4, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font);
        FailedJobTbl->setHorizontalHeaderItem(5, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font);
        FailedJobTbl->setHorizontalHeaderItem(6, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font);
        FailedJobTbl->setHorizontalHeaderItem(7, __qtablewidgetitem17);
        FailedJobTbl->setObjectName(QStringLiteral("FailedJobTbl"));
        FailedJobTbl->setGeometry(QRect(20, 20, 541, 171));
        FailedJobTbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        FailedJobTbl->setDragEnabled(false);
        FailedJobTbl->setAlternatingRowColors(false);
        FailedJobTbl->setSortingEnabled(true);
        FailedJobTbl->horizontalHeader()->setCascadingSectionResizes(false);
        FailedJobTbl->horizontalHeader()->setDefaultSectionSize(65);
        FailedJobTbl->horizontalHeader()->setMinimumSectionSize(15);
        FailedJobTbl->horizontalHeader()->setStretchLastSection(true);
        FailedJobTbl->verticalHeader()->setDefaultSectionSize(25);
        FailLbl = new QLabel(PreInput);
        FailLbl->setObjectName(QStringLiteral("FailLbl"));
        FailLbl->setGeometry(QRect(580, 20, 81, 171));
        FailLbl->setStyleSheet(QStringLiteral("image: url(:/images/images/icon/fail.png);"));
        personBox = new QGroupBox(Person);
        personBox->setObjectName(QStringLiteral("personBox"));
        personBox->setGeometry(QRect(10, 10, 271, 181));
        personBox->setFont(font);
        layoutWidget_3 = new QWidget(personBox);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(30, 30, 214, 71));
        verticalLayout = new QVBoxLayout(layoutWidget_3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 9);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        UserNameLbl = new QLabel(layoutWidget_3);
        UserNameLbl->setObjectName(QStringLiteral("UserNameLbl"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        UserNameLbl->setFont(font1);

        horizontalLayout->addWidget(UserNameLbl);

        UserNameLineEdit = new QLineEdit(layoutWidget_3);
        UserNameLineEdit->setObjectName(QStringLiteral("UserNameLineEdit"));
        UserNameLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(UserNameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        PasswdLbl = new QLabel(layoutWidget_3);
        PasswdLbl->setObjectName(QStringLiteral("PasswdLbl"));
        PasswdLbl->setFont(font);

        horizontalLayout_2->addWidget(PasswdLbl);

        PasswdLineEdit = new QLineEdit(layoutWidget_3);
        PasswdLineEdit->setObjectName(QStringLiteral("PasswdLineEdit"));
        PasswdLineEdit->setEchoMode(QLineEdit::Password);
        PasswdLineEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(PasswdLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        ModifyBtn = new QPushButton(personBox);
        ModifyBtn->setObjectName(QStringLiteral("ModifyBtn"));
        ModifyBtn->setGeometry(QRect(50, 112, 75, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        ModifyBtn->setFont(font2);
        ModifyBtn->setCursor(QCursor(Qt::PointingHandCursor));
        ModifyBtn->setStyleSheet(QLatin1String(" border-image: url(:/images/images/icon/document_edit_modify_write_48px_1631_easyicon.net.ico);\n"
"font: 75 14pt \"Calibri\";"));
        DeleteBtn = new QPushButton(personBox);
        DeleteBtn->setObjectName(QStringLiteral("DeleteBtn"));
        DeleteBtn->setGeometry(QRect(50, 145, 75, 28));
        DeleteBtn->setFont(font2);
        DeleteBtn->setCursor(QCursor(Qt::PointingHandCursor));
        DeleteBtn->setStyleSheet(QLatin1String("border-image: url(:/images/images/icon/delete_128px_1190332_easyicon.net.ico);\n"
"font: 75 14pt \"Calibri\";"));
        WarningChkBox = new QCheckBox(personBox);
        WarningChkBox->setObjectName(QStringLiteral("WarningChkBox"));
        WarningChkBox->setGeometry(QRect(150, 144, 71, 31));
        WarningChkBox->setCursor(QCursor(Qt::PointingHandCursor));
        WarningChkBox->setStyleSheet(QLatin1String("border-image: url(:/images/images/icon/warning_128px_1186332_easyicon.net.ico);\n"
"font: 75 14pt \"Calibri\";"));
        WarningChkBox->setChecked(true);
        EchoChkBox = new QCheckBox(personBox);
        EchoChkBox->setObjectName(QStringLiteral("EchoChkBox"));
        EchoChkBox->setGeometry(QRect(150, 123, 71, 16));
        EchoChkBox->setCursor(QCursor(Qt::PointingHandCursor));
        EchoChkBox->setStyleSheet(QLatin1String("border-image: url(:/images/images/icon/eye_128px_1153740_easyicon.net.ico);\n"
"font: 75 14pt \"Calibri\";"));
        graphBox = new QGroupBox(Person);
        graphBox->setObjectName(QStringLiteral("graphBox"));
        graphBox->setGeometry(QRect(10, 210, 271, 141));
        graphBox->setFont(font);
        GraphLbl = new QLabel(graphBox);
        GraphLbl->setObjectName(QStringLiteral("GraphLbl"));
        GraphLbl->setGeometry(QRect(13, 20, 241, 111));
        GraphLbl->setCursor(QCursor(Qt::PointingHandCursor));
        GraphLbl->setScaledContents(true);
        gifBox = new QGroupBox(Person);
        gifBox->setObjectName(QStringLiteral("gifBox"));
        gifBox->setGeometry(QRect(10, 370, 271, 171));
        gifBox->setFont(font);
        GifLbl = new QLabel(gifBox);
        GifLbl->setObjectName(QStringLiteral("GifLbl"));
        GifLbl->setGeometry(QRect(13, 21, 241, 141));
        GifLbl->setCursor(QCursor(Qt::PointingHandCursor));
        GifLbl->setScaledContents(true);
        frame = new QFrame(Person);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 991, 561));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QStringLiteral("background-image:url(:/images/images/Urban Dream.jpg)"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        FinishedJob->raise();
        PreInput->raise();
        personBox->raise();
        graphBox->raise();
        gifBox->raise();

        retranslateUi(Person);

        QMetaObject::connectSlotsByName(Person);
    } // setupUi

    void retranslateUi(QWidget *Person)
    {
        Person->setWindowTitle(QApplication::translate("Person", "Person", 0));
        FinishedJob->setTitle(QApplication::translate("Person", "Finished Jobs", 0));
        QTableWidgetItem *___qtablewidgetitem = FinishedJobTbl->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Person", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = FinishedJobTbl->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Person", "Job Name", 0));
        QTableWidgetItem *___qtablewidgetitem2 = FinishedJobTbl->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Person", "Join Time", 0));
        QTableWidgetItem *___qtablewidgetitem3 = FinishedJobTbl->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Person", "Starting", 0));
        QTableWidgetItem *___qtablewidgetitem4 = FinishedJobTbl->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Person", "Finish", 0));
        QTableWidgetItem *___qtablewidgetitem5 = FinishedJobTbl->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("Person", "Last Time", 0));
        QTableWidgetItem *___qtablewidgetitem6 = FinishedJobTbl->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("Person", "Deadline", 0));
        QTableWidgetItem *___qtablewidgetitem7 = FinishedJobTbl->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("Person", "Priority", 0));
        QTableWidgetItem *___qtablewidgetitem8 = FinishedJobTbl->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("Person", "Turnover", 0));
        QTableWidgetItem *___qtablewidgetitem9 = FinishedJobTbl->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("Person", "Weight Turnover", 0));
        ATT->setText(QApplication::translate("Person", "Average Turnover Time:", 0));
        ATTValue->setText(QApplication::translate("Person", "time", 0));
        WATT->setText(QApplication::translate("Person", "Weighted Average Turnover Time:", 0));
        WATTValue->setText(QApplication::translate("Person", "time", 0));
        PreInput->setTitle(QApplication::translate("Person", "Failed Jobs", 0));
        QTableWidgetItem *___qtablewidgetitem10 = FailedJobTbl->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("Person", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem11 = FailedJobTbl->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("Person", "Job Name", 0));
        QTableWidgetItem *___qtablewidgetitem12 = FailedJobTbl->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QApplication::translate("Person", "Join Time", 0));
        QTableWidgetItem *___qtablewidgetitem13 = FailedJobTbl->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QApplication::translate("Person", "Starting", 0));
        QTableWidgetItem *___qtablewidgetitem14 = FailedJobTbl->horizontalHeaderItem(4);
        ___qtablewidgetitem14->setText(QApplication::translate("Person", "RunTime", 0));
        QTableWidgetItem *___qtablewidgetitem15 = FailedJobTbl->horizontalHeaderItem(5);
        ___qtablewidgetitem15->setText(QApplication::translate("Person", "Last Time", 0));
        QTableWidgetItem *___qtablewidgetitem16 = FailedJobTbl->horizontalHeaderItem(6);
        ___qtablewidgetitem16->setText(QApplication::translate("Person", "DeadLine", 0));
        QTableWidgetItem *___qtablewidgetitem17 = FailedJobTbl->horizontalHeaderItem(7);
        ___qtablewidgetitem17->setText(QApplication::translate("Person", "Priority", 0));
        FailLbl->setText(QString());
        personBox->setTitle(QApplication::translate("Person", "Person Information", 0));
        UserNameLbl->setText(QApplication::translate("Person", "User Name", 0));
        PasswdLbl->setText(QApplication::translate("Person", "Password   ", 0));
        ModifyBtn->setText(QString());
        DeleteBtn->setText(QString());
        WarningChkBox->setText(QString());
        EchoChkBox->setText(QString());
        graphBox->setTitle(QApplication::translate("Person", "Graph", 0));
        GraphLbl->setText(QApplication::translate("Person", "Click to set graph", 0));
        gifBox->setTitle(QApplication::translate("Person", "Gif", 0));
        GifLbl->setText(QApplication::translate("Person", "Click to set gif", 0));
    } // retranslateUi

};

namespace Ui {
    class Person: public Ui_Person {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSON_H
