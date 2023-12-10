#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>
#include "function.h"

namespace Ui {
class Admin;
}

class Admin : public QWidget
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_Inquire_clicked();

    void on_InquireByTime_clicked();

    void on_InquireByPlace_clicked();

    void on_ADD_clicked();

    void on_DeleteInquire_clicked();

    void on_Delete_clicked();

    void on_ChangeInquire_clicked();

    void on_Change_clicked();

    void on_SortByPrice_clicked();

    void on_SortByTime_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
