#ifndef VOLUMN_H
#define VOLUMN_H

#include <QPushButton>
#include <QStyle>
#include <QWidget>
#include <QMediaPlayer>
#include <QSlider>
#include <QMouseEvent>

class muteVolumnButton: public QPushButton{
Q_OBJECT
public:
    explicit muteVolumnButton(QWidget *parent) : QPushButton(parent){
//        setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
        setIcon(QIcon(":/ico/mute.png"));
        setFixedSize(30,30);
        setFlat(true);
        setIconSize(QSize(30,30));
        setCursor((Qt::PointingHandCursor)); // 鼠标变小手 --> 可可爱爱，没有脑袋~~~
    }
private slots:
};


class volumeSlider : public QSlider {
Q_OBJECT
public:
    explicit volumeSlider(QWidget *parent) : QSlider(Qt::Horizontal, parent) {
        setTracking(true);
        setRange(0, 100);
        setValue(50);
        sliderMoved(0);
        setSingleStep(1);
        setCursor((Qt::PointingHandCursor));
        setStyleSheet("QSlider {\
                          margin: 6 10 -4 10;\
                          padding-bottom: 10px;\
                      }\
                      QSlider::add-page {\
                          background-color: rgb(205,205,205);\
                          height:5px;\
                          border-radius: 2px;\
                      }\
                      QSlider::sub-page {\
                          background-color:rgb(2, 10, 82);\
                          height:5px;\
                          border-radius: 2px;\
                      }\
                      QSlider::groove {\
                          background:transparent;\
                          height:6px;\
                      }\
                      QSlider::handle {\
                          height: 8px;\
                          width: 8px;\
                          margin: -2 0 -2 0;\
                          border-radius: 7px;\
                          background: white;\
                          border: 1px solid black;\
                      }");
    }

protected:
    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            double pos_val = minimum() + ((maximum() - minimum()) * event->x()) / width();
            pos_val+=50*(pos_val-50)/100;
            setValue(pos_val);
            sliderMoved(pos_val);
            event->accept();
        }
        QSlider::mousePressEvent(event);
    }


private slots:

//    void moveSlider(qint64 volume);
};

class volumnButton: public QPushButton{
Q_OBJECT
public:
    explicit volumnButton(QWidget *parent) : QPushButton(parent){
//        setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
        setIcon(QIcon(":/ico/volume.png"));
        setFixedSize(30,30);
        setFlat(true);
        setIconSize(QSize(30,30));
    }
private slots:
};

#endif // VOLUMN_H
