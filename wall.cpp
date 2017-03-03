#include "wall.h"
#include <QDir>
#include <QCoreApplication>
#include <qdebug.h>

Wall::Wall(QWidget *parent)
{
#ifdef __APPLE__
     QDir bin(QCoreApplication::applicationDirPath());
     bin.cdUp();
     bin.cdUp();
     bin.cdUp();
     QDir::setCurrent(bin.absolutePath());
 #endif
    posX = 1; //starts at 10,10 in matrix (immediately moved by the setup)
    posY = 1;
    sizeX = 10;//size is 10x10px (1 matrix unit)
    sizeY = 10;
    image = new QPixmap("Images/wall.png");
}

void Wall::drawWall(QPainter &painter)
{//Draws walls at the appropriate place
    painter.drawPixmap(10*posX, 10*posY, sizeX, sizeY, *image);//Converts matrix location to pixel location
}

void Wall::setXCoord(int x)
{
    posX=x;
}

int Wall::getXCoord()
{
    return posX;
}

void Wall::setYCoord(int y)
{
     posY=y;
}

int Wall::getYCoord()
{
    return posY;
}
