#ifndef IOFUNC_H
#define IOFUNC_H

#include<fstream>
#include<sstream>
#include"information.h"

class IOFunc
{
public:

    IOFunc();

    Stack<flightInfor> readFlightData(const string);

};

#endif // IOFUNC_H
