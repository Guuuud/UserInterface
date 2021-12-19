#ifndef FULLSCREEN_H
#define FULLSCREEN_H

#include <QPushButton>
#include <QStyle>
#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMouseEvent>


class fullScreenButton: public QPushButton{
Q_OBJECT
public:
    explicit fullScreenButton(QWidget *parent) : QPushButton(parent){
        setIcon(QIcon(":/ico/fullscreen.png"));
        setFixedSize(40,40);
        setFlat(true);
        setIconSize(QSize(40,40));
        setCursor((Qt::PointingHandCursor));
    }
};
#endif // FULLSCREEN_H

