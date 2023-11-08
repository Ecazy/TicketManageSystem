#include "function.h"

Linklist<flightInfor> findByTime(int y,int m,int d)
{
    Linklist<flightInfor> flightList;
    for (int i = 0; i < flightInforList.length; i++)
    {
        if (flightInforList[i].getDepatureDay().year == y && flightInforList[i].getDepatureDay().month == m && flightInforList[i].getDepatureDay().date == d)
        {
            flightList.addToTail(flightInforList[i]);
        }
    }
    return flightList;
}

Linklist<flightInfor> findByBAD(const string beginning,const string destination)
{
    Linklist<flightInfor> flightList;
    for (int i = 0; i < flightInforList.length; i++)
    {
        if (flightInforList[i].getBeginning() == beginning && flightInforList[i].getDestination() == destination)
        {
            flightList.addToTail(flightInforList[i]);
        }
    }
    return flightList;
}

void checkTime(Linklist<flightInfor>& flightList,int y,int m,int d)
{
    for (int i = 0; i < flightList.length; i++)
    {
        if (flightList[i].getDepatureDay().year == y && flightList[i].getDepatureDay().month == m && flightList[i].getDepatureDay().date == d)
            continue;
        else
            flightList.remove(i--);
    }
}

void checkBAD(Linklist<flightInfor>& flightList,const string beginning,const string destination)
{
    for (int i = 0; i < flightList.length; i++)
    {
        if (flightList[i].getBeginning() == beginning && flightList[i].getDestination() == destination)
            continue;
        else
            flightList.remove(i--);
    }
}

void removeNoTicketFlight(Linklist<flightInfor>& flightList)
{
    for (int i = 0; i < flightList.length; i++)
    {
        if (flightList[i].getStockRemained(FIRST) == 0 && flightList[i].getStockRemained(SECOND) == 0 && flightList[i].getStockRemained(THIRD) == 0)
            flightList.remove(i--);
    }
}

void sortByStartTime(Linklist<flightInfor>& flightList)
{
    flightList.sort([](flightInfor a,flightInfor b) {return a.getDepatureDay().hour * 60 + a.getDepatureDay().minute < b.getDepatureDay().hour * 60 + b.getDepatureDay().minute; });
}

void sortByPrice(Linklist<flightInfor>& flightList)
{
    flightList.sort([](flightInfor a,flightInfor b) {return a.getFares() < b.getFares(); });
}

void sortByArrivalTime(Linklist<flightInfor>& flightList)
{
    flightList.sort([](flightInfor a,flightInfor b) {return a.getDepatureDay().hour * 60 + a.getDepatureDay().minute + a.getDepatureDay().hour * 60 + a.getDepatureDay().minute < b.getDepatureDay().hour * 60 + b.getDepatureDay().minute + b.getDepatureDay().hour * 60 + b.getDepatureDay().minute; });
}

bool buyTicket(flightInfor& flight,passengerInfor& passenger)
{
    return passenger.bookTicket(flight);
}

bool cancelTicket(flightInfor& flight,passengerInfor& passenger)
{
    return passenger.cancelTicket(flight);
}

bool changeTicket(flightInfor& flight,passengerInfor& passenger,travelClass _travelclass)
{
    return passenger.changeTicket(flight,_travelclass);
}
