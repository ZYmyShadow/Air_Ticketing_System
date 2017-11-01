#include "FunctionDefinition.h"
#include <iostream>
using namespace std;

/*
--------------------------
---1. 初始化0为空位---------
---2. 1为已订票且付款-------
---3. 2为已订票未付款-------
--------------------------
*/
int Num = 0;

int RouteNum = 0;

Route route[132];

bool hasNextInt(string a)
{
	for (int i = 0; i < a.size(); i++)
	{
		int tmp = (int)a[i];
		if (tmp >= 48 && tmp <= 57)
			continue;
		else
			return false;
	} 
	return true;
}

int GetInt(string a)
{
	while (!hasNextInt(a))
	{
		printf("Error! Please input the number:");
		cin>>a;
	}
	int temp = 0;
	for(int i=0;i<a.size();i++)
	{
		temp = temp*10 + (a[i]-'0');
	}
	return temp;
}

//航线设置
void Route_Setting()
{
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 12; j++)
        {
            if(i != j)
            {
                route[RouteNum].setRoute(PlaceName[j],PlaceName[i]);
                route[RouteNum].setFlying_on_Sunday(TimeDay[RouteNum % 7]);
                route[RouteNum].setAirplane_Num(AirplaneNum[RouteNum % 11]);
                route[RouteNum].setFlight_Number(RouteNum+1);
                route[RouteNum].setOccupant_quota(AirplaneSize[RouteNum % 11]);
                route[RouteNum].setRest_Ticket(AirplaneSize[RouteNum % 11]);
                route[RouteNum].setSeat_Number(1);
                route[RouteNum].setBookClient(0);
                route[RouteNum].setWaitClient(0);
                RouteNum++;
            }
        }
    }
}
/*
//航线号
string Flight_Number()
{
    if(Num < 10)
    {
        Num++;
        return "HB00" + Num;
    }
    else if(Num<100)
    {
        Num++;
        return "HB0" + Num;
    }
    else if(Num<132)
    {
        Num++;
        return "HB" + Num;
    }
}
*/