#ifndef PLAYANDPAUSEBTN_H
#define PLAYANDPAUSEBTN_H

#include<QPushButton>
#include <QWidget>
#include <QMediaPlayer>

class playPauseButton : public QPushButton{
Q_OBJECT
    explicit playPauseButton(QWidget* parent): QPushButton(parent){
    setIcon(QIcon(":/ico/pause.png"));
    setFixedSize(40,40);
    setFlat(true); // 消除边框颜色，让按钮背景色随 Widget背景
    setIconSize(QSize(40,40));
    setCursor((Qt::PointingHandCursor));
    }
private slots:
    void states(QMediaPlayer::State state);
};

#endif // PLAYANDPAUSEBTN_H
