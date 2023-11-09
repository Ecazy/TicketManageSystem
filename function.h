#ifndef FUNCTION_H
#define FUNCTION_H

#include "iofunc.h"

//存储总共所有的航班信息于链表中
static Linklist<flightInfor> flightInforList;
IOFunc iof;

Linklist<flightInfor> findByTime(int y,int m,int d);
Linklist<flightInfor> findByBAD(const string beginning,const string destination);

void checkTime(Linklist<flightInfor>& flightList,int y,int m,int d);
void checkBAD(Linklist<flightInfor>& flightList,const string beginning,const string destination);

void removeNoTicketFlight(Linklist<flightInfor>& flightList);

void sortByStartTime(Linklist<flightInfor>& flightList);
void sortByPrice(Linklist<flightInfor>& flightList);
void sortByArrivalTime(Linklist<flightInfor>& flightList);

bool buyTicket(flightInfor& flight,passengerInfor& passenger);
bool cancelTicket(flightInfor& flight,passengerInfor& passenger);
bool changeTicket(flightInfor& flight,passengerInfor& passenger,travelClass _travelclass);

#endif // FUNCTION_H
