// myserver.cpp

#include "myserver.h"
#include "mythread.h"
#include <QNetworkInterface>


MyServer::MyServer(QObject *parent) :
    QTcpServer(parent)
{
}

QString MyServer::__iplist[50];
int MyServer::__ipListCount= 0;



void MyServer::startServer()
{

    int port = 1239;



    MyServer::clearIpList();
    // no ip found yet
    this->setIpListFound(false);
    this->setMainIpFound(false);



    if(!this->listen(QHostAddress::Any, port))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening to port " << port << "...";


       printMyIp();


    }
}

// This function is called by QTcpServer when a new connection is available.
void MyServer::incomingConnection(qintptr socketDescriptor)
{
    // We have a new connection
    qDebug() << socketDescriptor << " Connecting...";



    // Every new connection will be run in a newly created thread
    MyThread *thread = new MyThread(socketDescriptor, this);

    // connect signal/slot
    // once a thread is not needed, it will be beleted later
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    thread->start();
}


void MyServer::printMyIp(){




    findMainIp();
    if( MyServer::__ipListCount== 0 ){
        getAllLocalIp();
    }





}


void MyServer::getAllLocalIp(){

    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {

        if (address.protocol() == QAbstractSocket::IPv4Protocol
                && address != QHostAddress(QHostAddress::LocalHost)){

             MyServer::__iplist[ MyServer::__ipListCount++] = address.toString();

            qDebug() << address.toString();

            // address found
            this->setIpListFound(true);


        }



    }

}


void MyServer::setIpListFound(bool value){
    this->__IpListFound = value;
}


bool MyServer::getIpListFound(){
   return this->__IpListFound;
}


void MyServer::setMainIpFound(bool value){
    this->__MainIpFound = value;
}


bool MyServer::getMainIpFound(){
   return this->__MainIpFound;
}


void MyServer::findMainIp(){

    QTcpSocket socketForLocalIp;
    socketForLocalIp.connectToHost("8.8.8.8", 53); // google DNS, or something else reliable
    if (socketForLocalIp.waitForConnected()) {
        qDebug()
            << "local IPv4 address for Internet connectivity is"
            << socketForLocalIp.localAddress();


         MyServer::__iplist[__ipListCount++]
                = socketForLocalIp.localAddress().toString();


        this->setMainIpFound(true);

    } else {
        qWarning()
            << "could not determine local IPv4 address:"
            << socketForLocalIp.errorString();
    }


}


void MyServer::clearIpList(){

    for(int i = 0 ; i < 50 ; i ++)
         MyServer::__iplist[i] = "";

}
