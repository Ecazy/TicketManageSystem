cmake_minimum_required(VERSION 3.24)
project(TicketManageSystem_demo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "/Users/yangqianjing/Qt/6.6.0/macos/lib/cmake/Qt6")


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        UiTools
        REQUIRED)

add_executable(TicketManageSystem_demo
        datastructure.h
        function.cpp
        function.h
        Passenger.cpp
        Passenger.h
        main.cpp
        ticketmanagesystem.cpp
        ticketmanagesystem.h
        ui_ticketmanagesystem.h
        FlightInfo.h FlightInfo.cpp FileTool.cpp FileTool.h Login.cpp)
target_link_libraries(TicketManageSystem_demo
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::UiTools
        )

