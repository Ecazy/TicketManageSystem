#include "ticketmanagesystem.h"
#include "Login.h"
#include <QApplication>

#include<iostream>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Login s;
    s.setWindowTitle("Login");
    s.show();
    TicketManageSystem w;
    QObject::connect(&s,&Login::loginSuccessful,[&w,&s](){
        w.set_name(s.usrName);
        w.show();
    });
    return a.exec();

//    FileTool f;
//    for(int i=0;i<19762;++i)
//    {
//        string flightID,start,end;
//        int y,m,d,h,minu;
//        DateTime date;
//        double price1,price2,price3;
//        int cap;
//        cin>>start>>end>>flightID>>y>>m>>d>>h>>minu>>cap>>price1>>price2>>price3;
//        date.setDateTime(y,m,d,h, minu);
//        FlightInfo tmp(start,end,flightID,date,cap,price1,price2,price3);
//        f.add(tmp);
//        cout<<i+1<<endl;
//    }
}

