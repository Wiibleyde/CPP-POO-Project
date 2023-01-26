/********************************************************************************
** Form generated from reading UI file 'userdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDIALOG_H
#define UI_USERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_UserDialog
{
public:
    QLabel *status;
    QLineEdit *le_passion;
    QPushButton *pb_passion;
    QTableView *tv_passion;

    void setupUi(QDialog *UserDialog)
    {
        if (UserDialog->objectName().isEmpty())
            UserDialog->setObjectName("UserDialog");
        UserDialog->resize(631, 312);
        status = new QLabel(UserDialog);
        status->setObjectName("status");
        status->setEnabled(true);
        status->setGeometry(QRect(10, 10, 611, 41));
        le_passion = new QLineEdit(UserDialog);
        le_passion->setObjectName("le_passion");
        le_passion->setGeometry(QRect(260, 70, 241, 25));
        pb_passion = new QPushButton(UserDialog);
        pb_passion->setObjectName("pb_passion");
        pb_passion->setGeometry(QRect(120, 70, 131, 25));
        pb_passion->setFlat(false);
        tv_passion = new QTableView(UserDialog);
        tv_passion->setObjectName("tv_passion");
        tv_passion->setGeometry(QRect(10, 100, 611, 201));

        retranslateUi(UserDialog);

        QMetaObject::connectSlotsByName(UserDialog);
    } // setupUi

    void retranslateUi(QDialog *UserDialog)
    {
        UserDialog->setWindowTitle(QCoreApplication::translate("UserDialog", "Dialog", nullptr));
        status->setText(QString());
        pb_passion->setText(QCoreApplication::translate("UserDialog", "Ajouter une passion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserDialog: public Ui_UserDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDIALOG_H
