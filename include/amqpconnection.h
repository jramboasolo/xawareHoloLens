#ifndef AMQPCONNECTION_H
#define AMQPCONNECTION_H

#include <QObject>
#include <QThread>
#include <iostream>
#include <thread>
#include <utility>
#include <chrono>
#include <atomic>

class AmqpConnection: public QObject
{
    Q_OBJECT

public:
    AmqpConnection();
    AmqpConnection(const std::string& _hostName,int _port,const std::string& _exchangeName);
    ~AmqpConnection();
    void beginListen();
    int angleTheta;
    int anglePhi;
    std::atomic<bool> run;

private:
    std::string nameHost;
    std::string queueName;
    std::string exchangeName;
    int port;
    std::thread *listenThread;
    //QThread *listenThread;

signals:
    void newMessageReceive(int _angleTheta,int _anglePhi);
};

#endif // AMQPCONNECTION_H
