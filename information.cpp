#include "Information.h"

string flightInfor::getBeginning()
{
    return beginning;
}

string flightInfor::getDestination()
{
    return destination;
}

string flightInfor::getFlightID()
{
    return flightID;
}

string flightInfor::getPlaneID()
{
    return planeID;
}

DateTime flightInfor::getDepatureDay()
{
    return depatureDay;
}

int flightInfor::getOccuoLimit()
{
    return occupLimit;
}

double flightInfor::getFares()
{
    return fares;
}

unsigned int flightInfor::getStockRemained(travelClass _travelClass)
{
    switch(_travelClass)
    {
    case FIRST:
        return stockRemained.first;
    case SECOND:
        return stockRemained.second;
    case THIRD:
        return stockRemained.third;
    }
    return 0;
}

//void flightInfor::addPassenger(passengerInfor& _passenger)
//{
//    passengerList.addToTail(_passenger);
//}
//
//void flightInfor::deletePassenger(passengerInfor& _passenger)
//{
//    passengerList.removeByElement(_passenger);
//}

bool flightInfor::passengerBook(passengerInfor& _passenger)
{
    if(!passengerList.findByElement(_passenger))
    {
        travelClass _travelClass = _passenger.getTravelClass();
        unsigned int _stockRemained = getStockRemained(_travelClass);
        if(_stockRemained > 0)
        {
            passengerList.addToTail(_passenger);
            _passenger.setIsBooked(true);
            switch(_travelClass)
            {
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
        }
        else
            return false;
    }
    return false;
}

void flightInfor::passengerCancel(passengerInfor& _passenger)
{
    if(_passenger.getIsBooked() && passengerList.findByElement(_passenger))
    {
        passengerList.removeByElement(_passenger);
        _passenger.setIsBooked(false);
        switch(_passenger.getTravelClass())
        {
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
        passengerCancelBookList.addToHead({_passenger.getName(),_passenger.getTravelClass(),this->flightID});
    }
}

flightInfor flightInfor::operator=(flightInfor& _flight)
{
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

//-------------------------------------------------
string passengerInfor::getName()
{
    return name;
}

travelClass passengerInfor::getTravelClass()
{
    return travelclass;
}

bool passengerInfor::getIsBooked()
{
    return isBooked;
}

void passengerInfor::setIsBooked(bool isBooked)
{
    this->isBooked = isBooked;
}

bool passengerInfor::operator<(passengerInfor& _passenger)
{
    if(travelclass > _passenger.travelclass)
        return true;
    else if(travelclass == _passenger.travelclass)
        return name < _passenger.name;
    else
        return false;
}

bool passengerInfor::operator==(passengerInfor& _passenger)
{
    return name == _passenger.name;
}

bool passengerInfor::bookTicket(flightInfor& _flight)
{
    if(!isBooked)
    {
        if(_flight.passengerBook(*this))
        {
            isBooked = true;
            return true;
        }
        return false;
    }
    return false;
}

bool passengerInfor::cancelTicket(flightInfor& _flight)
{
    if(isBooked)
    {
        _flight.passengerCancel(*this);
        isBooked = false;
        return true;
    }
    return false;
}

bool passengerInfor::changeTicket(flightInfor& _flight,travelClass _travelclass)
{
    if(isBooked)
    {
        if(_flight.getStockRemained(_travelclass)>0)
        {
            _flight.passengerCancel(*this);
            travelclass = _travelclass;
            _flight.passengerBook(*this);
            return true;
        }
        return false;
    }
    return false;
}

StockRemained passengerInfor::getTicket(flightInfor& _flight)
{
    return {_flight.getStockRemained(FIRST),_flight.getStockRemained(SECOND),_flight.getStockRemained(THIRD)};
}
