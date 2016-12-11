// myserver.h

#ifndef MYSERVER_H
#define MYSERVER_H

#include <QTcpServer>
#include <string>




class MyServer : public QTcpServer
{
    Q_OBJECT


public:



    explicit MyServer(QObject *parent = 0);
    void startServer();
    void printMyIp();
    void clearIpList();
    QString getAllLocalIp();
    QString findMainIp();
    QString getLocalHoseName();



signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);




};

#endif // MYSERVER_H
