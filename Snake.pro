#-------------------------------------------------
#
# Project created by QtCreator 2017-02-25T14:08:16
#
#-------------------------------------------------

QT       += core gui quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snake
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamewindow.cpp \
    player.cpp \
    wall.cpp \
    apple.cpp \
    highscores.cpp

HEADERS  += mainwindow.h \
    gamewindow.h \
    player.h \
    wall.h \
    apple.h \
    highscores.h

FORMS    += mainwindow.ui \
    highscores.ui
