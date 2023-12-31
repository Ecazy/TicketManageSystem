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
    int hour;
    int minute;

    void setDateTime(int _year, int _month, int _date, int _hour, int _minute) {
        year = _year;
        month = _month;
        day = _date;
        hour = _hour;
        minute = _minute;
    }

    void getDate(int &_year, int &_month, int &_day, int &_hour, int &_minute) {
        _year = year;
        _month = month;
        _day = day;
        _hour = hour;
        _minute = minute;
    }

    bool operator<(const DateTime &date) {
        if (year == date.year) {
            if (month == date.month) {
                if (day == date.day) {
                    if (hour == date.hour) {
                        return minute < date.minute;
                    }
                    else
                        return  hour < date.hour;
                }
                else
                    return day < date.day;
            }
            else
                return  month < date.month;
        }
        else
            return  year < date.year;
    }
};

class FlightInfo {

//私有成员，包括起始地，目的地，航班号，飞机号，起飞时间，座位数，票价，余票
private:

    string beginning, destination;
    string flightID;
    DateTime depature;// 出发时间
    int capacity;// 载客量
    double first_fare;// 价格
    double second_fare;// 价格
    double third_fare;// 价格
    StockRemained stockRemained;// 余票
    //void addPassenger(passengerInfo& _passenger);
    //void deletePassenger(passengerInfo& _passenger);

public:

    FlightInfo() {}

    FlightInfo(string beginning, string destination, string flightID,DateTime depature,
               int capacity, double first_fare, double second_fare, double third_fare) :
            beginning(beginning), destination(destination), flightID(flightID),
            depature(depature),
            capacity(capacity), first_fare(first_fare),
            second_fare(second_fare),
            third_fare(third_fare),
            stockRemained(StockRemained{STOCK_TOTAL_FIRST, STOCK_TOTAL_SECOND, STOCK_TOTAL_THIRD}) {}

    FlightInfo(FlightInfo &_flight) {
        beginning = _flight.getBeginning();
        destination = _flight.getDestination();
        flightID = _flight.getFlightID();
        depature = _flight.getDepature();
        capacity = _flight.getCapacity();
        first_fare = _flight.getFares(FIRST);
        second_fare = _flight.getFares(SECOND);
        third_fare = _flight.getFares(THIRD);
        stockRemained = _flight.getStockRemained();

    }

    FlightInfo(const FlightInfo &_flight) {
        beginning = _flight.beginning;
        destination = _flight.destination;
        flightID = _flight.flightID;
        depature = _flight.depature;
        capacity = _flight.capacity;
        first_fare = _flight.first_fare;
        second_fare = _flight.second_fare;
        third_fare = _flight.third_fare;
        stockRemained = _flight.stockRemained;
    }

    ~FlightInfo() {};

    string getBeginning();

    string getDestination();

    string getFlightID();

    DateTime getDepature();

    int getCapacity();

    double getFares(travelClass a);

    unsigned int getStockRemained(travelClass _travelClass);

    StockRemained  getStockRemained();

    void setStockRemained(travelClass _travelClass, int a);

    void setFlightID(const string _flightID)
    {
        this->flightID=_flightID;
    }

    //是否存在余票
    bool ticket_has_left();

    FlightInfo& operator=(FlightInfo &_flight);
};


#endif //TICKETMANAGESYSTEM_FLIGHTINFO_H
