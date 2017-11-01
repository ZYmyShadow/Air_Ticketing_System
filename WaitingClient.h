#include <string.h>
#include <iostream>
using namespace std;

class WaitingClient		//等候替补的客户
{
private: 
	string Name;		//客户名字 
	int TheAmountOfBooking;		//客户订票量
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
}; 