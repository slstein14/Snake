//Sam Stein and Joey Rockwood
//This file contains the coding to make the Main window run and update properly,
//and to make the menus accessible to the user.
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFont>
#include <QDir>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
#ifdef __APPLE__
     QDir bin(QCoreApplication::applicationDirPath());
     bin.cdUp();
     bin.cdUp();
     bin.cdUp();
     QDir::setCurrent(bin.absolutePath());
 #endif
     //Declare Variables and set background image for main window
    ui->setupUi(this);
    QPixmap bkgnd("images/Snake.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    game=NULL;
    hScore = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete hScore;
}

void MainWindow::on_actionQuit_triggered()
{
    //Close main window
    this->close();
}

void MainWindow::on_actionContact_Us_triggered()
{
//needs its own formUI
}

void MainWindow::on_actionHigh_Score_triggered()
{//Creates a high score object if none exists, then displays it
    if(hScore==NULL)
    {
        hScore = new HighScores();
    }else{
        delete hScore;
        hScore = new HighScores();
    }

    hScore->show();
}

void MainWindow::on_actionEasy_triggered()
{//Starts game on easy
    if(hScore==NULL)
    {
        hScore = new HighScores();
    }else{
        delete hScore;
        hScore = new HighScores();
    }

    if(game == NULL)
        {
            game = new GameWindow();
            game->setDifficulty(1);
            game->sendHighScoreObject(hScore);
        }else{
            delete game;
            game = new GameWindow();
            game->setDifficulty(1);
            game->sendHighScoreObject(hScore);
        }
        game->show();
}

void MainWindow::on_actionMedium_triggered()
{//Starts game on medium
    if(hScore==NULL)
    {
        hScore = new HighScores();
    }else{
        delete hScore;
        hScore = new HighScores();
    }

    if(game == NULL)
        {
            game = new GameWindow();
            game->setDifficulty(2);
            game->sendHighScoreObject(hScore);
        }else{
            delete game;
            game = new GameWindow();
            game->setDifficulty(2);
            game->sendHighScoreObject(hScore);
        }
        game->show();
}

void MainWindow::on_actionHard_triggered()
{//Starts game on hard
    if(hScore==NULL)
    {
        hScore = new HighScores();
    }else{
        delete hScore;
        hScore = new HighScores();
    }

    if(game == NULL)
        {
            game = new GameWindow();
            game->setDifficulty(3);
            game->sendHighScoreObject(hScore);
        }else{
            delete game;
            game = new GameWindow();
            game->setDifficulty(3);
            game->sendHighScoreObject(hScore);
        }
        game->show();
}
