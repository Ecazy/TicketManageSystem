#include "FlightInfo.h"

string FlightInfo::getBeginning() {
    return beginning;
}

string FlightInfo::getDestination() {
    return destination;
}

string FlightInfo::getFlightID() {
    return flightID;
}

DateTime FlightInfo::getDepature() {
    return depature;
}

int FlightInfo::getCapacity() {
    return capacity;
}

double FlightInfo::getFares(travelClass a) {
    switch (a) {
        case FIRST:
            return first_fare;
            break;
        case SECOND:
            return second_fare;
            break;
        case THIRD:
            return third_fare;
            break;
    }
    return INT_MIN;
}

unsigned int FlightInfo::getStockRemained(travelClass _travelClass) {
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

StockRemained FlightInfo::getStockRemained()
{
    return stockRemained;
}

void FlightInfo::setStockRemained(travelClass _travelClass, int a) {
    switch (_travelClass) {
        case FIRST:
            stockRemained.first = a;
            break;
        case SECOND:
            stockRemained.second = a;
            break;
        case THIRD:
            stockRemained.third = a;
            break;
        default:
            break;
    }

}

/**
 * @brief 重载等号运算符
 * @param _flight 航班信息
 * @return 航班信息
 */
FlightInfo& FlightInfo::operator=(FlightInfo &_flight) {
    beginning = _flight.getBeginning();
    destination = _flight.getDestination();
    flightID = _flight.getFlightID();
    depature = _flight.depature;
    capacity = _flight.capacity;
    first_fare = _flight.first_fare;
    second_fare = _flight.second_fare;
    third_fare = _flight.third_fare;
    stockRemained = _flight.stockRemained;
    return *this;
}

bool FlightInfo::ticket_has_left() {
    int a = getStockRemained(FIRST) +
            getStockRemained(SECOND) +
            getStockRemained(THIRD);
    if (a > 0)
        return true;
    else
        return false;
}

