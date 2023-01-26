#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>
#include <QList>
#include <QString>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT
public:
    int currentId;
    QList<QString> getUserPassion();
public:
    explicit UserDialog(int id, QWidget *parent = nullptr);
    ~UserDialog();
private:
    Ui::UserDialog *ui;
private:
    void on_pb_passion_clicked();
    void on_pb_logout_clicked();
};

#endif // USERDIALOG_H
