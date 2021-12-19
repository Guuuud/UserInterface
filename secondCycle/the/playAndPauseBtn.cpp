#include "playAndPauseBtn.h"
#include "form.h"

void playPauseButton::states(QMediaPlayer::State state){
    switch (state) {
            case QMediaPlayer::PlayingState:
                setEnabled(true);
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
