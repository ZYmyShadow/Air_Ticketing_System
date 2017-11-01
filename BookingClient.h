#include <string.h>
#include <iostream>
using namespace std;

class BookingClient		//已订票的客户 
{
private: 
	string Name;		//客户名字
	int TheAmountOfBooking;		//客户订票量
	string Accommodation;		//客户所定舱位
    int seat_Head;          //座位头号
    int seat_Feet;          //座位尾号
	bool IsNoPay;		//是否付款
public:
    string getName()
    {
        return Name;
    }
    void setName(string name)
    {
        this->Name = name;
    }
    int getTheAmountOfBooking()
    {
        return TheAmountOfBooking;
    }
    void setTheAmountOfBooking(int theAmountOfBooking)
    {
        this->TheAmountOfBooking = theAmountOfBooking;
    }
    string getAccommodation()
    {
        return Accommodation;
    }
    void setAccommodation(string accommodation)
    {
        this->Accommodation = accommodation;
    }
    bool getIsNoPay()
    {
        return IsNoPay;
    }
    void setIsNoPay(bool isNoPay)
    {
        this->IsNoPay = isNoPay;
    }
    int getseat_Head()
    {
        return seat_Head;
    }
    void setseat_Head(int seat_head)
    {
        this->seat_Head = seat_head;
    }
    int getseat_Feet()
    {
        return seat_Feet;
    }
    void setseat_Feet(int seat_feet)
    {
        this->seat_Feet = seat_feet;
    }
};