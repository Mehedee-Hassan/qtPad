#include "mythread.h"
#include <iostream>
#include <QNetworkInterface>
#include <QHostInfo>

#include "controlrobot.h"




MyThread::MyThread(qintptr ID, QObject *parent) :
    QThread(parent)
{
    this->socketDescriptor = ID;
}

void MyThread::run()
{
    // thread starts here
   // qDebug() << " Thread started";

    socket = new QTcpSocket();

    // set the ID
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        // something's wrong, we just emit a signal
        emit error(socket->error());
        return;
    }

    // connect socket and signal
    // note - Qt::DirectConnection is used because it's multithreaded
    //        This makes the slot to be invoked immediately, when the signal is emitted.

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    // We'll have multiple clients, we want to know which is which
    //qDebug() << socketDescriptor << " Client connected";





    // make this thread a loop,
    // thread will stay alive so that signal/slot to function properly
    // not dropped out in the middle when thread dies

    exec();
}

void MyThread::readyRead()
{
    // get the information


    memset(__data,0,sizeof __data);


    //socket->read(__data,15);


    QByteArray Data = socket->readAll();
    //std::cout<<" \ndata = "<<__data<<std::endl;


    // will write on server side window
    // qDebug() << socketDescriptor << " Data in: " << Data;


    // qDebug() << "\nreturn "<<Data[0]<<" "<<Data[1];




     ///todo change in android to send new line before flag search
     if(Data[0] == '1' && Data[1] == '8'){
      //       qDebug() << "\nreturn 18";
            socket->write(QHostInfo::localHostName().toStdString().c_str());

     }

     // if it is a valid data
     // first will be '\n'
    if(Data[0] == '\n'){
    //    qDebug() << "\nnew line found = "<<Data <<"|\n";







        QList<QByteArray> listOfMessage = Data.split('\n');

            int len = listOfMessage.length();

            for(int i = 0 ; i < len ; i ++){

                if(listOfMessage[i].length() > 0){

       //             qDebug() << "\neach big line = "<<listOfMessage[i] <<"\n";

                    QList<QByteArray> singleData = utility_splitQbA(listOfMessage[i],' ');
                    mainControl_Robot(singleData);


                }



            }


    }





}

void MyThread::disconnected()
{
   // qDebug() << socketDescriptor << " Disconnected";


    socket->deleteLater();
    exit(0);
}



