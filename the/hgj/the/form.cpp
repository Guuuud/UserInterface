#include "form.h"


Form::Form(vector<TheButtonInfo> videos) : videos(videos){
    //windows' properties
    setWindowTitle("Tomeo");
    setMaximumWidth(500);

    //functions used to create the application tomeo
    createWidgets();
    createThumbnails();
    createLayout();
    createConnections();
}

void Form::createWidgets(){
    //video description
    label->setAlignment(Qt::AlignLeft);
    label->show();

    //full screen button


    // play/pause button
    playPauseButton->show();
    playAndPause();

    //video timeline
    slider = new QSlider(Qt::Horizontal, this);
    slider->show();

    //forward 10 seconds button
    forward->show();
    forward->setIcon(QIcon(":/fast-forward.svg"));

    //go backwards 10 seconds button
    backward->show();
    backward->setIcon(QIcon(":/rewind.svg"));

    //previous video button
    previous->show();
    previous->setIcon(QIcon(":/back.svg"));

    //next video button
    next->show();
    next->setIcon(QIcon(":/next.svg"));

    //search button
    search->setIcon(QIcon(":/magnifying-glass.svg"));
    search->setFixedHeight(40);
    searchField->setFixedHeight(40);
    filterBox->setFixedHeight(40);

    //volume slider
    volumeSlider->show();
    volumeSlider->setRange(0, 100);
    volumeSlider->setValue(player->volume());
    volumeLabel->show();
    volumeLabel->setPixmap(QPixmap(":/speaker.svg"));
    volumeLabel->setScaledContents(true);

    messageNext->setText("The 'next video' button is not currently working! The purpose of this button is to skip to the next video.");
    messageNext->hide();

    messagePrev->setText("The 'previous video' button is not currently working! The purpose of this button is to go to the previous video in the list");
    messagePrev->hide();

    messageSearch->setText("The 'search' button is not currently working! The purpose of this button is to search for videos that matched the specific filter chosen.");
    messageSearch->hide();
    videoWidget->setMaximumHeight(2000);
    videoWidget->setMinimumHeight(300);

    autoPlay();
    playPauseButton->setMaximumWidth(200);

    forward->setMaximumWidth(70);

    backward->setMaximumWidth(70);

    slider->setMaximumWidth(2000);


    label->setMaximumWidth(200);
    label->setMaximumHeight(40);

    volumeLabel->setMaximumSize(20,20);

    volumeSlider->setMinimumWidth(250);

    previous->setMaximumWidth(70);
    previous->show();
    next->setMaximumWidth(70);
    //filter box elements


    player->setVideoOutput(videoWidget);
    videoWidget->show();


}

void Form::createThumbnails(){
    // a list of the buttons
    vector<TheButton*> buttons;
    // the buttons are arranged in a grid layout
    buttonWidget->setLayout(layout);
    int n=0, j=0, doubleDigits=1, increase=0;
    //create x buttons (for x no of videos)
    for ( unsigned i = 0; i < videos.size(); i++ ) {
        //this conditions will create the rows and columns of the grid layout
        if(i % 2 == 0){
            n++;
        }
        if(i % 2 != 0){
            j = 0;
        }
        else{
            j = 1;
        }

        //creating a container layout inside the grid layout that contains the description and the video

        if(i<9){

        }
        else{
            //doubleDigits is set to 1 and it remains constant representing the first number
            //increase represents the second digit and it increases after each loop

            increase++;
        }
        QFrame *container = new QFrame;
        container->setLayout(new QVBoxLayout);
        //creating the thumbnails for the videos
        TheButton *button = new TheButton(buttonWidget);
        button->connect(button, SIGNAL(jumpTo(TheButtonInfo* )), player, SLOT (jumpTo(TheButtonInfo* ))); // when clicked, tell the player to play.
        //button->setMaximumHeight(600);
        buttons.push_back(button);
        //description->setFixedHeight(30);
        //description->setStyleSheet("font-size: 20px;height: 40px;width: 120px;");
        //adding the thumnails and the buttons to the container layout
        container->layout()->addWidget(button);
        layout->addWidget(container, n, j);
        button->init(&videos.at(i));

    }
    // tell the player what buttons and videos are available
    player->setContent(&buttons, & videos);
}

//this function creates the connections between the buttons and their functionality
void Form::createConnections(){

    connect(playPauseButton, SIGNAL(clicked()), this, SLOT(playAndPause()));
    connect(player, &QMediaPlayer::durationChanged, slider, &QSlider::setMaximum);
    connect(player, &QMediaPlayer::positionChanged, slider, &QSlider::setValue);
    connect(slider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);
    connect(forward, SIGNAL(clicked()), this, SLOT(seekForward()));
    connect(backward, SIGNAL(clicked()), this, SLOT(seekBackward()));
    connect(previous, SIGNAL(clicked()), this, SLOT(vidPrevious()));
    connect(next, SIGNAL(clicked()), this, SLOT(vidNext()));
    connect(search, SIGNAL(clicked()), this, SLOT(searchVideo()));
    connect(volumeSlider, &QSlider::valueChanged, player, &QMediaPlayer::setVolume);
}


void Form::createLayout(){
    //layout for the player's buttons
    QHBoxLayout* buttonsLayout = new QHBoxLayout();

    buttonsLayout->addWidget(previous);
    buttonsLayout->addWidget(backward);
    buttonsLayout->addWidget(playPauseButton);
    buttonsLayout->addWidget(forward);
    buttonsLayout->addWidget(next);
    buttonsLayout->addWidget(volumeLabel);
    buttonsLayout->addWidget(volumeSlider);
    buttonsLayout->addStretch(); //positions the widgets on the left

    //layout for the search bar, search button and filter combo box
    QVBoxLayout* descriptionLayout = new QVBoxLayout();

    descriptionLayout->addWidget(buttonWidget);

    top->addWidget(videoWidget);
    //"Location/Description" of the video playing
    top->addWidget(label);
    top->addWidget(slider);
    top->addLayout(buttonsLayout);
    top->addLayout(descriptionLayout);


    setLayout(top);

}


//full screen mode function

void Form::autoPlay() {
    playPauseButton->setIcon(QIcon(":/pause.svg"));
    player->play();
    isVideoPlaying = false;
}

// play/pause button connection
//we change the vlaue of the boolean variable isVideoPlaying
//in order to keep track of the video's status (played/paused)
void Form::playAndPause() {
  if (isVideoPlaying == false) {
    player->pause();
    playPauseButton->setIcon(QIcon(":/play-button.svg"));
    isVideoPlaying = true;
  }
  else {
    player->play();
    playPauseButton->setIcon(QIcon(":/pause.svg"));
    isVideoPlaying = false;
  }
}

//forward 5 seconds button connection
void Form::seekForward(){
    player->setPosition(round((double)slider->value() * 5 ));
}

//backward 5 seconds button connection
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
