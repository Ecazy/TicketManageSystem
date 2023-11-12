#include "information.h"

string flightInfo::getBeginning() {
    return beginning;
}

string flightInfo::getDestination() {
    return destination;
}

string flightInfo::getFlightID() {
    return flightID;
}

string flightInfo::getPlaneID() {
    return planeID;
}

DateTime flightInfo::getDepatureDay() {
    return depatureDay;
}

int flightInfo::getOccuoLimit() {
    return occupLimit;
}

double flightInfo::getFares() {
    return fares;
}

unsigned int flightInfo::getStockRemained(travelClass _travelClass) {
    switch (_travelClass) {
        case FIRST:
            return stockRemained.first;
        case SECOND:
            return stockRemained.second;
        case THIRD:
            return stockRemained.third;
    }
    return 0;
}

//void flightInfo::addPassenger(passengerInfo& _passenger)
//{
//    passengerList.addToTail(_passenger);
//}
//
//void flightInfo::deletePassenger(passengerInfo& _passenger)
//{
//    passengerList.removeByElement(_passenger);
//}

/**
 * @brief 乘客预约航班
 * @param _passenger 乘客信息
 * @return 预约成功返回true，否则返回false
 * @note 预约成功后，航班余票减一 
 */
bool flightInfo::passengerBook(passengerInfo &_passenger) {
    if (!passengerList.findByElement(_passenger)) {
        travelClass _travelClass = _passenger.getTravelClass();
        unsigned int _stockRemained = getStockRemained(_travelClass);
        if (_stockRemained > 0) {
            passengerList.addToTail(_passenger);
            _passenger.setIsBooked(true);
            switch (_travelClass) {
                case FIRST:
                    stockRemained.first--;
                    break;
                case SECOND:
                    stockRemained.second--;
                    break;
                case THIRD:
                    stockRemained.third--;
                    break;
            }
            return true;
        } else
            return false;
    }
    return false;
}

/**
 * @brief 乘客取消预约航班
 * @param _passenger 乘客信息
 * @note 取消预约成功后，航班余票加一
 */
void flightInfo::passengerCancel(passengerInfo &_passenger) {
    if (_passenger.getIsBooked() && passengerList.findByElement(_passenger)) {
        passengerList.removeByElement(_passenger);
        _passenger.setIsBooked(false);
        switch (_passenger.getTravelClass()) {
            case FIRST:
                stockRemained.first++;
                break;
            case SECOND:
                stockRemained.second++;
                break;
            case THIRD:
                stockRemained.third++;
                break;
        }
        passengerCancelBookList.addToHead({_passenger.getName(), _passenger.getTravelClass(), this->flightID});
    }
}

/**
 * @brief 重载等号运算符
 * @param _flight 航班信息
 * @return 航班信息 
 */
flightInfo flightInfo::operator=(flightInfo &_flight) {
    beginning = _flight.beginning;
    destination = _flight.destination;
    flightID = _flight.flightID;
    planeID = _flight.planeID;
    depatureDay = _flight.depatureDay;
    occupLimit = _flight.occupLimit;
    fares = _flight.fares;
    stockRemained = _flight.stockRemained;
    passengerList = _flight.passengerList;
    passengerCancelBookList = _flight.passengerCancelBookList;
    return *this;
}

/*-------------------------------------------------*/
//以下为乘客信息类的实现

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
bool passengerInfo::bookTicket(flightInfo &_flight) {
    if (!isBooked) {
        if (_flight.passengerBook(*this)) {
            isBooked = true;
            return true;
        }
        return false;
    }
    return false;
}

/**
 * @brief 乘客取消预约航班
 * @param _flight 航班信息
 * @return 取消预约成功返回true，否则返回false
 */
bool passengerInfo::cancelTicket(flightInfo &_flight) {
    if (isBooked) {
        _flight.passengerCancel(*this);
        isBooked = false;
        return true;
    }
    return false;
}

/**
 * @brief 乘客改签航班
 * @param _flight 航班信息
 * @param _travelclass 目标舱位等级
 * @return 改签成功返回true，否则返回false 
 */
bool passengerInfo::changeTicket(flightInfo &_flight, travelClass _travelclass) {
    if (isBooked) {
        if (_flight.getStockRemained(_travelclass) > 0) {
            _flight.passengerCancel(*this);
            travelclass = _travelclass;
            _flight.passengerBook(*this);
            return true;
        }
        return false;
    }
    return false;
}

/**
 * @brief 乘客查询航班余票
 * @param _flight 航班信息
 * @return 航班余票信息
 */
StockRemained passengerInfo::getTicket(flightInfo &_flight) {
    return {_flight.getStockRemained(FIRST), _flight.getStockRemained(SECOND), _flight.getStockRemained(THIRD)};
}
