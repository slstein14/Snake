#ifndef PLAYER_H
#define PLAYER_H
#include <QPainter>
#include <QPixmap>
#include <QWidget>


class Player : QObject
{
private:
    //enum keyPressed {NONE = 0, RIGHT = 1, UP = 2, DOWN = 3, LEFT = 4};
    //enum direction {WEST = -1, STAND = 0, EAST = 1};
    //bool rolling, jumping, moveLeft, moveRight, ascend, upPressed;
    //bool onGround, playerOnWall, playerOnPlatform, wallCollided;
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
