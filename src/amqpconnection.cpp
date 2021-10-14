#include "include/amqpconnection.h"

AmqpConnection::AmqpConnection()
{
    this->nameHost = "192.168.131.9";
    this->port = 5672;
    this->exchangeName = "monaco_ri";
    this->run = true;
    this->anglePhi = 10;
    this->listenThread = new std::thread(&AmqpConnection::beginListen,this);
    //this->listenThread = QThread::create(&AmqpConnection::beginListen);
}

AmqpConnection::AmqpConnection(const std::string &_nameHost, int _port, const std::string &_exchangeName)
{
    this->nameHost = _nameHost;
    this->port = _port;
    this->exchangeName = _exchangeName;
    this->run = true;
    this->listenThread = new std::thread(&AmqpConnection::beginListen,this);
    //this->listenThread = new std::thread(&AmqpConnection::beginListen);
}

AmqpConnection::~AmqpConnection()
{
    this->run = false;
    while(!listenThread->joinable())
    {

    }
    listenThread->join();
}

void AmqpConnection::beginListen()
{
    const auto wait_duration = std::chrono::milliseconds(5);

    while(this->run)
    {
        //std::this_thread::sleep_for(wait_duration);
        //std::cout << "listen some info" << std::endl;
        //std::cout << this->nameHost << std::endl;
    }
    std::cout << "Stop thread" << std::endl;
}



