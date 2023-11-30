#include "ticketmanagesystem.h"
#include "Login.h"
#include <QApplication>
//不能定同一个航班
//航班信息不能实时改变？
//write_in_my_ticket只有一个？
int main(int argc, char *argv[]) {
    FileTool f_test;
    DateTime for_test;
    for_test.setDateTime(0,0,0,0,0);
    FlightInfo test_flight("test","test","test",for_test,0,0,0,0);
    passengerInfo test1("root", test_flight, FIRST, true);
    passengerInfo test2("admin", test_flight, FIRST, true);
    passengerInfo test3("user", test_flight, FIRST, true);
    passengerInfo test4("test", test_flight, FIRST, true);
    f_test.add_user(test1);
    f_test.add_user(test2);
    f_test.add_user(test3);
    f_test.add_user(test4);
    QApplication a(argc, argv);
    Login s;
    s.show();
    TicketManageSystem w;
    QObject::connect(&s, &Login::loginSuccessful, [&w, &s]() {
        w.set_name(s.get_username);
        w.set_tickets();
        w.show();
    });

    return a.exec();
}