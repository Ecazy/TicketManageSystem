//
// Created by 杨千靖 on 2023/11/12.
//
#include <string>
#include "datastructure.h"

#ifndef TICKETMANAGESYSTEM_FLIGHTINFO_H
#define TICKETMANAGESYSTEM_FLIGHTINFO_H

#define STOCK_TOTAL_FIRST 50
#define STOCK_TOTAL_SECOND 100
#define STOCK_TOTAL_THIRD 200

using namespace std;

typedef enum {
    FIRST, SECOND, THIRD
} travelClass;

//星期的枚举
typedef enum {
    MON, TUE, WED, THU, FRI, SAT, SUN
} Week;

//航班余票的结构，包括头等舱，商务舱，经济舱
typedef struct {
    unsigned int first;
    unsigned int second;
    unsigned int third;
} StockRemained;

//时间类
class DateTime {
public:

    int year;
    int month;
    int day;
    Week week;
    int hour;
    int minute;

    void setDateTime(int _year, int _month, int _date, Week _week, int _hour, int _minute) {
        year = _year;
        month = _month;
        day = _date;
        week = _week;
        hour = _hour;
        minute = _minute;
    }
};

class FlightInfo {

//私有成员，包括起始地，目的地，航班号，飞机号，起飞时间，座位数，票价，余票
private:

    string beginning, destination;
    string flightID;
    string planeID;
    DateTime depature;// 出发时间
    int capacity;// 载客量
    double fares;// 价格
    StockRemained stockRemained;// 余票
    //void addPassenger(passengerInfo& _passenger);
    //void deletePassenger(passengerInfo& _passenger);

public:

    FlightInfo(){}

    FlightInfo(string beginning, string destination, string flightID, string planeID,
               DateTime depature,
               int capacity, double fares) :
            beginning(beginning), destination(destination), flightID(flightID), planeID(planeID),
            depature(depature),
            capacity(capacity), fares(fares),
            stockRemained(StockRemained{STOCK_TOTAL_FIRST, STOCK_TOTAL_SECOND, STOCK_TOTAL_THIRD}) {}

    FlightInfo(FlightInfo &_flight) {
        beginning = _flight.beginning;
        destination = _flight.destination;
        flightID = _flight.flightID;
        planeID = _flight.planeID;
        depature = _flight.depature;
        capacity = _flight.capacity;
        fares = _flight.fares;
        stockRemained = _flight.stockRemained;
    }

    FlightInfo(const FlightInfo &_flight) {
        beginning = _flight.beginning;
        destination = _flight.destination;
        flightID = _flight.flightID;
        planeID = _flight.planeID;
        depature = _flight.depature;
        capacity = _flight.capacity;
        fares = _flight.fares;
        stockRemained = _flight.stockRemained;
    }

    ~FlightInfo() {};

    string getBeginning();

    string getDestination();

    string getFlightID();

    string getPlaneID();

    DateTime getDepature();

    int getCapacity();

    double getFares();

    unsigned int getStockRemained(travelClass _travelClass);

    void setStockRemained(travelClass _travelClass, int a);

    //是否存在余票
    bool ticket_has_left();

    FlightInfo operator=(FlightInfo &_flight);
};

#endif //TICKETMANAGESYSTEM_FLIGHTINFO_H
