#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();

    void on_actionContact_Us_triggered();

    void on_actionNew_Game_triggered();

private:
    Ui::MainWindow *ui;

    GameWindow* game;
};

#endif // MAINWINDOW_H
