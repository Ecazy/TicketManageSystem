#include "function.h"

#ifndef TICKETMANAGESYSTEM_TOOL_H
#define TICKETMANAGESYSTEM_TOOL_H

class FileTool {
public:
    bool add(FlightInfo a);

    bool remove(FlightInfo a);

    //c表示舱位（0是头等，1是一等，2是二等）
    bool change(FlightInfo a, int c);

    //year, month, day
    Linklist<FlightInfo> read_by_time(int y, int m, int d);

    Linklist<FlightInfo> read_by_path(const string start, const string end);
};

#endif //TICKETMANAGESYSTEM_TOOL_H
