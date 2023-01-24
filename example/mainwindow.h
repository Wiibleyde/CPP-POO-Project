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
    static bool creerTable();
    static bool insertAccount(QString login, QString password, QString textFile);
    static bool updateAccount(QString login, QString password, QString textFile);
    static QString getFileName(QString login);
    static QString createTextFile(QString login, QString password);
    static QString readTextFile(QString login, QString password);
    static QString modifyTextFile(QString login, QString password, QString text);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_connect_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
