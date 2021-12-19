#include "form.h"
#include <QFileInfo>
#include <QtDebug>
#include <QDateTime>
#include "the_player.h"




Form::Form(vector<TheButtonInfo> videos) : videos(videos){
    setWindowTitle("Tomeo");
    //初始化
    initWidgets();

}

void Form::initWidgets(){
    //Description
    label->setAlignment(Qt::AlignLeft);
    // 视频的上一页和下一页


    //全屏
//    fullScreenButton->hide();
//    fullScreenButton->setBackgroundRole(QPalette::Light);
    videoWidget->setFullScreen(false);
    player->setVideoOutput(videoWidget);

    // screen shot button
    screenShot->setIcon(QIcon(":/ico/camera.png"));
    setCursor((Qt::PointingHandCursor));
    messageShot->setText("The screenshot function is unavailable temporarily");
    messageShot->hide();
    //进度条
    slider = new QSlider(Qt::Horizontal, this);


    setCursor((Qt::PointingHandCursor));
    //+10sec

    forward->setIcon(QIcon(":/ico/fast-forward-media-control-button.png"));
    setCursor((Qt::PointingHandCursor));
    //-10sec

    backward->setIcon(QIcon(":/ico/backwards.png"));
    setCursor((Qt::PointingHandCursor));
    //前一个视频

    previous->setIcon(QIcon(":/ico/backward-track.png"));
    setCursor((Qt::PointingHandCursor));
    //后一个视频

    next->setIcon(QIcon(":/ico/next.png"));
    setCursor((Qt::PointingHandCursor));
    //搜索
    search->setIcon(QIcon(":/ico/search.png"));
    search->setFixedHeight(40);
    searchField->setFixedHeight(40);
    filterBox->setFixedHeight(40);
    setCursor((Qt::PointingHandCursor));
    //音量条

    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(player->volume());

    setCursor((Qt::PointingHandCursor));
    // 音量
    volumeLabel->setPixmap(QPixmap(":/ico/volume.png"));
    volumeLabel->setScaledContents(true);
    setCursor((Qt::PointingHandCursor));

    messageSearch->setText("search button isn‘t working!");
    messageSearch->hide();
    videoWidget->setMaximumHeight(2000);
    videoWidget->setMinimumHeight(300);
    fullScreenButton->setIcon(QIcon(":/ico/fullscreen.png"));
    autoPlay();
//    playPauseButton->setMaximumWidth(200);

    forward->setMaximumWidth(70);
    backward->setMaximumWidth(70);
    slider->setMaximumWidth(2000);
    label->setMaximumWidth(200);
    label->setMaximumHeight(40);
    volumeLabel->setMaximumSize(20,20);
    volumeSlider->setMinimumWidth(250);
    previous->setMaximumWidth(70);

    next->setMaximumWidth(70);
    //Filter
    elementsFilterBy<<"Filter by"<<"Sports"<<"Life"<<"Date"<<"Size";
    filterBox->setCurrentIndex(1);
    filterBox->addItems(elementsFilterBy);
    player->setVideoOutput(videoWidget);

    descriptions<<"video";

    vector<TheButton*> buttons;
    // 给 Layout 创建 Buttons
    buttonWidget->setLayout(layout);
    int n=0, j=0, doubleDigits=1, increase=0;

    // 给 Videos 创建 Buttons

    for ( unsigned i = k; i < videos.size()&&i<k+6; i++ ) {
        //this conditions will create the rows and columns of the grid layout
        if(i % 2 == 0){
            n++;
        }
        if(i % 2 != 0){
            j = 1;
        }
        else{
            j = 0;
        }


        // Layout 框
        QLabel *description = new QLabel();
        if(i<9){
            //获取文件路径
            QString Raw_filename = videos[i].url->toString();
            //转成 List 类型
            QStringList Path = Raw_filename.split("/");
            //获取文件名
            QString vidNames = Path[Path.length()-1];
            QStringList vidName = vidNames.split(".");
            // vidName[0]: bike
            // vidName[1]: wmv
            //添加标签
            description->setText(' ' + vidName[0]);
        }
        else{
            // 2位数
//            QString file1 = videos.url->toString();
//            QString file = file1.right(file1.length() - 8);
//            QFileInfo file_info(file);
//            QDateTime created = file_info.birthTime();
//            description->setText("  Name:" + file_info.fileName() + "  \n" + "  Time:"
//            + created.toString("yyyy-MM-dd hh:mm:ss "));
            description->setText(descriptions[0] + ' ' + (doubleDigits + '0') + ('0' + increase));
            increase++;
        }
        QFrame *container = new QFrame;
        container->setLayout(new QVBoxLayout);
        // 创建缩略图
        TheButton *button = new TheButton(buttonWidget);
        // 点击播放
        button->connect(button, SIGNAL(jumpTo(TheButtonInfo* )), player, SLOT (jumpTo(TheButtonInfo* )));
        buttons.push_back(button);
        // 添加缩略图到 Layout
        container->layout()->addWidget(button);
        container->layout()->addWidget(description);
        layout->addWidget(container, n, j);
        button->init(&videos.at(i));

    }
    // Player
    player->setContent(&buttons, & videos);


    // Buttons

    // Connection
    connect(playPauseButton, SIGNAL(clicked()), this, SLOT(playAndPause()));
    connect(player, &QMediaPlayer::durationChanged, slider, &QSlider::setMaximum);
    connect(player, &QMediaPlayer::positionChanged, slider, &QSlider::setValue);
    connect(slider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);
    connect(forward, SIGNAL(clicked()), this, SLOT(seekForward()));
    connect(backward, SIGNAL(clicked()), this, SLOT(seekBackward()));
    connect(previous, SIGNAL(clicked()), player, SLOT(toPrevious()));
    connect(next, SIGNAL(clicked()), player, SLOT(toNext()));
    connect(search, SIGNAL(clicked()), this, SLOT(searchVideo()));
    connect(volumeSlider, &QSlider::valueChanged, player, &QMediaPlayer::setVolume);
    connect(fullScreenButton,SIGNAL(clicked(bool)),videoWidget,SLOT(setToFullScreen(bool)));
    connect(screenShot,SIGNAL(clicked()),this,SLOT(screenShotShow()));
    // 这里设置了如下的比例： 1：1：1：1：4：8，左右均为零。
    //Button Layout
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    buttonsLayout->addStretch(0);
    buttonsLayout->addWidget(previous);
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(backward);
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(playPauseButton);
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(forward);
    buttonsLayout->addStretch(1);
    buttonsLayout->addWidget(next);
    buttonsLayout->addStretch(4);
    buttonsLayout->addWidget(volumeLabel);
    buttonsLayout->addWidget(volumeSlider);
    buttonsLayout->addStretch(8);
    buttonsLayout->addWidget(screenShot);
    buttonsLayout->addWidget(fullScreenButton);
    buttonsLayout->addStretch(0);
    buttonsLayout->addStretch();

    //Right Hand Side Layout
    QHBoxLayout* searchLayout = new QHBoxLayout();
    searchLayout->addWidget(filterBox);

    searchLayout->addWidget(searchField);
    searchLayout->addWidget(search);

    QVBoxLayout* descriptionLayout = new QVBoxLayout();
    descriptionLayout->addLayout(searchLayout);
    descriptionLayout->addWidget(buttonWidget);

    top->addWidget(videoWidget);
    top->addWidget(label);
    top->addWidget(slider);
    top->addLayout(buttonsLayout);
    hop->addLayout(top);
    hop->addLayout(descriptionLayout);


    setLayout(hop);

}



void Form::autoPlay() {
    playPauseButton->setIcon(QIcon(":/ico/pause.png"));
    player->play();
    isVideoPlaying = false;
}

 //play/pause button connection
//we change the vlaue of the boolean variable isVideoPlaying
//in order to keep track of the video's status (played/paused)

void Form::playAndPause() {
  if (isVideoPlaying == false) {
    player->pause();
    playPauseButton->setIcon(QIcon(":/ico/play.png"));
    isVideoPlaying = true;
  }
  else {
    player->play();
    playPauseButton->setIcon(QIcon(":/ico/pause.png"));
    isVideoPlaying = false;
  }
}
// The following function is used to change the background color (day/night mode).

// 前进五秒
void Form::seekForward(){
    player->setPosition(round((double)slider->value() * 5 ));
}

// 回退五秒
void Form::seekBackward(){
    player->setPosition(round((double)slider->value() / 5));
}



//following 3 functions will display error messages when their corresponding button is clicked
void Form::vidNext(){
    messageNext->show();
}

void Form::vidPrevious(){
    messagePrev->show();
}
//shows the error message for the search button
void Form::searchVideo(){
    messageSearch->show();
}
void Form::screenShotShow(){
    messageShot->show();
}




//void Form::setToFullScreen(bool full){
//    videoWidget->setFullScreen(!full);
//}

//void Form::clickFullScreenButton(QKeyEvent *click){
//    videoWidget->setFullScreen(!videoWidget->isFullScreen());
//    click->accept();
//}

//void Form::keyPressEvent(QKeyEvent *event){
//    if(event->key()==Qt::Key_Escape){
//        videoWidget->setWindowFlags(Qt::SubWindow);
//        videoWidget->showNormal();
//    }
//}
