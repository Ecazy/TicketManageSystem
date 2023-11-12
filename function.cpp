#include "function.h"

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
    flightList.sort([](FlightInfo a, FlightInfo b) { return a.getFares() < b.getFares(); });
}

void sortByArrivalTime(Linklist<FlightInfo> &flightList) {
    flightList.sort([](FlightInfo a, FlightInfo b) {
        return a.getDepature().hour * 60 + a.getDepature().minute + a.getDepature().hour * 60 +
               a.getDepature().minute <
                b.getDepature().hour * 60 + b.getDepature().minute + b.getDepature().hour * 60 +
                b.getDepature().minute;
    });
}

bool buyTicket(FlightInfo &flight, passengerInfo &passenger) {
    return passenger.bookTicket(flight);
}

bool cancelTicket(FlightInfo &flight, passengerInfo &passenger) {
    return passenger.cancelTicket(flight);
}

bool changeTicket(FlightInfo &flight, passengerInfo &passenger, travelClass _travelclass) {
    return passenger.changeTicket(flight, _travelclass);
}
