#include <QApplication>
#include <QWidget>

#include <QtUiTools/QUiLoader>
#include <QFile>
#include<fstream>
#include<sstream>
#include"Passenger.h"


QWidget *loadUiFile(const string &path);

#ifndef TICKETMANAGESYSTEM_TOOL_H
#define TICKETMANAGESYSTEM_TOOL_H

class FileTool {
public:
    void add(FlightInfo a);

    bool remove(FlightInfo a);

    //c表示舱位（0是头等，1是一等，2是二等）
    bool change(FlightInfo a, int c, int flag = 1);

    //year, month, day
    Linklist<FlightInfo> read_by_time(int y, int m, int d);

    Linklist<FlightInfo> read_by_path(string start, string end);

    FlightInfo find_flight_by_Id(Linklist<FlightInfo> list, string id);
};

#endif //TICKETMANAGESYSTEM_TOOL_H
