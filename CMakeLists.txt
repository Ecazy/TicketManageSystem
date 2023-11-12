cmake_minimum_required(VERSION 3.5)
project(TicketManageSystem)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH "/Users/yangqianjing/Qt/6.6.0/macos/lib/cmake/Qt6")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(TicketManageSystem
        datastructure.h
        function.cpp
        function.h
        Passenger.cpp
        Passenger.h
        iofunc.cpp
        iofunc.h
        main.cpp
        ticketmanagesystem.cpp
        ticketmanagesystem.h
        ui_ticketmanagesystem.h
        FileTool.h FileTool.cpp Console.h FlightInfo.h FlightInfo.cpp Console.cpp)

target_link_libraries(TicketManageSystem
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )


