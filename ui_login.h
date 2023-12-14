/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
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
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *user_name;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *password;
    QLabel *title;
    QToolButton *exit;
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
        login->setGeometry(QRect(70, 170, 91, 31));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(70, 100, 211, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        user_name = new QLineEdit(horizontalLayoutWidget);
        user_name->setObjectName("user_name");

        horizontalLayout->addWidget(user_name);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(70, 130, 211, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        password = new QLineEdit(horizontalLayoutWidget_2);
        password->setObjectName("password");

        horizontalLayout_2->addWidget(password);

        title = new QLabel(centralwidget);
        title->setObjectName("title");
        title->setGeometry(QRect(80, 30, 201, 51));
        title->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\255\227\351\205\267\345\240\202\347\237\263\345\210\273\344\275\223\";"));
        exit = new QToolButton(centralwidget);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(190, 170, 91, 31));
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
        label_2->setText(QCoreApplication::translate("Login", " \345\257\206\347\240\201  ", nullptr));
        title->setText(QCoreApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700;\">\346\234\272\347\245\250\350\256\242\347\245\250\347\263\273\347\273\237</span></p></body></html>", nullptr));
        exit->setText(QCoreApplication::translate("Login", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
