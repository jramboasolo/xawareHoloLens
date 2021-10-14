#include "include/servertcp.h"

//Class to manage the tcp server


//Default constructeur, listen to the port 8080
ServerTcp::ServerTcp(QObject *parent)
{
    info = new InfoZeego();
    if(!listen(QHostAddress::Any,8080))
    {
        start = false;
        infoMessage = errorString().toStdString();
    }
    else
    {
        start = true;
        infoMessage = "The server is starting in the port " + QString::number(serverPort()).toStdString();
    }
    QObject::connect(this,SIGNAL(newConnection()),this, SLOT(AddNewConnection()));

}

//Constructeur that listen to a specific port
ServerTcp::ServerTcp(int port,QObject *parent)
{
    info = new InfoZeego();
    if(!listen(QHostAddress::Any,port))
    {
        start = false;
        infoMessage = errorString().toStdString();
    }
    else
    {
        start = true;
        infoMessage = "The server is starting in the port " + QString::number(serverPort()).toStdString();
    }
    QObject::connect(this,SIGNAL(newConnection()),this, SLOT(AddNewConnection()));
}

//Delete function
ServerTcp::~ServerTcp()
{
    close();
}

//Give the
std::string ServerTcp::GiveMessage()
{
    return infoMessage;
}

bool ServerTcp::IsStarting()
{
    return start;
}

void ServerTcp::AddNewConnection()
{
    QTcpSocket *newClient = nextPendingConnection();
    clients << newClient;
    std::cout << "New client" << std::endl;
    connect(newClient, SIGNAL(disconnected()), this, SLOT(deconnexionClient()));
}

void ServerTcp::deconnexionClient()
{
    std::cout << "Client disconnect" << std::endl;
    // We determine which client is disconnected
    QTcpSocket *socket = qobject_cast<QTcpSocket *>(sender());
    if (socket == 0) // if we don't find the client, we stop the function
        return;

    clients.removeOne(socket);

    socket->deleteLater();
}

void ServerTcp::sendDataSlot(int _angleTheta,int _anglePhi)
{
    info->anglePhi = _anglePhi;
    info->angleTheta = _angleTheta;
    //QString json = QJsonDocument(info->toJson()).toJson().constData();
    //SendData(json.toStdString());
}

void ServerTcp::SendData(const std::string& message)
{
    std::cout << "Send message" << std::endl;

    // Send the json to all clients
    for (int i = 0; i < clients.size(); i++)
    {
        clients[i]->write(message.c_str());
    }
}
