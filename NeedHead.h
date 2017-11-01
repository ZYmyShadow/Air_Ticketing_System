#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <iomanip>

#include "Route.h"


extern Route route[];

/*
Airplane1 airplane1[12];
Airplane2 airplane2[12];
Airplane3 airplane3[12];
Airplane4 airplane4[12];
Airplane5 airplane5[12];
Airplane6 airplane6[12];
Airplane7 airplane7[12];
Airplane8 airplane8[12];
Airplane9 airplane9[12];
Airplane10 airplane10[12];
Airplane11 airplane11[12];
*/

static string PlaceName[12] = {"武汉","北京","上海","沈阳","深圳","佛山","合肥","广州","昆明","成都","重庆","贵阳"};
static string placeName[12] = {"wuhan","beijing","shanghai","shenyang","shenzhen","fushan","hefei","guangzhou","kunming","chengdu","chongqing","guiyang"};

static string TimeDay[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
static string timeDay[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

static string AirplaneNum[11] = {"A300_700","A310_200F","A350_800","A380_800","B707_320C","Boeing_717","B737_700","A350_700","A250_250","E539_167","S364_792"};
static int AirplaneSize[11] = {20,19,18,17,16,15,14,13,12,11,10};