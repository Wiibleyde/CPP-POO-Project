/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *status;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *le_login;
    QLineEdit *le_password;
    QPushButton *pb_connect;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        status = new QLabel(centralwidget);
        status->setObjectName("status");
        status->setGeometry(QRect(10, 490, 781, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        status->setFont(font);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(40, 30, 681, 281));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 50, 131, 18));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 80, 131, 18));
        le_login = new QLineEdit(groupBox);
        le_login->setObjectName("le_login");
        le_login->setGeometry(QRect(250, 50, 291, 26));
        le_password = new QLineEdit(groupBox);
        le_password->setObjectName("le_password");
        le_password->setGeometry(QRect(250, 80, 291, 26));
        pb_connect = new QPushButton(groupBox);
        pb_connect->setObjectName("pb_connect");
        pb_connect->setGeometry(QRect(420, 210, 161, 26));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        status->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Connexion", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Login :", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Password :", nullptr));
        pb_connect->setText(QCoreApplication::translate("MainWindow", "Connecter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
