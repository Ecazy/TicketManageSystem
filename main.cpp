#include "ticketmanagesystem.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
    std::ofstream ofs("data.bin", std::ios::binary);
    QApplication a(argc, argv);
    TicketManageSystem w;
    w.show();
    return a.exec();
}

