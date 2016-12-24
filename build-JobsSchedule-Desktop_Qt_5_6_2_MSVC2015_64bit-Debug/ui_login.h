/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

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

class Ui_Login
{
public:
    QPushButton *LoginBtn;
    QPushButton *RegisterBtn;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *UserNameLbl;
    QLineEdit *UserNameLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *PasswdLbl;
    QLineEdit *PasswdLineEdit;
    QFrame *frame;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(268, 163);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/ico.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Login->setWindowIcon(icon);
        Login->setAutoFillBackground(true);
        Login->setStyleSheet(QStringLiteral(""));
        LoginBtn = new QPushButton(Login);
        LoginBtn->setObjectName(QStringLiteral("LoginBtn"));
        LoginBtn->setGeometry(QRect(30, 120, 75, 23));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setBold(true);
        font.setWeight(75);
        LoginBtn->setFont(font);
        LoginBtn->setAutoFillBackground(false);
        LoginBtn->setStyleSheet(QStringLiteral("background-color:rgb(249, 249, 249)"));
        RegisterBtn = new QPushButton(Login);
        RegisterBtn->setObjectName(QStringLiteral("RegisterBtn"));
        RegisterBtn->setGeometry(QRect(160, 120, 75, 23));
        RegisterBtn->setFont(font);
        RegisterBtn->setAutoFillBackground(false);
        RegisterBtn->setStyleSheet(QStringLiteral("background-color:rgb(249, 249, 249)"));
        layoutWidget = new QWidget(Login);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 214, 71));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 9);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        UserNameLbl = new QLabel(layoutWidget);
        UserNameLbl->setObjectName(QStringLiteral("UserNameLbl"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        UserNameLbl->setFont(font1);

        horizontalLayout->addWidget(UserNameLbl);

        UserNameLineEdit = new QLineEdit(layoutWidget);
        UserNameLineEdit->setObjectName(QStringLiteral("UserNameLineEdit"));

        horizontalLayout->addWidget(UserNameLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        PasswdLbl = new QLabel(layoutWidget);
        PasswdLbl->setObjectName(QStringLiteral("PasswdLbl"));
        PasswdLbl->setFont(font);

        horizontalLayout_2->addWidget(PasswdLbl, 0, Qt::AlignRight);

        PasswdLineEdit = new QLineEdit(layoutWidget);
        PasswdLineEdit->setObjectName(QStringLiteral("PasswdLineEdit"));
        PasswdLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(PasswdLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        frame = new QFrame(Login);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, 0, 271, 171));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QStringLiteral("background-image:url(:/images/images/talent.png)"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        layoutWidget->raise();
        LoginBtn->raise();
        RegisterBtn->raise();

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", 0));
        LoginBtn->setText(QApplication::translate("Login", "Sign In", 0));
        RegisterBtn->setText(QApplication::translate("Login", "Sign Up", 0));
        UserNameLbl->setText(QApplication::translate("Login", "User Name", 0));
        PasswdLbl->setText(QApplication::translate("Login", "Password   ", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
