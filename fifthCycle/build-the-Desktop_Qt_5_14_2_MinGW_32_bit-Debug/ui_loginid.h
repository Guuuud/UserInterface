/********************************************************************************
** Form generated from reading UI file 'loginid.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINID_H
#define UI_LOGINID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginId
{
public:
    QFrame *frame;
    QToolButton *close;
    QToolButton *minimized;
    QPushButton *login;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *LoginId)
    {
        if (LoginId->objectName().isEmpty())
            LoginId->setObjectName(QString::fromUtf8("LoginId"));
        LoginId->resize(651, 389);
        LoginId->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background:rgb(255, 255, 255);\n"
"font-size:15px;\n"
"font-style:MingLiU-ExtB;\n"
"}\n"
"QFrame{\n"
"border:sold 10px rgba(0,0,0);\n"
"background-image:url(:/ico/background.png)\n"
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
"color:white;\n"
"font-style:MingLiU-ExtB;\n"
"}\n"
"QLabel{\n"
"background:rgba(85,170,255,0);\n"
"color:white;\n"
"font-style:MingLiU-ExtB;\n"
"font-size:14px;\n"
"}\n"
""));
        frame = new QFrame(LoginId);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 631, 371));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        close = new QToolButton(frame);
        close->setObjectName(QString::fromUtf8("close"));
        close->setGeometry(QRect(580, 10, 38, 19));
        minimized = new QToolButton(frame);
        minimized->setObjectName(QString::fromUtf8("minimized"));
        minimized->setGeometry(QRect(530, 10, 38, 19));
        login = new QPushButton(frame);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(20, 10, 80, 20));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(210, 50, 311, 61));
        lineEdit_2 = new QLineEdit(frame);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(210, 130, 311, 61));
        lineEdit_3 = new QLineEdit(frame);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(210, 210, 311, 61));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 310, 80, 20));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 70, 91, 20));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(80, 160, 101, 16));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(80, 240, 121, 16));

        retranslateUi(LoginId);

        QMetaObject::connectSlotsByName(LoginId);
    } // setupUi

    void retranslateUi(QWidget *LoginId)
    {
        LoginId->setWindowTitle(QCoreApplication::translate("LoginId", "Form", nullptr));
        close->setText(QCoreApplication::translate("LoginId", "\303\227", nullptr));
        minimized->setText(QCoreApplication::translate("LoginId", "\342\200\224", nullptr));
        login->setText(QCoreApplication::translate("LoginId", "\347\231\273\345\275\225", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("LoginId", "\347\224\250\346\210\267\345\220\215", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("LoginId", "\345\257\206\347\240\201", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("LoginId", "\345\257\206\347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginId", "\346\263\250\345\206\214", nullptr));
        label->setText(QCoreApplication::translate("LoginId", "\346\263\250\345\206\214\346\226\260\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("LoginId", "\351\200\211\346\213\251\346\202\250\347\232\204\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("LoginId", "\345\206\215\346\254\241\350\276\223\345\205\245\346\202\250\347\232\204\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginId: public Ui_LoginId {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINID_H
