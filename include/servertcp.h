#ifndef SERVERTCP_H
#define SERVERTCP_H

#include <QObject>
#include <iostream>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTextStream>
//#include <QJsonObject>
//#include <QJsonDocument>


//Structure to create the JSON file and the JSON string to send
struct InfoZeego
{
    int angleTheta;
    int anglePhi;
    /*QJsonObject toJson() const {
          return {{"AngleTheta", angleTheta}, {"AnglePhi", anglePhi}};
    }*/
};


//Class to manage the tcp server

class ServerTcp : public QTcpServer
{
    Q_OBJECT
public:
    ServerTcp(QObject *parent = nullptr);
    ServerTcp(int port,QObject *parent = nullptr);
    std::string GiveMessage();
    InfoZeego *info;
    void SendData(const std::string &message);
    bool IsStarting();
    ~ServerTcp();

private:
    QList<QTcpSocket *> clients;
    bool start;
    std::string infoMessage;


private slots:
    void AddNewConnection();
    void deconnexionClient();
    void sendDataSlot(int _angleTheta,int _anglePhi);


signals:

};

#endif // SERVERTCP_H
