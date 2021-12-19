#ifndef EPISODENUMBER_H
#define EPISODENUMBER_H

#include <QPushButton>
#include <QStyle>
#include <QWidget>
#include <QMediaPlayer>
#include <QSpinBox>

class episodeNum: public QPushButton{
Q_OBJECT
public:
    explicit episodeNum(QWidget *parent): QPushButton(parent){
        QSpinBox *pSpinBox = new QSpinBox(this);
        pSpinBox->setRange(1,1000);
        pSpinBox->setSingleStep(1);
        pSpinBox->resize(160,40);
//        pSpinBox->setPrefix("The ");
//        pSpinBox->setSuffix(" episode");
    }
};

#endif // EPISODENUMBER_H
