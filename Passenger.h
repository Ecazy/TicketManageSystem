#ifndef INFORMATION_H
#define INFORMATION_H

#include "FlightInfo.h"

using namespace std;

class passengerInfo {
//私有成员，包括乘客姓名，舱位等级，是否已经订票
private:
    string name;
    FlightInfo my_flight;
    bool isBooked;
public:
    travelClass my_class;

    friend class FlightInfo;

    passengerInfo(string name, FlightInfo my_flight, travelClass my_class, bool isBooked = false) :
            name(name), my_flight(my_flight), my_class(my_class), isBooked(isBooked) {}

    passengerInfo() {};

    passengerInfo(passengerInfo &_passenger);

    passengerInfo(const passengerInfo &_passenger);

    ~passengerInfo() {};

    string getName();

    FlightInfo getFlightInfo();

    bool getIsBooked();

    void setIsBooked(bool isBooked);

    void setName(string name);

    void setFlightInfo(FlightInfo my_flight);

    void setTravelClass(travelClass my_class);

    bool operator<(passengerInfo &_passenger);

    bool operator==(passengerInfo &_passenger);

};



#endif