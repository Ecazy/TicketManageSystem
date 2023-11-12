/********************************************************************************
** Form generated from reading UI file 'ticketmanagesystem.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKETMANAGESYSTEM_H
#define UI_TICKETMANAGESYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TicketManageSystem {
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TicketManageSystem) {
        if (TicketManageSystem->objectName().isEmpty())
            TicketManageSystem->setObjectName("TicketManageSystem");
        TicketManageSystem->resize(800, 600);
        centralwidget = new QWidget(TicketManageSystem);
        centralwidget->setObjectName("centralwidget");
        TicketManageSystem->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TicketManageSystem);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        TicketManageSystem->setMenuBar(menubar);
        statusbar = new QStatusBar(TicketManageSystem);
        statusbar->setObjectName("statusbar");
        TicketManageSystem->setStatusBar(statusbar);

        retranslateUi(TicketManageSystem);

        QMetaObject::connectSlotsByName(TicketManageSystem);
    } // setupUi

    void retranslateUi(QMainWindow *TicketManageSystem) {
        TicketManageSystem->setWindowTitle(
                QCoreApplication::translate("TicketManageSystem", "TicketManageSystem", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TicketManageSystem : public Ui_TicketManageSystem {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKETMANAGESYSTEM_H
