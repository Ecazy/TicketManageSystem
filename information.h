#ifndef INFORMATION_H
#define INFORMATION_H

#include <string>
#include "datastructure.h"

using namespace std;

#define STOCK_TOTAL_FIRST 50
#define STOCK_TOTAL_SECOND 100
#define STOCK_TOTAL_THIRD 200

//飞机舱位等级的枚举
typedef enum {
    FIRST, SECOND, THIRD
} travelClass;

//星期的枚举
typedef enum {
    MON, TUE, WED, THU, FRI, SAT, SUN
} Week;

//时间类
class DateTime {
public:

    int year;
    int month;
    int date;
    Week week;
    int hour;
    int minute;

    void setDateTime(int _year, int _month, int _date, Week _week, int _hour, int _minute) {
        year = _year;
        month = _month;
        date = _date;
        week = _week;
        hour = _hour;
        minute = _minute;
    }
};

//乘客取消订单的结构，包括乘客姓名，舱位等级，航班号
typedef struct {
    string name;
    travelClass travelclass;
    string flightID;
} TicketInfo;

//航班余票的结构，包括头等舱，商务舱，经济舱
typedef struct {
    unsigned int first;
    unsigned int second;
    unsigned int third;
} StockRemained;

//由于两个类型的交叉引用，所以需要提前声明
class flightInfo;

class passengerInfo {
//私有成员，包括乘客姓名，舱位等级，是否已经订票
private:
    string name;
    travelClass travelclass;
    bool isBooked;
public:
    friend class flightInfo;

    passengerInfo(string name, travelClass travelclass, bool isBooked = false) :
            name(name), travelclass(travelclass), isBooked(isBooked) {}

    passengerInfo(passengerInfo &_passenger) {
        name = _passenger.name;
        travelclass = _passenger.travelclass;
    }

    passengerInfo(const passengerInfo &_passenger) {
        name = _passenger.name;
        travelclass = _passenger.travelclass;
    }

    ~passengerInfo() {};

    string getName();

    travelClass getTravelClass();

    bool getIsBooked();

    void setIsBooked(bool isBooked);

    bool operator<(passengerInfo &_passenger);

    bool operator==(passengerInfo &_passenger);

    bool bookTicket(flightInfo &_flight);

    bool cancelTicket(flightInfo &_flight);

    bool changeTicket(flightInfo &_flight, travelClass _travelclass);

    StockRemained getTicket(flightInfo &_flight);
};

class flightInfo {
//私有成员，包括起始地，目的地，航班号，飞机号，起飞时间，座位数，票价，余票
private:
    string beginning, destination;
    string flightID;
    string planeID;
    DateTime depatureDay;
    int occupLimit;
    double fares;
    StockRemained stockRemained;
    //void addPassenger(passengerInfo& _passenger);
    //void deletePassenger(passengerInfo& _passenger);
public:
    Linklist<passengerInfo> passengerList;
    Linklist<TicketInfo> passengerCancelBookList;

    flightInfo(string beginning, string destination, string flightID, string planeID, DateTime depatureDay,
               int occupLimit, double fares) :
            beginning(beginning), destination(destination), flightID(flightID), planeID(planeID),
            depatureDay(depatureDay), occupLimit(occupLimit), fares(fares),
            stockRemained(StockRemained{STOCK_TOTAL_FIRST, STOCK_TOTAL_SECOND, STOCK_TOTAL_THIRD}) {}

    flightInfo(flightInfo &_flight) {
        beginning = _flight.beginning;
        destination = _flight.destination;
        flightID = _flight.flightID;
        planeID = _flight.planeID;
        depatureDay = _flight.depatureDay;
        occupLimit = _flight.occupLimit;
        fares = _flight.fares;
        stockRemained = _flight.stockRemained;
    }

    flightInfo(const flightInfo &_flight) {
        beginning = _flight.beginning;
        destination = _flight.destination;
        flightID = _flight.flightID;
        planeID = _flight.planeID;
        depatureDay = _flight.depatureDay;
        occupLimit = _flight.occupLimit;
        fares = _flight.fares;
        stockRemained = _flight.stockRemained;
    }

    ~flightInfo() {};

    string getBeginning();

    string getDestination();

    string getFlightID();

    string getPlaneID();

    DateTime getDepatureDay();

    int getOccuoLimit();

    double getFares();

    unsigned int getStockRemained(travelClass _travelClass);

    bool passengerBook(passengerInfo &_passenger);

    void passengerCancel(passengerInfo &_passenger);

    flightInfo operator=(flightInfo &_flight);
};

//-------------------------------------------

#endif // INFORMATION_H
