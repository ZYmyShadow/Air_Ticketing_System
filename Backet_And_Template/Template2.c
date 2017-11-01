/*航空票务管理系统源代码*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 3 /*定义航线量的最大值*/

typedef struct wat_ros
{  
    char name[10];/*姓名*/
    int req_amt;/*订票量*/
    struct wat_ros *next;
}qnode,*qptr;

typedef struct pqueue
{  
    qptr front;/*等候替补客户名单域的头指针*/
    qptr rear;/*等候替补客户名单域的属指针*/
}linkqueue;

typedef struct ord_ros
{  
    char name[10];/*客户姓名*/
    int ord_amt;/*订票量*/
    int grade;/*舱位等级*/
    struct ord_ros *next;
}linklist;

struct airline
{   
    char ter_name[10];/*终点站名 */
    char air_num[10];/*航班号*/
    char plane_num[10];/*飞机号*/
    char day[7];/*飞行周日（星期几）*/
    int tkt_amt;/*乘员定额*/
    int tkt_sur;/*余票量*/
    linklist *order;/*乘员名单域，指向乘员名单链表的头指针*/
    linkqueue wait;/*等候替补的客户名单域，分别指向排队等候名单队头队尾的指针*/
}lineinfo;

struct airline *start;

void display(struct airline *info)
/*打印每条航线的基本信息*/
{
    printf("%8s\t%3s\t%s\t%4s\t\t%3d\t%10d\n",info->ter_name,info->air_num,info->plane_num,info->day,info->tkt_amt,info->tkt_sur);
}

void list()/*打印全部航线信息*/
{  
    struct airline *info;
    int i=0;
    info=start;
    printf("终点站名\t航班号\t飞机号\t飞行周日\t乘员定额\t余票量\n");
    while(i<MAXSIZE)
    {
        display(info);
        info++;
        i++;
    }
    printf("\n\n");
}


void search()
/*根据客户提出的终点站名输出航线信息*/
{  
    struct airline *info,*find();
    char name[10];
    int i=0;
    info=start;
    printf("请输入终点站名:");
    scanf("%s",name);
    while(i<MAXSIZE) 
    {
        if(!strcmp(name,info->ter_name)) break;
        info++;
        i++;
    }
    if(i>=MAXSIZE)
        printf("对不起，该航线未找到!\n");
    else
    {
        printf("终点站名\t航班号\t飞机号\t飞行周日\t乘员定额\t余票量\n");
        display(info);
    }
}

struct airline *find()
/*根据系统提出的航班号查询并以指针形式返回*/
{  
    struct airline *info;
    char number[10];
    int i=0;
    info=start;
    printf("请输入航班号:");
    scanf("%s",number);
    while(i<MAXSIZE) 
    {
        if(!strcmp(number,info->air_num)) return info;
        info++;
        i++;
    }
    printf("对不起，该航线末找到!\n");
    return NULL;
}

void prtlink()
/*打印订票乘员名单域的客户名单信息*/
{  
    linklist *p;
    struct airline *info;
    info=find();
    p=info->order;
    if(p!=NULL)
    {
        printf("客户姓名   订票数额   舱位等级\n");
        while(p)
        {
            printf("%s\t\t%d\t%d\n",p->name,p->ord_amt,p->grade);
            p=p->next;
        }
    }
    else
        printf("该航线没有客户信息!!\n");
}

linklist *insertlink(linklist *head,int amount,char name[],int grade)
/*增加订票乘员名单域的客户信息*/
{  
    linklist *p1,*new;
    p1=head;
    new=(linklist *)malloc(sizeof(linklist));
    if(!new) 
    {
        printf("\nOut of memory!!\n");
        return NULL;
    }
    strcpy(new->name,name);
    new->ord_amt=amount;
    new->grade=grade;
    new->next=NULL;
    if(head==NULL)/*若原无订票客户信息*/
    {
        head=new;
        new->next=NULL;
    }
    else
        head=new;
    new->next=p1;
    return head;
}

linkqueue appendqueue(linkqueue q,char name[],int amount)
/*增加排队等候的客户名单域*/
{ 
    qptr new;
    new=(qptr)malloc(sizeof(qnode));
    strcpy(new->name,name);
    new->req_amt=amount;
    new->next=NULL;
    if(q.front==NULL)/*若原排队等候客户名单域为空*/
        q.front=new;
    else
        q.rear->next=new;
    q.rear=new;
    return q;
}

void order()
/*办理订票业务*/
{  
    struct airline *info;
    int amount,grade;
    char name[10];
    info=start;
    if(!(info=find())) 
        return;/*根据客户提供的航班号进行查询，如为空，退出该模块*/
    printf("请输入你订票所需要的数量:");
    scanf("%d",&amount);
    if(amount>info->tkt_amt)/*若客户订票额超过乘员定票总额，退出*/
    {  
        printf("\n对不起，您输入的票的数量已经超过乘员定额!");
        return;
    }
    if(amount<=info->tkt_sur)/*若客户订票额末超过余票量，订票成功并等记信息*/
    {
        int i;
        printf("请输入您的姓名（订票客户）:");
        scanf("%s",name);
        printf("请输入%s票的舱位等级:",name);
        scanf("%d",&grade);
        info->order=insertlink(info->order,amount,name,grade);/*在订票乘员名单域中添加客户信息*/
        for(i=0;i<amount;i++)/*依次输出该订票客户的座位号*/
            printf("%s的座位号是:%d\n",name,info->tkt_amt-info->tkt_sur+i+1);
        info->tkt_sur-=amount;/*该航线的余票量应减掉该客户的订票量*/
        printf("\n祝您乘坐愉快！\n");
    }
    else       /*若满员或余票额少于订票额，询问客户是否需要进行排队等候*/
    {  
        char r;
        printf("\n已经没有更多的票，您需要排队等候吗?(Y/N)");
        r=getch();
        printf("%c",r);
        if(r=='Y'||r=='y')
        {  
            printf("\n请输入您的姓名（排队订票客户）:");
            scanf("%s",name);
            info->wait=appendqueue(info->wait,name,amount);/*在排队等候乘员名单域中添加客户信息*/
            printf("\n注册成功!\n");
        }
        else 
            printf("\n欢迎您下次再次订购！\n");
    }
}

void return_tkt()
/*退票模块*/
{  
    struct airline *info;
    qnode *t,*back,*f,*r;
    int grade;
    linklist *p1,*p2,*head;
    char cusname[10];
    if(!(info=find())) 
        return;/*调用查询函数，根据客户提供的航线进行搜索*/
    head=info->order;
    p1=head;
    printf("请输入你的姓名（退票客户）:");
    scanf("%s",cusname);
    while(p1!=NULL) 
    {
        /*根据客户提供的姓名到订票客户名单域进行查询*/
        if(!strcmp(cusname,p1->name)) 
            break;
        p2=p1;p1=p1->next;
    }
    if(p1==NULL)
    { 
        printf("对不起，你没有订过票!\n");
        return;
    }/*若未找到，退出本模块*/
    else
    {/*若信息查询成功，删除订票客户名单域中的信息*/
        if(p1==head) 
            head=p1->next;
        else 
            p2->next=p1->next;
        info->tkt_sur+=p1->ord_amt;
        grade=p1->grade;
        printf("%s成功退票！\n",p1->name);
        free(p1);
    }
    info->order=head;/*重新将航线名单域指向订票单链表的头指针 */
    f=(info->wait).front;/*f指向排队等候名单队列的头结点*/
    r=(info->wait).rear;/*r指向排队等候名单队列的尾结点*/
    t=f;/*t为当前满点条件的排队候补名单域*/
    while(t)
    {
        if(info->tkt_sur>=info->wait.front->req_amt)
        {/*若满足条件者为头结点*/
            int i;
            info->wait.front=t->next;
            printf("%s订票成功！\n",t->name);
            for(i=0;i<t->req_amt;i++)/*输出座位号*/
                printf("%s的座位号是:%d\n",t->name,(info->tkt_sur)-i);
            info->tkt_sur-=t->req_amt;
            info->order=insertlink(info->order,t->req_amt,t->name,grade);/*插入到订票客户名单链表中*/
            free(t);
            break;
        }
        back=t;t=t->next;
        if((info->tkt_sur)>=(t->req_amt)&&t!=NULL)/*若满足条件者不为头结点*/
        {  
            int i;
            back->next=t->next;
            printf("%s订票成功！\n",t->name);
            for(i=0;i<t->req_amt;i++)/*输出座位号*/
                printf("<%s>'s seat number is:%d\n",t->name,(info->tkt_sur)-i);
            info->tkt_sur-=t->req_amt;
            info->order=insertlink(info->order,t->req_amt,t->name,grade);/*插入到订票客户名单链表中*/
            free(t);
            break;
        }
        if(f==r) 
            break;
    }
}

int menu_select()
/*菜单界面*/
{  
    int c;
    char s[20];
    printf("\n\t\t航空客运订票系统\n");
    printf("******************************************\n");
    printf("1.浏览航线信息:\n");
    printf("2.浏览已订票客户信息:\n");
    printf("3.查询航线\n");
    printf("4.办理订票业务:\n");
    printf("5.办理退票业务:\n");
    printf("6.退出系统\n");
    printf("*******************************************\n");
    do
    {
        printf("请选择:");
        scanf("%s",s);
        c=atoi(s);
    }while(c<0||c>7);
    return c;
}

int main()
{  
    struct airline air[MAXSIZE]={{"beijing","1","B8571","SUN",3,3},
                                {"shanghai","2","S1002","MON",2,2},
                                {"london","3","L1003","FRI",1,1}};/*初始化航线信息*/
    /*  clrscr();*/
    start=air;
    for(;;)
    {
        switch(menu_select())
        {
            case 1:
                list();break;
            case 2:
                prtlink();
                break;
            case 3:
                search();
                break;
            case 4:
                order();
                break;
            case 5:
                return_tkt();
                break;
            case 6:
                printf("\n欢迎使用本系统，再见！\n");
                exit(0);
        }
        printf("\nPress any key to continue!\n");
        getch();
    }
    return 0;
}
