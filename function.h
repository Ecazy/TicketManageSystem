#ifndef FUNCTION_H
#define FUNCTION_H

#include "FileTool.h"
#include "ui_ticketmanagesystem.h"

typedef enum
{
    SUCCESS,
    BOOK_FAILURE,
    CANCEL_FAILURE,
    CHANGE_FAILURE
}ERROR_TYPE;

bool book(string name, string id, travelClass your_class);

bool change(string name, string now_id, string target_id, travelClass target_class);

bool cancel(string name, string id);

string formatTime(const DateTime &time);

void checkTime(Linklist<FlightInfo> &FlightList, int y, int m, int d);

void checkBAD(Linklist<FlightInfo> &FlightList, const string beginning, const string destination);

void removeNoTicketFlight();

void sortByStartTime();

void sortByPrice();

//void sortByArrivalTime(Linklist<FlightInfo> &flightList);



void WriteInMyTicket(Linklist<passengerInfo> &my_ticket_list,Ui::TicketManageSystem* ui);


void WriteInTicketAvailable(Ui::TicketManageSystem* ui);

void WriteInChange(Ui::TicketManageSystem* ui);

void flightListUpdateUI(Ui::TicketManageSystem* ui);

void Inquire(Ui::TicketManageSystem* ui);

void ChangeInquire(Ui::TicketManageSystem* ui);

ERROR_TYPE BookTicket(Ui::TicketManageSystem* ui,const string& name);

ERROR_TYPE ChangeTicket(Ui::TicketManageSystem* ui,const string& name);

ERROR_TYPE CancelTicket(Ui::TicketManageSystem* ui,const string& name);



#endif // FUNCTION_H
