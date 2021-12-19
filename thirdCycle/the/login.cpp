#include "login.h"
#include "ui_login.h"
#include <QMouseEvent>
#include <QMessageBox>
#include <QDebug>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    //去窗口边框
        setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //把窗口背景设置为透明;
        setAttribute(Qt::WA_TranslucentBackground);

}

Login::~Login()
{
    delete ui;
}


void Login::mousePressEvent(QMouseEvent *e)
{
//    if(e->button() == Qt::RightButton)
//    {
//        //如果是右键
//        close();
//    }
    if(e->button() == Qt::LeftButton)
    {
        //求坐标差值
        //当前点击坐标-窗口左上角坐标
        p = e->globalPos() - this->frameGeometry().topLeft();

    }
}

void Login::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        //移到左上角
        move(e->globalPos() - p);
    }

}

void Login::on_close_clicked()
{
    close();
}
void Login::on_minimized_clicked()
{
    showMinimized();
}


void Login::on_login_clicked()
{
//    int i = ui->lineEdit->cursorPosition();
//    i+=10;
//    qDebug() << i;
//    ui->lineEdit->setCursorPosition(i);
//    ui->lineEdit_2->setCursorPosition(i);
//    ui->lineEdit->setFocus();
//    ui->lineEdit_2->setFocus();
    ui->lineEdit->setAlignment(Qt::AlignJustify);
    if(ui->lineEdit->text().trimmed() == tr("admin") && ui->lineEdit_2->text() == tr("admin"))
        {
            this->hide();
            emit show_loginloading();
        }
        else
        {
           QMessageBox mess(QMessageBox::Information,tr("Warning!"),tr("Wrong user name or password!"));
           mess.setWindowIcon(QIcon(":/main/logo"));
           mess.exec();

        // 清空输入框内容
           ui->lineEdit->clear();
           ui->lineEdit_2->clear();
           //光标定位
           ui->lineEdit->setFocus();
        }
}

void Login::on_back_clicked()
{
    this->hide();
    emit show_loginid();

}


void Login::receive_loginid_login()
{
    this->show();
}
