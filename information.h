#ifndef INFORMATION_H
#define INFORMATION_H

#include<string>
#include "datastructure.h"
using namespace std;

#define STOCK_TOTAL_FIRST 50
#define STOCK_TOTAL_SECOND 100
#define STOCK_TOTAL_THIRD 200

//飞机舱位等级的枚举
typedef enum
{
    FIRST,SECOND,THIRD
}travelClass;

//星期的枚举
typedef enum
{
    MON,TUE,WED,THU,FRI,SAT,SUN
}Week;

//时间的结构体，包括年月日星期时分
typedef struct
{
    int year;
    int month;
    int date;
    Week week;
    int hour;
    int minute;
    void setDateTime(int _year, int _month, int _date, Week _week, int _hour, int _minute)
    {
        year = _year;
        month = _month;
        date = _date;
        week = _week;
        hour = _hour;
        minute = _minute;
    }
}DateTime;


//乘客取消订单的结构，包括乘客姓名，舱位等级，航班号
typedef struct
{
    string name;
    travelClass travelclass;
    string flightID;
}passengerCancelBook;

//航班余票的结构，包括头等舱，商务舱，经济舱
typedef struct{
    unsigned int first;
    unsigned int second;
    unsigned int third;
}StockRemained;

//由于两个类型的交叉引用，所以需要提前声明
class flightInfor;

class passengerInfor
{
//私有成员，包括乘客姓名，舱位等级，是否已经订票
private:
    string name;
    travelClass travelclass;
    bool isBooked;
public:
    friend class flightInfor;
    passengerInfor(string name, travelClass travelclass, bool isBooked=false) :
        name(name), travelclass(travelclass),isBooked(isBooked)
    {}
    passengerInfor(passengerInfor& _passenger)
    {
        name = _passenger.name;
        travelclass = _passenger.travelclass;
    }
    passengerInfor(const passengerInfor& _passenger)
    {
        name = _passenger.name;
        travelclass = _passenger.travelclass;
    }
    ~passengerInfor() {};
    string getName();
    travelClass getTravelClass();
    bool getIsBooked();
    void setIsBooked(bool isBooked);

    bool operator<(passengerInfor& _passenger);
    bool operator==(passengerInfor& _passenger);

    bool bookTicket(flightInfor& _flight);
    bool cancelTicket(flightInfor& _flight);
    bool changeTicket(flightInfor& _flight, travelClass _travelclass);
    StockRemained getTicket(flightInfor& _flight);
};

class flightInfor
{
//私有成员，包括起始地，目的地，航班号，飞机号，起飞时间，座位数，票价，余票
private:
    string beginning, destination;
    string flightID;
    string planeID;
    DateTime depatureDay;
    int occupLimit;
    double fares;
    StockRemained stockRemained;
    //void addPassenger(passengerInfor& _passenger);
    //void deletePassenger(passengerInfor& _passenger);
public:
    Linklist<passengerInfor> passengerList;
    Linklist<passengerCancelBook> passengerCancelBookList;
    flightInfor(string beginning,string destination,string flightID,string planeID,DateTime depatureDay,int occupLimit,double fares):
        beginning(beginning),destination(destination),flightID(flightID),planeID(planeID),depatureDay(depatureDay),occupLimit(occupLimit),fares(fares),stockRemained(StockRemained{STOCK_TOTAL_FIRST,STOCK_TOTAL_SECOND,STOCK_TOTAL_THIRD})
    {}
    flightInfor(flightInfor& _flight)
    {
        beginning = _flight.beginning;
        destination = _flight.destination;
        flightID = _flight.flightID;
        planeID = _flight.planeID;
        depatureDay = _flight.depatureDay;
        occupLimit = _flight.occupLimit;
        fares = _flight.fares;
        stockRemained = _flight.stockRemained;
    }
    flightInfor(const flightInfor& _flight)
    {
        beginning = _flight.beginning;
        destination = _flight.destination;
        flightID = _flight.flightID;
        planeID = _flight.planeID;
        depatureDay = _flight.depatureDay;
        occupLimit = _flight.occupLimit;
        fares = _flight.fares;
        stockRemained = _flight.stockRemained;
    }
    ~flightInfor() {};
    string getBeginning();
    string getDestination();
    string getFlightID();
    string getPlaneID();
    DateTime getDepatureDay();
    int getOccuoLimit();
    double getFares();
    unsigned int getStockRemained(travelClass _travelClass);

    bool passengerBook(passengerInfor& _passenger);
    void passengerCancel(passengerInfor& _passenger);

    flightInfor operator=(flightInfor& _flight);
};

//-------------------------------------------

#endif // INFORMATION_H
