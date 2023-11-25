#include "function.h"
#include "FileTool.h"
#include <QDateEdit>
#include <QTableWidget>
#include <QComboBox>

//此处需使用绝对路径
const string UI_PATH = "./ticketmanagesystem.ui";
Linklist<FlightInfo> flightList;

FileTool f;

Linklist<passengerInfo> my_tickets;

/**
 * @brief 查询指定时间的航班
 * @param y 年
 * @param m 月
 * @param d 日
 * @return 所有符合条件的航班信息的链表
 */
Linklist<FlightInfo> findByTime(int y, int m, int d) {
    Linklist<FlightInfo> flightList;
    for (int i = 0; i < flightInforList.length; i++) {
        if (flightInforList[i].getDepature().year == y && flightInforList[i].getDepature().month == m &&
            flightInforList[i].getDepature().day == d) {
            flightList.addToTail(flightInforList[i]);
        }
    }
    return flightList;
}

/**
 * @brief 查询指定起始地和目的地的航班
 * @param beginning 起始地
 * @param destination 目的地
 * @return 所有符合条件的航班信息的链表 
 */
Linklist<FlightInfo> findByBAD(const string beginning, const string destination) {
    Linklist<FlightInfo> flightList;
    for (int i = 0; i < flightInforList.length; i++) {
        if (flightInforList[i].getBeginning() == beginning && flightInforList[i].getDestination() == destination) {
            flightList.addToTail(flightInforList[i]);
        }
    }
    return flightList;
}

/**
 * @brief 检查航班是否符合指定时间，并将不符合条件的航班从列表中删除
 * @param flightList 航班信息链表 
 */
void checkTime(Linklist<FlightInfo> &flightList, int y, int m, int d) {
    for (int i = 0; i < flightList.length; i++) {
        if (flightList[i].getDepature().year == y && flightList[i].getDepature().month == m &&
            flightList[i].getDepature().day == d)
            continue;
        else
            flightList.remove(i--);
    }
}

/**
 * @brief 检查航班是否符合指定起始地和目的地，并将不符合条件的航班从列表中删除
 * @param flightList 航班信息链表  
 */
void checkBAD(Linklist<FlightInfo> &flightList, const string beginning, const string destination) {
    for (int i = 0; i < flightList.length; i++) {
        if (flightList[i].getBeginning() == beginning && flightList[i].getDestination() == destination)
            continue;
        else
            flightList.remove(i--);
    }
}

/**
 * @brief 删除没有余票的航班
 * @param flightList 航班信息链表 
 */
void removeNoTicketFlight() {
    for (int i = 0; i < flightList.length; i++) {
        if (flightList[i].getStockRemained(FIRST) == 0 && flightList[i].getStockRemained(SECOND) == 0 &&
            flightList[i].getStockRemained(THIRD) == 0)
            flightList.remove(i--);
    }
}

void sortByStartTime() {
    flightList.sort([](FlightInfo a, FlightInfo b) {
        return a.getDepature().hour * 60 + a.getDepature().minute <
               b.getDepature().hour * 60 + b.getDepature().minute;
    });
}

void sortByPrice() {
    flightList.sort([](FlightInfo a, FlightInfo b) { return a.getFares(THIRD) < b.getFares(THIRD); });
}

//void sortByArrivalTime() {
//    flightList.sort([](FlightInfo a, FlightInfo b) {
//        return a.getDepature().hour * 60 + a.getDepature().minute + a.getDepature().hour * 60 +
//               a.getDepature().minute <
//               b.getDepature().hour * 60 + b.getDepature().minute + b.getDepature().hour * 60 +
//               b.getDepature().minute;
//    });
//}

//以下为直接与界面交互的函数

//航班号，起点，终点，航班时间，一、二、三等舱余票

void WriteInTicketAvailable() {
    QWidget *widget = loadUiFile(UI_PATH);
    QTableWidget *ticketAvailable = widget->findChild<QTableWidget *>("TicketsAvailable");
    ticketAvailable->setRowCount(0);
    for (int i = 0; i < flightList.length; i++) {
        FlightInfo tmp = flightList[i];
        string flightID = tmp.getFlightID();
        string start = tmp.getBeginning();
        string destination = tmp.getDestination();
        DateTime dateTime = tmp.getDepature();
        int year, month, day;
        dateTime.getDate(year, month, day);
        int firstStock = tmp.getStockRemained(FIRST);
        int secondStock = tmp.getStockRemained(SECOND);
        int thirdStock = tmp.getStockRemained(THIRD);


        QString str;
        int column = 0;
        str = QString::fromStdString(flightID);
        ticketAvailable->item(i, column++)->setText(str);
        str = QString::fromStdString(start);
        ticketAvailable->item(i, column++)->setText(str);
        str = QString::fromStdString(destination);
        ticketAvailable->item(i, column++)->setText(str);
        string date = to_string(year) + "/" + to_string(month) + "/" + to_string(day);
        str = QString::fromStdString(date);
        ticketAvailable->item(i, column++)->setText(str);
        str = QString::fromStdString(to_string(firstStock));
        ticketAvailable->item(i, column++)->setText(str);
        str = QString::fromStdString(to_string(secondStock));
        ticketAvailable->item(i, column++)->setText(str);
        str = QString::fromStdString(to_string(thirdStock));
        ticketAvailable->item(i, column++)->setText(str);
    }
}

void Inquire() {
    FileTool f;
    QWidget *widget = loadUiFile(UI_PATH);
    QDateEdit *ConditionDate = widget->findChild<QDateEdit *>("ConditionDate");

    QString str;
    QDate date = ConditionDate->date();
    QComboBox *start = widget->findChild<QComboBox *>("ConditionStart");
    QComboBox *destination = widget->findChild<QComboBox *>("ConditionDestination");
    int year = date.year();
    int month = date.month();
    int day = date.day();
    flightList = f.read_by_time(year, month, day);
    checkBAD(flightList, start->currentData().toString().toStdString(),
             destination->currentData().toString().toStdString());
    WriteInTicketAvailable();
}

void WriteInMyTicket(Linklist<passengerInfo> &my_ticket_list) {
    QWidget *widget = loadUiFile(UI_PATH);
    QTableWidget *MyTickets = widget->findChild<QTableWidget *>("MyTickets");
    MyTickets->setRowCount(0);
    for (int i = 0; i < my_ticket_list.length; i++) {
        passengerInfo tmp = my_ticket_list[i];
        DateTime time;

        string flightID = tmp.getInfo().getFlightID();

        time.year = tmp.getInfo().getDepature().year;
        time.month = tmp.getInfo().getDepature().month;
        time.day = tmp.getInfo().getDepature().day;
        time.hour = tmp.getInfo().getDepature().hour;
        time.minute = tmp.getInfo().getDepature().minute;

        travelClass a = tmp.my_class;

        QString str;
        int column = 0;
        str = QString::fromStdString(flightID);
        MyTickets->item(i, column++)->setText(str);
        string date = to_string(time.year) + "/" + to_string(time.month) + "/" + to_string(time.day);
        str = QString::fromStdString(date);
        MyTickets->item(i, column++)->setText(str);
        switch (a) {
            case FIRST:
                str = QString::fromStdString("first class");
                MyTickets->item(i, column++)->setText(str);
                break;
            case SECOND:
                str = QString::fromStdString("second class");
                MyTickets->item(i, column++)->setText(str);
                break;
            case THIRD:
                str = QString::fromStdString("third class");
                MyTickets->item(i, column++)->setText(str);
                break;
        }
    }
}

bool book( string name, string id, string your_class) {
    for (int i = 0; i < my_tickets.length; i++) {
        if (my_tickets.getNode(i).getInfo().getFlightID() == id) {
            return false;
        }
    }
    if (your_class == "FIRST") {
        f.change(f.find_flight_by_Id(flightList, id), 0);
        passengerInfo a(name, f.find_flight_by_Id(flightList, id), FIRST, true);
        my_tickets.addToTail(a);
    } else if (your_class == "SECOND") {
        f.change(f.find_flight_by_Id(flightList, id), 1);
        passengerInfo a(name, f.find_flight_by_Id(flightList, id), SECOND, true);
        my_tickets.addToTail(a);
    } else if (your_class == "THIRD") {
        f.change(f.find_flight_by_Id(flightList, id), 2);
        passengerInfo a(name, f.find_flight_by_Id(flightList, id), THIRD, true);
        my_tickets.addToTail(a);
    }
    return true;
}

bool cancel(string name, string id) {
    for (int i = 0; i < my_tickets.length; i++) {
        if (my_tickets.getNode(i).getInfo().getFlightID() == id) {
            my_tickets.remove(i);
            f.change(my_tickets.getNode(i).getInfo(), my_tickets.getNode(i).my_class, -1);
            return true;
        }
    }
    return false;
}

bool change(string name, string now_id, string target_id, string target_class) {
    if (cancel(name, now_id))
        return book(flightList, name, target_id, target_class);
}

void BookTicket() {
    QWidget *widget = loadUiFile(UI_PATH);

    QComboBox *Book = widget->findChild<QComboBox *>("BookFlightIDComBox");
    QString flightID = Book->currentText();

    QComboBox* Class = widget->findChild<QComboBox*>("BookClasscomboBox");
    QString travelClass = Class->currentText();


    if(book("root",flightID.toStdString(),travelClass.toStdString()))
        return;
    else
        //TODO 处理错误
        return ;

}

void ChangeTicket() {
    QWidget *widget = loadUiFile(UI_PATH);
    QComboBox* Original = widget->findChild<QComboBox*>("BookedFlightID");
    QComboBox* Target = widget->findChild<QComboBox*>("BookFlightIDComBox_2");
    QComboBox* TargetClass = widget->findChild<QComboBox*>("TargetClassComboBox");
    QString originalFlightID = Original->currentText();
    QString targetFlightID = Target->currentText();
    QString targetFlightClass = TargetClass->currentText();
    //TODO 调用Change
}

void CancelTicket() {
    QWidget *widget = loadUiFile(UI_PATH);
    QComboBox *Cancel = widget->findChild<QComboBox *>("CancelMyTicketsComBox");
    QString cancelFlightID = Cancel->currentText();
    //TODO 调用Cancel
}

void flightListUpdateUI() {
    QWidget *widget = loadUiFile(UI_PATH);
    QComboBox *Book = widget->findChild<QComboBox *>("BookFlightIDComBox");
    QComboBox *Original = widget->findChild<QComboBox *>("BookedFlightID");
    QComboBox *Target = widget->findChild<QComboBox *>("BookFlightIDComBox_2");
    QComboBox *Cancel = widget->findChild<QComboBox *>("CancelMyTicketsComBox");

    QStringList flightIDList, MyFlightIDList;
    for (int i = 0; i < flightList.length; ++i) {
        QString flightID = QString::fromStdString(flightList[i].getFlightID());
        flightIDList.append(flightID);
    }
    //TODO 获取用户已订票并转换为QStringList，再加入到MyFlightIDList中，转换为Original

    Book->addItems(flightIDList);
    Target->addItems(flightIDList);
    Cancel->addItems(flightIDList);
}

