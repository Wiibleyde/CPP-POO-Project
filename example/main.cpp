#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MainWindow::creerTable();
    MainWindow::insertAccount("Nathan", "nat", "nathan.txt");
    w.show();
    return a.exec();
}
