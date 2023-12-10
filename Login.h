#ifndef TICKETMANAGESYSTEM_LOGIN_H
#define TICKETMANAGESYSTEM_LOGIN_H

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow {
Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

    ~Login();

    std::string usrName;

    std::string getName()
    {return usrName;}

signals:

    void loginSuccessful(); // 声明一个登录成功的信号

    void loginAdmin();//声明一个登录管理员信号


private slots:

    void on_login_clicked();

    void show_login();

private:
    Ui::Login *ui;

};

#endif //TICKETMANAGESYSTEM_LOGIN_H
