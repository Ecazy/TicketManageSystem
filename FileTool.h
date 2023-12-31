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
    void writeString(std::ofstream& ofs,const std::string& str);

    void writeString(std::fstream& fs,const std::string& str);

    std::string readString(std::ifstream& ifs);

    std::string readString(std::fstream& fs);

    void writeFlightInfo(std::fstream&fs,FlightInfo& tmp);

    void writeFlightInfo(std::ofstream& ofs,FlightInfo& tmp);

    void writePassengerInfo(std::fstream&fs,passengerInfo& tmp);

    void writePassengerInfo(std::ofstream& ofs,passengerInfo& tmp);

    void add(FlightInfo& a);

    void add(passengerInfo a);

    bool read(ifstream& ifs,FlightInfo &tmp);

    bool read(fstream& fs,FlightInfo &tmp);

    Linklist<FlightInfo> read(FlightInfo tmp);

    Linklist<passengerInfo> read(passengerInfo tmp);

    bool read(ifstream& ifs,passengerInfo &tmp);

    bool read(fstream& fs,passengerInfo &tmp);

    bool remove(const string flightID);

    bool remove(passengerInfo passengerInfo);

    bool change_by_id(FlightInfo a,const string flightID);

    //c表示舱位（0是头等，1是一等，2是二等）
    bool change(FlightInfo a, int c, int flag = 1);

    //year, month, day
    Linklist<FlightInfo> read_by_time(int y, int m, int d);

    Linklist<FlightInfo> read_by_path(string start, string end);

    Linklist<FlightInfo> read_by_id(string id);

    Linklist<passengerInfo> read_by_name(string name);

    FlightInfo find_flight_by_Id(Linklist<FlightInfo> list, string id);

    bool rewrite(Linklist<FlightInfo> flightList,Linklist<passengerInfo> passengerList);
};


#endif //TICKETMANAGESYSTEM_TOOL_H
