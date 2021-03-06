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

using namespace std;

class Form: public QWidget
{
    Q_OBJECT

public:

    Form(vector<TheButtonInfo> videos);

private:
    void createWidgets();
    void createLayout();
    void autoPlay();
    void createConnections();
    void createThumbnails();

    vector<TheButtonInfo> videos;
    QVideoWidget *videoWidget = new QVideoWidget;
    ThePlayer *player = new ThePlayer();
    QLabel* label = new QLabel("<h3>Description</h3>");
    QLabel *volumeLabel = new QLabel;
    QStringList descriptions;
    QComboBox* filterBox = new QComboBox();
    QStringList elementsFilterBy;
    QLineEdit* searchField = new QLineEdit();

    //buttons and sliders
    QWidget *buttonWidget = new QWidget();
    vector<TheButton*> buttons;
    QPushButton* playPauseButton = new QPushButton;
    QSlider *volumeSlider = new QSlider(Qt::Horizontal);
    QSlider *slider;
    QPushButton* forward = new QPushButton;
    QPushButton* backward = new QPushButton;
    QPushButton* previous = new QPushButton;
    QPushButton* next = new QPushButton;
    QPushButton* search = new QPushButton;

    //boolean values
    bool isVideoPlaying; //used for the play/pause button to check the status of the video
    bool isVideoFullScreen = false;

    //pop up error messages for the missing functionality
    QMessageBox* messageNext = new QMessageBox();
    QMessageBox* messagePrev = new QMessageBox();
    QMessageBox* messageSearch = new QMessageBox();

    //thumbnails layout
    QGridLayout* layout = new QGridLayout(this);
    QVBoxLayout *top = new QVBoxLayout();


//definitions of the functions used for the player's buttons
//they create the connection between the button and their functionality
private slots:
    void playAndPause();
    void seekForward();
    void seekBackward();
    void vidNext();
    void vidPrevious();
    void searchVideo();
};
#endif // FORM_H
