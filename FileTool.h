//
// Created by 杨千靖 on 2023/11/12.
//
#include "function.h"

#ifndef TICKETMANAGESYSTEM_TOOL_H
#define TICKETMANAGESYSTEM_TOOL_H

//记得初始化flag为true
typedef struct {
    int ID;
    int y, m, d;
    string start, end;
    int First, Second, Third;
    bool flag;
} FlightInfo;

class FileTool {
public:
    void add(FlightInfo a);

    void remove(FlightInfo a);

    //c表示舱位（0是头等，1是一等，2是二等）
    void change(FlightInfo a, int c);

    //year, month, day
    Linklist<FlightInfo> read_by_time(int y, int m, int d);

    Linklist<FlightInfo> read_by_path(const string start, const string end);
};

#endif //TICKETMANAGESYSTEM_TOOL_H
