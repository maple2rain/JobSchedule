/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOBS_H
#define UI_JOBS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *List;
    QLabel *CurTimeLbl;
    QLCDNumber *CurTimeClock;
    QCheckBox *PSA;
    QCheckBox *PM;
    QPushButton *ClearAllDataBtn;
    QPushButton *Run;
    QGroupBox *Algorithm;
    QGridLayout *gridLayout;
    QRadioButton *FCFS;
    QRadioButton *EDF;
    QRadioButton *SJF;
    QRadioButton *HRRN;
    QRadioButton *MFQ;
    QRadioButton *RR;
    QGroupBox *Input;
    QLabel *JobNameLbl;
    QLineEdit *JobNameEdit;
    QLabel *JoinTimeLbl;
    QLabel *LastTimeLbl;
    QLabel *PriorityLbl;
    QPushButton *ClearInputBtn;
    QLineEdit *JoinTimeEdit;
    QLineEdit *LastTimeEdit;
    QPushButton *CommitInputBtn;
    QToolButton *OpenFile;
    QComboBox *PriorityCombo;
    QGroupBox *About;
    QLabel *label;
    QGroupBox *PreInput;
    QTableWidget *PreInputTbl;
    QGroupBox *RunningJob;
    QTableWidget *RunJobTbl;
    QGroupBox *ReadyJob;
    QTableWidget *ReadyJobTbl;
    QGroupBox *FinishedJob;
    QTableWidget *FinishedJobTbl;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *ATT;
    QLabel *ATTValue;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *WATT;
    QLabel *WATTValue;
    QGroupBox *NextJob;
    QTableWidget *NextJobTbl;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1301, 521);
        List = new QGroupBox(Widget);
        List->setObjectName(QStringLiteral("List"));
        List->setGeometry(QRect(10, 10, 261, 121));
        CurTimeLbl = new QLabel(List);
        CurTimeLbl->setObjectName(QStringLiteral("CurTimeLbl"));
        CurTimeLbl->setGeometry(QRect(50, 10, 71, 21));
        CurTimeClock = new QLCDNumber(List);
        CurTimeClock->setObjectName(QStringLiteral("CurTimeClock"));
        CurTimeClock->setGeometry(QRect(150, 10, 64, 23));
        PSA = new QCheckBox(List);
        PSA->setObjectName(QStringLiteral("PSA"));
        PSA->setGeometry(QRect(50, 50, 41, 16));
        PM = new QCheckBox(List);
        PM->setObjectName(QStringLiteral("PM"));
        PM->setGeometry(QRect(140, 50, 35, 16));
        ClearAllDataBtn = new QPushButton(List);
        ClearAllDataBtn->setObjectName(QStringLiteral("ClearAllDataBtn"));
        ClearAllDataBtn->setGeometry(QRect(50, 80, 75, 23));
        Run = new QPushButton(List);
        Run->setObjectName(QStringLiteral("Run"));
        Run->setGeometry(QRect(140, 80, 75, 23));
        Algorithm = new QGroupBox(Widget);
        Algorithm->setObjectName(QStringLiteral("Algorithm"));
        Algorithm->setGeometry(QRect(10, 140, 261, 71));
        gridLayout = new QGridLayout(Algorithm);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        FCFS = new QRadioButton(Algorithm);
        FCFS->setObjectName(QStringLiteral("FCFS"));

        gridLayout->addWidget(FCFS, 0, 0, 1, 1);

        EDF = new QRadioButton(Algorithm);
        EDF->setObjectName(QStringLiteral("EDF"));

        gridLayout->addWidget(EDF, 1, 2, 1, 1);

        SJF = new QRadioButton(Algorithm);
        SJF->setObjectName(QStringLiteral("SJF"));

        gridLayout->addWidget(SJF, 1, 0, 1, 1);

        HRRN = new QRadioButton(Algorithm);
        HRRN->setObjectName(QStringLiteral("HRRN"));

        gridLayout->addWidget(HRRN, 1, 1, 1, 1);

        MFQ = new QRadioButton(Algorithm);
        MFQ->setObjectName(QStringLiteral("MFQ"));

        gridLayout->addWidget(MFQ, 0, 1, 1, 1);

        RR = new QRadioButton(Algorithm);
        RR->setObjectName(QStringLiteral("RR"));

        gridLayout->addWidget(RR, 0, 2, 1, 1);

        Input = new QGroupBox(Widget);
        Input->setObjectName(QStringLiteral("Input"));
        Input->setGeometry(QRect(10, 220, 261, 181));
        JobNameLbl = new QLabel(Input);
        JobNameLbl->setObjectName(QStringLiteral("JobNameLbl"));
        JobNameLbl->setGeometry(QRect(30, 20, 54, 12));
        JobNameEdit = new QLineEdit(Input);
        JobNameEdit->setObjectName(QStringLiteral("JobNameEdit"));
        JobNameEdit->setGeometry(QRect(100, 20, 111, 20));
        JoinTimeLbl = new QLabel(Input);
        JoinTimeLbl->setObjectName(QStringLiteral("JoinTimeLbl"));
        JoinTimeLbl->setGeometry(QRect(30, 50, 54, 12));
        LastTimeLbl = new QLabel(Input);
        LastTimeLbl->setObjectName(QStringLiteral("LastTimeLbl"));
        LastTimeLbl->setGeometry(QRect(30, 80, 54, 12));
        PriorityLbl = new QLabel(Input);
        PriorityLbl->setObjectName(QStringLiteral("PriorityLbl"));
        PriorityLbl->setGeometry(QRect(30, 110, 54, 12));
        ClearInputBtn = new QPushButton(Input);
        ClearInputBtn->setObjectName(QStringLiteral("ClearInputBtn"));
        ClearInputBtn->setGeometry(QRect(30, 140, 71, 21));
        JoinTimeEdit = new QLineEdit(Input);
        JoinTimeEdit->setObjectName(QStringLiteral("JoinTimeEdit"));
        JoinTimeEdit->setGeometry(QRect(100, 50, 111, 20));
        LastTimeEdit = new QLineEdit(Input);
        LastTimeEdit->setObjectName(QStringLiteral("LastTimeEdit"));
        LastTimeEdit->setGeometry(QRect(100, 80, 111, 20));
        CommitInputBtn = new QPushButton(Input);
        CommitInputBtn->setObjectName(QStringLiteral("CommitInputBtn"));
        CommitInputBtn->setGeometry(QRect(110, 140, 71, 21));
        OpenFile = new QToolButton(Input);
        OpenFile->setObjectName(QStringLiteral("OpenFile"));
        OpenFile->setGeometry(QRect(190, 140, 41, 21));
        PriorityCombo = new QComboBox(Input);
        PriorityCombo->setObjectName(QStringLiteral("PriorityCombo"));
        PriorityCombo->setGeometry(QRect(100, 110, 61, 20));
        JobNameLbl->raise();
        JobNameEdit->raise();
        JoinTimeLbl->raise();
        LastTimeLbl->raise();
        PriorityLbl->raise();
        ClearInputBtn->raise();
        JoinTimeEdit->raise();
        LastTimeEdit->raise();
        CommitInputBtn->raise();
        OpenFile->raise();
        PriorityCombo->raise();
        About = new QGroupBox(Widget);
        About->setObjectName(QStringLiteral("About"));
        About->setGeometry(QRect(10, 410, 261, 91));
        label = new QLabel(About);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 231, 81));
        label->setAutoFillBackground(false);
        label->setTextFormat(Qt::RichText);
        label->setWordWrap(true);
        label->setOpenExternalLinks(true);
        label->setTextInteractionFlags(Qt::TextBrowserInteraction);
        PreInput = new QGroupBox(Widget);
        PreInput->setObjectName(QStringLiteral("PreInput"));
        PreInput->setGeometry(QRect(290, 10, 451, 261));
        PreInputTbl = new QTableWidget(PreInput);
        if (PreInputTbl->columnCount() < 4)
            PreInputTbl->setColumnCount(4);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        PreInputTbl->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        PreInputTbl->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        PreInputTbl->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        PreInputTbl->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        PreInputTbl->setObjectName(QStringLiteral("PreInputTbl"));
        PreInputTbl->setGeometry(QRect(20, 20, 411, 221));
        PreInputTbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        PreInputTbl->setDragEnabled(true);
        PreInputTbl->setAlternatingRowColors(true);
        PreInputTbl->setSortingEnabled(true);
        PreInputTbl->horizontalHeader()->setCascadingSectionResizes(false);
        RunningJob = new QGroupBox(Widget);
        RunningJob->setObjectName(QStringLiteral("RunningJob"));
        RunningJob->setGeometry(QRect(760, 10, 531, 101));
        RunJobTbl = new QTableWidget(RunningJob);
        if (RunJobTbl->columnCount() < 7)
            RunJobTbl->setColumnCount(7);
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        RunJobTbl->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        RunJobTbl->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        RunJobTbl->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        RunJobTbl->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font);
        RunJobTbl->setHorizontalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font);
        RunJobTbl->setHorizontalHeaderItem(5, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font);
        RunJobTbl->setHorizontalHeaderItem(6, __qtablewidgetitem10);
        RunJobTbl->setObjectName(QStringLiteral("RunJobTbl"));
        RunJobTbl->setGeometry(QRect(20, 20, 491, 61));
        RunJobTbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ReadyJob = new QGroupBox(Widget);
        ReadyJob->setObjectName(QStringLiteral("ReadyJob"));
        ReadyJob->setGeometry(QRect(290, 290, 451, 211));
        ReadyJobTbl = new QTableWidget(ReadyJob);
        if (ReadyJobTbl->columnCount() < 4)
            ReadyJobTbl->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font);
        ReadyJobTbl->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font);
        ReadyJobTbl->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font);
        ReadyJobTbl->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font);
        ReadyJobTbl->setHorizontalHeaderItem(3, __qtablewidgetitem14);
        ReadyJobTbl->setObjectName(QStringLiteral("ReadyJobTbl"));
        ReadyJobTbl->setGeometry(QRect(20, 20, 411, 171));
        ReadyJobTbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        FinishedJob = new QGroupBox(Widget);
        FinishedJob->setObjectName(QStringLiteral("FinishedJob"));
        FinishedJob->setGeometry(QRect(760, 250, 531, 251));
        FinishedJobTbl = new QTableWidget(FinishedJob);
        if (FinishedJobTbl->columnCount() < 7)
            FinishedJobTbl->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(3, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(4, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(5, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(6, __qtablewidgetitem21);
        FinishedJobTbl->setObjectName(QStringLiteral("FinishedJobTbl"));
        FinishedJobTbl->setGeometry(QRect(20, 20, 491, 191));
        FinishedJobTbl->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        FinishedJobTbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        layoutWidget = new QWidget(FinishedJob);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 220, 200, 14));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ATT = new QLabel(layoutWidget);
        ATT->setObjectName(QStringLiteral("ATT"));

        horizontalLayout->addWidget(ATT);

        ATTValue = new QLabel(layoutWidget);
        ATTValue->setObjectName(QStringLiteral("ATTValue"));

        horizontalLayout->addWidget(ATTValue);

        layoutWidget1 = new QWidget(FinishedJob);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(260, 220, 224, 14));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        WATT = new QLabel(layoutWidget1);
        WATT->setObjectName(QStringLiteral("WATT"));

        horizontalLayout_2->addWidget(WATT);

        WATTValue = new QLabel(layoutWidget1);
        WATTValue->setObjectName(QStringLiteral("WATTValue"));

        horizontalLayout_2->addWidget(WATTValue);

        FinishedJobTbl->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        ATT->raise();
        ATTValue->raise();
        ATTValue->raise();
        ATT->raise();
        NextJob = new QGroupBox(Widget);
        NextJob->setObjectName(QStringLiteral("NextJob"));
        NextJob->setGeometry(QRect(760, 130, 531, 101));
        NextJobTbl = new QTableWidget(NextJob);
        if (NextJobTbl->columnCount() < 7)
            NextJobTbl->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFont(font1);
        NextJobTbl->setHorizontalHeaderItem(0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFont(font);
        NextJobTbl->setHorizontalHeaderItem(1, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setFont(font);
        NextJobTbl->setHorizontalHeaderItem(2, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setFont(font);
        NextJobTbl->setHorizontalHeaderItem(3, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setFont(font);
        NextJobTbl->setHorizontalHeaderItem(4, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setFont(font);
        NextJobTbl->setHorizontalHeaderItem(5, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setFont(font);
        NextJobTbl->setHorizontalHeaderItem(6, __qtablewidgetitem28);
        NextJobTbl->setObjectName(QStringLiteral("NextJobTbl"));
        NextJobTbl->setGeometry(QRect(20, 20, 491, 61));
        NextJobTbl->setEditTriggers(QAbstractItemView::NoEditTriggers);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        List->setTitle(QApplication::translate("Widget", "List", 0));
        CurTimeLbl->setText(QApplication::translate("Widget", "Current Time", 0));
        PSA->setText(QApplication::translate("Widget", "PSA", 0));
        PM->setText(QApplication::translate("Widget", "PM", 0));
        ClearAllDataBtn->setText(QApplication::translate("Widget", "Clear", 0));
        Run->setText(QApplication::translate("Widget", "Run", 0));
        Algorithm->setTitle(QApplication::translate("Widget", "Algorithm", 0));
        FCFS->setText(QApplication::translate("Widget", "FCFS", 0));
        EDF->setText(QApplication::translate("Widget", "EDF", 0));
        SJF->setText(QApplication::translate("Widget", "SJF", 0));
        HRRN->setText(QApplication::translate("Widget", "HRRN", 0));
        MFQ->setText(QApplication::translate("Widget", "MFQ", 0));
        RR->setText(QApplication::translate("Widget", "RR", 0));
        Input->setTitle(QApplication::translate("Widget", "Input", 0));
        JobNameLbl->setText(QApplication::translate("Widget", "Job Name", 0));
        JoinTimeLbl->setText(QApplication::translate("Widget", "Join Time", 0));
        LastTimeLbl->setText(QApplication::translate("Widget", "Last Time", 0));
        PriorityLbl->setText(QApplication::translate("Widget", "Priority", 0));
        ClearInputBtn->setText(QApplication::translate("Widget", "Clear", 0));
        CommitInputBtn->setText(QApplication::translate("Widget", "Commit", 0));
        OpenFile->setText(QApplication::translate("Widget", "File", 0));
        PriorityCombo->clear();
        PriorityCombo->insertItems(0, QStringList()
         << QApplication::translate("Widget", "0", 0)
         << QApplication::translate("Widget", "1", 0)
         << QApplication::translate("Widget", "2", 0)
        );
        About->setTitle(QApplication::translate("Widget", "About", 0));
        label->setText(QApplication::translate("Widget", "This simple program was completed by Maple.For more infomation, please visit the author's <a href = \"http://blog.leanote.com/maple2snow\">Home Page</a>..", 0));
        PreInput->setTitle(QApplication::translate("Widget", "Pre Input", 0));
        QTableWidgetItem *___qtablewidgetitem = PreInputTbl->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "Job Name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = PreInputTbl->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "Commit Time", 0));
        QTableWidgetItem *___qtablewidgetitem2 = PreInputTbl->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget", "Last Time", 0));
        QTableWidgetItem *___qtablewidgetitem3 = PreInputTbl->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget", "Priority", 0));
        RunningJob->setTitle(QApplication::translate("Widget", "Running Job", 0));
        QTableWidgetItem *___qtablewidgetitem4 = RunJobTbl->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem5 = RunJobTbl->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget", "Commit", 0));
        QTableWidgetItem *___qtablewidgetitem6 = RunJobTbl->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget", "Last", 0));
        QTableWidgetItem *___qtablewidgetitem7 = RunJobTbl->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget", "Starting", 0));
        QTableWidgetItem *___qtablewidgetitem8 = RunJobTbl->horizontalHeaderItem(4);
        ___qtablewidgetitem8->setText(QApplication::translate("Widget", "Running", 0));
        QTableWidgetItem *___qtablewidgetitem9 = RunJobTbl->horizontalHeaderItem(5);
        ___qtablewidgetitem9->setText(QApplication::translate("Widget", "Need", 0));
        QTableWidgetItem *___qtablewidgetitem10 = RunJobTbl->horizontalHeaderItem(6);
        ___qtablewidgetitem10->setText(QApplication::translate("Widget", "Priority", 0));
        ReadyJob->setTitle(QApplication::translate("Widget", "Ready Job", 0));
        QTableWidgetItem *___qtablewidgetitem11 = ReadyJobTbl->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("Widget", "Job Name", 0));
        QTableWidgetItem *___qtablewidgetitem12 = ReadyJobTbl->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QApplication::translate("Widget", "Commit Time", 0));
        QTableWidgetItem *___qtablewidgetitem13 = ReadyJobTbl->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QApplication::translate("Widget", "Last Time", 0));
        QTableWidgetItem *___qtablewidgetitem14 = ReadyJobTbl->horizontalHeaderItem(3);
        ___qtablewidgetitem14->setText(QApplication::translate("Widget", "Priority", 0));
        FinishedJob->setTitle(QApplication::translate("Widget", "Finished Job", 0));
        QTableWidgetItem *___qtablewidgetitem15 = FinishedJobTbl->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QApplication::translate("Widget", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem16 = FinishedJobTbl->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QApplication::translate("Widget", "Commit", 0));
        QTableWidgetItem *___qtablewidgetitem17 = FinishedJobTbl->horizontalHeaderItem(2);
        ___qtablewidgetitem17->setText(QApplication::translate("Widget", "Start", 0));
        QTableWidgetItem *___qtablewidgetitem18 = FinishedJobTbl->horizontalHeaderItem(3);
        ___qtablewidgetitem18->setText(QApplication::translate("Widget", "Finish", 0));
        QTableWidgetItem *___qtablewidgetitem19 = FinishedJobTbl->horizontalHeaderItem(4);
        ___qtablewidgetitem19->setText(QApplication::translate("Widget", "Last", 0));
        QTableWidgetItem *___qtablewidgetitem20 = FinishedJobTbl->horizontalHeaderItem(5);
        ___qtablewidgetitem20->setText(QApplication::translate("Widget", "Turn Around", 0));
        QTableWidgetItem *___qtablewidgetitem21 = FinishedJobTbl->horizontalHeaderItem(6);
        ___qtablewidgetitem21->setText(QApplication::translate("Widget", "Weight Trun Around", 0));
        ATT->setText(QApplication::translate("Widget", "Average Turnaround Time", 0));
        ATTValue->setText(QApplication::translate("Widget", "time", 0));
        WATT->setText(QApplication::translate("Widget", "Weighted Average Turnaround Time", 0));
        WATTValue->setText(QApplication::translate("Widget", "time", 0));
        NextJob->setTitle(QApplication::translate("Widget", "Next Job", 0));
        QTableWidgetItem *___qtablewidgetitem22 = NextJobTbl->horizontalHeaderItem(0);
        ___qtablewidgetitem22->setText(QApplication::translate("Widget", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem23 = NextJobTbl->horizontalHeaderItem(1);
        ___qtablewidgetitem23->setText(QApplication::translate("Widget", "Commit", 0));
        QTableWidgetItem *___qtablewidgetitem24 = NextJobTbl->horizontalHeaderItem(2);
        ___qtablewidgetitem24->setText(QApplication::translate("Widget", "Last", 0));
        QTableWidgetItem *___qtablewidgetitem25 = NextJobTbl->horizontalHeaderItem(3);
        ___qtablewidgetitem25->setText(QApplication::translate("Widget", "Starting", 0));
        QTableWidgetItem *___qtablewidgetitem26 = NextJobTbl->horizontalHeaderItem(4);
        ___qtablewidgetitem26->setText(QApplication::translate("Widget", "Running", 0));
        QTableWidgetItem *___qtablewidgetitem27 = NextJobTbl->horizontalHeaderItem(5);
        ___qtablewidgetitem27->setText(QApplication::translate("Widget", "Need", 0));
        QTableWidgetItem *___qtablewidgetitem28 = NextJobTbl->horizontalHeaderItem(6);
        ___qtablewidgetitem28->setText(QApplication::translate("Widget", "Priority", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOBS_H
