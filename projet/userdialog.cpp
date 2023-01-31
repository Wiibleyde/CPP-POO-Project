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
        layout->addWidget(ui->tv_passion);
        setLayout(layout);
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
