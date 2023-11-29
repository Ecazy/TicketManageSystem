//
// Created by 杨千靖 on 2023/11/29.
//
//#include "ui_ticketmanagesystem.h"
#include <QObject>
#include <QMessageBox>
#include "ui_login.h"
#include "Login.h"

Login::Login(QWidget *parent) : QMainWindow(parent), ui(new Ui::Login) {
    ui->setupUi(this);
}

Login::~Login() {
    delete ui;
}

void Login::on_login_clicked() {
    QLineEdit *lineEdit1 = ui->user_name; // 获取 QLineEdit 对象
    QString username = lineEdit1->text(); // 获取文本内容
    QLineEdit *lineEdit2 = ui->password; // 获取 QLineEdit 对象
    QString password = lineEdit2->text(); // 获取文本内容

    string name = username.toStdString();
    string code = password.toStdString();

    if (name == "root" && code == "12345")
            emit loginSuccessful();
}