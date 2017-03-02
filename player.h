#ifndef PLAYER_H
#define PLAYER_H
#include <QPainter>
#include <QPixmap>
#include <QWidget>


class Player : QObject
{
private:
    int posX, posY;
    int sizeX, sizeY;
    int frame;
    int ground, speedX;
    int lastActionPressed;
    int playerDirection;
    QPixmap *image;
    enum direction {Up = 0, Left = 1, Right = 2, Down=3};

public:
    Player(QWidget *parent);
    void drawPlayer(QPainter &painter);
    void setXCoord(int x);
    int getXCoord();
    void setYCoord(int y);
    int getYCoord();
    int getPlayerDirection();
    void setDirection(int dir);
};

#endif // PLAYER_H
