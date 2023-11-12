#ifndef INFORMATION_H
#define INFORMATION_H

#include "FlightInfo.h"

using namespace std;

//乘客取消订单的结构，包括乘客姓名，舱位等级，航班号
typedef struct {
    string name;
    travelClass travelclass;
    string flightID;
} TicketInfo;

class passengerInfo {
//私有成员，包括乘客姓名，舱位等级，是否已经订票
private:
    string name;
    travelClass travelclass;
    bool isBooked;
public:
    friend class FlightInfo;

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

    bool bookTicket(FlightInfo &_flight);

    bool cancelTicket(FlightInfo &_flight);

    bool changeTicket(FlightInfo &_flight, travelClass _travelclass);

    StockRemained getTicket(FlightInfo &_flight);
};

#endif