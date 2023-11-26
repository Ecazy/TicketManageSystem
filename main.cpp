#include "ticketmanagesystem.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    TicketManageSystem w;
    w.show();
    return a.exec();
}

