//    ______
//   /_  __/___  ____ ___  ___  ____
//    / / / __ \/ __ `__ \/ _ \/ __ \
//   / / / /_/ / / / / / /  __/ /_/ /
//  /_/  \____/_/ /_/ /_/\___/\____/
//              video for sports enthusiasts...
//
//  2811 cw3 : twak 11/11/2021
//

#include <iostream>
#include <QApplication>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QMediaPlaylist>
#include <string>
#include <vector>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtCore/QFileInfo>
#include <QtWidgets/QFileIconProvider>
#include <QDesktopServices>
#include <QImageReader>
#include <QMessageBox>
#include <QtCore/QDir>
#include <QtCore/QDirIterator>
#include "the_player.h"
#include "the_button.h"
#include "allButtons.h"
#include "progressBar.h"
#include "fullScreen.h"
#include "setToFullScreen.h"

// read in videos and thumbnails to this directory
std::vector<TheButtonInfo> getInfoIn (std::string loc) {

    std::vector<TheButtonInfo> out =  std::vector<TheButtonInfo>();
    QDir dir(QString::fromStdString(loc) );
    QDirIterator it(dir);

    while (it.hasNext()) { // for all files

        QString f = it.next();

            if (f.contains("."))

#if defined(_WIN32)
            if (f.contains(".wmv"))  { // windows
#else
            if (f.contains(".mp4") || f.contains("MOV"))  { // mac/linux
#endif

            QString thumb = f.left( f .length() - 4) +".png";
            if (QFile(thumb).exists()) { // if a png thumbnail exists
                QImageReader *imageReader = new QImageReader(thumb);
                    QImage sprite = imageReader->read(); // read the thumbnail
                    if (!sprite.isNull()) {
                        QIcon* ico = new QIcon(QPixmap::fromImage(sprite)); // voodoo to create an icon for the button
                        QUrl* url = new QUrl(QUrl::fromLocalFile( f )); // convert the file location to a generic url
                        out . push_back(TheButtonInfo( url , ico  ) ); // add to the output list
                    }
                    else
                        qDebug() << "warning: skipping video because I couldn't process thumbnail " << thumb << endl;
            }
            else
                qDebug() << "warning: skipping video because I couldn't find thumbnail " << thumb << endl;
        }
    }

    return out;
}

void setFullScreen(QVideoWidget* videoWidget){
    if(!videoWidget->isFullScreen()){
        videoWidget->setFullScreen(true);
    }
}

int main(int argc, char *argv[]) {

    // let's just check that Qt is operational first
    qDebug() << "Qt version: " << QT_VERSION_STR << endl;

    // create the Qt Application
    QApplication app(argc, argv);

    // collect all the videos in the folder
    std::vector<TheButtonInfo> videos;

    if (argc == 2)
        videos = getInfoIn( std::string(argv[1]) );

    if (videos.size() == 0) {

        const int result = QMessageBox::question(
                    NULL,
                    QString("Tomeo"),
                    QString("no videos found! download, unzip, and add command line argument to \"quoted\" file location. Download videos from Tom's OneDrive?"),
                    QMessageBox::Yes |
                    QMessageBox::No );

        switch( result )
        {
        case QMessageBox::Yes:
          QDesktopServices::openUrl(QUrl("https://leeds365-my.sharepoint.com/:u:/g/personal/scstke_leeds_ac_uk/EcGntcL-K3JOiaZF4T_uaA4BHn6USbq2E55kF_BTfdpPag?e=n1qfuN"));
          break;
        default:
            break;
        }
        exit(-1);
    }

    // the widget that will show the video
    videoFullScreen *videoWidget = new videoFullScreen();
    // the QMediaPlayer which controls the playback
    ThePlayer *player = new ThePlayer;
//    player->setVideoOutput(videoWidget);
    // a row of buttons
    QWidget *buttonWidget = new QWidget();
    // a list of the buttons
    std::vector<TheButton*> buttons;
    // the buttons are arranged horizontally
    QHBoxLayout *layout = new QHBoxLayout();
    buttonWidget->setLayout(layout);


    // create the four buttons
    for ( int i = 0; i < 6; i++ ) {
        TheButton *button = new TheButton(buttonWidget);
        button->connect(button, SIGNAL(jumpTo(TheButtonInfo* )), player, SLOT (jumpTo(TheButtonInfo*))); // when clicked, tell the player to play.
        buttons.push_back(button);
        layout->addWidget(button);
        button->init(&videos.at(i));
    }

    // tell the player what buttons and videos are available
    player->setContent(&buttons, & videos);

    // create the main window and layout
    QWidget window;
    QVBoxLayout *top = new QVBoxLayout();
    window.setLayout(top);
    window.setWindowTitle("tomeo");
    window.setMinimumSize(1000, 680);
    window.setWindowIcon(QIcon(":/ico/video-player.png")); //我不知道为什么图标加不上去
    // add the video and the buttons to the top level widget
//    top->addWidget(videoWidget);

    top->addWidget(buttonWidget);

// 接下来这一段是添加所需要的按钮，其实现原理如下：
    // 首先我的 allButton.h的头文件调用了所有的按钮，所以这里我在
    // 第一行便对 ButtonWidget这个类进行调用，即：butwidget的作用是
    // 访问所有的按钮元素。
    // 然后我定义了一个 layout，旨在将所有的按钮元素都放在这个layout
    // 上面来进行布局。
    // 第三，我调用了 QWidget这个类，生成一个大组件，上一步定义的 layout
    // 会被这个大组件展示出来。
    // 最后只需要将 allButtons这个组件加入到 top上即可。
    ButtonWidget * butwidget = new ButtonWidget();
    QHBoxLayout *lay = new QHBoxLayout();
    QWidget *allButtons = new QWidget();
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setMinimumWidth(500);
    slider->setCursor((Qt::PointingHandCursor));
    slider->show();
    QSlider::connect(player, &QMediaPlayer::durationChanged, slider, &QSlider::setMaximum);
    QSlider::connect(player, &QMediaPlayer::positionChanged, slider, &QSlider::setValue);
    QSlider::connect(slider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);
//    videoSlider *videoSld = new videoSlider(butwidget);

    // 下面试着来做一下 fullscreen
    videoWidget->setFullScreen(false);
    player->setVideoOutput(videoWidget);
    videoFullScreen::connect(butwidget->fullScreenBtn,SIGNAL(clicked(bool)),videoWidget,SLOT(setToFullScreen(bool)));
    top->addWidget(videoWidget);
//    fullscrenn->setFullScreen(false);
//    player->setVideoOutput(fullscrenn);
//    videoFullScreen::connect(butwidget->fullScreenBtn,SIGNAL(clicked(bool)),fullscrenn,SLOT(setToFullScreen(bool)));

//    top->addWidget(fullscrenn);

    allButtons->setLayout(lay);
    lay->addStretch(0);
    lay->addWidget(butwidget->playBtn);
//    lay->addStretch(12);
//    lay->addWidget(videoSld);
    lay->addStretch(1);
    lay->addWidget(slider);
    lay->addStretch(3);
    lay->addWidget(butwidget->speedBtn);
    lay->addStretch(1);
    butwidget->pSpinBox->setSingleStep(1);
    butwidget->pSpinBox->setRange(1,1000);
//    butwidget->pSpinBox->setValue(1);
//    lay->addWidget(butwidget->pSpinBox);
    lay->addStretch(4);
    lay->addWidget(butwidget->muteVolumeBtn);
    lay->addWidget(butwidget->volumnSlider);
    lay->addWidget(butwidget->volumnBtn);
    lay->addStretch(1);
    // 这个过程值得好好斟酌，后续也会用得到，其具体过程如下：
    // connect函数的作用是传输信号，其第一个参数是发出信号的对象，对于第一个 connect
    // 我们需要点击 button，所以 button为发出信号的对象，第二个参数是发出的信号，由于
    // button被点击，它应该传出一个被点击的信号，向接收端请求操作。
    // 第三个参数是接收信号的对象，我们想在点击了button之后让视频播放/暂停，
    // 所以接收端应该为播放器。
    // 最后一个参数是接收信号的操作，也就是所谓的槽，
    playButton::connect(butwidget->playBtn,SIGNAL(clicked(bool)),player,SLOT(pauseOrPlay()));
    ThePlayer::connect(player, SIGNAL(stateChanged(QMediaPlayer::State)),
                           butwidget->playBtn, SLOT(states(QMediaPlayer::State)));
    lay->addWidget(butwidget->fullScreenBtn);
    top->addWidget(allButtons);


// 结束，但是这里需要再说明的一点是关于 QVBoxlayout 与 QHBoxlayout的区别：
// 前者为垂直布局，后者为水平布局。

    // showtime!
    window.show();

    // wait for the app to terminate
    return app.exec();
}
