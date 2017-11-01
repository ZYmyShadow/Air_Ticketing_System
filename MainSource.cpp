/*
-----------------------------
-------航空客运订票系统------
-----------------------------
*/
#include "FunctionDefinition.h"
#include <iostream>
using namespace std;

int main()
{
    Route_Setting();
    char c;
    while(true)
    {
        Display();
        c = getch();
        switch (c)
        {
            case '1':
                Query_Route();
                system("pause");
                break;
            case '2':
                Booking_Tickets();
                system("pause");
                break;
            case '3':
                Refund();
                system("pause");
                break;
            case '0':
                exit(0);
                break;
            default:
                printf("\nError!\n");
                system("pause");
                break;
        }
    }
	return 0;
}
