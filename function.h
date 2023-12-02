#ifndef FUNCTION_H
#define FUNCTION_H

#include "FileTool.h"
#include "ui_ticketmanagesystem.h"



bool book(string name, string id, travelClass your_class, Linklist<passengerInfo> &my_tickets);

bool change(string name, string now_id, string target_id, travelClass target_class, Linklist<passengerInfo> &my_tickets);

bool cancel(string name, string id, Linklist<passengerInfo> &my_tickets);

void checkTime(Linklist<FlightInfo> &FlightList, int y, int m, int d);

void checkBAD(Linklist<FlightInfo> &FlightList, const string beginning, const string destination);

void removeNoTicketFlight();

void sortByStartTime();

void sortByPrice();

void WriteInMyTicket(Ui::TicketManageSystem *ui,Linklist<passengerInfo> &my_tickets);

void WriteInTicketAvailable(Ui::TicketManageSystem *ui);

void flightListUpdateUI(Ui::TicketManageSystem *ui, Linklist<passengerInfo> &my_tickets);

void Inquire(Ui::TicketManageSystem *ui);

void BookTicket(Ui::TicketManageSystem *ui, string name, Linklist<passengerInfo> &my_tickets);

void ChangeTicket(Ui::TicketManageSystem *ui, string name, Linklist<passengerInfo> &my_tickets);

void CancelTicket(Ui::TicketManageSystem *ui, string name, Linklist<passengerInfo> &my_tickets);

Linklist<passengerInfo> get_my_tickets(string name);


#endif // FUNCTION_H
