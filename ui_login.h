/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralwidget;
    QToolButton *login;
    QLineEdit *user_name;
    QLineEdit *password;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(365, 273);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName("centralwidget");
        login = new QToolButton(centralwidget);
        login->setObjectName("login");
        login->setGeometry(QRect(120, 210, 121, 41));
        user_name = new QLineEdit(centralwidget);
        user_name->setObjectName("user_name");
        user_name->setGeometry(QRect(110, 100, 161, 21));
        password = new QLineEdit(centralwidget);
        password->setObjectName("password");
        password->setGeometry(QRect(110, 150, 161, 21));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 100, 54, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 150, 54, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 40, 54, 16));
        Login->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName("statusbar");
        Login->setStatusBar(statusbar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "MainWindow", nullptr));
        login->setText(QCoreApplication::translate("Login", "\347\231\273\345\275\225", nullptr));
        label->setText(QCoreApplication::translate("Login", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("Login", "\345\257\206\347\240\201", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
