#include "function.h"
#include "FileTool.h"
#include <QDateEdit>
#include <QTableWidget>
#include <QComboBox>

Linklist<FlightInfo> flightList;
Linklist<passengerInfo> my_tickets;
FileTool f;


/**
 * @brief 检查航班是否符合指定时间，并将不符合条件的航班从列表中删除
 * @param FlightList 航班信息链表
 */
void checkTime(Linklist<FlightInfo> &FlightList, int y, int m, int d) {
    for (int i = 0; i < FlightList.length; i++) {
        if (FlightList[i].getDepature().year == y && FlightList[i].getDepature().month == m &&
            FlightList[i].getDepature().day == d)
            continue;
        else
            FlightList.remove(i--);
    }
}

/**
 * @brief 检查航班是否符合指定起始地和目的地，并将不符合条件的航班从列表中删除
 * @param FlightList 航班信息链表
 */
void checkBAD(Linklist<FlightInfo> &FlightList, const string beginning, const string destination) {
    for (int i = 0; i < FlightList.length; i++) {
        if (FlightList[i].getBeginning() == beginning && FlightList[i].getDestination() == destination)
            continue;
        else
            FlightList.remove(i--);
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

void WriteInTicketAvailable(Ui::TicketManageSystem *ui) {
//    QWidget *widget = loadUiFile(UI_PATH);
    QTableWidget *ticketAvailable = ui->TicketsAvailable;
    ticketAvailable->setRowCount(0);
    for (int i = 0; i < flightList.length; i++) {
        FlightInfo tmp = flightList[i];
        string flightID = tmp.getFlightID();
        string start = tmp.getBeginning();
        string destination = tmp.getDestination();
        DateTime dateTime = tmp.getDepature();
        int year, month, day, hour, minute;
        dateTime.getDate(year, month, day, hour, minute);
        int firstStock = tmp.getStockRemained(FIRST);
        int secondStock = tmp.getStockRemained(SECOND);
        int thirdStock = tmp.getStockRemained(THIRD);


        QString str;
        int column = 0;
        ticketAvailable->insertRow(i);
        str = QString::fromStdString(flightID);
        QTableWidgetItem *item0 = new QTableWidgetItem(str);
        ticketAvailable->setItem(i, column++, item0);

        str = QString::fromStdString(start);
        QTableWidgetItem *item1 = new QTableWidgetItem(str);
        ticketAvailable->setItem(i, column++, item1);

        str = QString::fromStdString(destination);
        QTableWidgetItem *item2 = new QTableWidgetItem(str);
        ticketAvailable->setItem(i, column++, item2);

        string date = to_string(year) + "/" + to_string(month) + "/" + to_string(day) + " " + to_string(hour) + ":" +
                      to_string(minute);
        str = QString::fromStdString(date);
        QTableWidgetItem *item3 = new QTableWidgetItem(str);
        ticketAvailable->setItem(i, column++, item3);

        str = QString::fromStdString(to_string(firstStock));
        QTableWidgetItem *item4 = new QTableWidgetItem(str);
        ticketAvailable->setItem(i, column++, item4);

        str = QString::fromStdString(to_string(secondStock));
        QTableWidgetItem *item5 = new QTableWidgetItem(str);
        ticketAvailable->setItem(i, column++, item5);

        str = QString::fromStdString(to_string(thirdStock));
        QTableWidgetItem *item6 = new QTableWidgetItem(str);
        ticketAvailable->setItem(i, column++, item6);
    }
}

void Inquire(Ui::TicketManageSystem *ui) {
//    QWidget *widget = loadUiFile(UI_PATH);
    QDateEdit *ConditionDate = ui->ConditionDate;

    QString str;
    QDate date = ConditionDate->date();
    QComboBox *start = ui->ConditionStart;
    QComboBox *destination = ui->ConditionDestination;
    int year = date.year();
    int month = date.month();
    int day = date.day();

    flightList = f.read_by_time(year, month, day);

    checkBAD(flightList, start->currentText().toStdString(),destination->currentText().toStdString());
    WriteInTicketAvailable(ui);
}

void WriteInMyTicket(Ui::TicketManageSystem *ui) {
    QTableWidget *MyTickets = ui->MyTickets;
    MyTickets->setRowCount(0);
    for (int i = 0; i < my_tickets.length; i++) {
        passengerInfo tmp = my_tickets[i];
        DateTime time;

        string flightID = tmp.getFlightInfo().getFlightID();

        time.year = tmp.getFlightInfo().getDepature().year;
        time.month = tmp.getFlightInfo().getDepature().month;
        time.day = tmp.getFlightInfo().getDepature().day;
        time.hour = tmp.getFlightInfo().getDepature().hour;
        time.minute = tmp.getFlightInfo().getDepature().minute;

        travelClass tc = tmp.my_class;

        QString str;
        int column = 0;
        MyTickets->insertRow(i);
        str = QString::fromStdString(flightID);
        QTableWidgetItem *item0 = new QTableWidgetItem(str);
        MyTickets->setItem(i,column++,item0);

        string date = to_string(time.year) + "/" + to_string(time.month) + "/" + to_string(time.day) + " " +
                      to_string(time.hour) + ":" +
                      to_string(time.minute);
        str = QString::fromStdString(date);
        QTableWidgetItem *item1 = new QTableWidgetItem(str);
        MyTickets->setItem(i,column++,item1);
        switch (tc) {
            case FIRST:
                str = QString::fromStdString("一等舱");
                break;
            case SECOND:
                str = QString::fromStdString("二等舱");
                break;
            case THIRD:
                str = QString::fromStdString("三等舱");
                break;
        }
        QTableWidgetItem *item2 = new QTableWidgetItem(str);
        MyTickets->setItem(i,column++,item2);
    }
}

bool book(string name, string id, travelClass your_class) {
    for (int i = 0; i < my_tickets.length; i++) {
        if (my_tickets.getNode(i).getFlightInfo().getFlightID() == id) {
            return false;
        }
    }
    if (your_class == FIRST) {
        f.change(f.find_flight_by_Id(flightList, id), 0);
        passengerInfo a(name, f.find_flight_by_Id(flightList, id), FIRST, true);
        my_tickets.addToTail(a);
    } else if (your_class == SECOND) {
        f.change(f.find_flight_by_Id(flightList, id), 1);
        passengerInfo a(name, f.find_flight_by_Id(flightList, id), SECOND, true);
        my_tickets.addToTail(a);
    } else if (your_class == THIRD) {
        f.change(f.find_flight_by_Id(flightList, id), 2);
        passengerInfo a(name, f.find_flight_by_Id(flightList, id), THIRD, true);
        my_tickets.addToTail(a);
    }
    return true;
}

bool cancel(string name, string id) {
    for (int i = 0; i < my_tickets.length; i++) {
        if (my_tickets.getNode(i).getFlightInfo().getFlightID() == id) {
            f.change(my_tickets.getNode(i).getFlightInfo(), my_tickets.getNode(i).my_class, -1);
            my_tickets.remove(i);
            return true;
        }
    }
    return false;
}

bool change(string name, string now_id, string target_id, travelClass target_class) {
    if (cancel(name, now_id))
        return book(name, target_id, target_class);
    return false;
}

void BookTicket(Ui::TicketManageSystem *ui) {
    QComboBox *Book = ui->BookFlightIDComBox;
    QString flightID = Book->currentText();

    QComboBox *Class = ui->BookClasscomboBox;
    QString TravelClass = Class->currentText();

    string tc = TravelClass.toStdString();
    travelClass targetClass;
    if (tc == "一等舱") targetClass = FIRST;
    else if (tc == "二等舱") targetClass = SECOND;
    else targetClass = THIRD;
    if (book("root", flightID.toStdString(), targetClass))
    {
        Inquire(ui);
        flightListUpdateUI(ui);
        WriteInMyTicket(ui);
        return;
    }

    qDebug() << "Error in book ticket";
}

void ChangeTicket(Ui::TicketManageSystem *ui) {
    QComboBox *Original = ui->BookedFlightID;
    QComboBox *Target = ui->BookFlightIDComBox_2;
    QComboBox *TargetClass = ui->TargetClassComboBox;
    QString originalFlightID = Original->currentText();
    QString targetFlightID = Target->currentText();
    QString targetFlightClass = TargetClass->currentText();

    string tc = targetFlightClass.toStdString();
    travelClass targetClass;
    if (tc == "一等舱") targetClass = FIRST;
    else if (tc == "二等舱") targetClass = SECOND;
    else targetClass = THIRD;
    if (change("root", originalFlightID.toStdString(), targetFlightID.toStdString(), targetClass))
    {
        Inquire(ui);
        flightListUpdateUI(ui);
        WriteInMyTicket(ui);
        return ;
    }
    qDebug() << "Error in change Ticket for the above reason";
}

void CancelTicket(Ui::TicketManageSystem *ui) {
    QComboBox *Cancel = ui->CancelMyTicketsComBox;
    QString cancelFlightID = Cancel->currentText();
    if (cancel("root", cancelFlightID.toStdString()))
    {
        Inquire(ui);
        flightListUpdateUI(ui);
        WriteInMyTicket(ui);
        return ;
    }
    qDebug() << "Error in canceling ticket";
}

void flightListUpdateUI(Ui::TicketManageSystem *ui) {
    QComboBox *Book = ui->BookFlightIDComBox;
    QComboBox *Original = ui->BookedFlightID;
    QComboBox *Target = ui->BookFlightIDComBox_2;
    QComboBox *Cancel = ui->CancelMyTicketsComBox;
    QComboBox *TargetClass = ui->TargetClassComboBox;

    QStringList flightIDList, MyFlightIDList;
    for (int i = 0; i < flightList.length; ++i) {
        QString flightID = QString::fromStdString(flightList[i].getFlightID());
        flightIDList.append(flightID);
    }
    for(int i=0;i<my_tickets.length;++i)
    {
        QString flightID = QString::fromStdString(my_tickets[i].getFlightInfo().getFlightID());
        MyFlightIDList.append(flightID);
    }

    Book->clear();
    Book->addItems(flightIDList);

    Original->clear();
    Original->addItems(MyFlightIDList);

    Cancel->clear();
    Cancel->addItems(MyFlightIDList);

    Target->clear();
    Target->addItems(flightIDList);
    if(flightIDList.length()!=0 and MyFlightIDList.length()!=0)
    {
        TargetClass->clear();
        TargetClass->addItems(QStringList() << "一等舱" << "二等舱" << "三等舱");
    }

}

