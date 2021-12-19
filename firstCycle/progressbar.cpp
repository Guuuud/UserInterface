#include "progressBar.h"

void videoSlider::SetValue(qint64 position) {
    setValue(position);
}

void videoSlider::SetRange(qint64 position) {
    //set range is used to allow the slider range to change when the video changes
    setRange(0, position);
}
