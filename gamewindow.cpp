#include "gamewindow.h"
#include <QKeyEvent>
#include <QDebug>
#include <QRect>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <iostream>
#include <QDir>
#include <QCoreApplication>
#include "player.h"
using namespace std;

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent)
{
#ifdef __APPLE__
     QDir bin(QCoreApplication::applicationDirPath());
     bin.cdUp();
     bin.cdUp();
     bin.cdUp();
     QDir::setCurrent(bin.absolutePath());
 #endif
        QPixmap bkgnd("images/background.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
//        qDebug()<<"Size: ";
//        qDebug()<<this->size();//640x480
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);

        this->setPalette(palette);
        //tick timer for movements
        timer = new QTimer();
        timer->setInterval(200);
        connect(timer, SIGNAL(timeout()), this, SLOT(updateField()));
        timer->start();

        //initialize map borders
        int matrix[48][64];
        for(int i=0;i<48;i++){
            for(int j=0;j<64;j++){
                if(0==j||0==i||63==j||47==i){
                    matrix[i][j]=3;
                }
                else matrix[i][j]=0;
            }
        }


        player = new Player(this);
}

void GameWindow::paintEvent(QPaintEvent *e)
{
    if(timer->isActive()){
        qDebug()<<"PaintEvent";
        QPainter painter(this);
        player->drawPlayer(painter);


        //Object Movement
        if(2==player->getPlayerDirection()){
            player->setXCoord(player->getXCoord()+1);
        }
        else if(1==player->getPlayerDirection()){

            player->setXCoord(player->getXCoord()-1);
        }
        else if(0==player->getPlayerDirection()){
            player->setYCoord(player->getYCoord()-1);
        }
        else{
            player->setYCoord(player->getYCoord()+1);
        }

        if((player->getXCoord()<0)||(player->getXCoord()>63)||(player->getYCoord()<0)||(player->getYCoord()>47)){
            timer->stop();
            QMessageBox mbox;
            mbox.setText("Game Over");
               mbox.exec();
        }
    }
}

void GameWindow::keyPressEvent(QKeyEvent *evt)
{
    switch(evt->key())
        {
        case Qt::Key_Right:
            player->setDirection(2);
            break;
        case Qt::Key_Down:
        player->setDirection(3);
            break;
        case Qt::Key_Up:
        player->setDirection(0);
            break;
        case Qt::Key_Left:
        player->setDirection(1);
            break;
        default:
            break;
        }
}

void GameWindow::updateField()
{
    this->update();
}
