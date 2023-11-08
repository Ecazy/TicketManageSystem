#include "iofunc.h"

IOFunc::IOFunc()
{

}

Stack<flightInfor> IOFunc::readFlightData(const string _path)
{
    Stack<flightInfor> _stack;
    ifstream _file;
    _file.open(_path);
    if (_file.is_open())
    {
        //the information of flight are split by ' '
        //and include flightID,planeID,beginning,destination,depatureDay,occupiedSeats,fares
        //DepatureDay is split by '-' and include year,month,day,hour,minute
        //and each flight is split by '\n'
        string _flightID, _planeID, _beginning, _destination;
        string _occupiedSeatsStr,faresStr;
        int _occupiedSeats;
        double _fares;
        DateTime _depatureDay;
        while (getline(_file, _flightID))
        {
            getline(_file, _planeID);
            getline(_file, _beginning);
            getline(_file, _destination);
            string _depatureDayStr;
            getline(_file, _depatureDayStr);
            //process the string of depatureDay
            {
                stringstream _ss(_depatureDayStr);
                int _week;
                int _year, _month, _day, _hour, _minute;
                _ss >> _year >> _month >> _day >> _week >> _hour >> _minute;
                Week _Week;
                switch (_week)
                {
                    case 0:
                        _Week = MON;
                        break;
                    case 1:
                        _Week = TUE;
                        break;
                    case 2:
                        _Week = WED;
                        break;
                    case 3:
                        _Week = THU;
                        break;
                    case 4:
                        _Week = FRI;
                        break;
                    case 5:
                        _Week = SAT;
                        break;
                    case 6:
                        _Week = SUN;
                        break;
                    default:
                        throw("Error: Week is not in the range of 0-6");
                        break;
                }
                _depatureDay.setDateTime(_year, _month, _day, _Week, _hour, _minute);
            }
            getline(_file, _occupiedSeatsStr);
            _occupiedSeats = stoi(_occupiedSeatsStr);
            getline(_file, faresStr);
            _fares = stod(faresStr);
            flightInfor _flight(_beginning,_destination,_flightID,_planeID,_depatureDay,_occupiedSeats,_fares);
            _stack.push(_flight);
        }
    }
    _file.close();
    return _stack;
}
