#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "userdialog.h"

QSqlDatabase MainWindow::db;

bool MainWindow::ouvreDb()
{
    MainWindow::db = QSqlDatabase::addDatabase("QSQLITE");
    MainWindow::db.setDatabaseName("../accounts.sq3");
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
    QString sql = "INSERT INTO accounts (login, password) VALUES ('"+username+"', '"+password+"')";
    qDebug() <<sql;
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
    QString sql = "INSERT INTO aime (idAccount, libelle) VALUES ("+QString::number(idAccount)+", '"+passion+"')";
    qDebug() <<sql;
    if(qry.exec(sql)) {
        qDebug() <<"Ajout aime OK";
        return true;
    } else {
        qDebug() <<"Ajout aime KO";
        return false;
    }
}

QList<QString> MainWindow::getAime(int idAccount)
{
    QList<QString> list;
    QSqlQuery qry;
    QString sql = "SELECT libelle from aime where idAccount="+QString::number(idAccount);
    qDebug() <<sql;
    if(qry.exec(sql)) {
        qDebug() <<"getAime OK";
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
    QString sql = "SELECT count(*) as nb, idAccount, sex from accounts where login='"+login+"' and password='"+pass+"'";
    //qDebug() <<"Retour select : "<<qry.exec(sql);
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
            UserDialog ud(qry.value(1).toInt());
            ud.exec();
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
