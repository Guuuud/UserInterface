//
// Created by twak on 11/11/2019.
//

#ifndef CW2_THE_BUTTON_H
#define CW2_THE_BUTTON_H

#include <QPushButton>
#include <QUrl>

class TheButtonInfo {

public:
    QUrl* url; // video file to play
    QIcon* icon; // icon to display

    TheButtonInfo ( QUrl* url, QIcon* icon) : url (url), icon (icon) {}
};
// Button这个类中包括ButtonInfo，并且声明了 init（）和 clicked（）这两个函数。
// ButtonInfo这个类中有两个变量（如上），第一个是 url，是播放视频的路径；第二个是 icon，是按钮的样式（播放、暂停、停止等）。
// init（）函数的作用是初始化按钮，将 icon给按钮，显示按钮图标，同时，把 ButtonInfo类型的指针i赋值给 info。
// clicked（）函数的作用是去调用jumpTo（）函数，同时把 init（）函数中赋值的 info传入函数 jumpTo（）中，通过 jumpTo（）函数完成跳转。
class TheButton : public QPushButton {
    Q_OBJECT

public:
    TheButtonInfo* info;

     TheButton(QWidget *parent) :  QPushButton(parent) {
         setIconSize(QSize(200,110));
         connect(this, SIGNAL(released()), this, SLOT (clicked() )); // if QPushButton clicked...then run clicked() below
//         pressed()：鼠标按下时触发。对应的函数是 mousePressEvent()。
//         clicked()：鼠标松开时触发。如果鼠标拖拽到按钮区域之外释放则不会触发。对应的函数是 mouseReleaseEvent()。
//                    一般情况下 connect 槽函数时使用该信号。
//         released()：鼠标松开时触发。即使鼠标拖拽到按钮区域之外释放也会触发。对应的函数是 mouseReleaseEvent()。//拖到区域外马上触发
//         toggled()：设置 setCheckable(true) 后再单击按钮才会触发该信号。
//                    一般用于多个按钮组成 QButtonGroup 并且 setExclusive(true) 设置按钮间互斥。
    }

    void init(TheButtonInfo* i);

private slots:
    void clicked();

signals:
    void jumpTo(TheButtonInfo*);

};

#endif //CW2_THE_BUTTON_H
