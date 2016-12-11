#include "mainwindow.h"
#include <QApplication>
#include "myserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);





    MyServer server;
    server.startServer();

    QString mainIp = server.findMainIp();
    QString othersIp = server.getAllLocalIp();
    QString hostname = server.getLocalHoseName();


   // qDebug()<<"mainIp"<<mainIp<<" "<<"othersIp"<<othersIp<<" \n";



    MainWindow w;
    w.setUpThisUI();
    w.setIpInformation(mainIp,othersIp,hostname,&server);
    w.show();

    return a.exec();
}
