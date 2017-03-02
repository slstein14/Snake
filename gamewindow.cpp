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
#include "wall.h"
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
        wallnumber=0;
        //initialize map borders
        for(int i=0;i<48;i++){
            for(int j=0;j<64;j++){
                if(0==j||0==i||63==j||47==i){
                    matrix[i][j]=3;
                    wallnumber++;
                    wall = new Wall(this);
                    wall->setXCoord(j);
                    wall->setYCoord(i);
                    walls.push_back(wall);
                }
                else matrix[i][j]=0;
            }
        }
        for(int i=4;i>1;i--){
            player = new Player(this);
            player->setXCoord(i);
            player->setYCoord(1);
            segments.push_back(player);
        }

}

void GameWindow::paintEvent(QPaintEvent *e)
{
    if(timer->isActive()){
        qDebug()<<"PaintEvent";
        QPainter painter(this);

        for(int i=0;i<segments.size();i++){
            (*(segments.at(i))).drawPlayer(painter);
        }

        for(int i=0;i<walls.size();i++){
            (*(walls.at(i))).drawWall(painter);
        }

        //Object Movement
        matrix[(*(segments.at(segments.size()-1))).getYCoord()][(*(segments.at(segments.size()-1))).getXCoord()]=0;

        rotate(segments.begin(),segments.end()-1,segments.end());
        if(2==player->getPlayerDirection()){
            (*(segments.at(0))).setXCoord((*(segments.at(1))).getXCoord()+1);
            (*(segments.at(0))).setYCoord((*(segments.at(1))).getYCoord());
        }
        else if(1==player->getPlayerDirection()){
            (*(segments.at(0))).setXCoord((*(segments.at(1))).getXCoord()-1);
            (*(segments.at(0))).setYCoord((*(segments.at(1))).getYCoord());
        }
        else if(0==player->getPlayerDirection()){
            (*(segments.at(0))).setXCoord((*(segments.at(1))).getXCoord());
            (*(segments.at(0))).setYCoord((*(segments.at(1))).getYCoord()-1);
        }
        else{
            (*(segments.at(0))).setXCoord((*(segments.at(1))).getXCoord());
            (*(segments.at(0))).setYCoord((*(segments.at(1))).getYCoord()+1);
        }
        matrix[(*(segments.at(0))).getYCoord()][(*(segments.at(0))).getXCoord()]=1;

        if(((*(segments.at(0))).getXCoord()<0)||((*(segments.at(0))).getXCoord()>63)||((*(segments.at(0))).getYCoord()<0)||((*(segments.at(0))).getYCoord()>47)){
            timer->stop();
            QMessageBox mbox;
            mbox.setText("Game Over");
               mbox.exec();
            this->close();
        }
    }
}

void GameWindow::keyPressEvent(QKeyEvent *evt)
{
    switch(evt->key())
        {
        case Qt::Key_Right:
            if(player->getPlayerDirection()!=1){
                player->setDirection(2);
            }
            break;
            case Qt::Key_Down:
        if(player->getPlayerDirection()!=0){
                player->setDirection(3);
            }
            break;
        case Qt::Key_Up:
            if(player->getPlayerDirection()!=3){
                player->setDirection(0);
            }
            break;
        case Qt::Key_Left:
            if(player->getPlayerDirection()!=2){
                player->setDirection(1);
            }
            break;
        default:
            break;
        }
}

void GameWindow::updateField()
{
    this->update();
}
