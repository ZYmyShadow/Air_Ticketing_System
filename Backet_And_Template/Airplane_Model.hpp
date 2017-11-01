#include <Route.h>
#include <string.h>
#include <iostream>
using namespace std;

/*
------------------
---1. 飞机型号-----
---2. 飞机座位数----
---3. 三级舱-------
---4. 二级舱-------
---5. 经济舱-------
---6. 航线---------
------------------
*/

//有座位号


class Airplane1 // A300
{
private:
    string Name = "A300";
    int Size = 298;
    int Three_Class_Cabin = 0;
    int Two_Class_Cabin = 266;
    int Economy_Class = 32;
    Route route;
public:
    void setRoute(Route route)
    {
        route = route;
    }
    Route getRoute()
    {
        return route;
    }
    string getName()
    {
        return Name;
    }
     int getSize()
    {
        return Size;
    }
     int getThree_Class_Cabin()
    {
        return Three_Class_Cabin;
    }
     int getTwo_Class_Cabin()
    {
        return Two_Class_Cabin;
    }
     int getEconomy_Class()
    {
        return Economy_Class;
    }
};

class Airplane2 // A310_200F
{
private:
    string Name = "A310_200F";
    int Size = 220;
    int Three_Class_Cabin = 0;
    int Two_Class_Cabin = 220;
    int Economy_Class = 0;
    Route route;
public:
    void setRoute(Route route)
    {
        route = route;
    }
    Route getRoute()
    {
        return route;
    }
    string getName()
    {
        return Name;
    }
     int getSize()
    {
        return Size;
    }
     int getThree_Class_Cabin()
    {
        return Three_Class_Cabin;
    }
     int getTwo_Class_Cabin()
    {
        return Two_Class_Cabin;
    }
     int getEconomy_Class()
    {
        return Economy_Class;
    }
};

class Airplane3 // A350_800
{
private:
    string Name = "A350_800";
    int Size = 253;
    int Three_Class_Cabin = 253;
    int Two_Class_Cabin = 0;
    int Economy_Class = 0;
    Route route;
public:
    void setRoute(Route route)
    {
        route = route;
    }
    Route getRoute()
    {
        return route;
    }
    string getName()
    {
        return Name;
    }
     int getSize()
    {
        return Size;
    }
     int getThree_Class_Cabin()
    {
        return Three_Class_Cabin;
    }
     int getTwo_Class_Cabin()
    {
        return Two_Class_Cabin;
    }
     int getEconomy_Class()
    {
        return Economy_Class;
    }
};

class Airplane4 // A380_800
{
private:
    string Name = "A380_800";
    int Size = 555;
    int Three_Class_Cabin = 555;
    int Two_Class_Cabin = 0;
    int Economy_Class = 0;
    Route route;
public:
    void setRoute(Route route)
    {
        route = route;
    }
    Route getRoute()
    {
        return route;
    }
    string getName()
    {
        return Name;
    }
     int getSize()
    {
        return Size;
    }
     int getThree_Class_Cabin()
    {
        return Three_Class_Cabin;
    }
     int getTwo_Class_Cabin()
    {
        return Two_Class_Cabin;
    }
     int getEconomy_Class()
    {
        return Economy_Class;
    }
};

class Airplane5 // B707_320C
{
private:
    string Name = "B707_320C";
    int Size = 147;
    int Three_Class_Cabin = 0;
    int Two_Class_Cabin = 147;
    int Economy_Class = 0;
    Route route;
public:
    void setRoute(Route route)
    {
        route = route;
    }
    Route getRoute()
    {
        return route;
    }
    string getName()
    {
        return Name;
    }
     int getSize()
    {
        return Size;
    }
     int getThree_Class_Cabin()
    {
        return Three_Class_Cabin;
    }
     int getTwo_Class_Cabin()
    {
        return Two_Class_Cabin;
    }
     int getEconomy_Class()
    {
        return Economy_Class;
    }
};

class Airplane6 // Boeing_717
{
private:
    string Name = "Boeing_717";
    int Size = 148;
    int Three_Class_Cabin = 0;
    int Two_Class_Cabin = 106;
    int Economy_Class = 42;
    Route route;
public:
    void setRoute(Route route)
    {
        route = route;
    }
    Route getRoute()
    {
        return route;
    }
    string getName()
    {
        return Name;
    }
     int getSize()
    {
        return Size;
    }
     int getThree_Class_Cabin()
    {
        return Three_Class_Cabin;
    }
     int getTwo_Class_Cabin()
    {
        return Two_Class_Cabin;
    }
     int getEconomy_Class()
    {
        return Economy_Class;
    }
};

class Airplane7 // B737_700
{
private:
    string Name = "B737_700";
    int Size = 149;
    int Three_Class_Cabin = 0;
    int Two_Class_Cabin = 0;
    int Economy_Class = 149;
    Route route;
public:
    void setRoute(Route route)
    {
        route = route;
    }
    Route getRoute()
    {
        return route;
    }
    string getName()
    {
        return Name;
    }
     int getSize()
    {
        return Size;
    }
     int getThree_Class_Cabin()
    {
        return Three_Class_Cabin;
    }
     int getTwo_Class_Cabin()
    {
        return Two_Class_Cabin;
    }
     int getEconomy_Class()
    {
        return Economy_Class;
    }
};

class Airplane8 // A350_700
{
private:
    string Name = "A350_700";
    int Size = 220;
    int Three_Class_Cabin = 60;
    int Two_Class_Cabin = 100;
    int Economy_Class = 60;
    Route route;
public:
    void setRoute(Route route)
    {
        route = route;
    }
    Route getRoute()
    {
        return route;
    }
    string getName()
    {
        return Name;
    }
     int getSize()
    {
        return Size;
    }
     int getThree_Class_Cabin()
    {
        return Three_Class_Cabin;
    }
     int getTwo_Class_Cabin()
    {
        return Two_Class_Cabin;
    }
     int getEconomy_Class()
    {
        return Economy_Class;
    }
};

class Airplane9 // A250_250
{
private:
    string Name = "A250_250";
    int Size = 230;
    int Three_Class_Cabin = 120;
    int Two_Class_Cabin = 80;
    int Economy_Class = 20;
    Route route;
public:
    void setRoute(Route route)
    {
        route = route;
    }
    Route getRoute()
    {
        return route;
    }
    string getName()
    {
        return Name;
    }
     int getSize()
    {
        return Size;
    }
     int getThree_Class_Cabin()
    {
        return Three_Class_Cabin;
    }
     int getTwo_Class_Cabin()
    {
        return Two_Class_Cabin;
    }
     int getEconomy_Class()
    {
        return Economy_Class;
    }
};

class Airplane10 // E539_167
{
private:
    string Name = "E539_167";
    int Size = 167;
    int Three_Class_Cabin = 73;
    int Two_Class_Cabin = 72;
    int Economy_Class = 32;
    Route route;
public:
    void setRoute(Route route)
    {
        route = route;
    }
    Route getRoute()
    {
        return route;
    }
    string getName()
    {
        return Name;
    }
     int getSize()
    {
        return Size;
    }
     int getThree_Class_Cabin()
    {
        return Three_Class_Cabin;
    }
     int getTwo_Class_Cabin()
    {
        return Two_Class_Cabin;
    }
     int getEconomy_Class()
    {
        return Economy_Class;
    }
};

class Airplane11 // S364_792
{
private:
    string Name = "S364_792";
    int Size = 430;
    int Three_Class_Cabin = 150;
    int Two_Class_Cabin = 150;
    int Economy_Class = 130;
    Route route;
public:
    void setRoute(Route route)
    {
        route = route;
    }
    Route getRoute()
    {
        return route;
    }
    string getName()
    {
        return Name;
    }
     int getSize()
    {
        return Size;
    }
     int getThree_Class_Cabin()
    {
        return Three_Class_Cabin;
    }
     int getTwo_Class_Cabin()
    {
        return Two_Class_Cabin;
    }
     int getEconomy_Class()
    {
        return Economy_Class;
    }
};