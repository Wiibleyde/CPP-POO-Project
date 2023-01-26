#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    static QSqlDatabase db;
    static bool ouvreDb();
    static void fermeDb();
    static bool addUser(QString username, QString password);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:

    void on_pb_connect_clicked();
    void on_pb_create_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
