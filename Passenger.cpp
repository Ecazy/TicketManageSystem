#include "Passenger.h"

string passengerInfo::getName() {
    return name;
}

travelClass passengerInfo::getTravelClass() {
    return travelclass;
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
    if (travelclass > _passenger.travelclass)
        return true;
    else if (travelclass == _passenger.travelclass)
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

/**
 * @brief 乘客预约航班
 * @param _flight 航班信息
 * @return 预约成功返回true，否则返回false
 */
bool passengerInfo::bookTicket(FlightInfo &_flight) {}

/**
 * @brief 乘客取消预约航班
 * @param _flight 航班信息
 * @return 取消预约成功返回true，否则返回false
 */
bool passengerInfo::cancelTicket(FlightInfo &_flight) {}

/**
 * @brief 乘客改签航班
 * @param _flight 航班信息
 * @param _travelclass 目标舱位等级
 * @return 改签成功返回true，否则返回false 
 */
bool passengerInfo::changeTicket(FlightInfo &_flight, travelClass _travelclass) {}

/**
 * @brief 乘客查询航班余票
 * @param _flight 航班信息
 * @return 航班余票信息
 */
StockRemained passengerInfo::getTicket(FlightInfo &_flight) {
    return {_flight.getStockRemained(FIRST),
            _flight.getStockRemained(SECOND),
            _flight.getStockRemained(THIRD)};
}

