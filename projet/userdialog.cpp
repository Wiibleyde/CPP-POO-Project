#include "userdialog.h"
#include "ui_userdialog.h"
#include "mainwindow.h"
// #include <QSqlRelationalTableModel>
#include <QStandardItemModel>
#include <QVBoxLayout>

UserDialog::UserDialog(int id, QWidget *parent) : QDialog(parent), currentId(id), ui(new Ui::UserDialog)
{
    ui->setupUi(this);
    QList<QString> passions = MainWindow::getAime(id);
    // If the user has at least one passion, create a table with all the passions and add it to the layout
    if (!passions.empty()) {
        QStandardItemModel *model = new QStandardItemModel(passions.size(), 1, this);
        model->setHorizontalHeaderItem(0, new QStandardItem(QString("Passion")));
        for (int i = 0; i < passions.size(); i++) {
            model->setItem(i, 0, new QStandardItem(passions[i]));
        }
        ui->tv_passion->setModel(model);
        ui->tv_passion->verticalHeader()->setVisible(false);
        ui->tv_passion->horizontalHeader()->setStretchLastSection(true);
        ui->tv_passion->setEditTriggers(QAbstractItemView::NoEditTriggers);
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(ui->pb_refresh);
        layout->addWidget(ui->tv_passion);
        layout->addWidget(ui->pb_passion);
        layout->addWidget(ui->pb_rm_passion);
        layout->addWidget(ui->le_passion);
        setLayout(layout);
    }
    // change the title of the dialog box to the user's name
    setWindowTitle(MainWindow::getUserById(id));
}

void UserDialog::ReloadTable()
{   
    // Reload the table shown in the dialog box with the user's passions
    QList<QString> passions = MainWindow::getAime(currentId);
    // If the user has at least one passion, create a table with all the passions and add it to the layout
    if (!passions.empty()) {
        QStandardItemModel *model = new QStandardItemModel(passions.size(), 1, this);
        model->setHorizontalHeaderItem(0, new QStandardItem(QString("Passion")));
        for (int i = 0; i < passions.size(); i++) {
            model->setItem(i, 0, new QStandardItem(passions[i]));
        }
        ui->tv_passion->setModel(model);
        ui->tv_passion->verticalHeader()->setVisible(false);
        ui->tv_passion->horizontalHeader()->setStretchLastSection(true);
        ui->tv_passion->setEditTriggers(QAbstractItemView::NoEditTriggers);
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
    // Reload table at every table modification
    ReloadTable();
}

void UserDialog::on_pb_rm_passion_clicked()
{
    QString passion = ui->le_passion->text();
    MainWindow::rmAime(currentId, passion);
    // Reload table at every table modification
    ReloadTable();
}

void UserDialog::on_pb_refresh_clicked()
{
    ReloadTable();
}