#ifndef APPLE_H
#define APPLE_H
#include <QPainter>
#include <QPixmap>
#include <QWidget>

class Apple : QObject
{
private:
    int posX, posY;
    int sizeX, sizeY;
    int frame;
    int ground, speedX;
    QPixmap *image;

public:
    Apple(QWidget *parent);
    void drawApple(QPainter &painter);
    void setXCoord(int x);
    int getXCoord();
    void setYCoord(int y);
    int getYCoord();
};

#endif // APPLE_H
