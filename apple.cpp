#include "apple.h"
#include <QDir>
#include <QCoreApplication>
#include <qdebug.h>

Apple::Apple(QWidget *parent)
{
#ifdef __APPLE__//Apple as in MacOS, not apple as in snake food
     QDir bin(QCoreApplication::applicationDirPath());
     bin.cdUp();
     bin.cdUp();
     bin.cdUp();
     QDir::setCurrent(bin.absolutePath());
 #endif
    posX = 1; //starts at 10,10 in matrix (immediately moved by the apple controls)
    posY = 1;
    sizeX = 10;//size is 10x10px (1 matrix unit)
    sizeY = 10;
    image = new QPixmap("Images/apple.png");
}

void Apple::drawApple(QPainter &painter)
{//Draws the apple at the target location
     painter.drawPixmap(10*posX, 10*posY, sizeX, sizeY, *image);//Converts matrix location to pixel location
 }

void Apple::setXCoord(int x)
{
    posX=x;
}

int Apple::getXCoord()
{
    return posX;
}

void Apple::setYCoord(int y)
{
    posY=y;
}

int Apple::getYCoord()
{
    return posY;
}
