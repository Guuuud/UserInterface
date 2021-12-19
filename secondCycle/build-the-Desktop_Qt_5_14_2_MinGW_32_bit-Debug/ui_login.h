/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QFrame *frame;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QCheckBox *checkBox;
    QPushButton *login;
    QToolButton *close;
    QToolButton *minimized;
    QToolButton *back;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(652, 392);
        Login->setBaseSize(QSize(4, 0));
        Login->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background:rgb(255, 255, 255);\n"
"font-size:15px;\n"
"font-style:MingLiU-ExtB;\n"
"}\n"
"QFrame{\n"
"border:sold 10px rgba(0,0,0);\n"
"background-image: url(:/ico/background.png);\n"
"}\n"
"QLineEdit{\n"
"color:#8d98a1;\n"
"background-color:#405361;\n"
"font-size:16px;\n"
"border-style:outset;\n"
"border-radius:10px;\n"
"font-style:MingLiU-ExtB;\n"
"}\n"
"QPushButton{\n"
"background:#ced1d8;\n"
"border-style:outset;\n"
"border-radius:10px;\n"
"font-style:MingLiU-ExtB;\n"
"}\n"
"QPushButton:pressed{\n"
"background-color:rgb(224,0,0);\n"
"border-style:inset;\n"
"font-style:MingLiU-ExtB;\n"
"}\n"
"QCheckBox{\n"
"background:rgba(85,170,255,0);\n"
"color:black;\n"
"font-style:MingLiU-ExtB;\n"
"}\n"
"QLabel{\n"
"background:rgba(85,170,255,0);\n"
"color:black;\n"
"font-style:MingLiU-ExtB;\n"
"font-size:14px;\n"
"}\n"
""));
        frame = new QFrame(Login);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 631, 371));
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(170, 90, 271, 51));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 170, 271, 51));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(313, 240, 121, 20));
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(170, 240, 101, 18));
        login = new QPushButton(frame);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(170, 270, 271, 51));
        close = new QToolButton(frame);
        close->setObjectName(QString::fromUtf8("close"));
        close->setGeometry(QRect(580, 10, 38, 19));
        minimized = new QToolButton(frame);
        minimized->setObjectName(QString::fromUtf8("minimized"));
        minimized->setGeometry(QRect(530, 10, 38, 19));
        back = new QToolButton(frame);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 10, 61, 19));

        retranslateUi(Login);

        login->setDefault(false);


        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Widget", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Login", "Username", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("Login", "Password", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "forget password", nullptr));
        checkBox->setText(QCoreApplication::translate("Login", "remember", nullptr));
        login->setText(QCoreApplication::translate("Login", "Login", nullptr));
        close->setText(QCoreApplication::translate("Login", "\303\227", nullptr));
        minimized->setText(QCoreApplication::translate("Login", "\342\200\224", nullptr));
        back->setText(QCoreApplication::translate("Login", "back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
