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

class GameWindow : public QWidget
{
    Q_OBJECT
private:
    QGenericMatrix<50,50,int>* matrix;


public:
    GameWindow(QWidget *parent = 0);
};

#endif // GAMEWINDOW_H
