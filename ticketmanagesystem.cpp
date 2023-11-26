#include "ticketmanagesystem.h"
#include <QMessageBox>
//#include "ui_ticketmanagesystem.h"
#include <QObject>

TicketManageSystem::TicketManageSystem(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::TicketManageSystem) {
    //TODO 将widget都声明，尝试addItem()
    ui->setupUi(this);

    //获取ui中的点击按钮
    QPushButton *inquire = ui->Inquire;
    QPushButton *sortByPrice = ui->SortByPrice;
    QPushButton *sortByTime = ui->SortByTime;
    QPushButton *removeNo = ui->RemoveNo;
    QPushButton *reserve = ui->Reserve;
    QPushButton *change = ui->Change;
    QPushButton *cancel = ui->Cancel;
    //绑定按钮事件
    QObject::connect(inquire, &QPushButton::clicked, this, &TicketManageSystem::ClickInquire);
    QObject::connect(reserve, &QPushButton::clicked, this, &TicketManageSystem::ClickBook);
    QObject::connect(change, &QPushButton::clicked, this, &TicketManageSystem::ClickChange);
    QObject::connect(cancel, &QPushButton::clicked, this, &TicketManageSystem::ClickCancel);
    QObject::connect(sortByPrice, &QPushButton::clicked, this, &TicketManageSystem::ClickSortByPrice);
    QObject::connect(sortByTime, &QPushButton::clicked, this, &TicketManageSystem::ClickSortByTime);
    QObject::connect(removeNo, &QPushButton::clicked, this, &TicketManageSystem::ClickRemove);
//    QObject::connect(TicketsAvailable,)
}

TicketManageSystem::~TicketManageSystem() {
    delete ui;
}


void TicketManageSystem::on_Inquire_clicked() {
}

void TicketManageSystem::ClickInquire() {
    Inquire(this->ui);
    flightListUpdateUI(this->ui);
    //终端返回信息
    qDebug() << "Inquire";
}


void TicketManageSystem::on_SortByPrice_clicked() {
}

void TicketManageSystem::ClickSortByPrice() {
    sortByPrice();
    WriteInTicketAvailable(this->ui);

    qDebug() << "SortByPrice";
}


void TicketManageSystem::on_SortByTime_clicked() {
}

void TicketManageSystem::ClickSortByTime() {
    sortByStartTime();
    WriteInTicketAvailable(this->ui);

    qDebug() << "SortByTime";
}


void TicketManageSystem::on_RemoveNo_clicked() {
}

void TicketManageSystem::ClickRemove() {
    removeNoTicketFlight();
    WriteInTicketAvailable(this->ui);

    qDebug() << "RemoveNo";
}

void TicketManageSystem::on_Reserve_clicked() {
}

void TicketManageSystem::ClickBook() {
    BookTicket(this->ui);

    qDebug() << "Reserve";
}

void TicketManageSystem::on_Change_clicked() {
}

void TicketManageSystem::ClickChange() {
    ChangeTicket(this->ui);

    qDebug() << "Change";
}


void TicketManageSystem::on_Cancel_clicked() {
}

void TicketManageSystem::ClickCancel() {
    CancelTicket(this->ui);

    qDebug() << "Cancel";
}

//简单介绍原理：
//通过将此处的this->ui传入函数中，才可修改程序中的数值、绑定程序中的按钮等部件
//也即此处的this->ui可理解为用于渲染界面的一个指针