// myserver.cpp

#include "myserver.h"
#include "mythread.h"
#include <QNetworkInterface>
#include <QHostInfo>


MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
}



void MyServer::startServer()
{

    int port = 1239;


   if(!this->listen(QHostAddress::Any, port))
    {
        //qDebug() << "Could not start server";
    }
    else
    {
      //  qDebug() << "Listening to port " << port << "...";


       //printMyIp();


    }
}

// This function is called by QTcpServer when a new connection is available.
void MyServer::incomingConnection(qintptr socketDescriptor)
{
    // We have a new connection
   // qDebug() << socketDescriptor << " Connecting...";



    // Every new connection will be run in a newly created thread
    MyThread *thread = new MyThread(socketDescriptor, this);

    // connect signal/slot
    // once a thread is not needed, it will be beleted later
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}


void MyServer::printMyIp(){




    findMainIp();
    {
        getAllLocalIp();
    }





}


QString MyServer::getAllLocalIp(){

    QString returnString = "";

    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {

        if (address.protocol() == QAbstractSocket::IPv4Protocol
                && address != QHostAddress(QHostAddress::LocalHost)){


                    returnString += address.toString();
                    returnString += "<br>";

        }



    }

    return returnString;
}



QString MyServer::findMainIp(){


    QString returnString = "";
    QTcpSocket socketForLocalIp;
    socketForLocalIp.connectToHost("8.8.8.8", 53); // google DNS, or something else reliable


    if (socketForLocalIp.waitForConnected()) {
//        qDebug()          << "local IPv4 address for Internet connectivity is"         << socketForLocalIp.localAddress();




              returnString += socketForLocalIp.localAddress().toString();
              returnString +="<br>";




    } else {
//        qWarning()            << "could not determine local IPv4 address:"            << socketForLocalIp.errorString();
    }


    return returnString;
}



QString MyServer::getLocalHoseName(){
    QString returnString = "";

    returnString = QHostInfo::localHostName();

    return returnString;
}

