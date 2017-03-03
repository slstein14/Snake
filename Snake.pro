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
    highscores.cpp \
    contactus.cpp \
    controls.cpp \
    renderobject.cpp

HEADERS  += mainwindow.h \
    gamewindow.h \
    highscores.h \
    contactus.h \
    controls.h \
    renderobject.h

FORMS    += mainwindow.ui \
    highscores.ui \
    contactus.ui \
    controls.ui
