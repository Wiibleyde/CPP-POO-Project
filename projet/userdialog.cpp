#include "userdialog.h"
#include "ui_userdialog.h"
#include "mainwindow.h"
#include <QSqlRelationalTableModel>

UserDialog::UserDialog(int id, QWidget *parent) :
    QDialog(parent), currentId(id),
    ui(new Ui::UserDialog)
{
    ui->setupUi(this);
    QSqlRelationalTableModel *model = new QSqlRelationalTableModel;
    model->setTable("v_aime");
    model->setFilter(QString("idAccount = %1").arg(id));
    model->select();
    ui->tv_passion->setModel(model);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("libelle"));
}

UserDialog::~UserDialog()
{
    delete ui;
}   

void UserDialog::on_pb_passion_clicked()
{
    QString passion = ui->le_passion->text();
    MainWindow::addAime(currentId, passion);
}
