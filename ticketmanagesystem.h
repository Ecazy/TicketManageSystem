#ifndef TICKETMANAGESYSTEM_H
#define TICKETMANAGESYSTEM_H

#include <QMainWindow>
#include "function.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TicketManageSystem; }
QT_END_NAMESPACE

class TicketManageSystem : public QMainWindow {
Q_OBJECT

private:
    string user_name;

public:
    TicketManageSystem(QWidget *parent = nullptr);

    ~TicketManageSystem();

    Linklist<passengerInfo> my_tickets;

    void set_name(string name) {
        user_name = name;
    }

    void set_tickets() {
        my_tickets = get_my_tickets(user_name);
    }

private slots:

    void on_Inquire_clicked();

    void on_SortByPrice_clicked();

    void on_SortByTime_clicked();

    void on_RemoveNo_clicked();

    void on_Reserve_clicked();

    void on_Change_clicked();

    void on_Cancel_clicked();

private:
    Ui::TicketManageSystem *ui;

};

#endif // TICKETMANAGESYSTEM_H
