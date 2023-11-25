#ifndef IOFUNC_H
#define IOFUNC_H

#include<fstream>
#include<sstream>
#include"Passenger.h"

#include <QtUiTools/QUiLoader>
#include <QFile>

//输入输出类，专用于程序输入输出信息
class IOFunc {
public:

    IOFunc();

    Stack<FlightInfo> readFlightData(const string);

};

QWidget* loadUiFile(const string& path);

#endif // IOFUNC_H
