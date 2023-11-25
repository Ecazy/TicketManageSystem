#ifndef FUNCTION_H
#define FUNCTION_H

#include "FileTool.h"



//存储总共所有的航班信息于链表中
static Linklist<FlightInfo> flightInforList;

bool book(Linklist<FlightInfo> list, string name, string id, string your_class);

Linklist<FlightInfo> findByTime(int y, int m, int d);

Linklist<FlightInfo> findByBAD(const string beginning, const string destination);

void checkTime(Linklist<FlightInfo> &flightList, int y, int m, int d);

void checkBAD(Linklist<FlightInfo> &flightList, const string beginning, const string destination);

void removeNoTicketFlight();

void sortByStartTime();

void sortByPrice();

//void sortByArrivalTime(Linklist<FlightInfo> &flightList);



void WriteInMyTicket(Linklist<passengerInfo> &my_ticket_list);


void WriteInTicketAvailable();

void flightListUpdateUI();

void Inquire();

void BookTicket();

void ChangeTicket();

void CancelTicket();



#endif // FUNCTION_H
