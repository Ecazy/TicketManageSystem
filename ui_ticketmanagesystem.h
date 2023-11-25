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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ticketmanagementsystem
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *Conditions;
    QDateEdit *ConditionDate;
    QComboBox *ConditionStart;
    QComboBox *ConditionDestination;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *TicketFuction;
    QPushButton *Inquire;
    QPushButton *Reserve;
    QPushButton *Cancel;
    QPushButton *Change;
    QTableWidget *TicketsAvailable;
    QTableWidget *MyTickets;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *SortByPrice;
    QPushButton *SortByTime;
    QPushButton *pushButton_3;

    void setupUi(QWidget *ticketmanagementsystem)
    {
        if (ticketmanagementsystem->objectName().isEmpty())
            ticketmanagementsystem->setObjectName("ticketmanagementsystem");
        ticketmanagementsystem->resize(671, 376);
        horizontalLayoutWidget = new QWidget(ticketmanagementsystem);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 291, 41));
        Conditions = new QHBoxLayout(horizontalLayoutWidget);
        Conditions->setObjectName("Conditions");
        Conditions->setContentsMargins(0, 0, 0, 0);
        ConditionDate = new QDateEdit(horizontalLayoutWidget);
        ConditionDate->setObjectName("ConditionDate");

        Conditions->addWidget(ConditionDate);

        ConditionStart = new QComboBox(horizontalLayoutWidget);
        ConditionStart->addItem(QString());
        ConditionStart->addItem(QString());
        ConditionStart->setObjectName("ConditionStart");

        Conditions->addWidget(ConditionStart);

        ConditionDestination = new QComboBox(horizontalLayoutWidget);
        ConditionDestination->addItem(QString());
        ConditionDestination->addItem(QString());
        ConditionDestination->addItem(QString());
        ConditionDestination->setObjectName("ConditionDestination");

        Conditions->addWidget(ConditionDestination);

        horizontalLayoutWidget_2 = new QWidget(ticketmanagementsystem);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(310, 30, 351, 31));
        TicketFuction = new QHBoxLayout(horizontalLayoutWidget_2);
        TicketFuction->setObjectName("TicketFuction");
        TicketFuction->setContentsMargins(0, 0, 0, 0);
        Inquire = new QPushButton(horizontalLayoutWidget_2);
        Inquire->setObjectName("Inquire");

        TicketFuction->addWidget(Inquire);

        Reserve = new QPushButton(horizontalLayoutWidget_2);
        Reserve->setObjectName("Reserve");

        TicketFuction->addWidget(Reserve);

        Cancel = new QPushButton(horizontalLayoutWidget_2);
        Cancel->setObjectName("Cancel");

        TicketFuction->addWidget(Cancel);

        Change = new QPushButton(horizontalLayoutWidget_2);
        Change->setObjectName("Change");

        TicketFuction->addWidget(Change);

        TicketsAvailable = new QTableWidget(ticketmanagementsystem);
        if (TicketsAvailable->columnCount() < 7)
            TicketsAvailable->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TicketsAvailable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TicketsAvailable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TicketsAvailable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TicketsAvailable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        TicketsAvailable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        TicketsAvailable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        TicketsAvailable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        TicketsAvailable->setObjectName("TicketsAvailable");
        TicketsAvailable->setEnabled(true);
        TicketsAvailable->setGeometry(QRect(10, 80, 511, 141));
        TicketsAvailable->setShowGrid(true);
        MyTickets = new QTableWidget(ticketmanagementsystem);
        if (MyTickets->columnCount() < 3)
            MyTickets->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        MyTickets->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        MyTickets->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        MyTickets->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        MyTickets->setObjectName("MyTickets");
        MyTickets->setGeometry(QRect(10, 251, 311, 101));
        verticalLayoutWidget = new QWidget(ticketmanagementsystem);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(560, 90, 91, 111));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        SortByPrice = new QPushButton(verticalLayoutWidget);
        SortByPrice->setObjectName("SortByPrice");

        verticalLayout->addWidget(SortByPrice);

        SortByTime = new QPushButton(verticalLayoutWidget);
        SortByTime->setObjectName("SortByTime");

        verticalLayout->addWidget(SortByTime);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);


        retranslateUi(ticketmanagementsystem);

        QMetaObject::connectSlotsByName(ticketmanagementsystem);
    } // setupUi

    void retranslateUi(QWidget *ticketmanagementsystem)
    {
        ticketmanagementsystem->setWindowTitle(QCoreApplication::translate("ticketmanagementsystem", "ticketmanagementsystem", nullptr));
        ConditionStart->setItemText(0, QCoreApplication::translate("ticketmanagementsystem", "\350\265\267\347\202\2711", nullptr));
        ConditionStart->setItemText(1, QCoreApplication::translate("ticketmanagementsystem", "\350\265\267\347\202\2712", nullptr));

        ConditionDestination->setItemText(0, QCoreApplication::translate("ticketmanagementsystem", "\347\273\210\347\202\2711", nullptr));
        ConditionDestination->setItemText(1, QCoreApplication::translate("ticketmanagementsystem", "\347\273\210\347\202\2712", nullptr));
        ConditionDestination->setItemText(2, QCoreApplication::translate("ticketmanagementsystem", "\347\273\210\347\202\2713", nullptr));

        Inquire->setText(QCoreApplication::translate("ticketmanagementsystem", "\346\237\245\350\257\242", nullptr));
        Reserve->setText(QCoreApplication::translate("ticketmanagementsystem", "\350\256\242\347\245\250", nullptr));
        Cancel->setText(QCoreApplication::translate("ticketmanagementsystem", "\351\200\200\347\245\250", nullptr));
        Change->setText(QCoreApplication::translate("ticketmanagementsystem", "\346\224\271\347\255\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TicketsAvailable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ticketmanagementsystem", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TicketsAvailable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ticketmanagementsystem", "\350\265\267\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TicketsAvailable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ticketmanagementsystem", "\347\273\210\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = TicketsAvailable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ticketmanagementsystem", "\350\210\252\347\217\255\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = TicketsAvailable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ticketmanagementsystem", "\344\270\200\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = TicketsAvailable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ticketmanagementsystem", "\344\272\214\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = TicketsAvailable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ticketmanagementsystem", "\344\270\211\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = MyTickets->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("ticketmanagementsystem", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = MyTickets->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("ticketmanagementsystem", "\350\210\252\347\217\255\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = MyTickets->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("ticketmanagementsystem", "\350\210\261\344\275\215", nullptr));
        SortByPrice->setText(QCoreApplication::translate("ticketmanagementsystem", "\346\214\211\344\273\267\346\240\274\346\216\222\345\272\217", nullptr));
        SortByTime->setText(QCoreApplication::translate("ticketmanagementsystem", "\346\214\211\346\227\266\351\227\264\346\216\222\345\272\217", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ticketmanagementsystem", "\345\216\273\351\231\244\346\227\240\347\245\250\350\210\252\347\217\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ticketmanagementsystem: public Ui_ticketmanagementsystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKETMANAGESYSTEM_H
