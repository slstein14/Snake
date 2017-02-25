#include "gamewindow.h"
#include <QKeyEvent>
#include <QDebug>
#include <QRect>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent)
{
        QPixmap bkgnd("images/background.jpg");
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
//        qDebug()<<"Size: ";
//        qDebug()<<this->size();//640x480
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);

        this->setPalette(palette);
        int values[2500]={0};
        matrix = new QGenericMatrix<50,50,int>(values);
//        for(int i=0;i<50;i++){
//            matrix->operator (i)(0)
//                    matrix->
//        }
}
