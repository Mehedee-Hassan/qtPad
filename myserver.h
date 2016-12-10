// myserver.h

#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <string>




class MyServer : public QTcpServer
{
    Q_OBJECT


public:

     static QString __iplist[50];
     static int __ipListCount;


    explicit MyServer(QObject *parent = 0);
    void startServer();
    void printMyIp();
    void clearIpList();
    void getAllLocalIp();


    void findMainIp();

    void setIpListFound(bool value);
    bool getIpListFound();

    void setMainIpFound(bool value);
    bool getMainIpFound();



signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);

     bool __IpListFound;
     bool __MainIpFound;


};

#endif // MYSERVER_H
