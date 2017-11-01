#include "FunctionDefinition.h"
#include <iostream>
using namespace std;

/*
------------------------------
-根据旅客提出的终点站名输出下列信息：
------------------------------
-----航班号--------------------
-----飞机号--------------------
-----星期几飞行-----------------
-----最近一天航班的日期----------
-----余票额--------------------
------------------------------
*/
void Query_Route()//查询航线
{
    char c;
    int i=0;
    string time;
    string place;
    while(true)
    {
        DisRoute();
        c = getch();
        switch (c)
        {
            case '1':
                time = GetTime();
                listRoute();
                listAcTime(time);
                system("pause");
                break;
            case '2':
                time = GetTime();
                time = SetTime(time);
                listRoute();
                listAcTime(time);
                system("pause");
                break;
            case '3':
                cout<<endl;
                for(int x=0;x<12;x++)
                {
                    cout<<PlaceName[x]<<" ";
                }
                cout<<endl;
                printf("请输入终点站：");
                cin>>place;
                for(i=0;i<12;i++)
                {
                    if(PlaceName[i] == place || placeName[i] == place)
                    {
                        listRoute();
                        listAcPlace(PlaceName[i]);
                        system("pause");
                        break;
                    }
                }
                if(i == 12)
                {
                    printf("没有找到该目的地的航班!\n");
                    system("pause");
                    break;
                }
                else
                    break;
                break;
            case '0':
                printf("\n返回上一级！\n");
                return;
            default:
                printf("Error!\n");
                system("pause");
                break;
        }
    }
}

string GetTime()/*获取当天时间*/
{
    time_t t = time(0); 
    char tmp[9]; 
    strftime( tmp, sizeof(tmp), "%A",localtime(&t)); 
    string m(&tmp[0],&tmp[strlen(tmp)]);
    return m;
}

/*设置第二天的时间*/
string SetTime(string time)
{
    for(int i=0;i<7;i++)
    {
        if(TimeDay[i] == time)
        {
            time = TimeDay[(i+1)%7];
            return time;
        }
    }
    return time;
}

void listRoute()//打印航线格式
{
    system("cls");
    cout<<"\n=====================================================================================\n";
    cout<<"终点站"<<setw(15)<<"航班号"<<setw(15)<<"飞机号"<<setw(15)<<"飞行时间"<<setw(15)<<"余票量";
    cout<<"\n=====================================================================================\n";
}

void listAcTime(string time)//根据时间打印全部航线信息
{
    for(int i=0;i<132;i++)
    {
        if(route[i].getFlying_on_Sunday() == time)
        {
            cout<<route[i].getTerminal_Name();
			cout<<setw(15)<<route[i].getFlight_Number();
			cout<<setw(15)<<route[i].getAirplane_Num();
			cout<<setw(15)<<route[i].getFlying_on_Sunday();
			cout<<setw(15)<<route[i].getRest_Ticket();
			cout<<endl;
        }
    }
}

/*根据客户提出的终点站名输出航线信息*/
void listAcPlace(string Place)//根据地点打印全部航线信息
{
    for(int i=0;i<132;i++)
    {
        if(route[i].getTerminal_Name() == Place)
        {
            cout<<route[i].getTerminal_Name();
			cout<<setw(15)<<route[i].getFlight_Number();
			cout<<setw(15)<<route[i].getAirplane_Num();
			cout<<setw(15)<<route[i].getFlying_on_Sunday();
			cout<<setw(15)<<route[i].getRest_Ticket();
			cout<<endl;
        }
    }
}