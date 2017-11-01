#include "FunctionDefinition.h"
#include <iostream>
using namespace std;

/*
-------------------------------------------
-根据客户提供的情况(日期、航班)为客户办理退票手续--
-然后查询该航班是否有人排队候补-----------------
-首先询问排在第一的客户------替补客户-----------
-若所退票额能满足他的要求----------------------
-则为他办理订票手续---------------------------
-否则依次询问其他排队候补的客户-----------------
-------------------------------------------
*/

void Refund()//退票业务
{
    int j = 0;
    char chioce;
    string Day;
    string place;
    int Flight;
    int num = 0;
    while(true)
    {
        DisRefund();
        chioce = getch();
        system("cls");
        switch(chioce)
        {
            case '1':
                printf("请输入终点站：");
                cin >> place;
                for(int i=0;i<12;i++)
                {
                    if(place == PlaceName[i] || place == placeName[i])
                    {
                        j=1;
                        listRoute();
                        listAcPlace(PlaceName[i]);
                    }
                }
                if(j == 0)
                {
                    printf("未找到该终点站！");
                    system("pause");
                    break;
                }
                Day = getDay();
                if(Day == "EXIT")
                {
                    break;
                }
                Flight = getFlight();
                num = 1;
                if(DayAndFlight(Day,Flight))
                {
                    printf("\n退票成功！\n");
                    system("pause");
                    break;
                }
                else
                {
                    printf("\n退票失败！\n");
                    system("pause");
                    break;
                }
                break;
            case '2':
                if(num == 1)
                {
                    if(Waiting_Agent(Day,Flight))
                    {
                        printf("\n成功办理订票手续！\n");
                        system("pause");
                        break;
                    }
                    else
                    {
                        system("pause");
                        break;
                    }
                }
                else
                {
                    printf("没有人退票无法预订！");
                    system("pause");
                    break;
                }
                break;
            case '0':
                return;
            default:
                printf("输入错误！\n请重新输入：");
                system("pause");
                break;
        }
    }
}

string getDay()//获取日期
{
    string Day;
    printf("输入日期格式：\n");
    for(int i = 0;i<7;i++)
    {
        cout<<"    "<<TimeDay[i]<<" / "<<timeDay[i]<<endl;
    }
    printf("请输入:");
    cin>>Day;
    Day = Determine_Date(Day);
    return Day;
}

int getFlight()//获取航班号
{
    string Flight_i;
    int Flight;
    printf("请输入航班号1 - 132：");
    cin>>Flight_i;
    Flight = GetInt(Flight_i);
    Flight = Determine_Flight(Flight);
    return Flight;
}

bool DayAndFlight(string Day, int Flight) // 输入日期和航班还有个人信息
{
    string name;
    char c;
    int j=0;
    while(true)
    {
        printf("请输入姓名：");
        cin >> name;
        for(int i=0;i<132;i++)
        {
            if(route[i].getFlight_Number() == Flight && route[i].getFlying_on_Sunday() == Day)
            {
                for(j = 0;j<route[i].getBookClient()+1;j++)
                {
                    if(route[i].bookClient[j].getName() == name)
                    {
                        return refundTicket(i,j);
                    }
                    if(j == route[i].getBookClient())
                    {
                        printf("未找到该乘客！");
                        system("pause");
                        return false;
                    }
                }
            }
        }
        printf("请问是否继续选择退票：(Y/N)");
        cin >> c;
        if(c == 'Y' || c == 'y')
        {
            continue;
        }
        else if(c == 'N' || c == 'n')
        {
            return false;
        }
    }
    return false;
}

bool refundTicket(int i, int j) // 退票
{
    int n;
    string n_i;
    char c;
    while(true)
    {
        printf("您可退的票有%d张",route[i].bookClient[j].getTheAmountOfBooking());
        printf("请问您需要退几张票?\n");
        cin >> n_i;
        n = GetInt(n_i);
        if(n > route[i].bookClient[j].getTheAmountOfBooking())
        {
            printf("您所退的票量超过你已订的票量，无法退票！\n");
            printf("请问你是否需要继续退票？(Y/N)\n");
            printf("请输入：");
            cin >> c;
            if(c == 'Y' || c == 'y')
            {
                continue;
            }
            else if(c == 'N' || c == 'n')
            {
                return false;
            }
        }
        else if(n == 0)
        {
            printf("输入为0，无法退票");
            printf("请问你是否需要继续退票？(Y/N)\n");
            printf("请输入：");
            cin >> c;
            if(c == 'Y' || c == 'y')
            {
                continue;
            }
            else if(c == 'N' || c == 'n')
            {
                return false;
            }
        }
        else if(n == route[i].bookClient[j].getTheAmountOfBooking())
        {
            route[i].setBookClient(route[i].getBookClient() - 1);
            route[i].setRest_Ticket(route[i].getRest_Ticket() + n);
            route[i].setSeat_Number(route[i].getSeat_Number() - n);
            for(int x=j;x < route[i].getBookClient();x++)
            {
                route[i].bookClient[x].setName(route[i].bookClient[x+1].getName());
                route[i].bookClient[x].setTheAmountOfBooking(route[i].bookClient[x+1].getTheAmountOfBooking());
                route[i].bookClient[x].setIsNoPay(route[i].bookClient[x+1].getIsNoPay());
                //route[i].bookClient[x].setseat_Head(route[i].bookClient[x+1].getseat_Head());
                //route[i].bookClient[x].setseat_Feet(route[i].bookClient[x+1].getseat_Feet());
            }
            route[i].bookClient[route[i].getBookClient()].setName(" ");
            route[i].bookClient[route[i].getBookClient()].setTheAmountOfBooking(0);
            //route[i].bookClient[route[i].getBookClient()].setseat_Head(0);
            //route[i].bookClient[route[i].getBookClient()].setseat_Feet(0);
            route[i].bookClient[route[i].getBookClient()].setIsNoPay(false);
            route[i].setBookClient(route[i].getBookClient() - 1);
            return true;
        }
        else if(n < route[i].bookClient[j].getTheAmountOfBooking() && n > 0)
        {
            route[i].setRest_Ticket(route[i].getRest_Ticket() + n);
            route[i].setSeat_Number(route[i].getSeat_Number() - n);
            route[i].bookClient[route[i].getBookClient()].setName(" ");
            route[i].bookClient[route[i].getBookClient()].setTheAmountOfBooking(0);
            //route[i].bookClient[route[i].getBookClient()].setseat_Feet(route[i].bookClient[route[i].getBookClient()].getseat_Feet() - n);
            return true;
        }
    }
}

string Determine_Date(string Day) // 判定日期输入是否正确
{
    while(true)
    {
        for(int i=0;i<7;i++)
        {
            if(Day == TimeDay[i] || Day == timeDay[i])
            {
                return TimeDay[i];
            }
        }
        printf("输入错误！\n 如果取消退票，请输入N \n");
        printf("请重新输入:");
        cin >> Day;
        if(Day == "N" || Day == "n")
        {
            return "EXIT";
        }
    }
}

int Determine_Flight(int Flight) // 判定航班号是否输入正确
{
    string Flight_i;
    while(true)
    {
        if(Flight > 132 || Flight <= 0)
        {
            printf("输入错误！\n");
            printf("请重新输入：");
            cin>>Flight_i;
            Flight = GetInt(Flight_i);
        }
        else
        {
            return Flight;
        }
    }
}

bool Waiting_Agent(string Day, int Flight)//询问等待客户时候办理订票手续
{
    int t=0;
    int j;
    for(int i=0;i<132;i++)
    {
        if(route[i].getFlight_Number() == Flight && route[i].getFlying_on_Sunday() == Day && route[i].getWaitClient() != 0)
        {
            for(j = 0;j<route[i].getWaitClient();j++)
            {
                if(route[i].getRest_Ticket() >= route[i].waitClient[j].getTheAmountOfBooking())
                {
                    if(IsNoBook(i,j))
                    {
                        t=2;
                        return true;
                    }
                    else
                    {
                        t=1;
                    }
                }
            }
            if(j == route[i].getWaitClient() && t == 1)
            {
                printf("\n没人接收订票价格！\n");
                return false;
            }
            else if(j == route[i].getWaitClient() && t == 0)
            {
                printf("未找到复合要求的乘客！");
                return false;
            }
        }
    }
    printf("该航线没有正在等待客户！");
    return false;
}

bool IsNoBook(int i, int j)//是否需要订票
{
    char c;
    printf("\n订票价格为100元");
    cout<<route[i].waitClient[j].getName()<<":";
    printf("\n是否需要且同意该订票价格？(Y/N)\n");
    cin >> c;
    if(c == 'Y' || c == 'y')
    {
        SetR(i,j);
        SetBook(i,j);
        SetWait(i,j);
        return true;
    }
    else if(c == 'N' || c == 'n')
    {
        return false;
    }
}

void SetR(int i,int j)//设置航线信息
{
    route[i].setFlying_on_Sunday(route[i].getFlying_on_Sunday());
    route[i].setRest_Ticket(route[i].getRest_Ticket() - route[i].waitClient[j].getTheAmountOfBooking());
    route[i].setSeat_Number(route[i].getSeat_Number() + route[i].waitClient[j].getTheAmountOfBooking());
    route[i].setBookClient(route[i].getBookClient()+1);
    route[i].setWaitClient(route[i].getWaitClient()-1);
}

void SetBook(int i,int j)//设置订票客户信息
{
    route[i].bookClient[route[i].getBookClient() - 1].setName(route[i].waitClient[j].getName());
    route[i].bookClient[route[i].getBookClient() - 1].setTheAmountOfBooking(route[i].waitClient[j].getTheAmountOfBooking());
    route[i].bookClient[route[i].getBookClient() - 1].setIsNoPay(true);
    //route[i].bookClient[route[i].getBookClient() - 1].setseat_Head(route[i].getSeat_Number() - route[i].waitClient[j].getTheAmountOfBooking());
    //route[i].bookClient[route[i].getBookClient() - 1].setseat_Feet(route[i].getSeat_Number() - 1);
}

void SetWait(int i,int j)//设置等待客户信息
{
    int x=0;
    for(x=j;x<route[i].getWaitClient()+1;x++)
    {
        route[i].waitClient[x].setName(route[i].waitClient[x+1].getName());
        route[i].waitClient[x].setTheAmountOfBooking(route[i].waitClient[x+1].getTheAmountOfBooking());
    }
    route[i].waitClient[x].setName(" ");
    route[i].waitClient[x].setTheAmountOfBooking(0);
}

