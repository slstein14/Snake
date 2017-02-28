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
    ui->setupUi(this);
    QPixmap bkgnd("images/Snake.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    game=NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::on_actionContact_Us_triggered()
{

}

void MainWindow::on_actionNew_Game_triggered()
{
    if(game == NULL)
        {
            game = new GameWindow();
        }else{
            delete game;
            game = new GameWindow();
        }
        game->show();
}
