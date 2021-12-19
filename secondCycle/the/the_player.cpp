//
// Created by twak on 11/11/2019.
//

#include "the_player.h"

// all buttons have been setup, store pointers here
void ThePlayer::setContent(std::vector<TheButton*>* b, std::vector<TheButtonInfo>* i) {
    buttons = b;
    infos = i;
    jumpTo(buttons -> at(0) -> info);
}

// change the image and video for one button every one second


void ThePlayer::playStateChanged (QMediaPlayer::State ms) {
    switch (ms) {
        case QMediaPlayer::State::StoppedState:
            play(); // starting playing again...
            break;
    default:
        break;
    }
}

void ThePlayer::jumpTo (TheButtonInfo* button) {
    setMedia( * button -> url);
    play();
}

void ThePlayer::toPrevious() {
    if(current_index==0)
        current_index=infos->size()-1;
    else
    current_index = (current_index - 1) % buttons->size(); // locate to the previous video
    setMedia(*infos->at(current_index).url);
    play();
}

void ThePlayer::toNext() {
    if(current_index==(int)infos->size()-1)
        current_index=0;
    else
    current_index = (current_index + 1) % buttons->size(); // locate to the next video
    setMedia(*infos->at(current_index).url);
    play();
}
