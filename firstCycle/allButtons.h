#ifndef ALLBUTTONS_H
#define ALLBUTTONS_H

#include <QWidget>
#include <QEvent>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include "pause.h"
#include "playSpeed.h"
#include "volumn.h"
#include "fullScreen.h"
#include "progressBar.h"
#include "episodeNumber.h"
#include <QSpinBox>

class ButtonWidget : public QWidget {
Q_OBJECT

public:
    ButtonWidget() : QWidget() {}

public:
    playButton *playBtn = new playButton(this);
    speedButton *speedBtn = new speedButton(this);
    muteVolumnButton *muteVolumeBtn = new muteVolumnButton(this);
    volumeSlider *volumnSlider = new volumeSlider(this);
    volumnButton *volumnBtn = new volumnButton(this);
    fullScreenButton *fullScreenBtn = new fullScreenButton(this);
//    episodeNum* epiNum = new episodeNum(this);
    QSpinBox *pSpinBox = new QSpinBox(this);
};

#endif // ALLBUTTONS_H
