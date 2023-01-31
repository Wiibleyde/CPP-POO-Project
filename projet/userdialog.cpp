#include "userdialog.h"
#include "ui_userdialog.h"
#include "mainwindow.h"
// #include <QSqlRelationalTableModel>
#include <QStandardItemModel>

UserDialog::UserDialog(int id, QWidget *parent) : QDialog(parent), currentId(id), ui(new Ui::UserDialog)
{
    ui -> setupUi(this);
    QList<QString> passions = MainWindow::getAime(id);
    if (!passions.empty()) {
        QStandardItemModel *model = new QStandardItemModel(passions.size(), 1, this);
        model->setHorizontalHeaderItem(0, new QStandardItem(QString("Passion")));
        for (int i = 0; i < passions.size(); i++) {
            model->setItem(i, 0, new QStandardItem(passions[i]));
        }
        ui->tv_passion->setModel(model);
    }
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
