#ifndef INFORMATION_H
#define INFORMATION_H

#include "FlightInfo.h"

using namespace std;

class passengerInfo {
//私有成员，包括乘客姓名，舱位等级，是否已经订票
private:
    string name;
    string password = "12345";
    FlightInfo my_flight;
    bool isBooked;
public:
    passengerInfo(){};

    travelClass my_class;

    friend class FlightInfo;

    passengerInfo(string name, FlightInfo my_flight, travelClass my_class, bool isBooked = false) :
            name(name), my_flight(my_flight), my_class(my_class), isBooked(isBooked) {}

    string getName();

    FlightInfo getFlightInfo();

    void setPassword(string code){
        password = code;
    }

    string getPassword(){
        return password;
    }

    bool getIsBooked();

    void setIsBooked(bool isBooked);

    bool operator<(passengerInfo &_passenger);

    bool operator==(passengerInfo &_passenger);

};



#endif