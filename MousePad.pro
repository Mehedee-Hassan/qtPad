#-------------------------------------------------
#
# Project created by QtCreator 2016-12-11T04:10:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MousePad
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myserver.cpp \
    mythread.cpp \
    robot.cpp

HEADERS  += mainwindow.h \
    controlrobot.h \
    myserver.h \
    mythread.h \
    Robot.h \
    utility.h

FORMS    += mainwindow.ui

RESOURCES += \
    resources.qrc
