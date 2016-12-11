#include "updateuithread.h"

UpdateUIThread::UpdateUIThread()
{



}


UpdateUIThread::UpdateUIThread(MyServer *server,MainWindow *mainwindow)
{

    this->server = server;
    this->mainwindow = mainwindow;



}


void UpdateUIThread::run(){


        QString mainIp = this->server->findMainIp();
        QString othersLocalIp = this->server->getAllLocalIp();
        QString hostname = this->server->getLocalHoseName();

        mainwindow->setIpInformation( mainIp , othersLocalIp, hostname);
        mainwindow->changeLabelText();

}




