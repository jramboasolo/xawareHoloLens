#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
//#include <QJsonObject>
//#include <QJsonDocument>

#include "servertcp.h"
#include "amqpconnection.h"


//Main window of the application

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


//Structure to create the JSON file and the JSON string to send
/*struct InfoZeego
{
    int angleTheta;
    int anglePhi;
    QJsonObject toJson() const {
          return {{"AngleTheta", angleTheta}, {"AnglePhi", anglePhi}};
    }
};*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Connection_clicked();

    void on_Disconnection_clicked();

    void on_sendButton_clicked();

private:
    Ui::MainWindow *ui;
    QLineEdit *hostName;
    QLineEdit *thetaValue;
    QLineEdit *phiValue;
    QLabel *status;
    QLabel *message;
    ServerTcp *server;
    InfoZeego *info;
    AmqpConnection *amqpClient;
};
#endif // MAINWINDOW_H
