#include "ticketmanagesystem.h"
#include "Login.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Login s;
    TicketManageSystem w;

    QObject::connect(&s, &Login::loginSuccessful, &w, &TicketManageSystem::show);

    s.show();
    return a.exec();
}

