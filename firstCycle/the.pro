QT += core gui widgets multimedia multimediawidgets

CONFIG += c++11
QMAKE_CXXFLAGS += "-std=c++11"

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        pauce.cpp \
        progressbar.cpp \
        setToFullScreen.cpp \
        the_button.cpp \
        the_player.cpp \
        tomeo.cpp

HEADERS += \
    allButtons.h \
    episodeNumber.h \
    fullScreen.h \
    pause.h \
    playSpeed.h \
    progressBar.h \
    setToFullScreen.h \
    the_button.h \
    the_player.h \
    volumn.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    form.ui

DISTFILES += \
    image/5261/6.ico

RESOURCES += \
    image.qrc

