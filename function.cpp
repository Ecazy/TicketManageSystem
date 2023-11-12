#include "function.h"

/**
 * @brief 查询指定时间的航班
 * @param y 年
 * @param m 月
 * @param d 日
 * @return 所有符合条件的航班信息的链表
 */
Linklist<flightInfo> findByTime(int y, int m, int d) {
    Linklist<flightInfo> flightList;
    for (int i = 0; i < flightInforList.length; i++) {
        if (flightInforList[i].getDepatureDay().year == y && flightInforList[i].getDepatureDay().month == m &&
            flightInforList[i].getDepatureDay().date == d) {
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
Linklist<flightInfo> findByBAD(const string beginning, const string destination) {
    Linklist<flightInfo> flightList;
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
void checkTime(Linklist<flightInfo> &flightList, int y, int m, int d) {
    for (int i = 0; i < flightList.length; i++) {
        if (flightList[i].getDepatureDay().year == y && flightList[i].getDepatureDay().month == m &&
            flightList[i].getDepatureDay().date == d)
            continue;
        else
            flightList.remove(i--);
    }
}

/**
 * @brief 检查航班是否符合指定起始地和目的地，并将不符合条件的航班从列表中删除
 * @param flightList 航班信息链表  
 */
void checkBAD(Linklist<flightInfo> &flightList, const string beginning, const string destination) {
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
void removeNoTicketFlight(Linklist<flightInfo> &flightList) {
    for (int i = 0; i < flightList.length; i++) {
        if (flightList[i].getStockRemained(FIRST) == 0 && flightList[i].getStockRemained(SECOND) == 0 &&
            flightList[i].getStockRemained(THIRD) == 0)
            flightList.remove(i--);
    }
}

void sortByStartTime(Linklist<flightInfo> &flightList) {
    flightList.sort([](flightInfo a, flightInfo b) {
        return a.getDepatureDay().hour * 60 + a.getDepatureDay().minute <
               b.getDepatureDay().hour * 60 + b.getDepatureDay().minute;
    });
}

void sortByPrice(Linklist<flightInfo> &flightList) {
    flightList.sort([](flightInfo a, flightInfo b) { return a.getFares() < b.getFares(); });
}

void sortByArrivalTime(Linklist<flightInfo> &flightList) {
    flightList.sort([](flightInfo a, flightInfo b) {
        return a.getDepatureDay().hour * 60 + a.getDepatureDay().minute + a.getDepatureDay().hour * 60 +
               a.getDepatureDay().minute <
               b.getDepatureDay().hour * 60 + b.getDepatureDay().minute + b.getDepatureDay().hour * 60 +
               b.getDepatureDay().minute;
    });
}

bool buyTicket(flightInfo &flight, passengerInfo &passenger) {
    return passenger.bookTicket(flight);
}

bool cancelTicket(flightInfo &flight, passengerInfo &passenger) {
    return passenger.cancelTicket(flight);
}

bool changeTicket(flightInfo &flight, passengerInfo &passenger, travelClass _travelclass) {
    return passenger.changeTicket(flight, _travelclass);
}
