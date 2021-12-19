#ifndef PLAYSPEED_H
#define PLAYSPEED_H

#include <QPushButton>
#include <QStyle>
#include <QWidget>
#include <QMediaPlayer>



class speedButton : public QPushButton {
Q_OBJECT
//    QString str = QObject::tr("&1X");
public:
    explicit speedButton(QWidget *parent) : QPushButton(parent) {
//        setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        setFixedSize(80, 40);
        setText("&1X");
//        setFlat(true);
//        setIconSize(QSize(40, 40));
        setStyleSheet("QPushButton{border-radius:20;background-color:rgba(0,0,0,20); }"
                    "QPushButton:hover{border-radius:20;background-color:rgba(0,0,0,25);}"
                      "QPushButton:pressed{border-radius:20;background-color:rgba(0,0,0,75); }");
        setCursor((Qt::PointingHandCursor));


        //we use the QStyle in built icons for our play button
    }

private slots:

    //void clicked();
//    void setState(QMediaPlayer::State state);
};

#endif // PLAYSPEED_H
