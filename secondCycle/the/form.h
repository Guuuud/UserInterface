#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <QApplication>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <string>
#include <vector>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QFileInfo>
#include <QtWidgets/QFileIconProvider>
#include <QImageReader>
#include <QtCore/QDir>
#include <QtCore/QDirIterator>
#include <QtWidgets>
#include <QKeyEvent>
#include <QMouseEvent>
#include "the_button.h"
#include "the_player.h"
#include "setFullScreen.h"

using namespace std;

class Form: public QWidget
{
    Q_OBJECT

public:

    Form(vector<TheButtonInfo> videos);
private:
    void initWidgets();

    void autoPlay();
       unsigned k=0;

    vector<TheButtonInfo> videos;
    videoFullScreen *videoWidget = new videoFullScreen();
    ThePlayer *player = new ThePlayer();
    QLabel* label = new QLabel("<h3>Now Playing :</h3>");
    QLabel *volumeLabel = new QLabel;
    QStringList descriptions;

    QStringList elementsFilterBy;

    vector<QString> videoname;

    //Widget
    QWidget *buttonWidget = new QWidget();
    vector<TheButton*> buttons;
    QPushButton* fullScreenButton = new QPushButton;
    QPushButton* playPauseButton = new QPushButton;

    QSlider *volumeSlider = new QSlider(Qt::Horizontal);
    QSlider *slider;
    QPushButton* forward = new QPushButton;
    QPushButton* backward = new QPushButton;
    QPushButton* previous = new QPushButton;
    QPushButton* next = new QPushButton;



    QPushButton* screenShot= new QPushButton;
    //boolean values

    bool isVideoPlaying;
    //True - Playing
    //False - Not Playing

    //未完成的功能弹窗 Unrealized functions
    QMessageBox* messageNext = new QMessageBox();
    QMessageBox* messagePrev = new QMessageBox();
    QMessageBox* messageSearch = new QMessageBox();
    QMessageBox* messageShot = new QMessageBox();
    //预览图
    QGridLayout* layout = new QGridLayout(this);
    QVBoxLayout *top = new QVBoxLayout();

//protected:
//    void clickFullScreenButton(QKeyEvent *click);
//    void keyPressEvent(QKeyEvent *event);

    //Private
private slots:
    void playAndPause();
    void seekForward();
    void seekBackward();
    void vidNext();
    void vidPrevious();
    void searchVideo();
    void screenShotShow();


//    void setToFullScreen(bool full);
};
#endif // FORM_H
