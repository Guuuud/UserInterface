//
// Created by twak on 11/11/2019.
//

#ifndef CW2_THE_PLAYER_H
#define CW2_THE_PLAYER_H


#include <QApplication>
#include <QMediaPlayer>
#include "the_button.h"
#include <vector>
#include <QTimer>



using namespace std;

class ThePlayer : public QMediaPlayer {

    Q_OBJECT

private:
    vector<TheButtonInfo>* infos;
    vector<TheButton*>* buttons;
    int current_index=1;
public:
    ThePlayer() : QMediaPlayer(NULL) {
        setVolume(20);
        connect (this, SIGNAL (stateChanged(QMediaPlayer::State)), this, SLOT (playStateChanged(QMediaPlayer::State)) );

    }

    // all buttons have been setup, store pointers here
    void setContent(vector<TheButton*>* b, vector<TheButtonInfo>* i);

private slots:

    void playStateChanged (QMediaPlayer::State ms);
    void toPrevious(); // switch to the previous video
    void toNext(); // switch to the next video

public slots:

    void jumpTo (TheButtonInfo* button);

};

#endif //CW2_THE_PLAYER_H
