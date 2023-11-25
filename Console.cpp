//
// Created by 杨千靖 on 2023/11/12.
//
#include <iostream>
#include "string.h"
#include "Passenger.h"
#include "Console.h"
#include "FileTool.h"

using namespace std;

FileTool f;

void Console::displayInfo(Linklist<FlightInfo> list) {
    for (int i = 0; i < list.length; i++) {
        cout << "Flight starts at: " << list.getNode(i).getBeginning() << endl;
        cout << "Flight ends at: " << list.getNode(i).getDestination() << endl;
        cout << "First class ticket price is: " << list.getNode(i).getFares(FIRST) << endl;
        cout << "Second class ticket price is: " << list.getNode(i).getFares(SECOND) << endl;
        cout << "Third class ticket price is: " << list.getNode(i).getFares(THIRD) << endl;
        cout << "Flight's ID at: " << list.getNode(i).getFlightID() << endl;
    }
}

void Console::book(Linklist<FlightInfo> list) {
    cout << "Please select your plane id and class(capital)." << endl;
    string request, temp;
    cin >> request;
    cin >> temp;
    if (temp == "FIRST") {
        f.change(f.find_flight_by_Id(list, request), 0);
    } else if (temp == "SECOND") {
        f.change(f.find_flight_by_Id(list, request), 1);
    } else if (temp == "THIRD") {
        f.change(f.find_flight_by_Id(list, request), 2);
    } else
        cout << "WRONG Input !!!" << endl;
}

void Console::book_ticket_by_date(int y, int m, int d) {
    Linklist<FlightInfo> list = f.read_by_time(y, m, d);
    displayInfo(list);
    book(list);
}

void Console::book_ticket_by_place(std::string start, std::string end) {
    Linklist<FlightInfo> list = f.read_by_path(start, end);
    displayInfo(list);
    book(list);
}

void Console::cancel_flight(std::string name) {

}

void Console::change_flight(std::string name) {

}

void Console::check_my_flight(std::string name) {

}

void Console::run() {

    DateTime time;
    time.setDateTime(2023,11,25,SAT,10,55);
    FlightInfo test("changsha","wuhan","114514","65536",time,100,1000,800,600);
    f.add(test);

    cout << "1. Book ticket by date" << endl;
    cout << "2. Book ticket by place" << endl;
    int a;
    cin >> a;
    switch (a) {
        case 1:
            cout << "Please input year,month and day." << endl;
            int y, m, d;
            cin >> y >> m >> d;
            book_ticket_by_date(y, m, d);
            break;
        case 2:
            cout << "Please input start and end." << endl;
            string start, end;
            cin >> start >> end;
            book_ticket_by_place(start, end);
            break;
    }
}