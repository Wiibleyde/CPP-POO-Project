#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>

QSqlDatabase MainWindow::db;

bool MainWindow::ouvreDb()
{
    MainWindow::db = QSqlDatabase::addDatabase("QSQLITE");
    MainWindow::db.setDatabaseName("accounts.sq3");
    if(MainWindow::db.open()) {
        qDebug() <<"OuvreDb : connexion OK";
        return true;
    }
    else {
        qDebug() <<"OuvreDb : connexion KO";
        return false;
    }
}

void MainWindow::fermeDb()
{
    MainWindow::db.close();
}

bool MainWindow::creerTable()
{
    QSqlQuery qry;
    QString sql = "CREATE TABLE IF NOT EXISTS accounts (idAccount INTEGER PRIMARY KEY AUTOINCREMENT,login TEXT NOT NULL,password TEXT NOT NULL,textFile TEXT)";
    if(qry.exec(sql)) {
        qDebug() <<"Table créée";
        return true;
    } else {
        qDebug() <<"Table non créée";
        return false;
    }
}

bool MainWindow::insertAccount(QString login, QString password, QString textFile)
{
    QSqlQuery qry;
    QString sql = "INSERT INTO accounts (login,password,textFile) VALUES ('"+login+"','"+password+"','"+textFile+"')";
    if(qry.exec(sql)) {
        qDebug() <<"Insertion OK";
        MainWindow::createTextFile(login);
        qDebug() << MainWindow::getFileName(login);
        return true;
    } else {
        qDebug() <<"Insertion KO";
        return false;
    }
}

QString MainWindow::getFileName(QString login)
{
    QSqlQuery qry;
    QString sql = "SELECT textFile FROM accounts WHERE login='"+login+"'";
    if(qry.exec(sql)) {
        while(qry.next()) {
            fileName = qry.value(0).toString();
        }
    }
    return fileName;
}

QString MainWindow::createTextFile(QString login)
{
    // create a text file empty and return the name of the file
    fileName = login + ".txt";
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "";
        file.close();
    }
    return fileName;
}

QString MainWindow::readTextFile(QString login, QString password)
{
    fileName = login + ".txt";
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            qDebug() << line;
        }
        file.close();
    }
    return fileName;
}

QString MainWindow::modifyTextFile(QString login, QString password, QString text)
{
    fileName = login + ".txt";
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << text;
        file.close();
    }
    return fileName;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(MainWindow::ouvreDb()) {
        ui->status->setText("DB OK");
    } else {
        ui->status->setText("DB KO");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    fermeDb();

}



void MainWindow::on_pb_connect_clicked()
{
    QString login = ui->le_login->text();
    QString pass = ui->le_password->text();
    QString accord;
    QSqlQuery qry;
    qDebug() <<"Traitement connexion";
    QString sql = "SELECT COUNT(*) as nb, idAccount, sex FROM accounts WHERE login='"+login+"' AND password='"+pass+"'";
    qDebug()<<sql;
    if(qry.exec(sql)) {
        qry.next();
        int nb=qry.value(0).toInt();
        switch(nb) {
        case 0:
            ui->status->setText("Mot de passe incorrect...");
            break;
        case 1: {
            accord = qry.value(2).toInt()==1?"e":"";
            ui->status->setText("Tu es connecté"+accord+" avec le compte "+QString::number(qry.value(1).toInt()));
            break;
        }
        default:
            ui->status->setText("Duplication de compte !");
            break;
        }
    } else {
        qDebug() <<"Erreur sql ??";
    }
}
