#include <QObject>
#include <QMessageBox>
#include "ui_login.h"
#include "Login.h"

Login::Login(QWidget *parent) : QMainWindow(parent), ui(new Ui::Login) {
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
}

Login::~Login() {
    delete ui;
}

void Login::on_login_clicked() {
    QLineEdit *lineEdit1 = ui->user_name; // 获取 QLineEdit 对象
    QString username = lineEdit1->text(); // 获取文本内容
    QLineEdit *lineEdit2 = ui->password; // 获取 QLineEdit 对象
    QString password = lineEdit2->text(); // 获取文本内容

    std::string name = username.toStdString();
    std::string code = password.toStdString();

    std::map<std::string, std::string>  usr = {{"admin", "123456"},{"root", "000000"}};

    if(usr.find(name)!=usr.end())
    {
        if(code==usr[name])
        {
            usrName =  name;
            QMessageBox::information(this, "登录成功", "登录成功");
            if(usrName=="admin")
                emit loginAdmin();
            else
                emit loginSuccessful();
            this->hide();
        }
        else
        {
            ui->password->setText("");
            QMessageBox::warning(this, "登录失败", "密码错误");
        }
    }
    else
    {
        ui->user_name->setText("");
        ui->password->setText("");
        QMessageBox::warning(this, "登录失败", "用户名不存在");
    }
}

void Login::show_login() {
    ui->user_name->setText("");
    ui->password->setText("");
    this->show();
    ui->user_name->setFocus();
}