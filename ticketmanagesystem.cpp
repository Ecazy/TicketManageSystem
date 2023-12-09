#include "ticketmanagesystem.h"
#include <QMessageBox>
//#include "ui_ticketmanagesystem.h"
#include <QObject>

TicketManageSystem::TicketManageSystem(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::TicketManageSystem) {
    ui->setupUi(this);

    QDateEdit* dateEdit = ui->ConditionDate;
    QCalendarWidget *calendarWidget = ui->calendarWidget;

    ui->name->setText(QString::fromStdString(usrName));
    //禁用表格更改
    ui->TicketsAvailable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->MyTickets->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //关联组件
    QObject::connect(dateEdit,&QDateEdit::dateChanged,calendarWidget,&QCalendarWidget::setSelectedDate);
    QObject::connect(calendarWidget, &QCalendarWidget::selectionChanged, [dateEdit, calendarWidget]() {
        dateEdit->setDate(calendarWidget->selectedDate());
    });
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
    ErrorFeedback(BookTicket(this->ui,usrName));

    qDebug() << "Reserve";
}


void TicketManageSystem::on_Change_clicked() {
    ErrorFeedback(ChangeTicket(this->ui,usrName));

    qDebug() << "Change";
}

void TicketManageSystem::on_Cancel_clicked() {
    ErrorFeedback(CancelTicket(this->ui,usrName));

    qDebug() << "Cancel";
}

void TicketManageSystem::ErrorFeedback(ERROR_TYPE et) {
    switch (et) {
        case SUCCESS:
            break;
        case BOOK_FAILURE:
            QMessageBox::warning(this, "错误", "订票失败");
            break;
        case CANCEL_FAILURE:
            QMessageBox::warning(this, "错误", "退票失败");
            break;
        case CHANGE_FAILURE:
            QMessageBox::warning(this, "错误", "改签失败");
            break;
        default:
            QMessageBox::warning(this,"错误","未知错误");
            break;
    }
    return;
}


//简单介绍原理：
//通过将此处的this->ui传入函数中，才可修改程序中的数值、绑定程序中的按钮等部件
//也即此处的this->ui可理解为用于渲染界面的一个指针