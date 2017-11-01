#include <string.h>
#include "BookingClient.h"
#include "WaitingClient.h"
#include <iostream>
using namespace std;

class Route     //航线 
{
private:
    string Starting_Place;//起始地点
	string Terminal_Name;//终点站名
	int Flight_Number;//航班号
    string Airplane_Num;//飞机号
	string Flying_on_Sunday;//飞行日期
	int Occupant_quota;//乘员定额
	int Rest_Ticket;//余票量
    int Seat_Number;//座位号
    int bookClientNum;//已订票客户的人数
    int waitClientNum;//替补客户的人数
public:
    BookingClient bookClient[600];//已订票人的信息
    WaitingClient waitClient[10000];//等候替补乘客
    
    void setRoute(string starting_Place,string terminal_Name)
    {
        this->Starting_Place = starting_Place;
        this->Terminal_Name = terminal_Name;
    }
    string getStarting_Place()
    {
        return Starting_Place;
    }
    string getTerminal_Name()
    {
        return Terminal_Name;
    }
    int getFlight_Number()
    {
        return Flight_Number;
    }
    void setFlight_Number(int flight_Number)
    {
        this->Flight_Number = flight_Number;
    }
    string getAirplane_Num()
    {
        return Airplane_Num;
    }
    void setAirplane_Num(string airplane_Num)
    {
        this->Airplane_Num = airplane_Num;
    }
    string getFlying_on_Sunday()
    {
        return Flying_on_Sunday;
    }
    void setFlying_on_Sunday(string flying_on_Sunday)
    {
        this->Flying_on_Sunday = flying_on_Sunday;
    }
    int getOccupant_quota()
    {
        return Occupant_quota;
    }
    void setOccupant_quota(int occupant_quota)
    {
        this->Occupant_quota = occupant_quota;
    }
    int getRest_Ticket()
    {
        return Rest_Ticket;
    }
    void setRest_Ticket(int rest_Ticket)
    {
        this->Rest_Ticket = rest_Ticket;
    }
    int getBookClient()
    {
        return bookClientNum;
    }
    void setBookClient(int bookclientnum)
    {
        this->bookClientNum = bookclientnum;
    }
    int getWaitClient()
    {
        return waitClientNum;
    }
    void setWaitClient(int waitclientnum)
    {
        this->waitClientNum = waitclientnum;
    }
    int getSeat_Number()
    {
        return Seat_Number;
    }
    void setSeat_Number(int seatNum)
    {
        this->Seat_Number = seatNum;
    }
};