/*
 * 用二进制文件储存航班的所有对象
 * 依据用户输入找到用户信息进行增删改查
 * 用户操作之后更新航班信息
 * function.h中的函数作用是对从文件中取出的对象形成的链表进行操作使之符合用户需求
 * 如排序，查询，显示
 */
#include "Passenger.h"

#ifndef TICKETMANAGESYSTEM_CONSOLE_H
#define TICKETMANAGESYSTEM_CONSOLE_H

class Console {

public:
    void book_ticket_by_date(int y, int m, int d);

    void book_ticket_by_place(string start, string end);

    void cancel_flight(string name);

    void change_flight(string name);

    void check_my_flight(string name);

    void displayInfo(Linklist<FlightInfo> list);

    void book(Linklist<FlightInfo> list);

    void run();
};

#endif //TICKETMANAGESYSTEM_CONSOLE_H
