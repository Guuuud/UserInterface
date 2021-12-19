#include "pause.h"

void playButton::states(QMediaPlayer::State state) {

    //allows the icon to change depending on whether the video is paused or playing
    switch (state) {
        case QMediaPlayer::PlayingState:
            setEnabled(true);
//            setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
            setIcon(QIcon(":/ico/pause.png"));
            break;
        case QMediaPlayer::PausedState:
            setEnabled(true);
            setIcon(QIcon(":/ico/play.png"));
            break;
        default:
            break;
    }

}
