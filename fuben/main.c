#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STU
{
    int num;
    char name[10];
    int age;
    char sex[5];
    char date[20];
    char adress[20];
    char tel[10];
    int iStuScore;
    struct STU *next;
} STUNODE;

//声明链表的头和尾(全局变量）
STUNODE* g_pHead =NULL;
STUNODE* g_pEnd =NULL;

int main()
{
    void AddStudent(int num,char name[10],int age,char sex[5],char date[20],char adress[20],char tel[10],int iStuScore);
    void ShowStu(STUNODE * g_pHead);
    int num,age,score;
    char name[10]={'0'};
    char sex[5]={'0'};
    char date[20]={'0'};
    char tel[10]={'0'};
    char adress[20]={'0'};
    int sign=1;
    int nOrder = -1;//若用getchar，main中的换行会被读进去，有大bug！
     printf("===============【后宫管理系统】================\n");
      printf("\t\t1.录入信息\n");
      printf("\t\t2.浏览信息\n");
      printf("\t\t3.查询信息(姓名/学号)\n");
      printf("\t\t4.删除信息\n");
      printf("\t\t5.修改信息\n");
      printf("\t\t0.退出系统\n");
      printf("===============【后宫管理系统】================\n");

    while(sign)
    {
        printf("请输入指令:");
        scanf("%d",&nOrder);
       switch(nOrder)
        {
           case 0:
               {
                    printf("退出信息管理系统\n");
                    sign=0;
               }
               break;
           case 1:   //TODO:录入学生信息
               {
                 printf("\n----------------【输入信息】-------------------\n");
                 printf("学生学号   姓名   年龄   sex    出生日期    地址    联系方式   成绩\n");
                 scanf("%d%s%d%s%s%s%s%d",&num,name,&age,sex,date,adress,tel,&score);
                 AddStudent(num,name,age,sex,date,adress,tel,score);
               }
            break;
           case 2:
               {
                   printf("\n---------------【浏览信息】-------------------\n");
                   STUNODE *p = g_pHead;
                  while(p!=NULL)
                  {
                    printf("%d\t%s\t%d\t%s\t%s\t%s\t%s\t%d\n",p->num,p->name,p->age,p->sex,p->date,p->adress,p->tel,p->iStuScore);
                    p=p->next;
                  }
               }
               break;
           case 3:
                printf("\n---------------【查询信息】-------------------\n");
               break;
           case 4:
                printf("\n---------------【删除信息】-------------------\n");
               break;
           case 5:
                printf("\n---------------【修改信息】-------------------\n");
               break;
           default:
            printf("指令不对！\n");
        }
    }
    return 0;
}
//录入学生信息
void AddStudent(int num,char name[10],int age,char sex[5],char date[20],char adress[20],char tel[10],int iStuScore)
{
     STUNODE *pTemp = malloc(sizeof(STUNODE));

    //第一步，检验参数的合法性
    if(iStuScore < 0 || iStuScore>100 || NULL == name)
    {
        printf("学生信息输入错误！\n");
        return;
    }

    //创建一个节点
    strcpy(pTemp->name,name);//对字符数组的赋值！！！不能想当然的写=直接赋值
    strcpy(pTemp->adress,adress);
    strcpy(pTemp->sex,sex);
    strcpy(pTemp->date,date);
    strcpy(pTemp->tel,tel);
    pTemp->num = num;   //对于数字来说可以直接赋值
    pTemp->age= age;
    pTemp->iStuScore = iStuScore;
    pTemp->next=NULL;
    //节点接在链表上(分情况，一个节点和多个节点）
    if(NULL == g_pHead)   /*链表为空，头和尾都指向新的节点*/
      {
        g_pHead = pTemp;
      }
      else
      {
        g_pEnd->next = pTemp;
      }
      g_pEnd = pTemp;
}
