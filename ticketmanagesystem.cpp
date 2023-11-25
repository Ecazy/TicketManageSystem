#include "ticketmanagesystem.h"
#include "ui_ticketmanagesystem.h"
#include <QMessageBox>
#include<QObject>

TicketManageSystem::TicketManageSystem(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::TicketManageSystem) {
    //TODO 将widget都声明，尝试addItem()
    ui->setupUi(this);
    QWidget* widget = loadUiFile("./ticketmanagesystem.ui");
    QPushButton *inquire = widget->findChild<QPushButton*>("Inquire");
    QTableWidget *TicketsAvailable = widget->findChild<QTableWidget*>("TicketsAvailable");
    QObject::connect(inquire,SIGNAL(clicked()),this,SLOT(ClickInquire()));
    QObject::connect(TicketsAvailable,)
}

TicketManageSystem::~TicketManageSystem() {
    delete ui;
}



void TicketManageSystem::on_Inquire_clicked()
{
}

void TicketManageSystem::ClickInquire()
{
    Inquire();
    WriteInTicketAvailable();
    flightListUpdateUI();
}


void TicketManageSystem::on_SortByPrice_clicked()
{
}

void TicketManageSystem::ClickSortByPrice()
{
    sortByPrice();
    WriteInTicketAvailable();
}


void TicketManageSystem::on_SortByTime_clicked()
{
}

void TicketManageSystem::ClickSortByTime()
{
    sortByStartTime();
    WriteInTicketAvailable();
}


void TicketManageSystem::on_RemoveNo_clicked()
{
}

void TicketManageSystem::ClickRemove() {
    removeNoTicketFlight();
    WriteInTicketAvailable();
}

void TicketManageSystem::on_Reserve_clicked()
{
}

void TicketManageSystem::ClickBook()
{
    BookTicket();
}

void TicketManageSystem::on_Change_clicked()
{
}

void ClickChange()
{
    ChangeTicket();
}


void TicketManageSystem::on_Cancel_clicked()
{
}

void TicketManageSystem::ClickCancel() {
    CancelTicket();
}

