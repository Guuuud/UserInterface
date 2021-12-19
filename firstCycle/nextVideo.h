#ifndef NEXTVIDEO_H
#define NEXTVIDEO_H
#include <QPushButton>
#include <QStyle>
#include <QWidget>
#include <QMediaPlayer>

class nextVideoButton: public QPushButton{
Q_OBJECT
public:
    explicit nextVideoButton(QWidget *parent): QPushButton(parent){
        setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        setFixedSize(40,40);
        setFlat(true);
        setIconSize(QSize(40,40));
        setStyleSheet("QPushButton:hover{border-radius:20;background-color:rgba(0,0,0,25);}"
                              "QPushButton:pressed{border-radius:20;background-color:rgba(0,0,0,75); }");
    }
private slots:
//    void states(QMediaPlayer::State state);
};
#endif // NEXTVIDEO_H
