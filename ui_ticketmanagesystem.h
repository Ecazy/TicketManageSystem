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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TicketManageSystem {
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *Conditions;
    QDateEdit *ConditionDate;
    QComboBox *ConditionStart;
    QComboBox *ConditionDestination;
    QTableWidget *TicketsAvailable;
    QTableWidget *MyTickets;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *SortOperation;
    QPushButton *SortByPrice;
    QPushButton *SortByTime;
    QPushButton *RemoveNo;
    QTabWidget *TicketOperation;
    QWidget *ReserveTab;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *BookFlightIDComBox;
    QComboBox *BookClasscomboBox;
    QLabel *label;
    QPushButton *Reserve;
    QWidget *CancelTab;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *BookedFlightID;
    QLabel *label_3;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *BookFlightIDComBox_2;
    QComboBox *TargetClassComboBox;
    QPushButton *Change;
    QLabel *label_5;
    QWidget *ChangeTab;
    QComboBox *CancelMyTicketsComBox;
    QLabel *label_4;
    QPushButton *Cancel;
    QPushButton *Inquire;

    void setupUi(QWidget *TicketManageSystem) {
        if (TicketManageSystem->objectName().isEmpty())
            TicketManageSystem->setObjectName("TicketManageSystem");
        TicketManageSystem->resize(671, 376);
        horizontalLayoutWidget = new QWidget(TicketManageSystem);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 291, 41));
        Conditions = new QHBoxLayout(horizontalLayoutWidget);
        Conditions->setObjectName("Conditions");
        Conditions->setContentsMargins(0, 0, 0, 0);
        ConditionDate = new QDateEdit(horizontalLayoutWidget);
        ConditionDate->setObjectName("ConditionDate");
        ConditionDate->setDateTime(QDateTime(QDate(2023, 11, 25), QTime(0, 0, 0)));

        Conditions->addWidget(ConditionDate);

        ConditionStart = new QComboBox(horizontalLayoutWidget);
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
        ConditionDestination->setObjectName("ConditionDestination");

        Conditions->addWidget(ConditionDestination);

        TicketsAvailable = new QTableWidget(TicketManageSystem);
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
        MyTickets = new QTableWidget(TicketManageSystem);
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
        verticalLayoutWidget = new QWidget(TicketManageSystem);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(560, 90, 91, 111));
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

        TicketOperation = new QTabWidget(TicketManageSystem);
        TicketOperation->setObjectName("TicketOperation");
        TicketOperation->setGeometry(QRect(350, 230, 301, 131));
        ReserveTab = new QWidget();
        ReserveTab->setObjectName("ReserveTab");
        horizontalLayoutWidget_4 = new QWidget(ReserveTab);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(10, 10, 231, 31));
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
        label->setGeometry(QRect(10, -10, 72, 29));
        Reserve = new QPushButton(ReserveTab);
        Reserve->setObjectName("Reserve");
        Reserve->setGeometry(QRect(90, 50, 111, 31));
        TicketOperation->addTab(ReserveTab, QString());
        CancelTab = new QWidget();
        CancelTab->setObjectName("CancelTab");
        label_2 = new QLabel(CancelTab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 61, 16));
        horizontalLayoutWidget_5 = new QWidget(CancelTab);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(0, 20, 171, 26));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        BookedFlightID = new QComboBox(horizontalLayoutWidget_5);
        BookedFlightID->setObjectName("BookedFlightID");

        horizontalLayout_3->addWidget(BookedFlightID);

        label_3 = new QLabel(CancelTab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 50, 54, 16));
        horizontalLayoutWidget_6 = new QWidget(CancelTab);
        horizontalLayoutWidget_6->setObjectName("horizontalLayoutWidget_6");
        horizontalLayoutWidget_6->setGeometry(QRect(0, 70, 281, 26));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        BookFlightIDComBox_2 = new QComboBox(horizontalLayoutWidget_6);
        BookFlightIDComBox_2->setObjectName("BookFlightIDComBox_2");

        horizontalLayout_4->addWidget(BookFlightIDComBox_2);

        TargetClassComboBox = new QComboBox(horizontalLayoutWidget_6);
        TargetClassComboBox->setObjectName("TargetClassComboBox");

        horizontalLayout_4->addWidget(TargetClassComboBox);

        Change = new QPushButton(CancelTab);
        Change->setObjectName("Change");
        Change->setGeometry(QRect(200, 20, 81, 21));
        label_5 = new QLabel(CancelTab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(150, 50, 54, 16));
        TicketOperation->addTab(CancelTab, QString());
        ChangeTab = new QWidget();
        ChangeTab->setObjectName("ChangeTab");
        CancelMyTicketsComBox = new QComboBox(ChangeTab);
        CancelMyTicketsComBox->setObjectName("CancelMyTicketsComBox");
        CancelMyTicketsComBox->setGeometry(QRect(10, 30, 141, 21));
        label_4 = new QLabel(ChangeTab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 6, 71, 20));
        Cancel = new QPushButton(ChangeTab);
        Cancel->setObjectName("Cancel");
        Cancel->setGeometry(QRect(180, 30, 111, 21));
        TicketOperation->addTab(ChangeTab, QString());
        Inquire = new QPushButton(TicketManageSystem);
        Inquire->setObjectName("Inquire");
        Inquire->setGeometry(QRect(380, 30, 89, 24));

        retranslateUi(TicketManageSystem);

        TicketOperation->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(TicketManageSystem);
    } // setupUi

    void retranslateUi(QWidget *TicketManageSystem) {
        TicketManageSystem->setWindowTitle(
                QCoreApplication::translate("TicketManageSystem", "ticketmanagementsystem", nullptr));
        ConditionStart->setItemText(0, QCoreApplication::translate("TicketManageSystem", "\345\214\227\344\272\254",
                                                                   nullptr));
        ConditionStart->setItemText(1, QCoreApplication::translate("TicketManageSystem", "\344\270\212\346\265\267",
                                                                   nullptr));
        ConditionStart->setItemText(2, QCoreApplication::translate("TicketManageSystem", "\345\271\277\345\267\236",
                                                                   nullptr));
        ConditionStart->setItemText(3, QCoreApplication::translate("TicketManageSystem", "\346\267\261\345\234\263",
                                                                   nullptr));
        ConditionStart->setItemText(4, QCoreApplication::translate("TicketManageSystem", "\346\255\246\346\261\211",
                                                                   nullptr));

        ConditionDestination->setItemText(0,
                                          QCoreApplication::translate("TicketManageSystem", "\345\214\227\344\272\254",
                                                                      nullptr));
        ConditionDestination->setItemText(1,
                                          QCoreApplication::translate("TicketManageSystem", "\344\270\212\346\265\267",
                                                                      nullptr));
        ConditionDestination->setItemText(2,
                                          QCoreApplication::translate("TicketManageSystem", "\345\271\277\345\267\236",
                                                                      nullptr));
        ConditionDestination->setItemText(3,
                                          QCoreApplication::translate("TicketManageSystem", "\346\267\261\345\234\263",
                                                                      nullptr));
        ConditionDestination->setItemText(4,
                                          QCoreApplication::translate("TicketManageSystem", "\346\255\246\346\261\211",
                                                                      nullptr));

        QTableWidgetItem *___qtablewidgetitem = TicketsAvailable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(
                QCoreApplication::translate("TicketManageSystem", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TicketsAvailable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(
                QCoreApplication::translate("TicketManageSystem", "\350\265\267\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TicketsAvailable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(
                QCoreApplication::translate("TicketManageSystem", "\347\273\210\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = TicketsAvailable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(
                QCoreApplication::translate("TicketManageSystem", "\350\210\252\347\217\255\346\227\266\351\227\264",
                                            nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = TicketsAvailable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("TicketManageSystem",
                                                                  "\344\270\200\347\255\211\350\210\261\344\275\231\347\245\250",
                                                                  nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = TicketsAvailable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("TicketManageSystem",
                                                                  "\344\272\214\347\255\211\350\210\261\344\275\231\347\245\250",
                                                                  nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = TicketsAvailable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("TicketManageSystem",
                                                                  "\344\270\211\347\255\211\350\210\261\344\275\231\347\245\250",
                                                                  nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = MyTickets->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(
                QCoreApplication::translate("TicketManageSystem", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = MyTickets->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(
                QCoreApplication::translate("TicketManageSystem", "\350\210\252\347\217\255\346\227\266\351\227\264",
                                            nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = MyTickets->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(
                QCoreApplication::translate("TicketManageSystem", "\350\210\261\344\275\215", nullptr));
        SortByPrice->setText(QCoreApplication::translate("TicketManageSystem",
                                                         "\346\214\211\344\273\267\346\240\274\346\216\222\345\272\217",
                                                         nullptr));
        SortByTime->setText(QCoreApplication::translate("TicketManageSystem",
                                                        "\346\214\211\346\227\266\351\227\264\346\216\222\345\272\217",
                                                        nullptr));
        RemoveNo->setText(QCoreApplication::translate("TicketManageSystem",
                                                      "\345\216\273\351\231\244\346\227\240\347\245\250\350\210\252\347\217\255",
                                                      nullptr));
        BookClasscomboBox->setItemText(0, QCoreApplication::translate("TicketManageSystem",
                                                                      "\344\270\200\347\255\211\350\210\261", nullptr));
        BookClasscomboBox->setItemText(1, QCoreApplication::translate("TicketManageSystem",
                                                                      "\344\272\214\347\255\211\350\210\261", nullptr));
        BookClasscomboBox->setItemText(2, QCoreApplication::translate("TicketManageSystem",
                                                                      "\344\270\211\347\255\211\350\210\261", nullptr));

        label->setText(QCoreApplication::translate("TicketManageSystem",
                                                   "\350\257\267\351\200\211\346\213\251\350\210\252\347\217\255\345\217\267",
                                                   nullptr));
        Reserve->setText(QCoreApplication::translate("TicketManageSystem", "\350\256\242\347\245\250", nullptr));
        TicketOperation->setTabText(TicketOperation->indexOf(ReserveTab),
                                    QCoreApplication::translate("TicketManageSystem", "\350\256\242\347\245\250",
                                                                nullptr));
        label_2->setText(QCoreApplication::translate("TicketManageSystem",
                                                     "\345\210\235\345\247\213\350\210\252\347\217\255\345\217\267",
                                                     nullptr));
        label_3->setText(
                QCoreApplication::translate("TicketManageSystem", "\346\226\260\350\210\252\347\217\255\345\217\267",
                                            nullptr));
        Change->setText(QCoreApplication::translate("TicketManageSystem", "\346\224\271\347\255\276", nullptr));
        label_5->setText(
                QCoreApplication::translate("TicketManageSystem", "\346\226\260\347\232\204\350\210\261\344\275\215",
                                            nullptr));
        TicketOperation->setTabText(TicketOperation->indexOf(CancelTab),
                                    QCoreApplication::translate("TicketManageSystem", "\346\224\271\347\255\276",
                                                                nullptr));
        label_4->setText(QCoreApplication::translate("TicketManageSystem",
                                                     "\351\200\200\347\245\250\350\210\252\347\217\255\345\217\267",
                                                     nullptr));
        Cancel->setText(QCoreApplication::translate("TicketManageSystem", "\351\200\200\347\245\250", nullptr));
        TicketOperation->setTabText(TicketOperation->indexOf(ChangeTab),
                                    QCoreApplication::translate("TicketManageSystem", "\351\200\200\347\245\250",
                                                                nullptr));
        Inquire->setText(QCoreApplication::translate("TicketManageSystem", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TicketManageSystem : public Ui_TicketManageSystem {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKETMANAGESYSTEM_H
