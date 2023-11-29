/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login {
public:
    QWidget *centralwidget;
    QToolButton *login;
    QLineEdit *user_name;
    QTextBrowser *user_name_hint;
    QTextBrowser *passwor_hint;
    QLineEdit *password;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login) {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(800, 600);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName("centralwidget");
        login = new QToolButton(centralwidget);
        login->setObjectName("login");
        login->setGeometry(QRect(320, 310, 121, 41));
        user_name = new QLineEdit(centralwidget);
        user_name->setObjectName("user_name");
        user_name->setGeometry(QRect(310, 200, 161, 21));
        user_name_hint = new QTextBrowser(centralwidget);
        user_name_hint->setObjectName("user_name_hint");
        user_name_hint->setGeometry(QRect(240, 200, 51, 21));
        passwor_hint = new QTextBrowser(centralwidget);
        passwor_hint->setObjectName("passwor_hint");
        passwor_hint->setGeometry(QRect(240, 250, 41, 21));
        password = new QLineEdit(centralwidget);
        password->setObjectName("password");
        password->setGeometry(QRect(310, 250, 161, 21));
        Login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Login);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Login->setMenuBar(menubar);
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName("statusbar");
        Login->setStatusBar(statusbar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow) {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        login->setText(QCoreApplication::translate("MainWindow", "\347\231\273\345\275\225", nullptr));
        user_name_hint->setHtml(QCoreApplication::translate("MainWindow",
                                                            "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                                                            "<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
                                                            "p, li { white-space: pre-wrap; }\n"
                                                            "hr { height: 1px; border-width: 0; }\n"
                                                            "li.unchecked::marker { content: \"\\2610\"; }\n"
                                                            "li.checked::marker { content: \"\\2612\"; }\n"
                                                            "</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
                                                            "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\224\250\346\210\267\345\220\215</p></body></html>",
                                                            nullptr));
        passwor_hint->setHtml(QCoreApplication::translate("MainWindow",
                                                          "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
                                                          "<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
                                                          "p, li { white-space: pre-wrap; }\n"
                                                          "hr { height: 1px; border-width: 0; }\n"
                                                          "li.unchecked::marker { content: \"\\2610\"; }\n"
                                                          "li.checked::marker { content: \"\\2612\"; }\n"
                                                          "</style></head><body style=\" font-family:'.AppleSystemUIFont'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
                                                          "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\257\206\347\240\201</p></body></html>",
                                                          nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login : public Ui_Login {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOW_H
