#include "NeedHead.h"

/*
--------------------------
---1. 初始化0为空位---------
---2. 1为已订票且付款-------
---3. 2为已订票未付款-------
---4. 3为等待客户-----------
--------------------------
*/

//飞机固定航线
//void Fixed_Route();

//航线设置
void Route_Setting();

//航线号
string Flight_Number();

/*
-------------------------
------判断是否为正整数------
-------------------------
*/
bool hasNextInt(string a);

int GetInt(string a);

/*
--------------------
-------显示界面------
--------------------
*/
//开始界面
void Display();

//订票界面
void DisBookTickets();

//退票界面
void DisRefund();

//查询航线界面
void DisRoute();

//题目
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
void Query_Route();//查询航线

string GetTime();/*获取当天时间*/

string SetTime(string time);/*设置第二天的时间*/

void listRoute();//打印航线格式

void listAcTime(string time);//根据时间打印全部航线信息
    
void listAcPlace(string Place);//根据地点打印全部航线信息

/*
-------------------------------------------------
-根据客户提出的要求（航班号、订票数额）查询该航班票额情况-
-若尚有余票，则为客户办理订票手续，输出座位号-----------
-若以满员或余票额少于定票额，则需重新询问客户要求--------
-若需要，可登记排队候补------------------------------
-------------------------------------------------
*/
void Booking_Tickets();//订票业务

//void initR();//初始化局部变量r

int SeletePlace();//选择终点站

int SeleteFlight(string place);//选择航班号

bool IsWait(string name,int num,int TicketNum);//是否继续订票
    
bool bookTickets(int num);//输入订票量级个人信息

int Input(string place);//输入信息

bool PayFee(int num);//付款

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
void Refund();//退票业务

string getDay();//获取日期

int getFlight();//获取航班号

bool DayAndFlight(string Day, int Flight); // 输入日期和航班还有个人信息

bool refundTicket(int i, int j); // 退票

string Determine_Date(string Day); // 判定日期输入是否正确

int Determine_Flight(int Flight); // 判定航班号是否输入正确

bool Waiting_Agent(string Day, int Flight);//询问等待客户时候办理订票手续

bool IsNoBook(int i, int j);//是否需要订票

void SetR(int i,int j);//设置航线信息
    
void SetBook(int i,int j);//设置订票客户信息
    
void SetWait(int i,int j);//设置等待客户信息