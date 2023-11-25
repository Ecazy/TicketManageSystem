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

void TicketManageSystem::Inquire() {
    QMessageBox::information(this, tr("Information"), tr("Open"));
}

