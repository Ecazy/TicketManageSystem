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

string FlightInfo::getPlaneID() {
    return planeID;
}

DateTime FlightInfo::getDepature() {
    return depature;
}

int FlightInfo::getCapacity() {
    return capacity;
}

double FlightInfo::getFares() {
    return fares;
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

void FlightInfo::setStockRemained(travelClass _travelClass, int a) {
    switch (_travelClass) {
        case FIRST:
            stockRemained.first = a;
        case SECOND:
            stockRemained.second = a;
        case THIRD:
            stockRemained.third = a;
    }

}

/**
 * @brief 重载等号运算符
 * @param _flight 航班信息
 * @return 航班信息
 */
FlightInfo FlightInfo::operator=(FlightInfo &_flight) {
    beginning = _flight.beginning;
    destination = _flight.destination;
    flightID = _flight.flightID;
    planeID = _flight.planeID;
    depature = _flight.depature;
    capacity = _flight.capacity;
    fares = _flight.fares;
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

