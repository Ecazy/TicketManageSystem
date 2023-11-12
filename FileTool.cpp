//
// Created by 杨千靖 on 2023/11/12.
#include "FileTool.h"
#include <iostream>

using namespace std;

// 二进制文件"data.bin"在main函数中创建

void FileTool::add(FlightInfo a) {
    // 按类写入二进制数据
    std::ofstream ofs("data.bin", std::ios::binary);
    ofs.write((char *) &a, sizeof(a));
    ofs.close();
}

//二进制文件删除成员过于麻烦，这里通过flag的bool值判断是否存在成员
//当前航班票卖空后将flag置为false即可
void FileTool::remove(FlightInfo a) {
    a.flag = false;
}

//减去一张余票
void FileTool::change(FlightInfo a, int c) {
    // 打开二进制文件
    std::ifstream ifs("data.bin", std::ios::binary);
    //读取数据
    FlightInfo temp;
    while (ifs.read((char *) &temp, sizeof(FlightInfo)) && temp.flag) {
        // 检查这个值是否是我们想要的
        if (temp.ID == a.ID) {
            // 修改结构体成员
            switch (c) {
                case 0:
                    a.First--;
                    break;
                case 1:
                    a.Second--;
                    break;
                case 2:
                    a.Third--;
                    break;
            }
            break;
        }
        if (a.First == 0 && a.Second == 0 && a.Third == 0) {
            a.flag = false;
        }
        // 关闭文件
        ifs.close();
    }
}

Linklist<FlightInfo> FileTool::read_by_time(int y, int m, int d) {
    // 打开二进制文件
    std::ifstream ifs("data.bin", std::ios::binary);
    FlightInfo temp;
    Linklist<FlightInfo> FlightList;
    while (ifs.read((char *) &temp, sizeof(FlightInfo)) && temp.flag) {
        // 检查这个值是否是我们想要的
        if (temp.y == y && temp.m == m && temp.d == d) {
            FlightList.addToTail(temp);
        }
        break;
    }
    // 关闭文件
    ifs.close();
    return FlightList;


}

Linklist<FlightInfo> FileTool::read_by_path(const string start, const string end) {
    // 打开二进制文件
    std::ifstream ifs("data.bin", std::ios::binary);
    FlightInfo temp;
    Linklist<FlightInfo> FlightList;
    while (ifs.read((char *) &temp, sizeof(FlightInfo)) && temp.flag) {
        // 检查这个值是否是我们想要的
        if (temp.start == start && temp.end == end) {
            FlightList.addToTail(temp);
        }
        break;
    }
    // 关闭文件
    ifs.close();
    return FlightList;

}
