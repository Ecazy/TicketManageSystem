#include "function.h"
#include "FileTool.h"
#include <QDateEdit>
#include <QTableWidget>
#include <QComboBox>

Linklist<FlightInfo> flightList;
Linklist<FlightInfo> changeFlightList;
Linklist<passengerInfo> my_tickets;
FileTool f;


/**
 * @brief  格式化时间
 * @param  DateTime &time 时间
 * @return string 格式化后的时间
 */
string formatTime(const DateTime &time)
{
    string str;
    str = to_string(time.year) + "/" + to_string(time.month) + "/" + to_string(time.day);
    if(time.hour<10)
        str+=" 0"+to_string(time.hour);
    else
        str+=" "+to_string(time.hour);

    if(time.minute<10)
        str+=":0"+to_string(time.minute);
    else
        str+=":"+to_string(time.minute);

    return str;
}

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
        int firstStock = tmp.getStockRemained(FIRST);
        int secondStock = tmp.getStockRemained(SECOND);
        int thirdStock = tmp.getStockRemained(THIRD);

        int firstPrice = tmp.getFares(FIRST);
        int secondPrice = tmp.getFares(SECOND);
        int thirdPrice = tmp.getFares(THIRD);


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

        string date = formatTime(dateTime);
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

        str = QString::fromStdString(to_string(firstPrice));
        QTableWidgetItem *item7 = new QTableWidgetItem(str);
        ticketAvailable->setItem(i,column++,item7);

        str = QString::fromStdString(to_string(secondPrice));
        QTableWidgetItem *item8 = new QTableWidgetItem(str);
        ticketAvailable->setItem(i,column++,item8);

        str = QString::fromStdString(to_string(thirdPrice));
        QTableWidgetItem *item9 = new QTableWidgetItem(str);
        ticketAvailable->setItem(i,column++,item9);

    }
}

void WriteInTicketsTable(Ui::Admin *ui) {
    QTableWidget *ticketAvailable = ui->TicketsTable;
    ticketAvailable->setRowCount(0);
    for (int i = 0; i < flightList.length; i++) {
        FlightInfo tmp = flightList[i];
        string flightID = tmp.getFlightID();
        string start = tmp.getBeginning();
        string destination = tmp.getDestination();
        DateTime dateTime = tmp.getDepature();
        int firstStock = tmp.getStockRemained(FIRST);
        int secondStock = tmp.getStockRemained(SECOND);
        int thirdStock = tmp.getStockRemained(THIRD);

        int firstPrice = tmp.getFares(FIRST);
        int secondPrice = tmp.getFares(SECOND);
        int thirdPrice = tmp.getFares(THIRD);


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

        string date = formatTime(dateTime);
        str = QString::fromStdString(date);
        QTableWidgetItem *item3 = new QTableWidgetItem(str);
        ticketAvailable->setItem(i, column++, item3);

        str = QString::fromStdString(to_string(firstPrice));
        QTableWidgetItem *item7 = new QTableWidgetItem(str);
        ticketAvailable->setItem(i, column++, item7);

        str = QString::fromStdString(to_string(secondPrice));
        QTableWidgetItem *item8 = new QTableWidgetItem(str);
        ticketAvailable->setItem(i, column++, item8);

        str = QString::fromStdString(to_string(thirdPrice));
        QTableWidgetItem *item9 = new QTableWidgetItem(str);
        ticketAvailable->setItem(i, column++, item9);


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

FlightInfo ReadFromAdd(Ui::Admin *ui) {
    QTableWidget *ticketInfo = ui->TicketsInfoTable;
    double firstPrice = ticketInfo->item(0,0)->text().toDouble(),
        secondPrice = ticketInfo->item(0,1)->text().toDouble(),
        thirdPrice = ticketInfo->item(0,2)->text().toDouble();

    int firstStock = ticketInfo->item(0,3)->text().toInt(),
        secondStock = ticketInfo->item(0,4)->text().toInt(),
        thirdStock = ticketInfo->item(0,5)->text().toInt();

    string flightID = ui->AddFlightID->text().toStdString();
    string start = ui->AddStart->currentText().toStdString(),
           end = ui->AddEnd->currentText().toStdString();
    QDate date = ui->AddTimeSet->date();
    QTime time = ui->AddTime->time();
    int year=date.year(),month=date.month(),day=date.day();
    int hour=time.hour(),minute=time.minute();

    DateTime dateTime;
    dateTime.setDateTime(year,month,day,hour,minute);

    FlightInfo flight(start,end,flightID,dateTime,350,firstPrice,secondPrice,thirdPrice);
    flight.setStockRemained(FIRST,firstStock);
    flight.setStockRemained(SECOND,secondStock);
    flight.setStockRemained(THIRD,thirdStock);

    return flight;
}

FlightInfo ReadFromChange(Ui::Admin *ui)
{
    QTableWidget *ticketInfo = ui->ChangeTicketsTable;
    string flightID =ticketInfo->item(0,0)->text().toStdString(),
           start = ticketInfo->item(0,1)->text().toStdString(),
           end = ticketInfo->item(0,2)->text().toStdString();
    QDateTimeEdit *time = ui->ChangeTimeSet;
    DateTime dateTime;
    dateTime.setDateTime(time->dateTime().date().year(),time->dateTime().date().month(),time->dateTime().date().day(),time->dateTime().time().hour(),time->dateTime().time().minute());
    double firstPrice = ticketInfo->item(0,4)->text().toDouble(),
        secondPrice = ticketInfo->item(0,5)->text().toDouble(),
        thirdPrice = ticketInfo->item(0,6)->text().toDouble();

    int firstStock = ticketInfo->item(0,7)->text().toInt(),
        secondStock = ticketInfo->item(0,8)->text().toInt(),
        thirdStock = ticketInfo->item(0,9)->text().toInt();

    FlightInfo tmp(start,end,flightID,dateTime,350,firstPrice,secondPrice,thirdPrice);
    tmp.setStockRemained(FIRST,firstStock);
    tmp.setStockRemained(SECOND,secondStock);
    tmp.setStockRemained(THIRD,thirdStock);

    return tmp;
}

void WriteIn(Ui::Admin *ui,bool flag)
{
    if(flag)
    {
        QTableWidget *ticketAvailable = ui->DeleteTicketsTable;
        ticketAvailable->setRowCount(0);
        for (int i = 0; i < flightList.length; i++) {
            FlightInfo tmp = flightList[i];
            string flightID = tmp.getFlightID();
            string start = tmp.getBeginning();
            string destination = tmp.getDestination();
            DateTime dateTime = tmp.getDepature();
            int firstStock = tmp.getStockRemained(FIRST);
            int secondStock = tmp.getStockRemained(SECOND);
            int thirdStock = tmp.getStockRemained(THIRD);

            int firstPrice = tmp.getFares(FIRST);
            int secondPrice = tmp.getFares(SECOND);
            int thirdPrice = tmp.getFares(THIRD);


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

            string date = formatTime(dateTime);
            str = QString::fromStdString(date);
            QTableWidgetItem *item3 = new QTableWidgetItem(str);
            ticketAvailable->setItem(i, column++, item3);

            str = QString::fromStdString(to_string(firstPrice));
            QTableWidgetItem *item7 = new QTableWidgetItem(str);
            ticketAvailable->setItem(i, column++, item7);

            str = QString::fromStdString(to_string(secondPrice));
            QTableWidgetItem *item8 = new QTableWidgetItem(str);
            ticketAvailable->setItem(i, column++, item8);

            str = QString::fromStdString(to_string(thirdPrice));
            QTableWidgetItem *item9 = new QTableWidgetItem(str);
            ticketAvailable->setItem(i, column++, item9);


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
    else
    {
        QTableWidget *ticketAvailable = ui->ChangeTicketsTable;
        ticketAvailable->setRowCount(0);
        for (int i = 0; i < flightList.length; i++) {
            FlightInfo tmp = flightList[i];
            string flightID = tmp.getFlightID();
            string start = tmp.getBeginning();
            string destination = tmp.getDestination();
            DateTime dateTime = tmp.getDepature();
            int firstStock = tmp.getStockRemained(FIRST);
            int secondStock = tmp.getStockRemained(SECOND);
            int thirdStock = tmp.getStockRemained(THIRD);

            int firstPrice = tmp.getFares(FIRST);
            int secondPrice = tmp.getFares(SECOND);
            int thirdPrice = tmp.getFares(THIRD);


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

            string date = formatTime(dateTime);
            str = QString::fromStdString(date);
            QTableWidgetItem *item3 = new QTableWidgetItem(str);
            ticketAvailable->setItem(i, column++, item3);

            str = QString::fromStdString(to_string(firstPrice));
            QTableWidgetItem *item7 = new QTableWidgetItem(str);
            ticketAvailable->setItem(i, column++, item7);

            str = QString::fromStdString(to_string(secondPrice));
            QTableWidgetItem *item8 = new QTableWidgetItem(str);
            ticketAvailable->setItem(i, column++, item8);

            str = QString::fromStdString(to_string(thirdPrice));
            QTableWidgetItem *item9 = new QTableWidgetItem(str);
            ticketAvailable->setItem(i, column++, item9);


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
}

void WriteInChange(Ui::TicketManageSystem *ui)
{
    QTableWidget *ticketAvailable = ui->ChangeTicketsAvailable;
    ticketAvailable->setRowCount(0);
    for (int i = 0; i < changeFlightList.length; i++) {
        FlightInfo tmp = changeFlightList[i];
        string flightID = tmp.getFlightID();
        string start = tmp.getBeginning();
        string destination = tmp.getDestination();
        DateTime dateTime = tmp.getDepature();
        int firstStock = tmp.getStockRemained(FIRST);
        int secondStock = tmp.getStockRemained(SECOND);
        int thirdStock = tmp.getStockRemained(THIRD);

        int firstPrice = tmp.getFares(FIRST);
        int secondPrice = tmp.getFares(SECOND);
        int thirdPrice = tmp.getFares(THIRD);


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

        string date = formatTime(dateTime);
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

        str = QString::fromStdString(to_string(firstPrice));
        QTableWidgetItem *item7 = new QTableWidgetItem(str);
        ticketAvailable->setItem(i,column++,item7);

        str = QString::fromStdString(to_string(secondPrice));
        QTableWidgetItem *item8 = new QTableWidgetItem(str);
        ticketAvailable->setItem(i,column++,item8);

        str = QString::fromStdString(to_string(thirdPrice));
        QTableWidgetItem *item9 = new QTableWidgetItem(str);
        ticketAvailable->setItem(i,column++,item9);

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

void Inquire(Ui::Admin *ui,const INQUIRE_TYPE it)
{
    QDateEdit *dateFilter;
    QDate date;
    QString str;
    QComboBox *start;
    QComboBox *destination;
    int year;
    int month;
    int day;

    switch (it) {
        case PLACE:
            flightList.clear();
            start = ui->StartFilterByPlace;
            destination = ui->EndFilterByPlace;
            if(start->currentText().toStdString() == destination->currentText().toStdString())
                break;
            flightList = f.read_by_path(start->currentText().toStdString(), destination->currentText().toStdString());
            break;
        case TIME:
            flightList.clear();
            dateFilter = ui->DateFilterByTime;
            date = dateFilter->date();
            year= date.year(),month=date.month(),day= date.day();
            flightList = f.read_by_time(year, month, day);
            break;
        case TIME_PLACE:
            flightList.clear();
            dateFilter = ui->DateFilter;
            date = dateFilter->date();
            year= date.year(),month=date.month(),day= date.day();
            start = ui->StartFilter;
            destination = ui->EndFilter;
            flightList = f.read_by_time(year, month, day);
            checkBAD(flightList, start->currentText().toStdString(),destination->currentText().toStdString());
            break;
    }
    WriteInTicketsTable(ui);
}

ERROR_TYPE Inquire(Ui::Admin *ui,bool flag)
{
    if(flag)
    {
        QLineEdit *deleteFlightID = ui->DeleteFlightID;
        string flightID = deleteFlightID->text().toStdString();
        if(flightID=="")    return INVALID_INPUT;
        flightList=f.read_by_id(flightID);
    }
    else
    {
        QLineEdit *changeFlightID = ui->ChangeFlightID;
        string flightID = changeFlightID->text().toStdString();
        if(flightID=="")    return INVALID_INPUT;
        flightList=f.read_by_id(flightID);
        DateTime dateTime = flightList[0].getDepature();
        QDate date;QTime time;
        date.setDate(dateTime.year,dateTime.month,dateTime.day);
        time.setHMS(dateTime.hour,dateTime.minute,0);
        ui->ChangeTimeSet->setDate(date);
        ui->ChangeTimeSet->setTime(time);
    }
    if(flightList.length==0)
        return INQUIRE_FAILURE_BLANKET;
    WriteIn(ui,flag);
    return SUCCESS;
}

void ChangeInquire(Ui::TicketManageSystem *ui)
{
    QDateEdit *ConditionDate = ui->ChangeConditionDate;

    QString str;
    QDate date = ConditionDate->date();
    QComboBox *start = ui->ChangeConditionStart;
    QComboBox *destination = ui->ChangeConditionDestination;
    int year = date.year();
    int month = date.month();
    int day = date.day();

    changeFlightList = f.read_by_time(year, month, day);

    checkBAD(changeFlightList, start->currentText().toStdString(),destination->currentText().toStdString());
    WriteInChange(ui);
}

void WriteInMyTicket(Ui::TicketManageSystem *ui) {
    //Change Tab
        QTableWidget *MyTickets = ui->ChangeMyTickets;
        MyTickets->setRowCount(0);
        for (int i = 0; i < my_tickets.length; i++) {
            passengerInfo tmp = my_tickets[i];
            DateTime time;
            string start = tmp.getFlightInfo().getBeginning(), end = tmp.getFlightInfo().getDestination();
            string flightID = tmp.getFlightInfo().getFlightID();
            time = tmp.getFlightInfo().getDepature();

            travelClass tc = tmp.my_class;

            QString str;
            int column = 0;
            MyTickets->insertRow(i);
            str = QString::fromStdString(flightID);
            QTableWidgetItem *item0 = new QTableWidgetItem(str);
            MyTickets->setItem(i,column++,item0);

            str = QString::fromStdString(start);
            QTableWidgetItem *itemStart = new QTableWidgetItem(str);
            MyTickets->setItem(i,column++,itemStart);

            str = QString::fromStdString(end);
            QTableWidgetItem *itemEnd = new QTableWidgetItem(str);
            MyTickets->setItem(i,column++,itemEnd);

            string date = formatTime(time);
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

    //Cancel Tab
        MyTickets = ui->CancelMyTickets;
        MyTickets->setRowCount(0);
        for (int i = 0; i < my_tickets.length; i++) {
            passengerInfo tmp = my_tickets[i];
            DateTime time;
            string start = tmp.getFlightInfo().getBeginning(), end = tmp.getFlightInfo().getDestination();
            string flightID = tmp.getFlightInfo().getFlightID();
            time = tmp.getFlightInfo().getDepature();

            travelClass tc = tmp.my_class;

            QString str;
            int column = 0;
            MyTickets->insertRow(i);
            str = QString::fromStdString(flightID);
            QTableWidgetItem *item0 = new QTableWidgetItem(str);
            MyTickets->setItem(i,column++,item0);

            str = QString::fromStdString(start);
            QTableWidgetItem *itemStart = new QTableWidgetItem(str);
            MyTickets->setItem(i,column++,itemStart);

            str = QString::fromStdString(end);
            QTableWidgetItem *itemEnd = new QTableWidgetItem(str);
            MyTickets->setItem(i,column++,itemEnd);

            string date = formatTime(time);
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
        if(f.change(f.find_flight_by_Id(flightList, id), 0)) {
            passengerInfo a(name, f.find_flight_by_Id(flightList, id), FIRST, true);
            my_tickets.addToTail(a);
            return true;
        }
        return false;
    } else if (your_class == SECOND) {
        if(f.change(f.find_flight_by_Id(flightList, id), 1)) {
            passengerInfo a(name, f.find_flight_by_Id(flightList, id), SECOND, true);
            my_tickets.addToTail(a);
            return true;
        }
        return false;
    } else {
        if(f.change(f.find_flight_by_Id(flightList, id), 2)) {
            passengerInfo a(name, f.find_flight_by_Id(flightList, id), THIRD, true);
            my_tickets.addToTail(a);
            return true;
        }
        return false;
    }
}

bool cancel(string name, string id) {
    for (int i = 0; i < my_tickets.length; i++) {
        if (my_tickets.getNode(i).getFlightInfo().getFlightID() == id) {
            if(f.change(my_tickets.getNode(i).getFlightInfo(), my_tickets.getNode(i).my_class, -1))
            {
                my_tickets.remove(i);
                return true;
            }
        }
    }
    return false;
}

bool change(string name, string now_id, string target_id, travelClass target_class) {
    if (cancel(name, now_id))
        return book(name, target_id, target_class);
    return false;
}

ERROR_TYPE BookTicket(Ui::TicketManageSystem *ui,const string& name) {
    QComboBox *Book = ui->BookFlightIDComBox;
    QString flightID = Book->currentText();

    QComboBox *Class = ui->BookClasscomboBox;
    QString TravelClass = Class->currentText();

    string tc = TravelClass.toStdString();
    travelClass targetClass;
    if (tc == "一等舱") targetClass = FIRST;
    else if (tc == "二等舱") targetClass = SECOND;
    else targetClass = THIRD;
    if (book(name, flightID.toStdString(), targetClass)) {
        Inquire(ui);
        flightListUpdateUI(ui);
        WriteInMyTicket(ui);
        return SUCCESS;
    }
    qDebug() << "Error in book ticket";
    return BOOK_FAILURE;
}

ERROR_TYPE ChangeTicket(Ui::TicketManageSystem *ui,const string& name) {
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
//    if (change("root", originalFlightID.toStdString(), targetFlightID.toStdString(), targetClass))
//    {
//        Inquire(ui);
//        flightListUpdateUI(ui);
//        WriteInMyTicket(ui);
//        return ;
//    }
    if(book(name, targetFlightID.toStdString(), targetClass))
    {
        Inquire(ui);
        flightListUpdateUI(ui);
        WriteInMyTicket(ui);
        if (cancel(name, originalFlightID.toStdString()))
        {
            Inquire(ui);
            flightListUpdateUI(ui);
            WriteInMyTicket(ui);
            return SUCCESS;
        }
    }
    qDebug() << "Error in changing ticket";
    return CHANGE_FAILURE;
}

ERROR_TYPE CancelTicket(Ui::TicketManageSystem *ui,const string& name) {
    QComboBox *Cancel = ui->CancelMyTicketsComBox;
    QString cancelFlightID = Cancel->currentText();
    if (cancel(name, cancelFlightID.toStdString()))
    {
        Inquire(ui);
        flightListUpdateUI(ui);
        WriteInMyTicket(ui);
        return SUCCESS;
    }
    qDebug() << "Error in canceling ticket";
    return CANCEL_FAILURE;
}

void flightListUpdateUI(Ui::TicketManageSystem *ui) {
    QComboBox *Book = ui->BookFlightIDComBox;
    QComboBox *Original = ui->BookedFlightID;
    QComboBox *Target = ui->BookFlightIDComBox_2;
    QComboBox *Cancel = ui->CancelMyTicketsComBox;
    QComboBox *TargetClass = ui->TargetClassComboBox;

    QStringList flightIDList, MyFlightIDList,ChangeList;
    for (int i = 0; i < flightList.length; ++i) {
        QString flightID = QString::fromStdString(flightList[i].getFlightID());
        flightIDList.append(flightID);
    }
    for(int i=0;i<my_tickets.length;++i)
    {
        QString flightID = QString::fromStdString(my_tickets[i].getFlightInfo().getFlightID());
        MyFlightIDList.append(flightID);
    }
    for(int i=0;i<changeFlightList.length;++i)
    {
        QString flightID = QString::fromStdString(changeFlightList[i].getFlightID());
        ChangeList.append(flightID);
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

ERROR_TYPE Add(Ui::Admin *ui)
{
    if(ui->TicketsInfoTable->item(0,0)== nullptr or ui->TicketsInfoTable->item(0,0)->text().isEmpty())    return INVALID_INPUT;
    FlightInfo tmp = ReadFromAdd(ui);
    f.add(tmp);
    ui->AddTimeSet->setTime(QTime::currentTime());
    ui->AddTime->setTime(QTime::currentTime());
    ui->AddFlightID->clear();
    ui->AddStart->setCurrentIndex(0);
    ui->AddEnd->setCurrentIndex(0);
    return SUCCESS;
}

ERROR_TYPE Delete(Ui::Admin *ui)
{
    string flightID = ui->DeleteFlightID->text().toStdString();
    if(f.remove(flightID)) {
        flightList.clear();
        Inquire(ui,true);
        ui->DeleteFlightID->clear();
        return SUCCESS;
    }
    qDebug()<<"Delete Fail";
    return DELETE_FAILURE;
}

ERROR_TYPE Change(Ui::Admin *ui)
{
    string flightID = ui->ChangeFlightID->text().toStdString();
    if(flightID=="" or ui->ChangeTicketsTable->rowCount()==0)    return CHANGE_FAILURE;
    FlightInfo tmp = ReadFromChange(ui);
    if(f.change_by_id(tmp,flightID)) {
        flightList.clear();
        Inquire(ui,false);
        ui->ChangeTimeSet->setTime(QTime::currentTime());
        ui->ChangeFlightID->clear();
        return SUCCESS;;
    }
    qDebug()<<"Change Fail";
    return CHANGE_FAILURE;
}

