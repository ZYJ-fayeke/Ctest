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

//���������ͷ��β(ȫ�ֱ�����
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
    int nOrder = -1;//����getchar��main�еĻ��лᱻ����ȥ���д�bug��
     printf("===============���󹬹���ϵͳ��================\n");
      printf("\t\t1.¼����Ϣ\n");
      printf("\t\t2.�����Ϣ\n");
      printf("\t\t3.��ѯ��Ϣ(����/ѧ��)\n");
      printf("\t\t4.ɾ����Ϣ\n");
      printf("\t\t5.�޸���Ϣ\n");
      printf("\t\t0.�˳�ϵͳ\n");
      printf("===============���󹬹���ϵͳ��================\n");

    while(sign)
    {
        printf("������ָ��:");
        scanf("%d",&nOrder);
       switch(nOrder)
        {
           case 0:
               {
                    printf("�˳���Ϣ����ϵͳ\n");
                    sign=0;
               }
               break;
           case 1:   //TODO:¼��ѧ����Ϣ
               {
                 printf("\n----------------��������Ϣ��-------------------\n");
                 printf("ѧ��ѧ��   ����   ����   sex    ��������    ��ַ    ��ϵ��ʽ   �ɼ�\n");
                 scanf("%d%s%d%s%s%s%s%d",&num,name,&age,sex,date,adress,tel,&score);
                 AddStudent(num,name,age,sex,date,adress,tel,score);
               }
            break;
           case 2:
               {
                   printf("\n---------------�������Ϣ��-------------------\n");
                   STUNODE *p = g_pHead;
                  while(p!=NULL)
                  {
                    printf("%d\t%s\t%d\t%s\t%s\t%s\t%s\t%d\n",p->num,p->name,p->age,p->sex,p->date,p->adress,p->tel,p->iStuScore);
                    p=p->next;
                  }
               }
               break;
           case 3:
                printf("\n---------------����ѯ��Ϣ��-------------------\n");
               break;
           case 4:
                printf("\n---------------��ɾ����Ϣ��-------------------\n");
               break;
           case 5:
                printf("\n---------------���޸���Ϣ��-------------------\n");
               break;
           default:
            printf("ָ��ԣ�\n");
        }
    }
    return 0;
}
//¼��ѧ����Ϣ
void AddStudent(int num,char name[10],int age,char sex[5],char date[20],char adress[20],char tel[10],int iStuScore)
{
     STUNODE *pTemp = malloc(sizeof(STUNODE));

    //��һ������������ĺϷ���
    if(iStuScore < 0 || iStuScore>100 || NULL == name)
    {
        printf("ѧ����Ϣ�������\n");
        return;
    }

    //����һ���ڵ�
    strcpy(pTemp->name,name);//���ַ�����ĸ�ֵ�����������뵱Ȼ��д=ֱ�Ӹ�ֵ
    strcpy(pTemp->adress,adress);
    strcpy(pTemp->sex,sex);
    strcpy(pTemp->date,date);
    strcpy(pTemp->tel,tel);
    pTemp->num = num;   //����������˵����ֱ�Ӹ�ֵ
    pTemp->age= age;
    pTemp->iStuScore = iStuScore;
    pTemp->next=NULL;
    //�ڵ����������(�������һ���ڵ�Ͷ���ڵ㣩
    if(NULL == g_pHead)   /*����Ϊ�գ�ͷ��β��ָ���µĽڵ�*/
      {
        g_pHead = pTemp;
      }
      else
      {
        g_pEnd->next = pTemp;
      }
      g_pEnd = pTemp;
}
