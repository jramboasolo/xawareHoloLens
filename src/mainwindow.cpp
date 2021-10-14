#include "include/mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

//Class for the Main window of the application

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hostName = ui->hostName;
    status = ui->StatusLabel;
    thetaValue = ui->thetaValue;
    phiValue = ui->phiValue;
    info = new InfoZeego();
    server = NULL;
    amqpClient = NULL;
}

MainWindow::~MainWindow()
{
    //Check if the server is running before to quit
    if(server != NULL)
    {
        delete server;
        server = NULL;
    }
    if(amqpClient != NULL)
    {
        delete  amqpClient;
        amqpClient = NULL;
    }
    delete ui;
}

//Slot when the user click on the button "start connection"
void MainWindow::on_Connection_clicked()
{
    server = new ServerTcp(8052,this);
    if(server->IsStarting())
    {
        status->setText(server->GiveMessage().c_str());
    }
    else
    {
        status->setText(server->GiveMessage().c_str());
    }
    amqpClient = new AmqpConnection();
    connect(amqpClient,SIGNAL(newMessageReceive(int,int)),server,SLOT(sendDataSlot(int,int)));
}


//Slot when the user click on the button "stop connection"
void MainWindow::on_Disconnection_clicked()
{
    status->setText("Server not running");
    if(server != NULL)
    {
        delete server;
        delete  amqpClient;
        server = NULL;
        amqpClient = NULL;
    }
}


//Slot when the user click on the button "send message" (use only for the tests)
void MainWindow::on_sendButton_clicked()
{
    QString phi = phiValue->text();
    if(phi.isEmpty())
    {
        info->anglePhi = 0;
    }
    else
    {
        info->anglePhi = phi.toInt();
    }
    QString theta = thetaValue->text();
    if(theta.isEmpty())
    {
        info->angleTheta = 0;
    }
    else
    {
        info->angleTheta = theta.toInt();
    }
    //QString json = QJsonDocument(info->toJson()).toJson().constData();
    amqpClient->angleTheta = info->angleTheta;
    amqpClient->anglePhi = info->anglePhi;
    //emit amqpClient->newMessageReceive(amqpClient->angleTheta,amqpClient->anglePhi);
    //server->SendData(json.toStdString());
}



