#include "function.h"
#include <QDateEdit>
#include <QTableWidget>
#include <QComboBox>

const string UI_PATH = "./ticketmanagesystem.ui";

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
void removeNoTicketFlight(Linklist<FlightInfo> &flightList) {
    for (int i = 0; i < flightList.length; i++) {
        if (flightList[i].getStockRemained(FIRST) == 0 && flightList[i].getStockRemained(SECOND) == 0 &&
            flightList[i].getStockRemained(THIRD) == 0)
            flightList.remove(i--);
    }
}

void sortByStartTime(Linklist<FlightInfo> &flightList) {
    flightList.sort([](FlightInfo a, FlightInfo b) {
        return a.getDepature().hour * 60 + a.getDepature().minute <
               b.getDepature().hour * 60 + b.getDepature().minute;
    });
}

void sortByPrice(Linklist<FlightInfo> &flightList) {
flightList.sort([](FlightInfo a, FlightInfo b) { return a.getFares(THIRD) < b.getFares(THIRD); });
}

void sortByArrivalTime(Linklist<FlightInfo> &flightList) {
    flightList.sort([](FlightInfo a, FlightInfo b) {
        return a.getDepature().hour * 60 + a.getDepature().minute + a.getDepature().hour * 60 +
               a.getDepature().minute <
               b.getDepature().hour * 60 + b.getDepature().minute + b.getDepature().hour * 60 +
               b.getDepature().minute;
    });
}

//以下为直接与界面交互的函数

//航班号，起点，终点，航班时间，一、二、三等舱余票
void WriteInTicketAvailable(Linklist<FlightInfo>&FlightList)
{
    QWidget* widget = loadUiFile(UI_PATH);
    QTableWidget* ticketAvailable = widget->findChild<QTableWidget*>("TicketsAvailable");
    for(int i=0;i<FlightList.length;i++)
    {
        FlightInfo tmp = FlightList[i];
        string flightID = tmp.getFlightID();
        string start = tmp.getBeginning();
        string destination = tmp.getDestination();
        DateTime dateTime = tmp.getDepature();
        int year,month,day;
        dateTime.getDate(year,month,day);
        int firstStock = tmp.getStockRemained(FIRST);
        int secondStock = tmp.getStockRemained(SECOND);
        int thirdStock = tmp.getStockRemained(THIRD);



        QString str;
        int column = 0;
        str=QString::fromStdString(flightID);
        ticketAvailable->item(i,column++)->setText(str);
        str = QString::fromStdString(start);
        ticketAvailable->item(i,column++)->setText(str);
        str = QString::fromStdString(destination);
        ticketAvailable->item(i,column++)->setText(str);
        string date = to_string(year)+"/"+ to_string(month)+"/"+ to_string(day);
        str = QString::fromStdString(date);
        ticketAvailable->item(i,column++)->setText(str);
        str = QString::fromStdString(to_string(firstStock));
        ticketAvailable->item(i,column++)->setText(str);
        str = QString::fromStdString(to_string(secondStock));
        ticketAvailable->item(i,column++)->setText(str);
        str = QString::fromStdString(to_string(thirdStock));
        ticketAvailable->item(i,column++)->setText(str);
    }
}

void Inquire()
{
    QWidget* widget = loadUiFile(UI_PATH);
    QDateEdit* ConditionDate = widget->findChild<QDateEdit*>("ConditionDate");
    QString str;
    QDate date = ConditionDate->date();
    QComboBox* start = widget->findChild<QComboBox*>("ConditionStart");
    QComboBox* destination = widget->findChild<QComboBox*>("ConditionDestination");
    int year = date.year();
    int month = date.month();
    int day = date.day();
    Linklist<FlightInfo> FlightList = findByTime(year,month,day);
    checkBAD(FlightList,start->currentData().toString().toStdString(),destination->currentData().toString().toStdString());
    WriteInTicketAvailable(FlightList);
}
