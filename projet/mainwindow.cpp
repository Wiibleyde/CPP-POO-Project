#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "userdialog.h"

QSqlDatabase MainWindow::db;

bool MainWindow::ouvreDb()
{   
    // Most import part : connect to the database, if it doesn't work, return false and print a message in the console and the application will close
    MainWindow::db = QSqlDatabase::addDatabase("QSQLITE");
    MainWindow::db.setDatabaseName("../accounts.sq3");
    // If the database is opened, return true and print a message in the console
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

bool MainWindow::addUser(QString username, QString password)
{
    QSqlQuery qry;
    // SQLite query to insert a new user in the database
    QString sql = "INSERT INTO accounts (login, password) VALUES ('"+username+"', '"+password+"')";
    qDebug() <<sql;
    // If the query is executed, return true and print a message in the console
    if(qry.exec(sql)) {
        qDebug() <<"Ajout utilisateur OK";
        return true;
    } else {
        qDebug() <<"Ajout utilisateur KO";
        return false;
    }
}

bool MainWindow::addAime(int idAccount, QString passion)
{
    QSqlQuery qry;
    // SQLite query to insert a new passion in the database for a specific user
    QString sql = "INSERT INTO aime (idAccount, libelle) VALUES ("+QString::number(idAccount)+", '"+passion+"')";
    qDebug() <<sql;
    // If the query is executed, return true and print a message in the console
    if(qry.exec(sql)) {
        qDebug() <<"Ajout aime OK";
        return true;
    } else {
        qDebug() <<"Ajout aime KO";
        return false;
    }
}

bool MainWindow::rmAime(int idAccount, QString passion)
{
    QSqlQuery qry;
    // SQLite query to delete a passion in the database for a specific user
    QString sql = "DELETE FROM aime WHERE idAccount="+QString::number(idAccount)+" AND libelle='"+passion+"'";
    qDebug() <<sql;
    // If the query is executed, return true and print a message in the console
    if(qry.exec(sql)) {
        qDebug() <<"Suppression aime OK";
        return true;
    } else {
        qDebug() <<"Suppression aime KO";
        return false;
    }
}

QList<QString> MainWindow::getAime(int idAccount)
{
    QList<QString> list;
    QSqlQuery qry;
    // SQLite query to get all the passions of a specific user
    QString sql = "SELECT libelle from aime where idAccount="+QString::number(idAccount);
    qDebug() <<sql;
    // If the query is executed, return true and print a message in the console
    if(qry.exec(sql)) {
        qDebug() <<"getAime OK";
        // Add all the passions in a QList
        while(qry.next()) {
            list.append(qry.value(0).toString());
        }
        return list;
    } else {
        qDebug() <<"getAime KO";
        return list;
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(MainWindow::ouvreDb()) {
        ui->status->setText( "Connexion à la Base de Données OK.");
    } else {
        ui->status->setText("Problème de connexion à la Base de Données");
    }
    // set window title
    this->setWindowTitle("Connexion");
}

MainWindow::~MainWindow()
{
    delete ui;
    fermeDb();
}

QString MainWindow::getUserById(int id) 
{
    QSqlQuery qry;
    // SQLite query to get the login of a specific user
    QString sql = "SELECT login from accounts where idAccount="+QString::number(id);
    qDebug() <<sql;
    // If the query is executed, return true and print a message in the console
    if(qry.exec(sql)) {
        qry.next();
        qDebug() <<"getUserById OK";
        return qry.value(0).toString();
    } else {
        qDebug() <<"getUserById KO";
        return "";
    }
}

void MainWindow::on_pb_connect_clicked()
{
    QString login = ui->le_login->text();
    QString pass = ui->le_password->text();
    QString accord;
    QSqlQuery qry;
    qDebug() <<"Traitement connexion";
    // SQLite query to get the number of accounts with the same login and password
    QString sql = "SELECT count(*) as nb, idAccount, sex from accounts where login='"+login+"' and password='"+pass+"'";
    qDebug()<<sql;
    // If the query is executed, return true and print a message in the console
    if(qry.exec(sql)) {
        qry.next();
        int nb=qry.value(0).toInt();
        switch(nb) {
        case 0:
            // If there is no account with the same login and password, print a message in the console
            ui->status->setText("Mot de passe incorrect...");
            break;
        case 1: {
            // If there is one account with the same login and password, print a message in the console and open the UserDialog window
            accord = qry.value(2).toInt()==1?"e":"";
            ui->status->setText("Tu es connecté"+accord+" avec le compte "+QString::number(qry.value(1).toInt()));
            UserDialog ud(qry.value(1).toInt());
            ud.exec();
            break;
        }
        default:
            // If there is more than one account with the same login and password, print a message in the console
            ui->status->setText("Duplication de compte !");
            break;
        }
    } else {
        qDebug() <<"Erreur sql ??";
    }
}

void MainWindow::on_pb_create_clicked()
{
    QString login = ui->le_login->text();
    QString pass = ui->le_password->text();
    if(addUser(login, pass)) {
        ui->status->setText("Utilisateur créé avec succès");
    } else {
        ui->status->setText("Erreur lors de la création de l'utilisateur");
    }
}
