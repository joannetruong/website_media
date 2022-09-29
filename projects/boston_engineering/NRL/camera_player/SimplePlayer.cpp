/*
* VLC-Qt Simple Player
* Copyright (C) 2015 Tadej Novak <tadej@tano.si>
*/

#include <QFileDialog>
#include <QInputDialog>

#include <VLCQtCore/Common.h>
#include <VLCQtCore/Instance.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>
#include <QPixmap>

#include "SimplePlayer.h"
#include "ui_SimplePlayer.h"

SimplePlayer::SimplePlayer(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::SimplePlayer),
      _media(0)
{
    ui->setupUi(this);
    QPixmap pix(":/resource/img/BE_logo.png");
    ui->BEC->setPixmap(pix);

    _instance = new VlcInstance(VlcCommon::args(), this);
    _player = new VlcMediaPlayer(_instance);
    _player->setVideoWidget(ui->video);

 mgr = new QNetworkAccessManager(this);
    connect(ui->Left, &QPushButton::clicked, this, &SimplePlayer::buttonClicked);
    connect(ui->Right, &QPushButton::clicked, this, &SimplePlayer::buttonClicked);
    connect(ui->Up, &QPushButton::clicked, this, &SimplePlayer::buttonClicked);
    connect(ui->Down, &QPushButton::clicked, this, &SimplePlayer::buttonClicked);
    connect(ui->RightUp, &QPushButton::clicked, this, &SimplePlayer::buttonClicked);
    connect(ui->RightDown, &QPushButton::clicked, this, &SimplePlayer::buttonClicked);
    connect(ui->LeftUp, &QPushButton::clicked, this, &SimplePlayer::buttonClicked);
    connect(ui->LeftDown, &QPushButton::clicked, this, &SimplePlayer::buttonClicked);
    connect(ui->zoomOut, &QPushButton::clicked, this, &SimplePlayer::buttonClicked);
    connect(ui->zoomIn, &QPushButton::clicked, this, &SimplePlayer::buttonClicked);
    connect(ui->actionOpenLocal, &QAction::triggered, this, &SimplePlayer::openLocal);
    connect(ui->actionOpenUrl, &QAction::triggered, this, &SimplePlayer::openUrl);
    connect(ui->openLocal, &QPushButton::clicked, this, &SimplePlayer::openLocal);
    connect(ui->openUrl, &QPushButton::clicked, this, &SimplePlayer::openUrl);

    _instance = new VlcInstance(VlcCommon::args(), this);
    _player = new VlcMediaPlayer(_instance);
    _player2 = new VlcMediaPlayer(_instance);
    _player3 = new VlcMediaPlayer(_instance);
    _player4 = new VlcMediaPlayer(_instance);
    _player->setVideoWidget(ui->video);
    _player2->setVideoWidget(ui->video_2);
    _player3->setVideoWidget(ui->video_3);
    _player4->setVideoWidget(ui->video_4);

}

void SimplePlayer::openLocal()
 {
     QString file =
             QFileDialog::getOpenFileName(this, tr("Open file"),
                                          QDir::homePath(),
                                          tr("Multimedia files(*)"));

     if (file.isEmpty())
         return;

     _media = new VlcMedia(file, true, _instance);

     _player->open(_media);
     _player2->open(_media);
     _player3->open(_media);
     _player4->open(_media);
 }
void SimplePlayer::openUrl()
{
    QString url = "http://192.168.1.108:80/axis-cgi/mjpg/video.cgi?camera=0";
    _media = new VlcMedia(url, _instance);
    _player->open(_media);
    _player2->open(_media);
    _player3->open(_media);
    _player4->open(_media);
}


SimplePlayer::~SimplePlayer()
{
    delete _player;
    delete _media;
    delete _instance;
    delete ui;
}

void SimplePlayer::buttonClicked()
{
  QObject* button = QObject::sender();
  if (button == ui->Left)
      {
      if (ui->Left->isChecked()) {
           mgr->get(QNetworkRequest(QUrl("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=start&channel=0&code=Left&arg1=0&arg2=1&arg3=0")));
        }
      else {
          mgr->get(QNetworkRequest(QUrl("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=stop&channel=0&code=Left&arg1=0&arg2=1&arg3=0")));
        }
      }
  else if (button == ui->Right)
    {
      if (ui->Right->isChecked()) {
          mgr->get(QNetworkRequest(QUrl(QString("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=start&channel=0&code=Right&arg1=0&arg2=1&arg3=0"))));
        }
      else {
          mgr->get(QNetworkRequest(QUrl("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=stop&channel=0&code=Right&arg1=0&arg2=1&arg3=0")));
        }
    }
  else if (button == ui->Up)
    {
      if (ui->Up->isChecked()) {
          mgr->get(QNetworkRequest(QUrl(QString("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=start&channel=0&code=Up&arg1=0&arg2=1&arg3=0"))));
        }
      else {
          mgr->get(QNetworkRequest(QUrl("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=stop&channel=0&code=Up&arg1=0&arg2=1&arg3=0")));
        }
    }
  else if (button == ui->Down)
    {
      if (ui->Down->isChecked()) {
          mgr->get(QNetworkRequest(QUrl(QString("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=start&channel=0&code=Down&arg1=0&arg2=1&arg3=0"))));
        }
      else {
          mgr->get(QNetworkRequest(QUrl("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=stop&channel=0&code=Down&arg1=0&arg2=1&arg3=0")));
        }
    }
  else if (button == ui->RightUp)
    {
      if (ui->RightUp->isChecked()) {
          mgr->get(QNetworkRequest(QUrl(QString("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=start&channel=0&code=RightUp&arg1=0&arg2=1&arg3=0"))));
        }
      else {
          mgr->get(QNetworkRequest(QUrl("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=stop&channel=0&code=RightUp&arg1=0&arg2=1&arg3=0")));
        }
    }
  else if (button == ui->RightDown)
    {
      if (ui->RightDown->isChecked()) {
          mgr->get(QNetworkRequest(QUrl(QString("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=start&channel=0&code=RightDown&arg1=0&arg2=1&arg3=0"))));
        }
      else {
          mgr->get(QNetworkRequest(QUrl("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=stop&channel=0&code=RightDown&arg1=0&arg2=1&arg3=0")));
        }
    }
  else if (button == ui->LeftUp)
    {
      if (ui->LeftUp->isChecked()) {
          mgr->get(QNetworkRequest(QUrl(QString("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=start&channel=0&code=LeftUp&arg1=0&arg2=1&arg3=0"))));
        }
      else {
          mgr->get(QNetworkRequest(QUrl("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=stop&channel=0&code=LeftUp&arg1=0&arg2=1&arg3=0")));
        }
    }
  else if (button == ui->LeftDown)
    {
      if (ui->LeftDown->isChecked()) {
          mgr->get(QNetworkRequest(QUrl(QString("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=start&channel=0&code=LeftDown&arg1=0&arg2=1&arg3=0"))));
        }
      else {
          mgr->get(QNetworkRequest(QUrl("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=stop&channel=0&code=LeftDown&arg1=0&arg2=1&arg3=0")));
        }
    }
  else if (button == ui->zoomOut)
    {
      if (ui->zoomOut->isChecked()) {
          mgr->get(QNetworkRequest(QUrl(QString("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=start&channel=0&code=ZoomWide&arg1=0&arg2=1&arg3=0"))));
        }
      else {
          mgr->get(QNetworkRequest(QUrl("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=stop&channel=0&code=ZoomWide&arg1=0&arg2=1&arg3=0")));
        }
    }
  else if (button == ui->zoomIn)
    {
      if (ui->zoomIn->isChecked()) {
          mgr->get(QNetworkRequest(QUrl(QString("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=start&channel=0&code=ZoomTele&arg1=0&arg2=1&arg3=0"))));
        }
      else {
          mgr->get(QNetworkRequest(QUrl("http://admin:admin@192.168.1.108/cgi-bin/ptz.cgi?action=stop&channel=0&code=ZoomTele&arg1=0&arg2=1&arg3=0")));
        }
    }

}

