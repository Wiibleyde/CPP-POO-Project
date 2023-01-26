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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UserDialog
{
public:
    QListView *lv_passions;
    QLabel *status;
    QLineEdit *le_passion;
    QPushButton *pb_passion;

    void setupUi(QDialog *UserDialog)
    {
        if (UserDialog->objectName().isEmpty())
            UserDialog->setObjectName("UserDialog");
        UserDialog->resize(631, 311);
        lv_passions = new QListView(UserDialog);
        lv_passions->setObjectName("lv_passions");
        lv_passions->setGeometry(QRect(10, 110, 611, 192));
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
