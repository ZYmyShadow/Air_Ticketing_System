#include <stdio.h>       /*标准输入、输出头文件*/
#include <string.h>      /*包含字符串函数处理头文件*/
#include <stdlib.h>
#include <process.h>     /*包含access函数的头文件*/
#define N 1000          /*定义最多的航班数*/
#define  PRINT  "%d\t\t%s\t\t%s\t\t 星 期 %s\t\t%d\n",s[i].num,s[i].start,s[i].over,s[i].time,s[i].count   /*宏定义输出格式*/

struct air              /*定义结构体数组*/
{
	int num;               /*定义航班号*/
	char start[20];         /*航班起始站*/
	char over[20];          /*终点站*/
	char time[10];          /*飞行时间*/
	int count;
}s[N];             /*机票数量*/

int i,m=0;              /*定义全局变量*/
char ii[10];

void add();             /*函数声明增加航班信息函数*/
void print();           /*显示航班信息*/
void search();          /*查找航班信息*/
void dingpiao();        /*订票业务*/
void tuipiao();         /*退票*/
void read();            /*读取文件*/
void save();            /*保存文件*/
void output();          /*输出格式*/
void paixu();           /*航班排序*/
void chushihua();       /*系统初始化*/
void build();           /*建立数据文件*/
void paixu1();          /*按航班号从小到大排序*/
void paixu2();          /*从大到小*/
void main()             /*主函数*/
{
	int j;    
	chushihua();            /*系统初始化判断是否存在原始数据文件*/ 
	printf("O(^_^)O欢迎使用天鑫飞机订票系统(*^__^*)\n"); /*打印出系统主界面*/
	do  {
			system("cls");
			printf("================================================================================\n");      
			printf("1.增加航班信息\n" 
				"\t2.浏览航班信息\n"  
				"\t\t3.查找航班信息(按航班号)\t\t╮（╯_╰）╭\n" 
				"\t\t\t4.航班排序(按航班号)\n" 
				"\t\t\t\t5.订票业务\n"  
				"\to（︶︿︶）o\t\t\t6.退票业务\n" 
				"\t\t\t\t\t\t0.退出\n");  
			printf("================================================================================\n");   
			printf("请在0-6中选择以回车键结束： "); 
			scanf("%d",&j); 
			system("cls");
			switch(j)  
			{
				case 1:
					add();         /*调用增加航班函数*/
					break;  
				case 2:
					print();         /*调用显示模块*/
					break;  
				case 3:
					search();        /*调用查找模块*/
					break;  
				case 4:
					paixu();         /*调用排序函数*/
					break;  
				case 5:
					dingpiao();      /*调用订票模块*/
					break;  
				case 6:
					tuipiao();       /*调用退票模块*/
					break;   
				case 0:                 /*退出系统*/
					save();  
					printf("谢谢使用，再见！ ");
					break;
			}
		}while(j!=0);
}           /*判断是否调用其他函数*/

void chushihua()        /*定义系统初始化函数*/
{
	if(access("hangban.dat",0)) 
	{
		build();
	} 
	else  
		read();
}    

void build()            /*定义建立数据文件函数*/
{
	FILE *fp;              /*定义文件指针*/ 
	if((fp=fopen("hangban.dat","wb"))==NULL)    /*打开文件并判定是否出错*/  
	{
		printf("创建文件失败! ");        /*打印出错提示*/
		getchar(); 
		return;
	}  
	printf("请依次输入航班信息(以回车键结束):\n");      /*打印提示信息*/
	printf("-------------------------------------------------------------------------- \n"); 
	for(i=0;i<N;i++)  
	{
		printf("请输入航班号: ");    
		scanf("%d",&s[i].num);            /*输入航班号*/
		printf("请输入起始站: ");  
		scanf("%s",s[i].start);           /*输入起始站*/
		printf("请输入终点站: ");  
		scanf("%s",s[i].over);            /*输入终点站*/
		printf("请输入时间(星期几): ");  
		scanf("%s",s[i].time);            /*输入时间*/
		printf("请输入机票数: ");  
		scanf("%d",&s[i].count);          /*输入机票数*/
		fwrite(&s[i],sizeof(struct air),1,fp); 
		m++;  
		printf("添加完毕,是否继续添加?\n请键入y或n以回车键结束:"); 
		scanf("%s",ii);  
		if(strcmp(ii,"y")!=0)             /*判断是否继续添加航班信息*/
		{
			fclose(fp);                      /*关闭文件*/
			return;
		}
	}
}  

void read()                       /*定义读取文件函数*/
{
	FILE *fp;  
	if((fp=fopen("hangban.dat","r"))==NULL) 
	{
		printf("创建文件失败! "); 
		getchar(); 
		return;
	} 
	i=0;  
	while(!feof(fp))  
	{
		fread(&s[i],sizeof(struct air),1,fp);       /*逐块读取数据*/
		i++;  
		m++;
	}               /*计算存在航班数*/
	m--; 
	fclose(fp);
}  

void save()         /*定义保存函数*/
{
	FILE *fp;  
	if((fp=fopen("hangban.dat","wb"))==NULL)   
	{
		printf("创建文件失败! "); 
		getchar(); 
		return;
	}  
	for(i=0;i<m;i++)       /*逐块保存数据*/
		fwrite(&s[i],sizeof(struct air),1,fp); 
	fclose(fp);
}  

void add()           /*定义增加航班信息函数*/
{
	do
	{
		printf("请依次输入您要增加的航班信息(以回车键结束):  \n"); /*打印提示信息*/
		printf("-------------------------------------------------------------------------- \n");
		printf("请输入航班号: ");    
		scanf("%d",&s[m].num);        /*读取航班号*/
		printf("请输入起始站: "); 
		scanf("%s",s[m].start);       /*读取起始站*/
		printf("请输入终点站: ");  
		scanf("%s",s[m].over);        /*读取终点站*/
		printf("请输入时间: ");  
		scanf("%s",s[m].time);        /*读取时间*/
		printf("请输入机票数: ");  
		scanf("%d",&s[m].count);      /*读取机票数*/  
		m++;  
		printf("添加完毕,是否继续添加?\n请键入y或n以回车键结束:"); 
		scanf("%s",ii);
	}  
	while(!strcmp(ii,"y"));
}/*判断是否继续添加*/

void output()                  /*定义输出格式函数*/ 
{
	printf("航班号\t\t起始站\t\t终点站\t\t时间\t\t机票数\n");  /*信息标题*/
	for(i =0;i<m;i++)  
		printf(PRINT);
}                

/*打印出信息*/   
void print()                   /*定义显示航班信息函数*/
{
	printf("\n目前我们有如下航班：\n");  
	output();                      /*调用输出格式函数*/
	printf("\n请按回车键返回上层菜单 "); 
	getchar(); 
	getchar();
}  

void search()                  /*定义查询函数*/
{
	int n;   
	do  
	{
		printf("\n请输入航班号： ");  
		scanf("%d",&n);                /*输入查询的航班号*/
		for(i=0;i<m;i++)  
		{
			if(s[i].num==n)                /*按航班号判定输出条件*/
			{
				printf("\n您所查找的航班信息为:\n ");  
				printf("航班号\t\t起始站\t\t终点站\t\t时间\t\t机票数 \n\n"); 
				printf(PRINT);                 /*显示信息*/
				printf("\n查询完毕，按回车键继续"); 
				getchar(); 
				getchar(); 
				return;
			}
		}  
		printf("\n对不起，没有您需要的信息！\n "); 
		printf("是否重新查找?请键入y或n以回车键结束 "); 
		scanf("%s",ii);
	}  
	while(!strcmp(ii,"y"));
}         /*判定是否重新查找*/

void dingpiao()                  /*定义订票业务函数*/
{
	int n;  
	char a[10]="y"; 
	do  
	{
		search();                       /*调用查询模块*/
		if(!strcmp(ii,"n"))  
		{
			printf("对不起!没有找到您所需要的航班,所以不能订票。\n");  /*未查找到所需航班*/ 
			printf("\n请按回车键返回上层菜单 "); 
			getchar(); 
			getchar(); 
			strcpy(ii,"n"); 
			break;
		} 
		do  
		{
			printf("请输入您要订的机票数（以回车键结束）： "); 
			scanf("%d",&n);                  /*输入所订机票数*/
			if(n<=0)                         /*判定机票数是否出错*/
			{
				printf("输入错误！至少需退1张机票。\n");
			}
			else if(s[i].count == 0)	//判断机票是否售完
			{
				printf("对不起，你所选择的航班的机票已售完！\n");
				break;
			}
			else if(s[i].count!=0&&s[i].count>=n)        /*判定机票数是否大于等于订票数*/  
			{
				s[i].count=s[i].count-n; 
				printf("订票成功! "); 
				break;
			}  
			else if(s[i].count<n)              /*判定机票数是否小于订票数*/
			{
				printf("对不起，你所选择的航班只剩 %d张机票\n", s[i].count);  
				printf("是否需要重新输入机票数?请输入y或n以回车键结束: ");/*判定是否重新输入订票数*/
				scanf("%s",a);
			}
		}while(!strcmp(a,"y"));  
		printf("是否需要订其他航班的机票?请输入y或n以回车键结束: "); 
		scanf("%s",a);
	}while(!strcmp(a,"y"));
}       /*判定是否继续订票*/

void tuipiao()                /*定义退票函数*/
{
	int n; 
	char a[10]; 
	do 
	{  
		search();         /*调用查询函数*/
		if(!strcmp(ii,"n"))  
		{
			printf("对不起!没有找到您所需要的航班,所以不能退票。\n"); 
			printf("\n请按回车键返回上层菜单 "); 
			getchar(); 
			getchar(); 
			strcpy(ii,"n"); 
			break;
		}  
		printf("请输入您要退的机票数目： "); 
		scanf("%d",&n);        /*输入所退票数*/
		if(n<=0)               /*判定票数是否有效*/
			printf("输入错误！至少需退1张机票。 "); 
		else   
		{
			s[i].count=s[i].count+n; 
			printf("退票成功! ");
		}  
		printf("是否继续？ 请键入y或n以回车键结束: ");    /*判定是否继续退票*/
		scanf("%s",a);
	}while(!strcmp(a,"y"));
}      /*判定并跳出循环*/  

void paixu()                 /*定义排序函数*/
{
	int n;  
	printf("\n********************************************************************************\n");       
	printf("1.按航班号从小到大排序\n" "\t2.按航班号从大到小排序\n");  
	printf("********************************************************************************\n");    
	printf("请在1-2中选择以回车键结束： "); 
	scanf("%d",&n);           /*输入排序方式*/
	switch(n)  
	{
		case 1:
			paixu1();         /*调用从小到大排序函数*/
			break;  
		case 2:
			paixu2();          /*调用从大到小排序函数*/
			break;  
	}
	printf("排序后的航班信息为:\n");  
	output();                 /*显示排序后航班信息*/
	printf("\n请按回车键返回上层菜单 "); 
	getchar(); 
	getchar();
}  

void paixu1()             /*定义从小到大排序函数*/
{
	int k,j; 
	struct air t;  
	for(i =0;i<m;i++)          /*选择法排序*/
	{
		k=i;  
		for(j=i+1;j<m;j++) 
			if(s[k].num>s[j].num) 
				k=j; 
		if(i!=k) 
		{
			t=s[k]; 
			s[k]=s[i]; 
			s[i]=t;
		}
	}
}  

void paixu2()             /*定义从大到小排序函数*/
{
	int k,j; 
	struct air t; 
	for(i=0;i<m;i++) 
	{
		k=i;  
		for(j=i+1;j<m;j++) 
			if(s[k].num<s[j].num) 
				k=j; 
		if(i!=k) 
		{
			t=s[k]; 
			s[k]=s[i]; 
			s[i]=t;
		}
	}
}