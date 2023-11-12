#ifndef IOFUNC_H
#define IOFUNC_H

#include<fstream>
#include<sstream>
#include"Passenger.h"

//输入输出类，专用于程序输入输出信息
class IOFunc {
public:

    IOFunc();

    Stack<FlightInfo> readFlightData(const string);

};

#endif // IOFUNC_H
