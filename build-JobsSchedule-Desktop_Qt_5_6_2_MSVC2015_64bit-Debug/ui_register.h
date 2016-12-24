/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QPushButton *OkBtn;
    QPushButton *CancelBtn;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *UserNameLbl;
    QLineEdit *UserNameLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *PasswdLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *ConfirmLbl;
    QLineEdit *ConfirmLineEdit;
    QFrame *frame;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(287, 172);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/ico.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Register->setWindowIcon(icon);
        OkBtn = new QPushButton(Register);
        OkBtn->setObjectName(QStringLiteral("OkBtn"));
        OkBtn->setGeometry(QRect(30, 130, 75, 23));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setBold(true);
        font.setWeight(75);
        OkBtn->setFont(font);
        OkBtn->setStyleSheet(QStringLiteral("background-color:rgb(249, 249, 249)"));
        CancelBtn = new QPushButton(Register);
        CancelBtn->setObjectName(QStringLiteral("CancelBtn"));
        CancelBtn->setGeometry(QRect(170, 130, 75, 23));
        CancelBtn->setFont(font);
        CancelBtn->setStyleSheet(QStringLiteral("background-color:rgb(249, 249, 249)"));
        layoutWidget = new QWidget(Register);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 10, 211, 101));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        UserNameLbl = new QLabel(layoutWidget);
        UserNameLbl->setObjectName(QStringLiteral("UserNameLbl"));
        UserNameLbl->setFont(font);

        horizontalLayout->addWidget(UserNameLbl);

        UserNameLineEdit = new QLineEdit(layoutWidget);
        UserNameLineEdit->setObjectName(QStringLiteral("UserNameLineEdit"));

        horizontalLayout->addWidget(UserNameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        PasswdLineEdit = new QLineEdit(layoutWidget);
        PasswdLineEdit->setObjectName(QStringLiteral("PasswdLineEdit"));
        PasswdLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(PasswdLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        ConfirmLbl = new QLabel(layoutWidget);
        ConfirmLbl->setObjectName(QStringLiteral("ConfirmLbl"));
        ConfirmLbl->setMaximumSize(QSize(16777215, 16777215));
        ConfirmLbl->setFont(font);

        horizontalLayout_3->addWidget(ConfirmLbl);

        ConfirmLineEdit = new QLineEdit(layoutWidget);
        ConfirmLineEdit->setObjectName(QStringLiteral("ConfirmLineEdit"));
        ConfirmLineEdit->setMaximumSize(QSize(16777215, 16777215));
        ConfirmLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(ConfirmLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        frame = new QFrame(Register);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(-290, -79, 581, 351));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QStringLiteral("background-image:url(:/images/images/talent.png)"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        OkBtn->raise();
        CancelBtn->raise();
        layoutWidget->raise();

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Sign Up", 0));
        OkBtn->setText(QApplication::translate("Register", "OK", 0));
        CancelBtn->setText(QApplication::translate("Register", "Cancel", 0));
        UserNameLbl->setText(QApplication::translate("Register", "User Name", 0));
        label->setText(QApplication::translate("Register", "Password   ", 0));
        ConfirmLbl->setText(QApplication::translate("Register", "Confirmed  ", 0));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
