#include "ticketmanagesystem.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    iof.readFlightData("D:/Code/C++/Project/data.dat");
    QApplication a(argc, argv);
    TicketManageSystem w;
    w.show();
    return a.exec();
}
