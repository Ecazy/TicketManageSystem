#ifndef FUNCTION_H
#define FUNCTION_H

#include "iofunc.h"

//存储总共所有的航班信息于链表中
static Linklist<flightInfo> flightInforList;
IOFunc iof;

Linklist<flightInfo> findByTime(int y, int m, int d);

Linklist<flightInfo> findByBAD(const string beginning, const string destination);

void checkTime(Linklist<flightInfo> &flightList, int y, int m, int d);

void checkBAD(Linklist<flightInfo> &flightList, const string beginning, const string destination);

void removeNoTicketFlight(Linklist<flightInfo> &flightList);

void sortByStartTime(Linklist<flightInfo> &flightList);

void sortByPrice(Linklist<flightInfo> &flightList);

void sortByArrivalTime(Linklist<flightInfo> &flightList);

bool buyTicket(flightInfo &flight, passengerInfo &passenger);

bool cancelTicket(flightInfo &flight, passengerInfo &passenger);

bool changeTicket(flightInfo &flight, passengerInfo &passenger, travelClass _travelclass);

#endif // FUNCTION_H
