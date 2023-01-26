#include "userdialog.h"
#include "ui_userdialog.h"

UserDialog::UserDialog(int id, QWidget *parent) :
    QDialog(parent), currentId(id),
    ui(new Ui::UserDialog)
{
    ui->setupUi(this);
}

UserDialog::~UserDialog()
{
    delete ui;
}   

QList<QString> UserDialog::getUserPassion()
{
    QList<QString> passions;
    QSqlQuery qry;
    QString sql = "SELECT passion FROM passions WHERE idAccount = "+QString::number(currentId);
    if(qry.exec(sql)) {
        while(qry.next()) {
            passions.append(qry.value(0).toString());
        }
    }
    return passions;
}

void UserDialog::on_pb_passion_clicked()
{
    QString passion = ui->le_passion->text();
    QSqlQuery qry;
    QString sql = "INSERT INTO passions (idAccount, passion) VALUES ("+QString::number(currentId)+", '"+passion+"')";
    qDebug() <<sql;
    if(qry.exec(sql)) {
        qDebug() <<"Ajout passion OK";
    } else {
        qDebug() <<"Ajout passion KO";
    }
}

void UserDialog::on_pb_logout_clicked()
{
    this->close();
}
