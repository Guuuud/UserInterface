#include "loginid.h"
#include "ui_loginid.h"
#include <QMouseEvent>
#include <QMessageBox>
LoginId::LoginId(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginId)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    //把窗口背景设置为透明;
        setAttribute(Qt::WA_TranslucentBackground);
}

LoginId::~LoginId()
{
    delete ui;
}


void LoginId::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        //求坐标差值
        //当前点击坐标-窗口左上角坐标
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}

void LoginId::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        //移到左上角
        move(e->globalPos() - p);
    }

}

void LoginId::on_close_clicked()
{
    close();
}
void LoginId::on_minimized_clicked()
{
    showMinimized();
}

void LoginId::on_login_clicked()
{
    this->hide();
    emit show_login();
}


void LoginId::receive_back()
{
    this->show();
}



void LoginId::on_pushButton_clicked()
{
    QMessageBox mess(QMessageBox::Information,tr("Warning!"),tr("注册功能暂不开放!"));
    mess.setWindowIcon(QIcon(":/main/logo"));
    mess.exec();
}
