#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"
#include "highscores.h"
#include "contactus.h"
#include "controls.h"

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

    void on_actionHigh_Score_triggered();

    void on_actionEasy_triggered();

    void on_actionMedium_triggered();

    void on_actionHard_triggered();

    void on_actionControls_triggered();

private:
    Ui::MainWindow *ui;

    GameWindow* game;
    HighScores* hScore;
    ContactUs* contact;
    Controls* controls;
};

#endif // MAINWINDOW_H
