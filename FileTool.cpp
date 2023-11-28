#include "FileTool.h"
#include <iostream>
#include <fstream>

using namespace std;

void writeString(ostream& ofs,const string& str)
{
    size_t len = str.size();
    ofs.write(reinterpret_cast<const char*>(&len),sizeof(size_t));
    ofs.write(str.c_str(),len);
}

string readString(istream& ifs)
{
    size_t len;
    ifs.read(reinterpret_cast<char*>(&len),sizeof(size_t));
    string str(len,' ');
    ifs.read(&str[0],len);
    return str;
}
// 二进制文件"data.bin"在main函数中创建

void FileTool::add(FlightInfo& a) {
    // 按类写入二进制数据
    std::ofstream ofs("D:/Code/C++/Project/Widget/TicketManageSystem/data.bin", std::ios::binary | std::ios::app);
    //以下为逐成员变量写入文件
    writeString(ofs, a.getBeginning());
    writeString(ofs,a.getDestination());
    writeString(ofs,a.getFlightID());

    DateTime depature(a.getDepature());
    ofs.write(reinterpret_cast<const char*>(&depature),sizeof(depature));
    int capacity = a.getCapacity();
    ofs.write(reinterpret_cast<const char*>(&capacity),sizeof(capacity));
    double first=a.getFares(FIRST),second=a.getFares(SECOND),third=a.getFares(THIRD);
    ofs.write(reinterpret_cast<const char*>(&first),sizeof(double));
    ofs.write(reinterpret_cast<const char*>(&second),sizeof(double));
    ofs.write(reinterpret_cast<const char*>(&third),sizeof(double));
    StockRemained stock =  a.getStockRemained();
    ofs.write(reinterpret_cast<const char*>(&stock),sizeof(stock));
//    ofs.write((char *) &a, sizeof(a));
    ofs.close();
}

bool FileTool::read(ifstream& ifs,FlightInfo& tmp)
{
    if(ifs.eof())
        return false;
    string beginning,destination,flightID;
    DateTime depature;
    int capacity;
    double first,second,third;
    StockRemained stock;
    beginning = readString(ifs);
    destination = readString(ifs);
    flightID = readString(ifs);
    ifs.read(reinterpret_cast<char*>(&depature),sizeof(depature));
    ifs.read(reinterpret_cast<char*>(&capacity),sizeof(capacity));
    ifs.read(reinterpret_cast<char*>(&first),sizeof(double));
    ifs.read(reinterpret_cast<char*>(&second),sizeof(double));
    ifs.read(reinterpret_cast<char*>(&third),sizeof(double));
    ifs.read(reinterpret_cast<char*>(&stock),sizeof(stock));
    FlightInfo temp(beginning,destination,flightID,depature,capacity,first,second,third);
    tmp = temp;
    tmp.setStockRemained(FIRST,stock.first);
    tmp.setStockRemained(SECOND,stock.second);
    tmp.setStockRemained(THIRD,stock.third);
    return true;
}

//减去一张余票
//TODO 此处可能大改,未规划好如何改进
bool FileTool::change(FlightInfo a, int c, int flag) {
    // 打开二进制文件
    std::fstream fs("D:/Code/C++/Project/Widget/TicketManageSystem/data.bin", std::ios::in | std::ios::out | std::ios::binary);
    //读取数据
    FlightInfo temp;
    int num, count = 0;
    while (fs.read((char *) &temp, sizeof(FlightInfo)) && temp.ticket_has_left()) {

        // 检查这个值是否是我们想要的
        if (temp.getFlightID() == a.getFlightID()) {
            // 修改类成员
            switch (c) {
                case 0:
                    num = temp.getStockRemained(FIRST);
                    num-= flag;
                    if (num < 0)
                        return false;
                    a.setStockRemained(FIRST, num);
                    break;
                case 1:
                    num = temp.getStockRemained(SECOND);
                    num-=flag;
                    if (num < 0)
                        return false;
                    a.setStockRemained(SECOND, num);
                    break;
                case 2:
                    num = temp.getStockRemained(THIRD);
                    num-=flag;
                    if (num < 0)
                        return false;
                    a.setStockRemained(THIRD, num);
                    break;
            }
            fs.seekp(count * sizeof(FlightInfo),ios::beg);
            fs.write(reinterpret_cast<const char*>(&temp), sizeof(FlightInfo));
            break;
        }
        count++;
        // 关闭文件
        fs.close();
    }
    return true;
}

Linklist<FlightInfo> FileTool::read_by_time(int y, int m, int d) {
    // 打开二进制文件
    std::ifstream ifs("D:/Code/C++/Project/Widget/TicketManageSystem/data.bin", std::ios::binary);
    FlightInfo temp;
    Linklist<FlightInfo> FlightList;
    while ( this->read(ifs,temp) && temp.ticket_has_left()) {
        // 检查这个值是否是我们想要的
        if (temp.getDepature().year == y && temp.getDepature().month == m && temp.getDepature().day == d) {
            FlightList.addToTail(temp);
        }
    }
    // 关闭文件
    ifs.close();
    return FlightList;
}

Linklist<FlightInfo> FileTool::read_by_path(string start, string end) {
    // 打开二进制文件
    std::ifstream ifs("D:/Code/C++/Project/Widget/TicketManageSystem/data.bin", std::ios::binary);
    FlightInfo temp;
    Linklist<FlightInfo> FlightList;
    while (read(ifs,temp) && temp.ticket_has_left()) {
        // 检查这个值是否是我们想要的
        if (temp.getBeginning() == start && temp.getDestination() == end) {
            FlightList.addToTail(temp);
        }
    }
    // 关闭文件
    ifs.close();
    return FlightList;
}

FlightInfo FileTool::find_flight_by_Id(Linklist<FlightInfo> list, string id) {
    for (int i = 0; i < list.length; i++) {
        if (list.getNode(i).getFlightID() == id) {
            return list.getNode(i);
        }
    }
    return list.getNode(0);
}


QWidget *loadUiFile(const string &path) {
    QUiLoader uiLoader;
    QFile file("D:/Code/C++/Project/Widget/TicketManageSystem/ticketmanagesystem.ui");
    QWidget *main = uiLoader.load(&file);
//    if(main!= nullptr)
    return main;

}