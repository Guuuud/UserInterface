#include "setToFullScreen.h"
#include <QVideoWidget>

void videoFullScreen::setToFullScreen(bool full){
    setFullScreen(!full);
}

void videoFullScreen::clickFullScreenButton(QKeyEvent *click){
    setFullScreen(!isFullScreen());
    click->accept();
}

void videoFullScreen::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Escape){
        setWindowFlags(Qt::SubWindow);
        showNormal();
    }
}
