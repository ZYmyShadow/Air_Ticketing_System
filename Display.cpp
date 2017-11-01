#include "FunctionDefinition.h"
#include <iostream>
using namespace std;

/*
--------------------
-------显示界面------
--------------------
*/

//开始界面
void Display()
{
    system("cls");
    cout<<"\n\n\n\n";
    cout<<"\t\t欢迎来到航空服务\t\t";
    cout<<"\n\n";
    cout<<"\t============================\n";
    cout<<"\t\t 1. 查询航线 \t\t";
    cout<<"\n\n";
    cout<<"\t\t 2. 订票业务 \t\t";
    cout<<"\n\n";
    cout<<"\t\t 3. 退票业务 \t\t";
    cout<<"\n\n";
    cout<<"\t\t 0. 退出系统 \t\t";
    cout<<"\n";
    cout<<"\t============================\n";
    cout<<"\n\n\n";
    cout<<"\t\t请选择：";
}

//订票界面
void DisBookTickets()
{
    system("cls");
    cout<<"\n\n\n\n";
    cout<<"\t\t欢迎来到订票系统\t\t";
    cout<<"\n\n";
    cout<<"\t============================\n";
    cout<<"\t\t 1. 选择终点站 \t\t";
    cout<<"\n\n";
    cout<<"\t\t 2. 输入订票信息 \t\t";
    cout<<"\n\n";
    cout<<"\t\t 3. 付款 \t\t";
    cout<<"\n\n";
    cout<<"\t\t 0. 返回上一级 \t\t";
    cout<<"\n";
    cout<<"\t============================\n";
    cout<<"\n\n\n";
    cout<<"\t\t请选择：";
}

//退票界面
void DisRefund()
{
    system("cls");
    cout<<"\n\n\n\n";
    cout<<"\t\t欢迎来到退票系统\t\t";
    cout<<"\n\n";
    cout<<"\t============================\n";
    cout<<"\t\t 1. 输入个人信息 \t\t";
    cout<<"\n\n";
    cout<<"\t\t 2. 询问排在等候客户 \t\t";
    cout<<"\n\n";
    cout<<"\t\t 0. 返回上一级 \t\t";
    cout<<"\n";
    cout<<"\t============================\n";
    cout<<"\n\n\n";
    cout<<"\t\t请选择：";
}

//航线显示
void DisRoute()
{
    system("cls");
    cout<<"\n\n\n\n";
    cout<<"\t\t欢迎来到航空服务\t\t";
    cout<<"\n\n";
    cout<<"\t============================\n";
    cout<<"\t\t 1. 今日航线 \t\t";
    cout<<"\n\n";
    cout<<"\t\t 2. 明日航线 \t\t";
    cout<<"\n\n";
    cout<<"\t\t 3. 指定航线 \t\t";
    cout<<"\n\n";
    cout<<"\t\t 0. 返回上一级 \t\t";
    cout<<"\n";
    cout<<"\t============================\n";
    cout<<"\n\n\n";
    cout<<"\t\t请选择：";
}