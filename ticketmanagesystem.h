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

private:
    Ui::TicketManageSystem *ui;

    void Inquire();
};

#endif // TICKETMANAGESYSTEM_H
