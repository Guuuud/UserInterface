#ifndef LOGINID_H
#define LOGINID_H

#include <QWidget>

namespace Ui {
class LoginId;
}

class LoginId : public QWidget
{
    Q_OBJECT

public:
    explicit LoginId(QWidget *parent = nullptr);
    ~LoginId();

protected:
    void mouseMoveEvent(QMouseEvent *e);//鼠标移动
    void mousePressEvent(QMouseEvent *e);//鼠标按下移动

private slots:
    void on_close_clicked();

    void on_minimized_clicked();

    void on_login_clicked();

    void receive_back();

    void on_pushButton_clicked();

signals:
    void show_login();

private:
    Ui::LoginId *ui;
    QPoint p;
};

#endif // LOGINID_H
