#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include <QPixmap>
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include <QGenericMatrix>
#include "player.h"

class GameWindow : public QWidget
{
    Q_OBJECT
private:
    QTimer *timer;
    Player *player;

public:
    GameWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *evt);


public slots:
    void updateField();
};

#endif // GAMEWINDOW_H
