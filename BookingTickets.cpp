#include "FunctionDefinition.h"
#include <iostream>
using namespace std;

/*
-------------------------------------------------
-根据客户提出的要求（航班号、订票数额）查询该航班票额情况-
-若尚有余票，则为客户办理订票手续，输出座位号-----------
-若以满员或余票额少于定票额，则需重新询问客户要求--------
-若需要，可登记排队候补------------------------------
-------------------------------------------------
*/
int paynum=0;
Route r;

void Booking_Tickets()//订票业务
{
    char c;
    int num = -2;
    int RouteNum = 0;
    paynum = 0;
    //initR();
    while(true)
    {
        DisBookTickets();
        c = getch();
        switch (c)
        {
            case '1':
                num = SeletePlace();
                if(num == -1)
                {
                    printf("没有该地点的航班!\n");
                    system("pause");
                    break;
                }
                else
                {
                    listRoute();
                    listAcPlace(PlaceName[num]);
                }
                system("pause");
                break;
            case '2':
                if(num == -2)
                {
                    printf("没有选择终点站！\n");
                    system("pause");
                    break;
                }
                else if(num == -1)
                {
                    printf("没有该地点的航班！\n");
                    system("pause");
                    break;
                }
                /*else if(paynum == 2)
                {
                    printf("上一个客户没有付款无法执行订票");
                    system("pause");
                    break;
                }*/
                else
                {
                    listRoute();
                    listAcPlace(PlaceName[num]);
                    RouteNum = Input(PlaceName[num]);
                    break;
                }
                system("pause");
                break;
            case '3':
                if(RouteNum == -2 || RouteNum == -1)
                {
                    printf("您无需付款！");
                    system("pause");
                    break;
                }
                else
                {
                    if(paynum == 3 || paynum == 1)
                    {
                        printf("您无需付款！");
                        system("pause");
                        break;
                    }
                    else if(paynum == 2)
                    {
                        if(PayFee(RouteNum))
                        {
                            printf("付款成功！");
                            paynum = 1;
                            system("pause");
                            break;
                        }
                        else
                        {
                            printf("付款失败");
                            system("pause");
                            break;
                        }
                        system("pause");
                        break;
                    }
                    else if(paynum == 0)
                    {
                        printf(" 无需付款！");
                        system("pause");
                        break;
                    }
                }
                system("pause");
                break;
            case '0':
                if(paynum == 2)
                {
                    char selete;
                    while(true)
                    {
                        printf("您需要付款，否则订票作废！\n");
                        printf("请问你需要付款吗（Y/N）？：");
                        cin >> selete;
                        if(selete == 'Y' || selete == 'y')
                        {
                            break;
                        }
                        else if(selete == 'N' || selete == 'n')
                        {
                            r.setRest_Ticket(0);
                            r.bookClient[r.getBookClient()].setName(" ");
                            r.bookClient[r.getBookClient()].setTheAmountOfBooking(0);
                            r.setBookClient(r.getBookClient()-1);
                            r.setSeat_Number(0);
                            return ;
                        }
                        else
                        {
                            printf("输入错误！\n");
                            printf("请重新输入：");
                        }
                    }
                }
                else
                {
                    return;
                }
                break;
            default:
                printf("Error!");
                system("pause");
                break;
        }
    }
}
/*
void initR()//初始化局部变量r
{
    r.setRest_Ticket(0);
    r.setBookClient(0);
    r.setWaitClient(0);
    r.setSeat_Number(1);
    for(int i=0;i<600;i++)
    {
        
    }
    r.bookClientNum[0];
}*/

int SeletePlace()//选择终点站
{
    cout<<endl;
    for(int i=0;i<12;i++)
    {
        cout<<PlaceName[i]<<" ";
    }
    cout<<endl;
    printf("请选择终点站(中文或者拼音)：");
    string Ter_name;
    cin >> Ter_name;
    for(int i=0;i<12;i++)
    {
        if(Ter_name == PlaceName[i] || Ter_name == placeName[i])
        {
            return i;
        }
    }
    return -1;
}

int SeleteFlight(string place)//选择航班号
{
    int Flight;
    string Place;
    string Flight_i;
    int Flight_num;
    cin >> Flight_i;
    Flight_num = GetInt(Flight_i);
    for(int i=0;i<132;i++)
    {
        Flight = route[i].getFlight_Number();
        Place = route[i].getTerminal_Name();
        if(Flight == Flight_num && Place == place)
        {
            return i;
        }
    }
    return -1;
}

bool IsWait(string name,int num,int TicketNum)//是否继续订票
{
    char IsNo;
    printf("是否确认需要订票(Y/N)？\n");
    while(true)
    {
        cin>>IsNo;
        if(IsNo == 'Y' || IsNo == 'y')
        {
            printf("请等待有人退票，谢谢使用！");
            r.waitClient[r.getWaitClient()].setName(name);
            r.waitClient[r.getWaitClient()].setTheAmountOfBooking(TicketNum);
            r.setWaitClient(r.getWaitClient()+1);
            paynum = 3;
            if(r.getWaitClient() != 0)
            {
                route[num].waitClient[route[num].getWaitClient()].setName(r.waitClient[r.getWaitClient()-1].getName());
                route[num].waitClient[route[num].getWaitClient()].setTheAmountOfBooking(r.waitClient[r.getWaitClient()-1].getTheAmountOfBooking());
                route[num].setWaitClient(route[num].getWaitClient()+1);
            }
            return true;
        }
        else if(IsNo == 'N' || IsNo == 'n')
        {
            printf("谢谢");
            return false;
        }
        else
        {
            printf("输入错误！\n");
            printf("请重新输入：");
        }
    }
}

bool bookTickets(int num)//输入订票量级个人信息
{
    string name;
    string Ticket_i;
    int TicketNum;
    printf("请输入你的姓名（xxx）：");
    cin>>name;
    printf("每人最多定7张票\n请输入所需票量：");
    while(true)
    {
        //cin >> TicketNum;
        cin>>Ticket_i;
        TicketNum = GetInt(Ticket_i);
        if(TicketNum > 7)
        {
            printf("您只能定最多7张票！\n");
            printf("请重新输入需要多少张机票(输入0退出订票)：");
        }
        else if(TicketNum > route[num].getRest_Ticket())
        {
            printf("抱歉，你所需要的票量超出了剩余票量!\n剩余票量为%d",route[num].getRest_Ticket());
            return IsWait(name,num,TicketNum);
        }
        else if(TicketNum == 0)
        {
            return false;
        }
        else if(TicketNum > 0 && TicketNum <= 7)
        {
            break;
        }
        else
        {
            printf("输入错误，请重新输入：");
        }
    }
    r.setBookClient(0);
    r.setRest_Ticket(TicketNum);
    r.bookClient[r.getBookClient()].setName(name);
    r.bookClient[r.getBookClient()].setTheAmountOfBooking(TicketNum);
    //r.bookClient[r.getBookClient()].setseat_Head(route[num].getSeat_Number());
    //r.bookClient[r.getBookClient()].setseat_Feet(route[num].getSeat_Number()+TicketNum-1);
    r.setBookClient(1);
    printf("座位号为%d - %d\n",route[num].getSeat_Number(),route[num].getSeat_Number()+TicketNum-1);
    r.setSeat_Number(TicketNum);
    paynum = 2;
    return true;
}

int Input(string place)//输入信息
{
    printf("\n请选择航班号：");
    int num = -2;
    num = SeleteFlight(place);
    if(num == -1)
    {
        printf("该终点站没有该航班！\n");
        system("pause");
        return num;
    }
    else
    {
        if(bookTickets(num))
        {
            printf("\n订票成功");
            system("pause");
            return num;
        }
        else
        {
            printf("取消订票！");
            system("pause");
            return -2;
        }
    }
}

bool PayFee(int num)//付款
{
    char c;
    printf("\n是否付款（Y/N）:");
    while(true)
    {
        cin>>c;
        if(c == 'Y' || c == 'y')
        {
            if(r.getBookClient() != 0)
            {
                route[num].setRest_Ticket(route[num].getRest_Ticket() - r.getRest_Ticket());
                route[num].bookClient[route[num].getBookClient()].setName(r.bookClient[r.getBookClient()-1].getName());
                route[num].bookClient[route[num].getBookClient()].setTheAmountOfBooking(r.getRest_Ticket());
                //route[num].bookClient[route[num].getBookClient()].setseat_Head(r.bookClient[r.getBookClient()-1].getseat_Head());
                //route[num].bookClient[route[num].getBookClient()].setseat_Feet(r.bookClient[r.getBookClient()-1].getseat_Feet());
                route[num].setBookClient(route[num].getBookClient()+1);
                route[num].setSeat_Number(route[num].getSeat_Number()+r.getSeat_Number());
            }
            /*if(r.getWaitClient() != 0)
            {
                route[num].waitClient[route[num].getWaitClient()].setName(r.waitClient[r.getWaitClient()-1].getName());
                route[num].waitClient[route[num].getWaitClient()].setTheAmountOfBooking(r.waitClient[r.getWaitClient()-1].getTheAmountOfBooking());
                route[num].setWaitClient(route[num].getWaitClient()+1);
            }*/
            route[num].bookClient[route[num].getBookClient()-1].setIsNoPay(true);
            return true;
        }
        else if(c == 'N' || c == 'n')
        {
            return false;
        }
        else
        {
            printf("输入错误，请重新输入（Y/N）：");
        }
    }
}