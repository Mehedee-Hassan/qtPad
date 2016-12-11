#ifndef UPDATEUITHREAD_H
#define UPDATEUITHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include "myserver.h"
#include "mainwindow.h"


class UpdateUIThread :public QThread
{


public:

    MyServer *server;
    MainWindow *mainwindow;
    UpdateUIThread();
    UpdateUIThread(MyServer *server,MainWindow *mainwindow);

    void run();



};

#endif // UPDATEUITHREAD_H
