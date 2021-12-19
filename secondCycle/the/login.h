#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

protected:

    void mouseMoveEvent(QMouseEvent *e);//鼠标移动
    void mousePressEvent(QMouseEvent *e);//鼠标按下移动

private slots:
    void on_close_clicked();

    void on_minimized_clicked();

    void on_login_clicked();

    void on_back_clicked();

    void receive_loginid_login();

signals:
    void show_loginloading();

    void show_loginid();
private:
    Ui::Login *ui;

    QPoint p;

};
#endif // Login_H
