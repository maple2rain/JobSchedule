/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
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
    QPushButton *RunBtn;
    QPushButton *PauseBtn;
    QPushButton *StopBtn;
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
    QLabel *DeadLineLbl;
    QLineEdit *DeadLineEdit;
    QGroupBox *About;
    QLabel *AboutLbl;
    QGroupBox *PreInput;
    QTableWidget *PreInputTbl;
    QGroupBox *RunningJob;
    QTableWidget *RunJobTbl;
    QGroupBox *ReadyJob;
    QTableWidget *ReadyJobTbl;
    QGroupBox *FinishedJob;
    QTableWidget *FinishedJobTbl;
    QWidget *layoutWidget;
    QHBoxLayout *ATTHL;
    QLabel *ATT;
    QLabel *ATTValue;
    QWidget *layoutWidget1;
    QHBoxLayout *WATTHL;
    QLabel *WATT;
    QLabel *WATTValue;
    QGroupBox *NextJob;
    QTableWidget *NextJobTbl;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1372, 563);
        Widget->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/ico.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        List = new QGroupBox(Widget);
        List->setObjectName(QStringLiteral("List"));
        List->setGeometry(QRect(10, 10, 261, 141));
        CurTimeLbl = new QLabel(List);
        CurTimeLbl->setObjectName(QStringLiteral("CurTimeLbl"));
        CurTimeLbl->setGeometry(QRect(50, 10, 71, 21));
        CurTimeClock = new QLCDNumber(List);
        CurTimeClock->setObjectName(QStringLiteral("CurTimeClock"));
        CurTimeClock->setGeometry(QRect(150, 10, 64, 23));
        CurTimeClock->setAutoFillBackground(false);
        CurTimeClock->setStyleSheet(QStringLiteral("background-color:rgbrgb(253, 255, 221)"));
        CurTimeClock->setDigitCount(5);
        PSA = new QCheckBox(List);
        PSA->setObjectName(QStringLiteral("PSA"));
        PSA->setGeometry(QRect(50, 50, 41, 16));
        PM = new QCheckBox(List);
        PM->setObjectName(QStringLiteral("PM"));
        PM->setGeometry(QRect(140, 50, 35, 16));
        ClearAllDataBtn = new QPushButton(List);
        ClearAllDataBtn->setObjectName(QStringLiteral("ClearAllDataBtn"));
        ClearAllDataBtn->setGeometry(QRect(50, 80, 75, 23));
        RunBtn = new QPushButton(List);
        RunBtn->setObjectName(QStringLiteral("RunBtn"));
        RunBtn->setGeometry(QRect(140, 80, 75, 23));
        PauseBtn = new QPushButton(List);
        PauseBtn->setObjectName(QStringLiteral("PauseBtn"));
        PauseBtn->setGeometry(QRect(50, 110, 75, 23));
        PauseBtn->setCursor(QCursor(Qt::ArrowCursor));
        PauseBtn->setMouseTracking(true);
        PauseBtn->setAutoFillBackground(true);
        StopBtn = new QPushButton(List);
        StopBtn->setObjectName(QStringLiteral("StopBtn"));
        StopBtn->setGeometry(QRect(140, 110, 75, 23));
        Algorithm = new QGroupBox(Widget);
        Algorithm->setObjectName(QStringLiteral("Algorithm"));
        Algorithm->setGeometry(QRect(10, 160, 261, 71));
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
        Input->setGeometry(QRect(10, 240, 261, 221));
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
        PriorityLbl->setGeometry(QRect(30, 140, 54, 12));
        ClearInputBtn = new QPushButton(Input);
        ClearInputBtn->setObjectName(QStringLiteral("ClearInputBtn"));
        ClearInputBtn->setGeometry(QRect(30, 180, 71, 21));
        JoinTimeEdit = new QLineEdit(Input);
        JoinTimeEdit->setObjectName(QStringLiteral("JoinTimeEdit"));
        JoinTimeEdit->setGeometry(QRect(100, 50, 111, 20));
        LastTimeEdit = new QLineEdit(Input);
        LastTimeEdit->setObjectName(QStringLiteral("LastTimeEdit"));
        LastTimeEdit->setGeometry(QRect(100, 80, 111, 20));
        CommitInputBtn = new QPushButton(Input);
        CommitInputBtn->setObjectName(QStringLiteral("CommitInputBtn"));
        CommitInputBtn->setGeometry(QRect(110, 180, 71, 21));
        OpenFile = new QToolButton(Input);
        OpenFile->setObjectName(QStringLiteral("OpenFile"));
        OpenFile->setGeometry(QRect(190, 180, 41, 21));
        PriorityCombo = new QComboBox(Input);
        PriorityCombo->setObjectName(QStringLiteral("PriorityCombo"));
        PriorityCombo->setGeometry(QRect(100, 140, 61, 20));
        DeadLineLbl = new QLabel(Input);
        DeadLineLbl->setObjectName(QStringLiteral("DeadLineLbl"));
        DeadLineLbl->setGeometry(QRect(30, 110, 54, 12));
        DeadLineEdit = new QLineEdit(Input);
        DeadLineEdit->setObjectName(QStringLiteral("DeadLineEdit"));
        DeadLineEdit->setGeometry(QRect(100, 110, 111, 20));
        About = new QGroupBox(Widget);
        About->setObjectName(QStringLiteral("About"));
        About->setGeometry(QRect(10, 470, 261, 81));
        AboutLbl = new QLabel(About);
        AboutLbl->setObjectName(QStringLiteral("AboutLbl"));
        AboutLbl->setGeometry(QRect(10, 10, 231, 71));
        AboutLbl->setAutoFillBackground(false);
        AboutLbl->setTextFormat(Qt::RichText);
        AboutLbl->setWordWrap(true);
        AboutLbl->setOpenExternalLinks(true);
        AboutLbl->setTextInteractionFlags(Qt::TextBrowserInteraction);
        PreInput = new QGroupBox(Widget);
        PreInput->setObjectName(QStringLiteral("PreInput"));
        PreInput->setGeometry(QRect(290, 10, 431, 261));
        PreInputTbl = new QTableWidget(PreInput);
        if (PreInputTbl->columnCount() < 5)
            PreInputTbl->setColumnCount(5);
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
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        PreInputTbl->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        PreInputTbl->setObjectName(QStringLiteral("PreInputTbl"));
        PreInputTbl->setGeometry(QRect(20, 20, 391, 211));
        PreInputTbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        PreInputTbl->setDragEnabled(true);
        PreInputTbl->setAlternatingRowColors(true);
        PreInputTbl->setSortingEnabled(true);
        PreInputTbl->horizontalHeader()->setCascadingSectionResizes(false);
        PreInputTbl->horizontalHeader()->setDefaultSectionSize(75);
        PreInputTbl->horizontalHeader()->setMinimumSectionSize(15);
        PreInputTbl->horizontalHeader()->setStretchLastSection(true);
        PreInputTbl->verticalHeader()->setDefaultSectionSize(25);
        RunningJob = new QGroupBox(Widget);
        RunningJob->setObjectName(QStringLiteral("RunningJob"));
        RunningJob->setGeometry(QRect(740, 10, 471, 101));
        RunJobTbl = new QTableWidget(RunningJob);
        if (RunJobTbl->columnCount() < 7)
            RunJobTbl->setColumnCount(7);
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font1);
        RunJobTbl->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        RunJobTbl->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        RunJobTbl->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font);
        RunJobTbl->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font);
        RunJobTbl->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font);
        RunJobTbl->setHorizontalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font);
        RunJobTbl->setHorizontalHeaderItem(6, __qtablewidgetitem11);
        RunJobTbl->setObjectName(QStringLiteral("RunJobTbl"));
        RunJobTbl->setGeometry(QRect(20, 20, 441, 61));
        RunJobTbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        RunJobTbl->horizontalHeader()->setDefaultSectionSize(60);
        RunJobTbl->horizontalHeader()->setStretchLastSection(true);
        RunJobTbl->verticalHeader()->setDefaultSectionSize(25);
        ReadyJob = new QGroupBox(Widget);
        ReadyJob->setObjectName(QStringLiteral("ReadyJob"));
        ReadyJob->setGeometry(QRect(290, 290, 431, 261));
        ReadyJobTbl = new QTableWidget(ReadyJob);
        if (ReadyJobTbl->columnCount() < 5)
            ReadyJobTbl->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font);
        ReadyJobTbl->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font);
        ReadyJobTbl->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font);
        ReadyJobTbl->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font);
        ReadyJobTbl->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font);
        ReadyJobTbl->setHorizontalHeaderItem(4, __qtablewidgetitem16);
        ReadyJobTbl->setObjectName(QStringLiteral("ReadyJobTbl"));
        ReadyJobTbl->setGeometry(QRect(20, 20, 391, 221));
        ReadyJobTbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ReadyJobTbl->setSortingEnabled(true);
        ReadyJobTbl->horizontalHeader()->setDefaultSectionSize(75);
        ReadyJobTbl->horizontalHeader()->setStretchLastSection(true);
        ReadyJobTbl->verticalHeader()->setDefaultSectionSize(25);
        FinishedJob = new QGroupBox(Widget);
        FinishedJob->setObjectName(QStringLiteral("FinishedJob"));
        FinishedJob->setGeometry(QRect(740, 250, 621, 301));
        FinishedJobTbl = new QTableWidget(FinishedJob);
        if (FinishedJobTbl->columnCount() < 8)
            FinishedJobTbl->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(4, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(5, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(6, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setFont(font);
        FinishedJobTbl->setHorizontalHeaderItem(7, __qtablewidgetitem24);
        FinishedJobTbl->setObjectName(QStringLiteral("FinishedJobTbl"));
        FinishedJobTbl->setGeometry(QRect(20, 20, 591, 231));
        FinishedJobTbl->setAutoFillBackground(true);
        FinishedJobTbl->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        FinishedJobTbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        FinishedJobTbl->setSortingEnabled(true);
        FinishedJobTbl->horizontalHeader()->setDefaultSectionSize(65);
        FinishedJobTbl->horizontalHeader()->setStretchLastSection(true);
        FinishedJobTbl->verticalHeader()->setDefaultSectionSize(25);
        layoutWidget = new QWidget(FinishedJob);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 270, 200, 14));
        ATTHL = new QHBoxLayout(layoutWidget);
        ATTHL->setSpacing(6);
        ATTHL->setContentsMargins(11, 11, 11, 11);
        ATTHL->setObjectName(QStringLiteral("ATTHL"));
        ATTHL->setContentsMargins(0, 0, 0, 0);
        ATT = new QLabel(layoutWidget);
        ATT->setObjectName(QStringLiteral("ATT"));

        ATTHL->addWidget(ATT);

        ATTValue = new QLabel(layoutWidget);
        ATTValue->setObjectName(QStringLiteral("ATTValue"));

        ATTHL->addWidget(ATTValue);

        layoutWidget1 = new QWidget(FinishedJob);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(320, 270, 230, 14));
        WATTHL = new QHBoxLayout(layoutWidget1);
        WATTHL->setSpacing(6);
        WATTHL->setContentsMargins(11, 11, 11, 11);
        WATTHL->setObjectName(QStringLiteral("WATTHL"));
        WATTHL->setContentsMargins(0, 0, 0, 0);
        WATT = new QLabel(layoutWidget1);
        WATT->setObjectName(QStringLiteral("WATT"));

        WATTHL->addWidget(WATT);

        WATTValue = new QLabel(layoutWidget1);
        WATTValue->setObjectName(QStringLiteral("WATTValue"));

        WATTHL->addWidget(WATTValue);

        NextJob = new QGroupBox(Widget);
        NextJob->setObjectName(QStringLiteral("NextJob"));
        NextJob->setGeometry(QRect(740, 130, 471, 101));
        NextJobTbl = new QTableWidget(NextJob);
        if (NextJobTbl->columnCount() < 7)
            NextJobTbl->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setFont(font1);
        NextJobTbl->setHorizontalHeaderItem(0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setFont(font);
        NextJobTbl->setHorizontalHeaderItem(1, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setFont(font);
        NextJobTbl->setHorizontalHeaderItem(2, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setFont(font);
        NextJobTbl->setHorizontalHeaderItem(3, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        __qtablewidgetitem29->setFont(font);
        NextJobTbl->setHorizontalHeaderItem(4, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setFont(font);
        NextJobTbl->setHorizontalHeaderItem(5, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        __qtablewidgetitem31->setFont(font);
        NextJobTbl->setHorizontalHeaderItem(6, __qtablewidgetitem31);
        NextJobTbl->setObjectName(QStringLiteral("NextJobTbl"));
        NextJobTbl->setGeometry(QRect(20, 20, 441, 61));
        NextJobTbl->setEditTriggers(QAbstractItemView::NoEditTriggers);
        NextJobTbl->horizontalHeader()->setDefaultSectionSize(60);
        NextJobTbl->horizontalHeader()->setStretchLastSection(true);
        graphicsView = new QGraphicsView(Widget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(1230, 10, 131, 221));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Jobs Scheduler", 0));
        List->setTitle(QApplication::translate("Widget", "List", 0));
        CurTimeLbl->setText(QApplication::translate("Widget", "Current Time", 0));
        PSA->setText(QApplication::translate("Widget", "PSA", 0));
        PM->setText(QApplication::translate("Widget", "PM", 0));
        ClearAllDataBtn->setText(QApplication::translate("Widget", "Clear", 0));
        RunBtn->setText(QApplication::translate("Widget", "Run", 0));
#ifndef QT_NO_STATUSTIP
        PauseBtn->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        PauseBtn->setText(QApplication::translate("Widget", "Pause", 0));
        StopBtn->setText(QApplication::translate("Widget", "Stop", 0));
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
         << QApplication::translate("Widget", "3", 0)
         << QApplication::translate("Widget", "4", 0)
         << QApplication::translate("Widget", "5", 0)
         << QApplication::translate("Widget", "6", 0)
         << QApplication::translate("Widget", "7", 0)
         << QApplication::translate("Widget", "8", 0)
         << QApplication::translate("Widget", "9", 0)
         << QApplication::translate("Widget", "10", 0)
         << QApplication::translate("Widget", "11", 0)
         << QApplication::translate("Widget", "12", 0)
         << QApplication::translate("Widget", "13", 0)
         << QApplication::translate("Widget", "14", 0)
         << QApplication::translate("Widget", "15", 0)
        );
        DeadLineLbl->setText(QApplication::translate("Widget", "DeadLine", 0));
        About->setTitle(QApplication::translate("Widget", "About", 0));
        AboutLbl->setText(QApplication::translate("Widget", "This simple program was completed by Maple.For more infomation, please visit the author's <a href = \"http://blog.leanote.com/maple2snow\">Home Page</a>..", 0));
        PreInput->setTitle(QApplication::translate("Widget", "Pre Input", 0));
        QTableWidgetItem *___qtablewidgetitem = PreInputTbl->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "Job Name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = PreInputTbl->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "Commit Time", 0));
        QTableWidgetItem *___qtablewidgetitem2 = PreInputTbl->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget", "Last Time", 0));
        QTableWidgetItem *___qtablewidgetitem3 = PreInputTbl->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget", "DeadLine", 0));
        QTableWidgetItem *___qtablewidgetitem4 = PreInputTbl->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget", "Priority", 0));
        RunningJob->setTitle(QApplication::translate("Widget", "Running Job", 0));
        QTableWidgetItem *___qtablewidgetitem5 = RunJobTbl->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem6 = RunJobTbl->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget", "Commit", 0));
        QTableWidgetItem *___qtablewidgetitem7 = RunJobTbl->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget", "Last", 0));
        QTableWidgetItem *___qtablewidgetitem8 = RunJobTbl->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("Widget", "Starting", 0));
        QTableWidgetItem *___qtablewidgetitem9 = RunJobTbl->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QApplication::translate("Widget", "Running", 0));
        QTableWidgetItem *___qtablewidgetitem10 = RunJobTbl->horizontalHeaderItem(5);
        ___qtablewidgetitem10->setText(QApplication::translate("Widget", "Need", 0));
        QTableWidgetItem *___qtablewidgetitem11 = RunJobTbl->horizontalHeaderItem(6);
        ___qtablewidgetitem11->setText(QApplication::translate("Widget", "Priority", 0));
        ReadyJob->setTitle(QApplication::translate("Widget", "Ready Job", 0));
        QTableWidgetItem *___qtablewidgetitem12 = ReadyJobTbl->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QApplication::translate("Widget", "Job Name", 0));
        QTableWidgetItem *___qtablewidgetitem13 = ReadyJobTbl->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QApplication::translate("Widget", "Commit Time", 0));
        QTableWidgetItem *___qtablewidgetitem14 = ReadyJobTbl->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QApplication::translate("Widget", "Last Time", 0));
        QTableWidgetItem *___qtablewidgetitem15 = ReadyJobTbl->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QApplication::translate("Widget", "Deadline", 0));
        QTableWidgetItem *___qtablewidgetitem16 = ReadyJobTbl->horizontalHeaderItem(4);
        ___qtablewidgetitem16->setText(QApplication::translate("Widget", "Priority", 0));
        FinishedJob->setTitle(QApplication::translate("Widget", "Finished Job", 0));
        QTableWidgetItem *___qtablewidgetitem17 = FinishedJobTbl->horizontalHeaderItem(0);
        ___qtablewidgetitem17->setText(QApplication::translate("Widget", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem18 = FinishedJobTbl->horizontalHeaderItem(1);
        ___qtablewidgetitem18->setText(QApplication::translate("Widget", "Commit", 0));
        QTableWidgetItem *___qtablewidgetitem19 = FinishedJobTbl->horizontalHeaderItem(2);
        ___qtablewidgetitem19->setText(QApplication::translate("Widget", "Starting", 0));
        QTableWidgetItem *___qtablewidgetitem20 = FinishedJobTbl->horizontalHeaderItem(3);
        ___qtablewidgetitem20->setText(QApplication::translate("Widget", "Finish", 0));
        QTableWidgetItem *___qtablewidgetitem21 = FinishedJobTbl->horizontalHeaderItem(4);
        ___qtablewidgetitem21->setText(QApplication::translate("Widget", "Last", 0));
        QTableWidgetItem *___qtablewidgetitem22 = FinishedJobTbl->horizontalHeaderItem(5);
        ___qtablewidgetitem22->setText(QApplication::translate("Widget", "Deadline", 0));
        QTableWidgetItem *___qtablewidgetitem23 = FinishedJobTbl->horizontalHeaderItem(6);
        ___qtablewidgetitem23->setText(QApplication::translate("Widget", "Turn Over", 0));
        QTableWidgetItem *___qtablewidgetitem24 = FinishedJobTbl->horizontalHeaderItem(7);
        ___qtablewidgetitem24->setText(QApplication::translate("Widget", "Weight Trun over", 0));
        ATT->setText(QApplication::translate("Widget", "Average Turnover Time:", 0));
        ATTValue->setText(QApplication::translate("Widget", "time", 0));
        WATT->setText(QApplication::translate("Widget", "Weighted Average Turnover Time:", 0));
        WATTValue->setText(QApplication::translate("Widget", "time", 0));
        NextJob->setTitle(QApplication::translate("Widget", "Next Job", 0));
        QTableWidgetItem *___qtablewidgetitem25 = NextJobTbl->horizontalHeaderItem(0);
        ___qtablewidgetitem25->setText(QApplication::translate("Widget", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem26 = NextJobTbl->horizontalHeaderItem(1);
        ___qtablewidgetitem26->setText(QApplication::translate("Widget", "Commit", 0));
        QTableWidgetItem *___qtablewidgetitem27 = NextJobTbl->horizontalHeaderItem(2);
        ___qtablewidgetitem27->setText(QApplication::translate("Widget", "Last", 0));
        QTableWidgetItem *___qtablewidgetitem28 = NextJobTbl->horizontalHeaderItem(3);
        ___qtablewidgetitem28->setText(QApplication::translate("Widget", "Starting", 0));
        QTableWidgetItem *___qtablewidgetitem29 = NextJobTbl->horizontalHeaderItem(4);
        ___qtablewidgetitem29->setText(QApplication::translate("Widget", "Running", 0));
        QTableWidgetItem *___qtablewidgetitem30 = NextJobTbl->horizontalHeaderItem(5);
        ___qtablewidgetitem30->setText(QApplication::translate("Widget", "Need", 0));
        QTableWidgetItem *___qtablewidgetitem31 = NextJobTbl->horizontalHeaderItem(6);
        ___qtablewidgetitem31->setText(QApplication::translate("Widget", "Priority", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
