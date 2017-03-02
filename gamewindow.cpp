#include "gamewindow.h"
#include <QKeyEvent>
#include <QDebug>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <QDir>
#include <QCoreApplication>
#include "player.h"
#include "wall.h"
#include "apple.h"
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
        timer->setInterval(100);
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
        apple = new Apple(this);
        this->moveApple();//initialize apple randomly
        srand(time(0));
}

void GameWindow::paintEvent(QPaintEvent *e)
{
    if(timer->isActive()){
        qDebug()<<"PaintEvent";
        QPainter painter(this);

        apple->drawApple(painter);


        for(int i=0;i<segments.size();i++){
            (*(segments.at(i))).drawPlayer(painter);
        }

        for(int i=0;i<walls.size();i++){
            (*(walls.at(i))).drawWall(painter);
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

void GameWindow::moveSnake()
{
    //Object Movement
    int backX=(*(segments.at(segments.size()-1))).getXCoord();
    int backY=(*(segments.at(segments.size()-1))).getYCoord();
    matrix[backY][backX]=0;
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
    if(2==matrix[(*(segments.at(0))).getYCoord()][(*(segments.at(0))).getXCoord()]){
        appleEaten=true;
        Player *newseg = new Player(this);
        newseg->setXCoord(backX);
        newseg->setYCoord(backY);
        segments.push_back(newseg);
    }

    if((3==matrix[(*(segments.at(0))).getYCoord()][(*(segments.at(0))).getXCoord()])||(1==matrix[(*(segments.at(0))).getYCoord()][(*(segments.at(0))).getXCoord()])){
        timer->stop();
        QMessageBox mbox;
        mbox.setText("Game Over");
           mbox.exec();
        this->close();
    }

    matrix[(*(segments.at(0))).getYCoord()][(*(segments.at(0))).getXCoord()]=1;
}

void GameWindow::moveApple()
{
    matrix[apple->getYCoord()][apple->getXCoord()]=0;
    int x=0;
    int y=0;
    while(0!=matrix[y][x]){
        x = rand()%64;
        y = rand()%48;
    }
    apple->setXCoord(x);
    apple->setYCoord(y);
    matrix[y][x]=2;
    appleEaten=false;
}

void GameWindow::updateField()
{
    this->moveSnake();
    if(appleEaten){
        this->moveApple();
    }
    this->update();
}
