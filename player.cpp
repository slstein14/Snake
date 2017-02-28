#include "player.h"
#include <QDir>
#include <QCoreApplication>
#include <qdebug.h>

Player::Player(QWidget *parent)
{
#ifdef __APPLE__
     QDir bin(QCoreApplication::applicationDirPath());
     bin.cdUp();
     bin.cdUp();
     bin.cdUp();
     QDir::setCurrent(bin.absolutePath());
 #endif
        posX = 1; //starts at 10,10 in matrix
        posY = 1;
        sizeX = 10;//size is 10x10px to start (1 segment)
        sizeY = 10;
        playerDirection=2;
        image = new QPixmap("Images/snakeSegment.png");
}

void Player::drawPlayer(QPainter &painter)
{
    qDebug()<<"Player PaintEvent at X: "<<posX<<" Y: "<<posY;
    painter.drawPixmap(10*posX, 10*posY, sizeX, sizeY, *image);//Converts matrix location to pixel location
}

void Player::setXCoord(int x)
{
    posX=x;
}

int Player::getXCoord()
{
    return posX;
}

void Player::setYCoord(int y)
{
    posY=y;
}

int Player::getYCoord()
{
    return posY;
}

int Player::getPlayerDirection()
{
    return playerDirection;
}

void Player::setDirection(int dir)
{
    playerDirection=dir;
}
