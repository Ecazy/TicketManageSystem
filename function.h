#ifndef FUNCTION_H
#define FUNCTION_H

#include "FileTool.h"
#include "ui_ticketmanagesystem.h"



//存储总共所有的航班信息于链表中
static Linklist<FlightInfo> flightInforList;

bool book(string name, string id, travelClass your_class);

bool change(string name, string now_id, string target_id, travelClass target_class);

bool cancel(string name, string id);

void checkTime(Linklist<FlightInfo> &FlightList, int y, int m, int d);

void checkBAD(Linklist<FlightInfo> &FlightList, const string beginning, const string destination);

void removeNoTicketFlight();

void sortByStartTime();

void sortByPrice();

//void sortByArrivalTime(Linklist<FlightInfo> &flightList);



void WriteInMyTicket(Linklist<passengerInfo> &my_ticket_list,Ui::TicketManageSystem* ui);


void WriteInTicketAvailable(Ui::TicketManageSystem* ui);

void flightListUpdateUI(Ui::TicketManageSystem* ui);

void Inquire(Ui::TicketManageSystem* ui);

void BookTicket(Ui::TicketManageSystem* ui);

void ChangeTicket(Ui::TicketManageSystem* ui);

void CancelTicket(Ui::TicketManageSystem* ui);



#endif // FUNCTION_H
