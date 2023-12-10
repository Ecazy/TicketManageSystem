#ifndef FUNCTION_H
#define FUNCTION_H

#include "FileTool.h"
#include "ui_ticketmanagesystem.h"
#include "ui_admin.h"

typedef enum
{
    SUCCESS,
    BOOK_FAILURE,
    CANCEL_FAILURE,
    CHANGE_FAILURE,
    ADD_FAILURE,
    DELETE_FAILURE,
    AMEND_FAILURE,
    INQUIRE_FAILURE_BLANKET,
    INVALID_INPUT
}ERROR_TYPE;

typedef enum
{
    TIME_PLACE,
    TIME,
    PLACE
}INQUIRE_TYPE;

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

void updateFlightList(Ui::TicketManageSystem* ui);


void ShowMy(Ui::TicketManageSystem* ui,string name);

void Inquire(Ui::TicketManageSystem* ui);

void Inquire(Ui::Admin* ui,const INQUIRE_TYPE it);

ERROR_TYPE Inquire(Ui::Admin* ui,bool flag);

void ChangeInquire(Ui::TicketManageSystem* ui);

FlightInfo ReadFromChanfe(Ui::Admin* ui);

ERROR_TYPE BookTicket(Ui::TicketManageSystem* ui,const string& name);

ERROR_TYPE ChangeTicket(Ui::TicketManageSystem* ui,const string& name);

ERROR_TYPE CancelTicket(Ui::TicketManageSystem* ui,const string& name);

void WriteInTicketsTable(Ui::Admin* ui);

FlightInfo ReadFromAdd(Ui::Admin* ui);

void WriteIn(Ui::Admin* ui,bool flag);

ERROR_TYPE Add(Ui::Admin* ui);

ERROR_TYPE Delete(Ui::Admin* ui);

ERROR_TYPE  Change(Ui::Admin* ui);



#endif // FUNCTION_H
