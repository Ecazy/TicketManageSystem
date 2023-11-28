#include "Passenger.h"

string passengerInfo::getName() {
    return name;
}

bool passengerInfo::getIsBooked() {
    return isBooked;
}

void passengerInfo::setIsBooked(bool isBooked) {
    this->isBooked = isBooked;
}

/**
 * @brief 重载小于运算符
 * @param _passenger
 * @return 舱位等级大的返回true，舱位等级相同的返回姓名小的返回true，否则返回false 
 */
bool passengerInfo::operator<(passengerInfo &_passenger) {
    if (my_class > _passenger.my_class)
        return true;
    else if (my_class == _passenger.my_class)
        return name < _passenger.name;
    else
        return false;
}

/**
 * @brief 重载乘客类型的==，用以判断两个乘客是否相同
 * @param _passenger
 * @return 两个乘客姓名相同返回true，否则返回false
 * @note 由于本问题中涉及乘客信息较为简单，故只判断姓名是否相同即可
 */
bool passengerInfo::operator==(passengerInfo &_passenger) {
    return name == _passenger.name;
}


FlightInfo passengerInfo::getFlightInfo() {
    return my_flight;
}