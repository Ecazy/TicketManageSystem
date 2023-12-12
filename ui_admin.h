/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QTableWidget *TicketsTable;
    QTabWidget *tabWidget_2;
    QWidget *tab_5;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QDateEdit *DateFilter;
    QComboBox *StartFilter;
    QComboBox *EndFilter;
    QPushButton *Inquire;
    QWidget *tab_6;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QDateEdit *DateFilterByTime;
    QPushButton *InquireByTime;
    QWidget *tab_7;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QComboBox *StartFilterByPlace;
    QComboBox *EndFilterByPlace;
    QPushButton *InquireByPlace;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *SortByPrice;
    QPushButton *SortByTime;
    QWidget *tab;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QDateEdit *AddTimeSet;
    QTimeEdit *AddTime;
    QComboBox *AddStart;
    QComboBox *AddEnd;
    QLineEdit *AddFlightID;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTableWidget *TicketsInfoTable;
    QPushButton *ADD;
    QWidget *tab_2;
    QLabel *label_5;
    QLineEdit *DeleteFlightID;
    QTableWidget *DeleteTicketsTable;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *DeleteInquire;
    QPushButton *Delete;
    QWidget *tab_3;
    QLineEdit *ChangeFlightID;
    QLabel *label_6;
    QTableWidget *ChangeTicketsTable;
    QDateTimeEdit *ChangeTimeSet;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *ChangeInquire;
    QPushButton *Change;
    QLabel *label_7;
    QPushButton *Exit;

    void setupUi(QWidget *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName("Admin");
        Admin->resize(1078, 411);
        tabWidget = new QTabWidget(Admin);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 30, 1081, 381));
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        TicketsTable = new QTableWidget(tab_4);
        if (TicketsTable->columnCount() < 10)
            TicketsTable->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TicketsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TicketsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TicketsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TicketsTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        TicketsTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        TicketsTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        TicketsTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        TicketsTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        TicketsTable->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        TicketsTable->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        TicketsTable->setObjectName("TicketsTable");
        TicketsTable->setGeometry(QRect(0, 120, 1041, 231));
        tabWidget_2 = new QTabWidget(tab_4);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(0, 30, 531, 91));
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        horizontalLayoutWidget = new QWidget(tab_5);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 501, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        DateFilter = new QDateEdit(horizontalLayoutWidget);
        DateFilter->setObjectName("DateFilter");
        DateFilter->setDate(QDate(2023, 12, 10));

        horizontalLayout->addWidget(DateFilter);

        StartFilter = new QComboBox(horizontalLayoutWidget);
        StartFilter->addItem(QString());
        StartFilter->addItem(QString());
        StartFilter->addItem(QString());
        StartFilter->addItem(QString());
        StartFilter->addItem(QString());
        StartFilter->addItem(QString());
        StartFilter->addItem(QString());
        StartFilter->addItem(QString());
        StartFilter->addItem(QString());
        StartFilter->addItem(QString());
        StartFilter->addItem(QString());
        StartFilter->addItem(QString());
        StartFilter->addItem(QString());
        StartFilter->addItem(QString());
        StartFilter->addItem(QString());
        StartFilter->setObjectName("StartFilter");

        horizontalLayout->addWidget(StartFilter);

        EndFilter = new QComboBox(horizontalLayoutWidget);
        EndFilter->addItem(QString());
        EndFilter->addItem(QString());
        EndFilter->addItem(QString());
        EndFilter->addItem(QString());
        EndFilter->addItem(QString());
        EndFilter->addItem(QString());
        EndFilter->addItem(QString());
        EndFilter->addItem(QString());
        EndFilter->addItem(QString());
        EndFilter->addItem(QString());
        EndFilter->addItem(QString());
        EndFilter->addItem(QString());
        EndFilter->addItem(QString());
        EndFilter->addItem(QString());
        EndFilter->addItem(QString());
        EndFilter->setObjectName("EndFilter");

        horizontalLayout->addWidget(EndFilter);

        Inquire = new QPushButton(horizontalLayoutWidget);
        Inquire->setObjectName("Inquire");
        Inquire->setBaseSize(QSize(6, 0));

        horizontalLayout->addWidget(Inquire);

        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        horizontalLayoutWidget_5 = new QWidget(tab_6);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(50, 10, 261, 51));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        DateFilterByTime = new QDateEdit(horizontalLayoutWidget_5);
        DateFilterByTime->setObjectName("DateFilterByTime");
        DateFilterByTime->setDate(QDate(2023, 12, 10));

        horizontalLayout_5->addWidget(DateFilterByTime);

        InquireByTime = new QPushButton(horizontalLayoutWidget_5);
        InquireByTime->setObjectName("InquireByTime");
        InquireByTime->setBaseSize(QSize(6, 0));

        horizontalLayout_5->addWidget(InquireByTime);

        tabWidget_2->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        horizontalLayoutWidget_6 = new QWidget(tab_7);
        horizontalLayoutWidget_6->setObjectName("horizontalLayoutWidget_6");
        horizontalLayoutWidget_6->setGeometry(QRect(10, 10, 501, 41));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        StartFilterByPlace = new QComboBox(horizontalLayoutWidget_6);
        StartFilterByPlace->addItem(QString());
        StartFilterByPlace->addItem(QString());
        StartFilterByPlace->addItem(QString());
        StartFilterByPlace->addItem(QString());
        StartFilterByPlace->addItem(QString());
        StartFilterByPlace->addItem(QString());
        StartFilterByPlace->addItem(QString());
        StartFilterByPlace->addItem(QString());
        StartFilterByPlace->addItem(QString());
        StartFilterByPlace->addItem(QString());
        StartFilterByPlace->addItem(QString());
        StartFilterByPlace->addItem(QString());
        StartFilterByPlace->addItem(QString());
        StartFilterByPlace->addItem(QString());
        StartFilterByPlace->addItem(QString());
        StartFilterByPlace->setObjectName("StartFilterByPlace");

        horizontalLayout_6->addWidget(StartFilterByPlace);

        EndFilterByPlace = new QComboBox(horizontalLayoutWidget_6);
        EndFilterByPlace->addItem(QString());
        EndFilterByPlace->addItem(QString());
        EndFilterByPlace->addItem(QString());
        EndFilterByPlace->addItem(QString());
        EndFilterByPlace->addItem(QString());
        EndFilterByPlace->addItem(QString());
        EndFilterByPlace->addItem(QString());
        EndFilterByPlace->addItem(QString());
        EndFilterByPlace->addItem(QString());
        EndFilterByPlace->addItem(QString());
        EndFilterByPlace->addItem(QString());
        EndFilterByPlace->addItem(QString());
        EndFilterByPlace->addItem(QString());
        EndFilterByPlace->addItem(QString());
        EndFilterByPlace->addItem(QString());
        EndFilterByPlace->setObjectName("EndFilterByPlace");

        horizontalLayout_6->addWidget(EndFilterByPlace);

        InquireByPlace = new QPushButton(horizontalLayoutWidget_6);
        InquireByPlace->setObjectName("InquireByPlace");
        InquireByPlace->setBaseSize(QSize(6, 0));

        horizontalLayout_6->addWidget(InquireByPlace);

        tabWidget_2->addTab(tab_7, QString());
        horizontalLayoutWidget_4 = new QWidget(tab_4);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(570, 60, 191, 61));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        SortByPrice = new QPushButton(horizontalLayoutWidget_4);
        SortByPrice->setObjectName("SortByPrice");

        horizontalLayout_4->addWidget(SortByPrice);

        SortByTime = new QPushButton(horizontalLayoutWidget_4);
        SortByTime->setObjectName("SortByTime");

        horizontalLayout_4->addWidget(SortByTime);

        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        horizontalLayoutWidget_2 = new QWidget(tab);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(0, 20, 281, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        AddTimeSet = new QDateEdit(horizontalLayoutWidget_2);
        AddTimeSet->setObjectName("AddTimeSet");
        AddTimeSet->setDate(QDate(2023, 12, 10));

        horizontalLayout_2->addWidget(AddTimeSet);

        AddTime = new QTimeEdit(horizontalLayoutWidget_2);
        AddTime->setObjectName("AddTime");
        AddTime->setMinimumTime(QTime(8, 0, 0));

        horizontalLayout_2->addWidget(AddTime);

        AddStart = new QComboBox(horizontalLayoutWidget_2);
        AddStart->addItem(QString());
        AddStart->addItem(QString());
        AddStart->addItem(QString());
        AddStart->addItem(QString());
        AddStart->addItem(QString());
        AddStart->addItem(QString());
        AddStart->addItem(QString());
        AddStart->addItem(QString());
        AddStart->addItem(QString());
        AddStart->addItem(QString());
        AddStart->addItem(QString());
        AddStart->addItem(QString());
        AddStart->addItem(QString());
        AddStart->addItem(QString());
        AddStart->addItem(QString());
        AddStart->setObjectName("AddStart");

        horizontalLayout_2->addWidget(AddStart);

        AddEnd = new QComboBox(horizontalLayoutWidget_2);
        AddEnd->addItem(QString());
        AddEnd->addItem(QString());
        AddEnd->addItem(QString());
        AddEnd->addItem(QString());
        AddEnd->addItem(QString());
        AddEnd->addItem(QString());
        AddEnd->addItem(QString());
        AddEnd->addItem(QString());
        AddEnd->addItem(QString());
        AddEnd->addItem(QString());
        AddEnd->addItem(QString());
        AddEnd->addItem(QString());
        AddEnd->addItem(QString());
        AddEnd->addItem(QString());
        AddEnd->addItem(QString());
        AddEnd->setObjectName("AddEnd");

        horizontalLayout_2->addWidget(AddEnd);

        AddFlightID = new QLineEdit(tab);
        AddFlightID->setObjectName("AddFlightID");
        AddFlightID->setGeometry(QRect(290, 30, 81, 21));
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(290, 10, 54, 16));
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 10, 54, 16));
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 10, 54, 16));
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(230, 10, 54, 16));
        TicketsInfoTable = new QTableWidget(tab);
        if (TicketsInfoTable->columnCount() < 6)
            TicketsInfoTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        TicketsInfoTable->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        TicketsInfoTable->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        TicketsInfoTable->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        TicketsInfoTable->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        TicketsInfoTable->setHorizontalHeaderItem(4, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        TicketsInfoTable->setHorizontalHeaderItem(5, __qtablewidgetitem15);
        if (TicketsInfoTable->rowCount() < 1)
            TicketsInfoTable->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        TicketsInfoTable->setVerticalHeaderItem(0, __qtablewidgetitem16);
        TicketsInfoTable->setObjectName("TicketsInfoTable");
        TicketsInfoTable->setGeometry(QRect(380, 0, 671, 51));
        ADD = new QPushButton(tab);
        ADD->setObjectName("ADD");
        ADD->setGeometry(QRect(30, 70, 80, 24));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        label_5 = new QLabel(tab_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 10, 54, 16));
        DeleteFlightID = new QLineEdit(tab_2);
        DeleteFlightID->setObjectName("DeleteFlightID");
        DeleteFlightID->setGeometry(QRect(10, 30, 113, 23));
        DeleteTicketsTable = new QTableWidget(tab_2);
        if (DeleteTicketsTable->columnCount() < 10)
            DeleteTicketsTable->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        DeleteTicketsTable->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        DeleteTicketsTable->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        DeleteTicketsTable->setHorizontalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        DeleteTicketsTable->setHorizontalHeaderItem(3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        DeleteTicketsTable->setHorizontalHeaderItem(4, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        DeleteTicketsTable->setHorizontalHeaderItem(5, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        DeleteTicketsTable->setHorizontalHeaderItem(6, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        DeleteTicketsTable->setHorizontalHeaderItem(7, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        DeleteTicketsTable->setHorizontalHeaderItem(8, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        DeleteTicketsTable->setHorizontalHeaderItem(9, __qtablewidgetitem26);
        DeleteTicketsTable->setObjectName("DeleteTicketsTable");
        DeleteTicketsTable->setGeometry(QRect(130, 10, 911, 81));
        horizontalLayoutWidget_3 = new QWidget(tab_2);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(10, 60, 111, 21));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        DeleteInquire = new QPushButton(horizontalLayoutWidget_3);
        DeleteInquire->setObjectName("DeleteInquire");

        horizontalLayout_3->addWidget(DeleteInquire);

        Delete = new QPushButton(horizontalLayoutWidget_3);
        Delete->setObjectName("Delete");

        horizontalLayout_3->addWidget(Delete);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        ChangeFlightID = new QLineEdit(tab_3);
        ChangeFlightID->setObjectName("ChangeFlightID");
        ChangeFlightID->setGeometry(QRect(10, 20, 121, 23));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 0, 54, 16));
        ChangeTicketsTable = new QTableWidget(tab_3);
        if (ChangeTicketsTable->columnCount() < 10)
            ChangeTicketsTable->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        ChangeTicketsTable->setHorizontalHeaderItem(0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        ChangeTicketsTable->setHorizontalHeaderItem(1, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        ChangeTicketsTable->setHorizontalHeaderItem(2, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        ChangeTicketsTable->setHorizontalHeaderItem(3, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        ChangeTicketsTable->setHorizontalHeaderItem(4, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        ChangeTicketsTable->setHorizontalHeaderItem(5, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        ChangeTicketsTable->setHorizontalHeaderItem(6, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        ChangeTicketsTable->setHorizontalHeaderItem(7, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        ChangeTicketsTable->setHorizontalHeaderItem(8, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        ChangeTicketsTable->setHorizontalHeaderItem(9, __qtablewidgetitem36);
        ChangeTicketsTable->setObjectName("ChangeTicketsTable");
        ChangeTicketsTable->setGeometry(QRect(250, 10, 801, 81));
        ChangeTimeSet = new QDateTimeEdit(tab_3);
        ChangeTimeSet->setObjectName("ChangeTimeSet");
        ChangeTimeSet->setGeometry(QRect(10, 70, 121, 24));
        ChangeTimeSet->setDate(QDate(2023, 12, 10));
        ChangeTimeSet->setTime(QTime(8, 0, 0));
        verticalLayoutWidget = new QWidget(tab_3);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(140, 10, 101, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ChangeInquire = new QPushButton(verticalLayoutWidget);
        ChangeInquire->setObjectName("ChangeInquire");

        verticalLayout->addWidget(ChangeInquire);

        Change = new QPushButton(verticalLayoutWidget);
        Change->setObjectName("Change");

        verticalLayout->addWidget(Change);

        label_7 = new QLabel(tab_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 50, 54, 16));
        tabWidget->addTab(tab_3, QString());
        Exit = new QPushButton(Admin);
        Exit->setObjectName("Exit");
        Exit->setGeometry(QRect(710, 10, 80, 24));

        retranslateUi(Admin);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QWidget *Admin)
    {
        Admin->setWindowTitle(QCoreApplication::translate("Admin", "Administration", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TicketsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Admin", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TicketsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Admin", "\350\265\267\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TicketsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Admin", "\347\273\210\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = TicketsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("Admin", "\350\210\252\347\217\255\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = TicketsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("Admin", "\344\270\200\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = TicketsTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("Admin", "\344\272\214\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = TicketsTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("Admin", "\344\270\211\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = TicketsTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("Admin", "\344\270\200\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = TicketsTable->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("Admin", "\344\272\214\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = TicketsTable->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("Admin", "\344\270\211\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        StartFilter->setItemText(0, QCoreApplication::translate("Admin", "\345\214\227\344\272\254", nullptr));
        StartFilter->setItemText(1, QCoreApplication::translate("Admin", "\344\270\212\346\265\267", nullptr));
        StartFilter->setItemText(2, QCoreApplication::translate("Admin", "\345\271\277\345\267\236", nullptr));
        StartFilter->setItemText(3, QCoreApplication::translate("Admin", "\346\267\261\345\234\263", nullptr));
        StartFilter->setItemText(4, QCoreApplication::translate("Admin", "\346\255\246\346\261\211", nullptr));
        StartFilter->setItemText(5, QCoreApplication::translate("Admin", "\346\210\220\351\203\275", nullptr));
        StartFilter->setItemText(6, QCoreApplication::translate("Admin", "\346\235\255\345\267\236", nullptr));
        StartFilter->setItemText(7, QCoreApplication::translate("Admin", "\351\207\215\345\272\206", nullptr));
        StartFilter->setItemText(8, QCoreApplication::translate("Admin", "\351\225\277\346\262\231", nullptr));
        StartFilter->setItemText(9, QCoreApplication::translate("Admin", "\350\245\277\345\256\211", nullptr));
        StartFilter->setItemText(10, QCoreApplication::translate("Admin", "\345\215\227\344\272\254", nullptr));
        StartFilter->setItemText(11, QCoreApplication::translate("Admin", "\345\215\227\346\230\214", nullptr));
        StartFilter->setItemText(12, QCoreApplication::translate("Admin", "\345\244\251\346\264\245", nullptr));
        StartFilter->setItemText(13, QCoreApplication::translate("Admin", "\351\203\221\345\267\236", nullptr));
        StartFilter->setItemText(14, QCoreApplication::translate("Admin", "\346\265\216\345\215\227", nullptr));

        EndFilter->setItemText(0, QCoreApplication::translate("Admin", "\345\214\227\344\272\254", nullptr));
        EndFilter->setItemText(1, QCoreApplication::translate("Admin", "\344\270\212\346\265\267", nullptr));
        EndFilter->setItemText(2, QCoreApplication::translate("Admin", "\345\271\277\345\267\236", nullptr));
        EndFilter->setItemText(3, QCoreApplication::translate("Admin", "\346\267\261\345\234\263", nullptr));
        EndFilter->setItemText(4, QCoreApplication::translate("Admin", "\346\255\246\346\261\211", nullptr));
        EndFilter->setItemText(5, QCoreApplication::translate("Admin", "\346\210\220\351\203\275", nullptr));
        EndFilter->setItemText(6, QCoreApplication::translate("Admin", "\346\235\255\345\267\236", nullptr));
        EndFilter->setItemText(7, QCoreApplication::translate("Admin", "\351\207\215\345\272\206", nullptr));
        EndFilter->setItemText(8, QCoreApplication::translate("Admin", "\351\225\277\346\262\231", nullptr));
        EndFilter->setItemText(9, QCoreApplication::translate("Admin", "\350\245\277\345\256\211", nullptr));
        EndFilter->setItemText(10, QCoreApplication::translate("Admin", "\345\215\227\344\272\254", nullptr));
        EndFilter->setItemText(11, QCoreApplication::translate("Admin", "\345\215\227\346\230\214", nullptr));
        EndFilter->setItemText(12, QCoreApplication::translate("Admin", "\345\244\251\346\264\245", nullptr));
        EndFilter->setItemText(13, QCoreApplication::translate("Admin", "\351\203\221\345\267\236", nullptr));
        EndFilter->setItemText(14, QCoreApplication::translate("Admin", "\346\265\216\345\215\227", nullptr));

        Inquire->setText(QCoreApplication::translate("Admin", "\346\237\245\350\257\242\345\205\250\351\203\250\350\210\252\347\217\255", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("Admin", "\346\214\211\346\227\266\351\227\264\345\234\260\347\202\271\346\237\245\350\257\242", nullptr));
        InquireByTime->setText(QCoreApplication::translate("Admin", "\346\237\245\350\257\242\345\205\250\351\203\250\350\210\252\347\217\255", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QCoreApplication::translate("Admin", "\346\214\211\346\227\266\351\227\264\346\237\245\350\257\242", nullptr));
        StartFilterByPlace->setItemText(0, QCoreApplication::translate("Admin", "\345\214\227\344\272\254", nullptr));
        StartFilterByPlace->setItemText(1, QCoreApplication::translate("Admin", "\344\270\212\346\265\267", nullptr));
        StartFilterByPlace->setItemText(2, QCoreApplication::translate("Admin", "\345\271\277\345\267\236", nullptr));
        StartFilterByPlace->setItemText(3, QCoreApplication::translate("Admin", "\346\267\261\345\234\263", nullptr));
        StartFilterByPlace->setItemText(4, QCoreApplication::translate("Admin", "\346\255\246\346\261\211", nullptr));
        StartFilterByPlace->setItemText(5, QCoreApplication::translate("Admin", "\346\210\220\351\203\275", nullptr));
        StartFilterByPlace->setItemText(6, QCoreApplication::translate("Admin", "\346\235\255\345\267\236", nullptr));
        StartFilterByPlace->setItemText(7, QCoreApplication::translate("Admin", "\351\207\215\345\272\206", nullptr));
        StartFilterByPlace->setItemText(8, QCoreApplication::translate("Admin", "\351\225\277\346\262\231", nullptr));
        StartFilterByPlace->setItemText(9, QCoreApplication::translate("Admin", "\350\245\277\345\256\211", nullptr));
        StartFilterByPlace->setItemText(10, QCoreApplication::translate("Admin", "\345\215\227\344\272\254", nullptr));
        StartFilterByPlace->setItemText(11, QCoreApplication::translate("Admin", "\345\215\227\346\230\214", nullptr));
        StartFilterByPlace->setItemText(12, QCoreApplication::translate("Admin", "\345\244\251\346\264\245", nullptr));
        StartFilterByPlace->setItemText(13, QCoreApplication::translate("Admin", "\351\203\221\345\267\236", nullptr));
        StartFilterByPlace->setItemText(14, QCoreApplication::translate("Admin", "\346\265\216\345\215\227", nullptr));

        EndFilterByPlace->setItemText(0, QCoreApplication::translate("Admin", "\345\214\227\344\272\254", nullptr));
        EndFilterByPlace->setItemText(1, QCoreApplication::translate("Admin", "\344\270\212\346\265\267", nullptr));
        EndFilterByPlace->setItemText(2, QCoreApplication::translate("Admin", "\345\271\277\345\267\236", nullptr));
        EndFilterByPlace->setItemText(3, QCoreApplication::translate("Admin", "\346\267\261\345\234\263", nullptr));
        EndFilterByPlace->setItemText(4, QCoreApplication::translate("Admin", "\346\255\246\346\261\211", nullptr));
        EndFilterByPlace->setItemText(5, QCoreApplication::translate("Admin", "\346\210\220\351\203\275", nullptr));
        EndFilterByPlace->setItemText(6, QCoreApplication::translate("Admin", "\346\235\255\345\267\236", nullptr));
        EndFilterByPlace->setItemText(7, QCoreApplication::translate("Admin", "\351\207\215\345\272\206", nullptr));
        EndFilterByPlace->setItemText(8, QCoreApplication::translate("Admin", "\351\225\277\346\262\231", nullptr));
        EndFilterByPlace->setItemText(9, QCoreApplication::translate("Admin", "\350\245\277\345\256\211", nullptr));
        EndFilterByPlace->setItemText(10, QCoreApplication::translate("Admin", "\345\215\227\344\272\254", nullptr));
        EndFilterByPlace->setItemText(11, QCoreApplication::translate("Admin", "\345\215\227\346\230\214", nullptr));
        EndFilterByPlace->setItemText(12, QCoreApplication::translate("Admin", "\345\244\251\346\264\245", nullptr));
        EndFilterByPlace->setItemText(13, QCoreApplication::translate("Admin", "\351\203\221\345\267\236", nullptr));
        EndFilterByPlace->setItemText(14, QCoreApplication::translate("Admin", "\346\265\216\345\215\227", nullptr));

        InquireByPlace->setText(QCoreApplication::translate("Admin", "\346\237\245\350\257\242\345\205\250\351\203\250\350\210\252\347\217\255", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QCoreApplication::translate("Admin", "\346\214\211\345\234\260\347\202\271\346\237\245\350\257\242", nullptr));
        SortByPrice->setText(QCoreApplication::translate("Admin", "\346\214\211\344\273\267\346\240\274\346\216\222\345\272\217", nullptr));
        SortByTime->setText(QCoreApplication::translate("Admin", "\346\214\211\346\227\266\351\227\264\346\216\222\345\272\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("Admin", "\346\237\245\350\257\242\350\210\252\347\217\255", nullptr));
        AddStart->setItemText(0, QCoreApplication::translate("Admin", "\345\214\227\344\272\254", nullptr));
        AddStart->setItemText(1, QCoreApplication::translate("Admin", "\344\270\212\346\265\267", nullptr));
        AddStart->setItemText(2, QCoreApplication::translate("Admin", "\345\271\277\345\267\236", nullptr));
        AddStart->setItemText(3, QCoreApplication::translate("Admin", "\346\267\261\345\234\263", nullptr));
        AddStart->setItemText(4, QCoreApplication::translate("Admin", "\346\255\246\346\261\211", nullptr));
        AddStart->setItemText(5, QCoreApplication::translate("Admin", "\346\210\220\351\203\275", nullptr));
        AddStart->setItemText(6, QCoreApplication::translate("Admin", "\346\235\255\345\267\236", nullptr));
        AddStart->setItemText(7, QCoreApplication::translate("Admin", "\351\207\215\345\272\206", nullptr));
        AddStart->setItemText(8, QCoreApplication::translate("Admin", "\351\225\277\346\262\231", nullptr));
        AddStart->setItemText(9, QCoreApplication::translate("Admin", "\350\245\277\345\256\211", nullptr));
        AddStart->setItemText(10, QCoreApplication::translate("Admin", "\345\215\227\344\272\254", nullptr));
        AddStart->setItemText(11, QCoreApplication::translate("Admin", "\345\215\227\346\230\214", nullptr));
        AddStart->setItemText(12, QCoreApplication::translate("Admin", "\345\244\251\346\264\245", nullptr));
        AddStart->setItemText(13, QCoreApplication::translate("Admin", "\351\203\221\345\267\236", nullptr));
        AddStart->setItemText(14, QCoreApplication::translate("Admin", "\346\265\216\345\215\227", nullptr));

        AddEnd->setItemText(0, QCoreApplication::translate("Admin", "\345\214\227\344\272\254", nullptr));
        AddEnd->setItemText(1, QCoreApplication::translate("Admin", "\344\270\212\346\265\267", nullptr));
        AddEnd->setItemText(2, QCoreApplication::translate("Admin", "\345\271\277\345\267\236", nullptr));
        AddEnd->setItemText(3, QCoreApplication::translate("Admin", "\346\267\261\345\234\263", nullptr));
        AddEnd->setItemText(4, QCoreApplication::translate("Admin", "\346\255\246\346\261\211", nullptr));
        AddEnd->setItemText(5, QCoreApplication::translate("Admin", "\346\210\220\351\203\275", nullptr));
        AddEnd->setItemText(6, QCoreApplication::translate("Admin", "\346\235\255\345\267\236", nullptr));
        AddEnd->setItemText(7, QCoreApplication::translate("Admin", "\351\207\215\345\272\206", nullptr));
        AddEnd->setItemText(8, QCoreApplication::translate("Admin", "\351\225\277\346\262\231", nullptr));
        AddEnd->setItemText(9, QCoreApplication::translate("Admin", "\350\245\277\345\256\211", nullptr));
        AddEnd->setItemText(10, QCoreApplication::translate("Admin", "\345\215\227\344\272\254", nullptr));
        AddEnd->setItemText(11, QCoreApplication::translate("Admin", "\345\215\227\346\230\214", nullptr));
        AddEnd->setItemText(12, QCoreApplication::translate("Admin", "\345\244\251\346\264\245", nullptr));
        AddEnd->setItemText(13, QCoreApplication::translate("Admin", "\351\203\221\345\267\236", nullptr));
        AddEnd->setItemText(14, QCoreApplication::translate("Admin", "\346\265\216\345\215\227", nullptr));

        label->setText(QCoreApplication::translate("Admin", "\350\210\252\347\217\255\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("Admin", "\345\207\272\345\217\221\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("Admin", "\350\265\267\347\202\271", nullptr));
        label_4->setText(QCoreApplication::translate("Admin", "\347\273\210\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = TicketsInfoTable->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("Admin", "\344\270\200\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = TicketsInfoTable->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("Admin", "\344\272\214\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = TicketsInfoTable->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("Admin", "\344\270\211\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = TicketsInfoTable->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("Admin", "\344\270\200\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = TicketsInfoTable->horizontalHeaderItem(4);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("Admin", "\344\272\214\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = TicketsInfoTable->horizontalHeaderItem(5);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("Admin", "\344\270\211\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = TicketsInfoTable->verticalHeaderItem(0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("Admin", "\346\267\273\345\212\240\344\277\241\346\201\257", nullptr));
        ADD->setText(QCoreApplication::translate("Admin", "\346\267\273\345\212\240", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Admin", "\346\226\260\345\242\236\350\210\252\347\217\255", nullptr));
        label_5->setText(QCoreApplication::translate("Admin", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = DeleteTicketsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("Admin", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = DeleteTicketsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("Admin", "\350\265\267\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = DeleteTicketsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("Admin", "\347\273\210\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = DeleteTicketsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("Admin", "\350\210\252\347\217\255\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = DeleteTicketsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("Admin", "\344\270\200\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = DeleteTicketsTable->horizontalHeaderItem(5);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("Admin", "\344\272\214\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = DeleteTicketsTable->horizontalHeaderItem(6);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("Admin", "\344\270\211\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = DeleteTicketsTable->horizontalHeaderItem(7);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("Admin", "\344\270\200\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = DeleteTicketsTable->horizontalHeaderItem(8);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("Admin", "\344\272\214\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = DeleteTicketsTable->horizontalHeaderItem(9);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("Admin", "\344\270\211\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        DeleteInquire->setText(QCoreApplication::translate("Admin", "\346\237\245\350\257\242", nullptr));
        Delete->setText(QCoreApplication::translate("Admin", "\345\210\240\351\231\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Admin", "\345\210\240\351\231\244\350\210\252\347\217\255", nullptr));
        label_6->setText(QCoreApplication::translate("Admin", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = ChangeTicketsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("Admin", "\350\210\252\347\217\255\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = ChangeTicketsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("Admin", "\350\265\267\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = ChangeTicketsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("Admin", "\347\273\210\347\202\271", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = ChangeTicketsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("Admin", "\350\210\252\347\217\255\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = ChangeTicketsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("Admin", "\344\270\200\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = ChangeTicketsTable->horizontalHeaderItem(5);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("Admin", "\344\272\214\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = ChangeTicketsTable->horizontalHeaderItem(6);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("Admin", "\344\270\211\347\255\211\350\210\261\347\245\250\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = ChangeTicketsTable->horizontalHeaderItem(7);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("Admin", "\344\270\200\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = ChangeTicketsTable->horizontalHeaderItem(8);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("Admin", "\344\272\214\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = ChangeTicketsTable->horizontalHeaderItem(9);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("Admin", "\344\270\211\347\255\211\350\210\261\344\275\231\347\245\250", nullptr));
        ChangeInquire->setText(QCoreApplication::translate("Admin", "\346\237\245\350\257\242", nullptr));
        Change->setText(QCoreApplication::translate("Admin", "\344\277\256\346\224\271", nullptr));
        label_7->setText(QCoreApplication::translate("Admin", "\344\277\256\346\224\271\346\227\266\351\227\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("Admin", "\344\277\256\346\224\271\350\210\252\347\217\255", nullptr));
        Exit->setText(QCoreApplication::translate("Admin", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
