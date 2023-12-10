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

    void set_name(const string name){ usrName = name;}

    string& get_name(){return usrName;}

    void ErrorFeedback(ERROR_TYPE);


private slots:
    void on_Inquire_clicked();

    void on_SortByPrice_clicked();

    void on_SortByTime_clicked();

    void on_RemoveNo_clicked();

    void on_Reserve_clicked();

    void on_Change_clicked();

    void on_Cancel_clicked();

    void on_ChangeInquire_clicked();
private:
    string usrName;
    Ui::TicketManageSystem *ui;

};

#endif // TICKETMANAGESYSTEM_H
