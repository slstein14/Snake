#ifndef WALL_H
#define WALL_H
#include <QPainter>
#include <QPixmap>
#include <QWidget>

class Wall : QObject
{
private:
    int posX, posY;
    int sizeX, sizeY;
    int frame;
    int ground, speedX;
    QPixmap *image;

public:
    Wall(QWidget *parent);
    void drawWall(QPainter &painter);
    void setXCoord(int x);
    int getXCoord();
    void setYCoord(int y);
    int getYCoord();
};

#endif // WALL_H
