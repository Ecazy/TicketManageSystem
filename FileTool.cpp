#include "FileTool.h"
#include <iostream>
#include <fstream>

using namespace std;

// 二进制文件"data.bin"在main函数中创建

void FileTool::add_user(passengerInfo user_ticket) {
    std::ofstream ofs("/Users/yangqianjing/user_data.bin", std::ios::binary | std::ios::app);
    ofs.write((char *) &user_ticket, sizeof(user_ticket));
    ofs.close();
}

Linklist<passengerInfo> FileTool::find_user_by_name(std::string name) {
    std::ifstream ifs("/Users/yangqianjing/user_data.bin", std::ios::binary);
    passengerInfo temp;
    Linklist<passengerInfo> tickets;
    while (ifs.read((char *) &temp, sizeof(passengerInfo))) {
        if (temp.getName() == name) {
            tickets.addToTail(temp);
        }
    }
    // 关闭文件
    ifs.close();
    return tickets;
}

void FileTool::add(FlightInfo a) {
    // 按类写入二进制数据
    std::ofstream ofs("/Users/yangqianjing/ticket_data.bin", std::ios::binary | std::ios::app);
    ofs.write((char *) &a, sizeof(a));
    ofs.close();
}

//减去一张余票
bool FileTool::change(FlightInfo a, int c, int flag) {
    // 打开二进制文件
    std::fstream fs("/Users/yangqianjing/ticket_data.bin", std::ios::in | std::ios::out | std::ios::binary);
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
                    num -= flag;
                    if (num < 0)
                        return false;
                    a.setStockRemained(FIRST, num);
                    break;
                case 1:
                    num = temp.getStockRemained(SECOND);
                    num -= flag;
                    if (num < 0)
                        return false;
                    a.setStockRemained(SECOND, num);
                    break;
                case 2:
                    num = temp.getStockRemained(THIRD);
                    num -= flag;
                    if (num < 0)
                        return false;
                    a.setStockRemained(THIRD, num);
                    break;
            }
            fs.seekp(count * sizeof(FlightInfo), ios::beg);
            fs.write(reinterpret_cast<const char *>(&a), sizeof(FlightInfo));
            break;
        }
        count++;
        // 关闭文件

    }
    fs.close();
    return true;
}

Linklist<FlightInfo> FileTool::read_by_time(int y, int m, int d) {
    // 打开二进制文件
    std::ifstream ifs("/Users/yangqianjing/ticket_data.bin", std::ios::binary);
    FlightInfo temp;
    Linklist<FlightInfo> FlightList;
    while (ifs.read((char *) &temp, sizeof(FlightInfo)) && temp.ticket_has_left()) {
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
    std::ifstream ifs("/Users/yangqianjing/ticket_data.bin", std::ios::binary);
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


QWidget *loadUiFile(const string &path) {
    QUiLoader uiLoader;
    QFile file("/Users/yangqianjing/git/TicketManageSystem_v_2.7/ticketmanagesystem.ui");
    QWidget *main = uiLoader.load(&file);
//    if(main!= nullptr)
    return main;

}