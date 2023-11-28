#include "ticketmanagesystem.h"
#include <QMessageBox>
//#include "ui_ticketmanagesystem.h"
#include <QObject>

TicketManageSystem::TicketManageSystem(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::TicketManageSystem) {
    //TODO 将widget都声明，尝试addItem()
    ui->setupUi(this);

    //禁用表格更改
    ui->TicketsAvailable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->MyTickets->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

TicketManageSystem::~TicketManageSystem() {
    delete ui;
}


void TicketManageSystem::on_Inquire_clicked() {
    Inquire(this->ui);
    flightListUpdateUI(this->ui);
    //终端返回信息
    qDebug() << "Inquire";
}

void TicketManageSystem::on_SortByPrice_clicked() {
    sortByPrice();
    WriteInTicketAvailable(this->ui);

    qDebug() << "SortByPrice";
}

void TicketManageSystem::on_SortByTime_clicked() {
    sortByStartTime();
    WriteInTicketAvailable(this->ui);

    qDebug() << "SortByTime";
}

void TicketManageSystem::on_RemoveNo_clicked() {
    removeNoTicketFlight();
    WriteInTicketAvailable(this->ui);

    qDebug() << "RemoveNo";
}

void TicketManageSystem::on_Reserve_clicked() {
    BookTicket(this->ui);

    qDebug() << "Reserve";
}


void TicketManageSystem::on_Change_clicked() {
    ChangeTicket(this->ui);

    qDebug() << "Change";
}

void TicketManageSystem::on_Cancel_clicked() {
    CancelTicket(this->ui);

    qDebug() << "Cancel";
}


//简单介绍原理：
//通过将此处的this->ui传入函数中，才可修改程序中的数值、绑定程序中的按钮等部件
//也即此处的this->ui可理解为用于渲染界面的一个指针