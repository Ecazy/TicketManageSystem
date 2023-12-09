/********************************************************************************
** Form generated from reading UI file 'ticketmanagesystem.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKETMANAGESYSTEM_H
#define UI_TICKETMANAGESYSTEM_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TicketManageSystem
{
public:
    QTabWidget *TicketOperation;
    QWidget *ReserveTab;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *BookFlightIDComBox;
    QComboBox *BookClasscomboBox;
    QLabel *label;
    QPushButton *Reserve;
    QTableWidget *TicketsAvailable;
    QPushButton *Inquire;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *Conditions;
    QDateEdit *ConditionDate;
    QComboBox *ConditionStart;
    QComboBox *ConditionDestination;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *SortOperation;
    QPushButton *SortByPrice;
    QPushButton *SortByTime;
    QPushButton *RemoveNo;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *ChangeTab;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *BookFlightIDComBox_2;
    QComboBox *TargetClassComboBox;
    QPushButton *Change;
    QLabel *label_5;
    QTableWidget *ChangeMyTickets;
    QLabel *label_8;
    QTableWidget *ChangeTicketsAvailable;
    QLabel *label_10;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *Conditions_2;
    QDateEdit *ChangeConditionDate;
    QComboBox *ChangeConditionStart;
    QComboBox *ChangeConditionDestination;
    QPushButton *ChangeInquire;
    QComboBox *BookedFlightID;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QWidget *CancelTab;
    QComboBox *CancelMyTicketsComBox;
    QLabel *label_4;
    QPushButton *Cancel;
    QTableWidget *CancelMyTickets;
    QLabel *label_9;
    QLabel *name;

    void setupUi(QWidget *TicketManageSystem)
    {
        if (TicketManageSystem->objectName().isEmpty())
            TicketManageSystem->setObjectName("TicketManageSystem");
        TicketManageSystem->resize(978, 447);
        TicketOperation = new QTabWidget(TicketManageSystem);
        TicketOperation->setObjectName("TicketOperation");
        TicketOperation->setGeometry(QRect(10, 20, 911, 401));
        ReserveTab = new QWidget();
        ReserveTab->setObjectName("ReserveTab");
        horizontalLayoutWidget_4 = new QWidget(ReserveTab);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(510, 50, 231, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        BookFlightIDComBox = new QComboBox(horizontalLayoutWidget_4);
        BookFlightIDComBox->setObjectName("BookFlightIDComBox");

        horizontalLayout_2->addWidget(BookFlightIDComBox);

        BookClasscomboBox = new QComboBox(horizontalLayoutWidget_4);
        BookClasscomboBox->addItem(QString());
        BookClasscomboBox->addItem(QString());
        BookClasscomboBox->addItem(QString());
        BookClasscomboBox->setObjectName("BookClasscomboBox");

        horizontalLayout_2->addWidget(BookClasscomboBox);

        label = new QLabel(ReserveTab);
        label->setObjectName("label");
        label->setGeometry(QRect(510, 20, 72, 29));
        Reserve = new QPushButton(ReserveTab);
        Reserve->setObjectName("Reserve");
        Reserve->setGeometry(QRect(770, 50, 111, 31));
        TicketsAvailable = new QTableWidget(ReserveTab);
        if (TicketsAvailable->columnCount() < 10)
            TicketsAvailable->setColumnCount(10);
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
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        TicketsAvailable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        TicketsAvailable->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        TicketsAvailable->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        TicketsAvailable->setObjectName("TicketsAvailable");
        TicketsAvailable->setEnabled(true);
        TicketsAvailable->setGeometry(QRect(0, 130, 801, 241));
        TicketsAvailable->setShowGrid(true);
        Inquire = new QPushButton(ReserveTab);
        Inquire->setObjectName("Inquire");
        Inquire->setGeometry(QRect(370, 50, 89, 24));
        horizontalLayoutWidget = new QWidget(ReserveTab);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 40, 349, 49));
        Conditions = new QHBoxLayout(horizontalLayoutWidget);
        Conditions->setObjectName("Conditions");
        Conditions->setContentsMargins(0, 0, 0, 0);
        ConditionDate = new QDateEdit(horizontalLayoutWidget);
        ConditionDate->setObjectName("ConditionDate");
        ConditionDate->setDateTime(QDateTime(QDate(2023, 12, 9), QTime(16, 0, 0)));
        ConditionDate->setDate(QDate(2023, 12, 9));

        Conditions->addWidget(ConditionDate);

        ConditionStart = new QComboBox(horizontalLayoutWidget);
        ConditionStart->addItem(QString());
        ConditionStart->addItem(QString());
        ConditionStart->addItem(QString());
        ConditionStart->addItem(QString());
        ConditionStart->addItem(QString());
        ConditionStart->addItem(QString());
        ConditionStart->addItem(QString());
        ConditionStart->addItem(QString());
        ConditionStart->addItem(QString());
        ConditionStart->addItem(QString());
        ConditionStart->addItem(QString());
        ConditionStart->addItem(QString());
        ConditionStart->addItem(QString());
        ConditionStart->addItem(QString());
        ConditionStart->addItem(QString());
        ConditionStart->setObjectName("ConditionStart");

        Conditions->addWidget(ConditionStart);

        ConditionDestination = new QComboBox(horizontalLayoutWidget);
        ConditionDestination->addItem(QString());
        ConditionDestination->addItem(QString());
        ConditionDestination->addItem(QString());
        ConditionDestination->addItem(QString());
        ConditionDestination->addItem(QString());
        ConditionDestination->addItem(QString());
        ConditionDestination->addItem(QString());
        ConditionDestination->addItem(QString());
        ConditionDestination->addItem(QString());
        ConditionDestination->addItem(QString());
        ConditionDestination->addItem(QString());
        ConditionDestination->addItem(QString());
        ConditionDestination->addItem(QString());
        ConditionDestination->addItem(QString());
        ConditionDestination->addItem(QString());
        ConditionDestination->setObjectName("ConditionDestination");

        Conditions->addWidget(ConditionDestination);

        verticalLayoutWidget = new QWidget(ReserveTab);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(810, 140, 91, 111));
        SortOperation = new QVBoxLayout(verticalLayoutWidget);
        SortOperation->setObjectName("SortOperation");
        SortOperation->setContentsMargins(0, 0, 0, 0);
        SortByPrice = new QPushButton(verticalLayoutWidget);
        SortByPrice->setObjectName("SortByPrice");

        SortOperation->addWidget(SortByPrice);

        SortByTime = new QPushButton(verticalLayoutWidget);
        SortByTime->setObjectName("SortByTime");

        SortOperation->addWidget(SortByTime);

        RemoveNo = new QPushButton(verticalLayoutWidget);
        RemoveNo->setObjectName("RemoveNo");

        SortOperation->addWidget(RemoveNo);

        label_6 = new QLabel(ReserveTab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 110, 54, 16));
        label_7 = new QLabel(ReserveTab);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 20, 54, 16));
        label_11 = new QLabel(ReserveTab);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(120, 20, 54, 16));
        label_12 = new QLabel(ReserveTab);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(240, 20, 54, 16));
        TicketOperation->addTab(ReserveTab, QString());
        ChangeTab = new QWidget();
        ChangeTab->setObjectName("ChangeTab");
        label_2 = new QLabel(ChangeTab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(630, 230, 61, 16));
        horizontalLayoutWidget_5 = new QWidget(ChangeTab);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(530, 130, 171, 26));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(ChangeTab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(630, 290, 54, 16));
        horizontalLayoutWidget_6 = new QWidget(ChangeTab);
        horizontalLayoutWidget_6->setObjectName("horizontalLayoutWidget_6");
        horizontalLayoutWidget_6->setGeometry(QRect(630, 310, 281, 26));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        BookFlightIDComBox_2 = new QComboBox(horizontalLayoutWidget_6);
        BookFlightIDComBox_2->setObjectName("BookFlightIDComBox_2");

        horizontalLayout_4->addWidget(BookFlightIDComBox_2);

        TargetClassComboBox = new QComboBox(horizontalLayoutWidget_6);
        TargetClassComboBox->setObjectName("TargetClassComboBox");

        horizontalLayout_4->addWidget(TargetClassComboBox);

        Change = new QPushButton(ChangeTab);
        Change->setObjectName("Change");
        Change->setGeometry(QRect(820, 250, 81, 21));
        label_5 = new QLabel(ChangeTab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(790, 290, 54, 16));
        ChangeMyTickets = new QTableWidget(ChangeTab);
        if (ChangeMyTickets->columnCount() < 5)
            ChangeMyTickets->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        ChangeMyTickets->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        ChangeMyTickets->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        ChangeMyTickets->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        ChangeMyTickets->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        ChangeMyTickets->setHorizontalHeaderItem(4, __qtablewidgetitem14);
        ChangeMyTickets->setObjectName("ChangeMyTickets");
        ChangeMyTickets->setGeometry(QRect(10, 270, 501, 101));
        label_8 = new QLabel(ChangeTab);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 250, 54, 16));
        ChangeTicketsAvailable = new QTableWidget(ChangeTab);
        if (ChangeTicketsAvailable->columnCount() < 10)
            ChangeTicketsAvailable->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        ChangeTicketsAvailable->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        ChangeTicketsAvailable->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        ChangeTicketsAvailable->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        ChangeTicketsAvailable->setHorizontalHeaderItem(3, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        ChangeTicketsAvailable->setHorizontalHeaderItem(4, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        ChangeTicketsAvailable->setHorizontalHeaderItem(5, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        ChangeTicketsAvailable->setHorizontalHeaderItem(6, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        ChangeTicketsAvailable->setHorizontalHeaderItem(7, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        ChangeTicketsAvailable->setHorizontalHeaderItem(8, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        ChangeTicketsAvailable->setHorizontalHeaderItem(9, __qtablewidgetitem24);
        ChangeTicketsAvailable->setObjectName("ChangeTicketsAvailable");
        ChangeTicketsAvailable->setEnabled(true);
        ChangeTicketsAvailable->setGeometry(QRect(10, 70, 801, 141));
        ChangeTicketsAvailable->setShowGrid(true);
        label_10 = new QLabel(ChangeTab);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 50, 54, 16));
        horizontalLayoutWidget_2 = new QWidget(ChangeTab);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 349, 49));
        Conditions_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        Conditions_2->setObjectName("Conditions_2");
        Conditions_2->setContentsMargins(0, 0, 0, 0);
        ChangeConditionDate = new QDateEdit(horizontalLayoutWidget_2);
        ChangeConditionDate->setObjectName("ChangeConditionDate");
        ChangeConditionDate->setDateTime(QDateTime(QDate(2023, 12, 9), QTime(8, 0, 0)));
        ChangeConditionDate->setDate(QDate(2023, 12, 9));

        Conditions_2->addWidget(ChangeConditionDate);

        ChangeConditionStart = new QComboBox(horizontalLayoutWidget_2);
        ChangeConditionStart->addItem(QString());
        ChangeConditionStart->addItem(QString());
        ChangeConditionStart->addItem(QString());
        ChangeConditionStart->addItem(QString());
        ChangeConditionStart->addItem(QString());
        ChangeConditionStart->addItem(QString());
        ChangeConditionStart->addItem(QString());
        ChangeConditionStart->addItem(QString());
        ChangeConditionStart->addItem(QString());
        ChangeConditionStart->addItem(QString());
        ChangeConditionStart->addItem(QString());
        ChangeConditionStart->addItem(QString());
        ChangeConditionStart->addItem(QString());
        ChangeConditionStart->addItem(QString());
        ChangeConditionStart->addItem(QString());
        ChangeConditionStart->setObjectName("ChangeConditionStart");

        Conditions_2->addWidget(ChangeConditionStart);

        ChangeConditionDestination = new QComboBox(horizontalLayoutWidget_2);
        ChangeConditionDestination->addItem(QString());
        ChangeConditionDestination->addItem(QString());
        ChangeConditionDestination->addItem(QString());
        ChangeConditionDestination->addItem(QString());
        ChangeConditionDestination->addItem(QString());
        ChangeConditionDestination->addItem(QString());
        ChangeConditionDestination->addItem(QString());
        ChangeConditionDestination->addItem(QString());
        ChangeConditionDestination->addItem(QString());
        ChangeConditionDestination->addItem(QString());
        ChangeConditionDestination->addItem(QString());
        ChangeConditionDestination->addItem(QString());
        ChangeConditionDestination->addItem(QString());
        ChangeConditionDestination->addItem(QString());
        ChangeConditionDestination->addItem(QString());
        ChangeConditionDestination->setObjectName("ChangeConditionDestination");

        Conditions_2->addWidget(ChangeConditionDestination);

        ChangeInquire = new QPushButton(ChangeTab);
        ChangeInquire->setObjectName("ChangeInquire");
        ChangeInquire->setGeometry(QRect(460, 10, 89, 24));
        BookedFlightID = new QComboBox(ChangeTab);
        BookedFlightID->setObjectName("BookedFlightID");
        BookedFlightID->setGeometry(QRect(630, 250, 169, 24));
        label_13 = new QLabel(ChangeTab);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 0, 54, 16));
        label_14 = new QLabel(ChangeTab);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(130, 0, 54, 16));
        label_15 = new QLabel(ChangeTab);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(250, 0, 54, 16));
        TicketOperation->addTab(ChangeTab, QString());
        CancelTab = new QWidget();
        CancelTab->setObjectName("CancelTab");
        CancelMyTicketsComBox = new QComboBox(CancelTab);
        CancelMyTicketsComBox->setObjectName("CancelMyTicketsComBox");
        CancelMyTicketsComBox->setGeometry(QRect(10, 30, 141, 21));
        label_4 = new QLabel(CancelTab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 6, 71, 20));
        Cancel = new QPushButton(CancelTab);
        Cancel->setObjectName("Cancel");
        Cancel->setGeometry(QRect(180, 30, 111, 21));
        CancelMyTickets = new QTableWidget(CancelTab);
        if (CancelMyTickets->columnCount() < 5)
            CancelMyTickets->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        CancelMyTickets->setHorizontalHeaderItem(0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        CancelMyTickets->setHorizontalHeaderItem(1, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        CancelMyTickets->setHorizontalHeaderItem(2, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        CancelMyTickets->setHorizontalHeaderItem(3, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        CancelMyTickets->setHorizontalHeaderItem(4, __qtablewidgetitem29);
        CancelMyTickets->setObjectName("CancelMyTickets");
        CancelMyTickets->setGeometry(QRect(10, 100, 501, 91));
        label_9 = new QLabel(CancelTab);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 80, 54, 16));
        TicketOperation->addTab(CancelTab, QString());
        name = new QLabel(TicketManageSystem);
        name->setObjectName("name");
        name->setGeometry(QRect(530, 30, 54, 16));

        retranslateUi(TicketManageSystem);

        TicketOperation->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(TicketManageSystem);
    } // setupUi

    void retranslateUi(QWidget *TicketManageSystem)
    {
        TicketManageSystem->setWindowTitle(QCoreApplication::translate("TicketManageSystem", "ticketmanagementsystem", nullptr));
        BookClasscomboBox->setItemText(0, QCoreApplication::translate("TicketManageSystem", "\344\270\200\347\255\211\350\210\261", nullptr));
        BookClasscomboBox->setItemText(1, QCoreApplication::translate("TicketManageSystem", "\344\272\214\347\255\211\350\210\261", nullptr));
        BookClasscomboBox->setItemText(2, QCoreApplication::translate("TicketManageSystem", "\344\270\211\347\255\211\350\210\261", nullptr));

        label->setText(QCoreApplication::translate("TicketManageSystem", "\350\257\267\351\200\211\346\213\251\350\210\252\347\217\255\345\217\267", nullptr));
        Reserve->setText(QCoreApplication::translate("TicketManageSystem", "\350\256\242\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TicketsAvailable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TicketManageSystem", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TicketsAvailable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TicketManageSystem", "\350\265\267\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TicketsAvailable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TicketManageSystem", "\347\273\210\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = TicketsAvailable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("TicketManageSystem", "\350\210\252\347\217\255\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = TicketsAvailable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("TicketManageSystem", "\344\270\200\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = TicketsAvailable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("TicketManageSystem", "\344\272\214\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = TicketsAvailable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("TicketManageSystem", "\344\270\211\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = TicketsAvailable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("TicketManageSystem", "\344\270\200\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = TicketsAvailable->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("TicketManageSystem", "\344\272\214\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = TicketsAvailable->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("TicketManageSystem", "\344\270\211\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        Inquire->setText(QCoreApplication::translate("TicketManageSystem", "\346\237\245\350\257\242", nullptr));
        ConditionStart->setItemText(0, QCoreApplication::translate("TicketManageSystem", "\345\214\227\344\272\254", nullptr));
        ConditionStart->setItemText(1, QCoreApplication::translate("TicketManageSystem", "\344\270\212\346\265\267", nullptr));
        ConditionStart->setItemText(2, QCoreApplication::translate("TicketManageSystem", "\345\271\277\345\267\236", nullptr));
        ConditionStart->setItemText(3, QCoreApplication::translate("TicketManageSystem", "\346\267\261\345\234\263", nullptr));
        ConditionStart->setItemText(4, QCoreApplication::translate("TicketManageSystem", "\346\255\246\346\261\211", nullptr));
        ConditionStart->setItemText(5, QCoreApplication::translate("TicketManageSystem", "\346\210\220\351\203\275", nullptr));
        ConditionStart->setItemText(6, QCoreApplication::translate("TicketManageSystem", "\346\235\255\345\267\236", nullptr));
        ConditionStart->setItemText(7, QCoreApplication::translate("TicketManageSystem", "\351\207\215\345\272\206", nullptr));
        ConditionStart->setItemText(8, QCoreApplication::translate("TicketManageSystem", "\351\225\277\346\262\231", nullptr));
        ConditionStart->setItemText(9, QCoreApplication::translate("TicketManageSystem", "\350\245\277\345\256\211", nullptr));
        ConditionStart->setItemText(10, QCoreApplication::translate("TicketManageSystem", "\345\215\227\344\272\254", nullptr));
        ConditionStart->setItemText(11, QCoreApplication::translate("TicketManageSystem", "\345\215\227\346\230\214", nullptr));
        ConditionStart->setItemText(12, QCoreApplication::translate("TicketManageSystem", "\345\244\251\346\264\245", nullptr));
        ConditionStart->setItemText(13, QCoreApplication::translate("TicketManageSystem", "\351\203\221\345\267\236", nullptr));
        ConditionStart->setItemText(14, QCoreApplication::translate("TicketManageSystem", "\346\265\216\345\215\227", nullptr));

        ConditionDestination->setItemText(0, QCoreApplication::translate("TicketManageSystem", "\345\214\227\344\272\254", nullptr));
        ConditionDestination->setItemText(1, QCoreApplication::translate("TicketManageSystem", "\344\270\212\346\265\267", nullptr));
        ConditionDestination->setItemText(2, QCoreApplication::translate("TicketManageSystem", "\345\271\277\345\267\236", nullptr));
        ConditionDestination->setItemText(3, QCoreApplication::translate("TicketManageSystem", "\346\267\261\345\234\263", nullptr));
        ConditionDestination->setItemText(4, QCoreApplication::translate("TicketManageSystem", "\346\255\246\346\261\211", nullptr));
        ConditionDestination->setItemText(5, QCoreApplication::translate("TicketManageSystem", "\346\210\220\351\203\275", nullptr));
        ConditionDestination->setItemText(6, QCoreApplication::translate("TicketManageSystem", "\346\235\255\345\267\236", nullptr));
        ConditionDestination->setItemText(7, QCoreApplication::translate("TicketManageSystem", "\351\207\215\345\272\206", nullptr));
        ConditionDestination->setItemText(8, QCoreApplication::translate("TicketManageSystem", "\351\225\277\346\262\231", nullptr));
        ConditionDestination->setItemText(9, QCoreApplication::translate("TicketManageSystem", "\350\245\277\345\256\211", nullptr));
        ConditionDestination->setItemText(10, QCoreApplication::translate("TicketManageSystem", "\345\215\227\344\272\254", nullptr));
        ConditionDestination->setItemText(11, QCoreApplication::translate("TicketManageSystem", "\345\215\227\346\230\214", nullptr));
        ConditionDestination->setItemText(12, QCoreApplication::translate("TicketManageSystem", "\345\244\251\346\264\245", nullptr));
        ConditionDestination->setItemText(13, QCoreApplication::translate("TicketManageSystem", "\351\203\221\345\267\236", nullptr));
        ConditionDestination->setItemText(14, QCoreApplication::translate("TicketManageSystem", "\346\265\216\345\215\227", nullptr));

        SortByPrice->setText(QCoreApplication::translate("TicketManageSystem", "\346\214\211\344\273\267\346\240\274\346\216\222\345\272\217", nullptr));
        SortByTime->setText(QCoreApplication::translate("TicketManageSystem", "\346\214\211\346\227\266\351\227\264\346\216\222\345\272\217", nullptr));
        RemoveNo->setText(QCoreApplication::translate("TicketManageSystem", "\345\216\273\351\231\244\346\227\240\347\245\250\350\210\252\347\217\255", nullptr));
        label_6->setText(QCoreApplication::translate("TicketManageSystem", "\345\215\225\347\250\213\350\210\252\347\217\255", nullptr));
        label_7->setText(QCoreApplication::translate("TicketManageSystem", "\345\207\272\345\217\221\346\227\266\351\227\264", nullptr));
        label_11->setText(QCoreApplication::translate("TicketManageSystem", "\345\207\272\345\217\221\345\234\260", nullptr));
        label_12->setText(QCoreApplication::translate("TicketManageSystem", "\347\233\256\347\232\204\345\234\260", nullptr));
        TicketOperation->setTabText(TicketOperation->indexOf(ReserveTab), QCoreApplication::translate("TicketManageSystem", "\350\256\242\347\245\250", nullptr));
        label_2->setText(QCoreApplication::translate("TicketManageSystem", "\345\210\235\345\247\213\350\210\252\347\217\255\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("TicketManageSystem", "\346\226\260\350\210\252\347\217\255\345\217\267", nullptr));
        Change->setText(QCoreApplication::translate("TicketManageSystem", "\346\224\271\347\255\276", nullptr));
        label_5->setText(QCoreApplication::translate("TicketManageSystem", "\346\226\260\347\232\204\350\210\261\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = ChangeMyTickets->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("TicketManageSystem", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = ChangeMyTickets->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("TicketManageSystem", "\350\265\267\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = ChangeMyTickets->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("TicketManageSystem", "\347\273\210\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = ChangeMyTickets->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("TicketManageSystem", "\350\210\252\347\217\255\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = ChangeMyTickets->horizontalHeaderItem(4);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("TicketManageSystem", "\350\210\261\344\275\215", nullptr));
        label_8->setText(QCoreApplication::translate("TicketManageSystem", "\346\210\221\347\232\204\350\256\242\345\215\225", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = ChangeTicketsAvailable->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("TicketManageSystem", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = ChangeTicketsAvailable->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("TicketManageSystem", "\350\265\267\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = ChangeTicketsAvailable->horizontalHeaderItem(2);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("TicketManageSystem", "\347\273\210\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = ChangeTicketsAvailable->horizontalHeaderItem(3);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("TicketManageSystem", "\350\210\252\347\217\255\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = ChangeTicketsAvailable->horizontalHeaderItem(4);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("TicketManageSystem", "\344\270\200\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = ChangeTicketsAvailable->horizontalHeaderItem(5);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("TicketManageSystem", "\344\272\214\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = ChangeTicketsAvailable->horizontalHeaderItem(6);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("TicketManageSystem", "\344\270\211\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = ChangeTicketsAvailable->horizontalHeaderItem(7);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("TicketManageSystem", "\344\270\200\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = ChangeTicketsAvailable->horizontalHeaderItem(8);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("TicketManageSystem", "\344\272\214\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = ChangeTicketsAvailable->horizontalHeaderItem(9);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("TicketManageSystem", "\344\270\211\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        label_10->setText(QCoreApplication::translate("TicketManageSystem", "\347\233\256\347\232\204\350\210\252\347\217\255", nullptr));
        ChangeConditionStart->setItemText(0, QCoreApplication::translate("TicketManageSystem", "\345\214\227\344\272\254", nullptr));
        ChangeConditionStart->setItemText(1, QCoreApplication::translate("TicketManageSystem", "\344\270\212\346\265\267", nullptr));
        ChangeConditionStart->setItemText(2, QCoreApplication::translate("TicketManageSystem", "\345\271\277\345\267\236", nullptr));
        ChangeConditionStart->setItemText(3, QCoreApplication::translate("TicketManageSystem", "\346\267\261\345\234\263", nullptr));
        ChangeConditionStart->setItemText(4, QCoreApplication::translate("TicketManageSystem", "\346\255\246\346\261\211", nullptr));
        ChangeConditionStart->setItemText(5, QCoreApplication::translate("TicketManageSystem", "\346\210\220\351\203\275", nullptr));
        ChangeConditionStart->setItemText(6, QCoreApplication::translate("TicketManageSystem", "\346\235\255\345\267\236", nullptr));
        ChangeConditionStart->setItemText(7, QCoreApplication::translate("TicketManageSystem", "\351\207\215\345\272\206", nullptr));
        ChangeConditionStart->setItemText(8, QCoreApplication::translate("TicketManageSystem", "\351\225\277\346\262\231", nullptr));
        ChangeConditionStart->setItemText(9, QCoreApplication::translate("TicketManageSystem", "\350\245\277\345\256\211", nullptr));
        ChangeConditionStart->setItemText(10, QCoreApplication::translate("TicketManageSystem", "\345\215\227\344\272\254", nullptr));
        ChangeConditionStart->setItemText(11, QCoreApplication::translate("TicketManageSystem", "\345\215\227\346\230\214", nullptr));
        ChangeConditionStart->setItemText(12, QCoreApplication::translate("TicketManageSystem", "\345\244\251\346\264\245", nullptr));
        ChangeConditionStart->setItemText(13, QCoreApplication::translate("TicketManageSystem", "\351\203\221\345\267\236", nullptr));
        ChangeConditionStart->setItemText(14, QCoreApplication::translate("TicketManageSystem", "\346\265\216\345\215\227", nullptr));

        ChangeConditionDestination->setItemText(0, QCoreApplication::translate("TicketManageSystem", "\345\214\227\344\272\254", nullptr));
        ChangeConditionDestination->setItemText(1, QCoreApplication::translate("TicketManageSystem", "\344\270\212\346\265\267", nullptr));
        ChangeConditionDestination->setItemText(2, QCoreApplication::translate("TicketManageSystem", "\345\271\277\345\267\236", nullptr));
        ChangeConditionDestination->setItemText(3, QCoreApplication::translate("TicketManageSystem", "\346\267\261\345\234\263", nullptr));
        ChangeConditionDestination->setItemText(4, QCoreApplication::translate("TicketManageSystem", "\346\255\246\346\261\211", nullptr));
        ChangeConditionDestination->setItemText(5, QCoreApplication::translate("TicketManageSystem", "\346\210\220\351\203\275", nullptr));
        ChangeConditionDestination->setItemText(6, QCoreApplication::translate("TicketManageSystem", "\346\235\255\345\267\236", nullptr));
        ChangeConditionDestination->setItemText(7, QCoreApplication::translate("TicketManageSystem", "\351\207\215\345\272\206", nullptr));
        ChangeConditionDestination->setItemText(8, QCoreApplication::translate("TicketManageSystem", "\351\225\277\346\262\231", nullptr));
        ChangeConditionDestination->setItemText(9, QCoreApplication::translate("TicketManageSystem", "\350\245\277\345\256\211", nullptr));
        ChangeConditionDestination->setItemText(10, QCoreApplication::translate("TicketManageSystem", "\345\215\227\344\272\254", nullptr));
        ChangeConditionDestination->setItemText(11, QCoreApplication::translate("TicketManageSystem", "\345\215\227\346\230\214", nullptr));
        ChangeConditionDestination->setItemText(12, QCoreApplication::translate("TicketManageSystem", "\345\244\251\346\264\245", nullptr));
        ChangeConditionDestination->setItemText(13, QCoreApplication::translate("TicketManageSystem", "\351\203\221\345\267\236", nullptr));
        ChangeConditionDestination->setItemText(14, QCoreApplication::translate("TicketManageSystem", "\346\265\216\345\215\227", nullptr));

        ChangeInquire->setText(QCoreApplication::translate("TicketManageSystem", "\346\237\245\350\257\242", nullptr));
        label_13->setText(QCoreApplication::translate("TicketManageSystem", "\345\207\272\345\217\221\346\227\266\351\227\264", nullptr));
        label_14->setText(QCoreApplication::translate("TicketManageSystem", "\345\207\272\345\217\221\345\234\260", nullptr));
        label_15->setText(QCoreApplication::translate("TicketManageSystem", "\347\233\256\347\232\204\345\234\260", nullptr));
        TicketOperation->setTabText(TicketOperation->indexOf(ChangeTab), QCoreApplication::translate("TicketManageSystem", "\346\224\271\347\255\276", nullptr));
        label_4->setText(QCoreApplication::translate("TicketManageSystem", "\351\200\200\347\245\250\350\210\252\347\217\255\345\217\267", nullptr));
        Cancel->setText(QCoreApplication::translate("TicketManageSystem", "\351\200\200\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = CancelMyTickets->horizontalHeaderItem(0);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("TicketManageSystem", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = CancelMyTickets->horizontalHeaderItem(1);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("TicketManageSystem", "\350\265\267\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = CancelMyTickets->horizontalHeaderItem(2);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("TicketManageSystem", "\347\273\210\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = CancelMyTickets->horizontalHeaderItem(3);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("TicketManageSystem", "\350\210\252\347\217\255\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = CancelMyTickets->horizontalHeaderItem(4);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("TicketManageSystem", "\350\210\261\344\275\215", nullptr));
        label_9->setText(QCoreApplication::translate("TicketManageSystem", "\346\210\221\347\232\204\350\256\242\345\215\225", nullptr));
        TicketOperation->setTabText(TicketOperation->indexOf(CancelTab), QCoreApplication::translate("TicketManageSystem", "\351\200\200\347\245\250", nullptr));
        name->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TicketManageSystem: public Ui_TicketManageSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKETMANAGESYSTEM_H
