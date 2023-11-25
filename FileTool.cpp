#include "FileTool.h"
#include <iostream>
#include <fstream>
using namespace std;

// 二进制文件"data.bin"在main函数中创建

void FileTool::add(FlightInfo a) {
    // 按类写入二进制数据
    std::ofstream ofs("data.bin", std::ios::binary);
    ofs.write((char *) &a, sizeof(a));
    ofs.close();
}

//减去一张余票
bool FileTool::change(FlightInfo a, int c) {
    // 打开二进制文件
    std::ifstream ifs("data.bin", std::ios::binary);
    //读取数据
    FlightInfo temp;
    int num;
    while (ifs.read((char *) &temp, sizeof(FlightInfo)) && temp.ticket_has_left()) {
        // 检查这个值是否是我们想要的
        if (temp.getFlightID() == a.getFlightID()) {
            // 修改类成员
            switch (c) {
                case 0:
                    num = temp.getStockRemained(FIRST);
                    num--;
                    if(num < 0)
                        return false;
                    a.setStockRemained(FIRST,num);
                    break;
                case 1:
                    num = temp.getStockRemained(SECOND);
                    num--;
                    if(num < 0)
                        return false;
                    a.setStockRemained(SECOND,num);
                    break;
                case 2:
                    num = temp.getStockRemained(THIRD);
                    num--;
                    if(num < 0)
                        return false;
                    a.setStockRemained(THIRD,num);
                    break;
            }
            break;
        }
        // 关闭文件
        ifs.close();
    }
    return true;
}

Linklist<FlightInfo> FileTool::read_by_time(int y, int m, int d) {
    // 打开二进制文件
    std::ifstream ifs("data.bin", std::ios::binary);
    FlightInfo temp;
    Linklist<FlightInfo> FlightList;
    while (ifs.read((char *) &temp, sizeof(FlightInfo)) && temp.ticket_has_left()) {
        // 检查这个值是否是我们想要的
        if (temp.getDepature().year == y && temp.getDepature().month == m && temp.getDepature().day == d) {
            FlightList.addToTail(temp);
        }
        break;
    }
    // 关闭文件
    ifs.close();
    return FlightList;
}

Linklist<FlightInfo> FileTool::read_by_path(string start, string end) {
    // 打开二进制文件
    std::ifstream ifs("data.bin", std::ios::binary);
    FlightInfo temp;
    Linklist<FlightInfo> FlightList;
    while (ifs.read((char *) &temp, sizeof(FlightInfo)) && temp.ticket_has_left()) {
        // 检查这个值是否是我们想要的
        if (temp.getBeginning() == start && temp.getDestination() == end) {
            FlightList.addToTail(temp);
        }
        break;
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

QWidget* loadUiFile(const string &path)
{
    QUiLoader uiLoader;
    QFile file("D:/Code/C++/Project/Widget/TicketManageSystem/ticketmanagesystem.ui");
    QWidget *main = uiLoader.load(&file);
//    if(main!= nullptr)
    return main;

}