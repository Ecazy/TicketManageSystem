#ifndef TICKETMANAGESYSTEM_H
#define TICKETMANAGESYSTEM_H

#include <QMainWindow>
#include "function.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TicketManageSystem; }
QT_END_NAMESPACE

class TicketManageSystem : public QMainWindow {
Q_OBJECT

public:
    TicketManageSystem(QWidget *parent = nullptr);

    ~TicketManageSystem();


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
