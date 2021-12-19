#ifndef PAUSE_H
#define PAUSE_H

#include <QPushButton>
#include <QStyle>
#include <QWidget>
#include <QMediaPlayer>

class playButton: public QPushButton{
Q_OBJECT
public:
    explicit playButton(QWidget *parent): QPushButton(parent){
//        setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        // 我们不想使用 QStyle这样的内置组件，所以我们选择调用其它图片
        setIcon(QIcon(":/ico/pause.png"));
        setFixedSize(40,40);
        setFlat(true); // 消除边框颜色，让按钮背景色随 Widget背景
        setIconSize(QSize(40,40));
        setCursor((Qt::PointingHandCursor));
    }
private slots:
    void states(QMediaPlayer::State state);
};

#endif // PAUSE_H
