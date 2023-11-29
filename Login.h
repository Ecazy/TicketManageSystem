#ifndef TICKETMANAGESYSTEM_LOGIN_H
#define TICKETMANAGESYSTEM_LOGIN_H

#include <QMainWindow>
#include "function.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow {
Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

    ~Login();

signals:

    void loginSuccessful(); // 声明一个登录成功的信号


private slots:

    void on_login_clicked();

private:
    Ui::Login *ui;

};

#endif //TICKETMANAGESYSTEM_LOGIN_H
