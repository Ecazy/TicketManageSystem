#include "ticketmanagesystem.h"
#include "ui_ticketmanagesystem.h"
#include <QMessageBox>

TicketManageSystem::TicketManageSystem(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::TicketManageSystem) {
    ui->setupUi(this);
}

TicketManageSystem::~TicketManageSystem() {
    delete ui;
}



void TicketManageSystem::on_Inquire_clicked()
{
    Inquire();
    WriteInTicketAvailable();
    flightListUpdateUI();
}


void TicketManageSystem::on_SortByPrice_clicked()
{
    sortByPrice();
    WriteInTicketAvailable();
}


void TicketManageSystem::on_SortByTime_clicked()
{
    sortByStartTime();
    WriteInTicketAvailable();
}


void TicketManageSystem::on_RemoveNo_clicked()
{
    removeNoTicketFlight();
    WriteInTicketAvailable();
}


void TicketManageSystem::on_Reserve_clicked()
{
    BookTicket();
}


void TicketManageSystem::on_Change_clicked()
{
    ChangeTicket();
}


void TicketManageSystem::on_Cancel_clicked()
{
    CancelTicket();
}

