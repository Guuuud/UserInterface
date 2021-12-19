#ifndef SETFULLSCREEN_H
#define SETFULLSCREEN_H

#include <QPushButton>
#include <QStyle>
#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMouseEvent>

class videoFullScreen : public QVideoWidget{
Q_OBJECT
public:
    videoFullScreen():QVideoWidget(){
    }
protected:
    void clickFullScreenButton(QKeyEvent *click);
    void keyPressEvent(QKeyEvent *event);
private slots:
    void setToFullScreen(bool full);
};

#endif // SETFULLSCREEN_H
