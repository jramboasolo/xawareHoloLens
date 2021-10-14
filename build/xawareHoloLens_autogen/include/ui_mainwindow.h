/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *StatusLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *thetaMessage;
    QLineEdit *thetaValue;
    QLabel *label;
    QLineEdit *phiValue;
    QPushButton *sendButton;
    QHBoxLayout *horizontalLayout;
    QLabel *adress;
    QLineEdit *hostName;
    QPushButton *Connection;
    QPushButton *Disconnection;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(70, 10, 681, 521));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        StatusLabel = new QLabel(verticalLayoutWidget);
        StatusLabel->setObjectName(QString::fromUtf8("StatusLabel"));
        StatusLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(StatusLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        thetaMessage = new QLabel(verticalLayoutWidget);
        thetaMessage->setObjectName(QString::fromUtf8("thetaMessage"));
        thetaMessage->setMargin(2);

        horizontalLayout_2->addWidget(thetaMessage);

        thetaValue = new QLineEdit(verticalLayoutWidget);
        thetaValue->setObjectName(QString::fromUtf8("thetaValue"));

        horizontalLayout_2->addWidget(thetaValue);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMargin(2);

        horizontalLayout_2->addWidget(label);

        phiValue = new QLineEdit(verticalLayoutWidget);
        phiValue->setObjectName(QString::fromUtf8("phiValue"));

        horizontalLayout_2->addWidget(phiValue);

        sendButton = new QPushButton(verticalLayoutWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        horizontalLayout_2->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        adress = new QLabel(verticalLayoutWidget);
        adress->setObjectName(QString::fromUtf8("adress"));

        horizontalLayout->addWidget(adress);

        hostName = new QLineEdit(verticalLayoutWidget);
        hostName->setObjectName(QString::fromUtf8("hostName"));
        hostName->setEnabled(true);

        horizontalLayout->addWidget(hostName);

        Connection = new QPushButton(verticalLayoutWidget);
        Connection->setObjectName(QString::fromUtf8("Connection"));

        horizontalLayout->addWidget(Connection);

        Disconnection = new QPushButton(verticalLayoutWidget);
        Disconnection->setObjectName(QString::fromUtf8("Disconnection"));

        horizontalLayout->addWidget(Disconnection);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        StatusLabel->setText(QApplication::translate("MainWindow", "Server not running", 0, QApplication::UnicodeUTF8));
        thetaMessage->setText(QApplication::translate("MainWindow", "theta", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "phi", 0, QApplication::UnicodeUTF8));
        sendButton->setText(QApplication::translate("MainWindow", "Send message", 0, QApplication::UnicodeUTF8));
        adress->setText(QApplication::translate("MainWindow", "Give ip adress", 0, QApplication::UnicodeUTF8));
        Connection->setText(QApplication::translate("MainWindow", "Start Server", 0, QApplication::UnicodeUTF8));
        Disconnection->setText(QApplication::translate("MainWindow", "Stop Serveur", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
