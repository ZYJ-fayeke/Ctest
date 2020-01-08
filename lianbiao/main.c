#include <stdio.h>
#include <stdlib.h>

#define LEN sizeof(struct Student)


struct Student
{
    int num;
    float score;
    struct Student *next;
};

int n;  //�ڵ�����



struct Student *Creat(void)
{
    struct Student *head,*p1,*tail;
    n=0;
    head=p1=tail=NULL;

    p1=(struct student *) malloc(LEN); //(struct Student *)��ǿ��ת��
    if(p1==NULL)
    {
        printf("creat error!\n");
        return NULL;
    }

    head=p1; tail=p1;

    printf("please enter %d node's : num and score:",n+1);
    scanf("%d%f",&(p1->num),&(p1->score));

    while(p1->num!=0)
    {
        n=n+1; //��һ���ڵ�
        if(n==1)  //ͷ��
        {
            head=p1;tail=p1;
            tail->next=NULL;
        }
        else{
            tail->next=p1;
        }
        tail=p1;  //β���Ƶ���һ���ڵ�

        //������һ���ڵ㣡
        p1=( struct Student *)malloc(LEN);
        if(p1==NULL)
        {
            printf("creat error!\n");
            return NULL;
        }

        printf("please enter %d node's : num score:",n+1);
        scanf("%d%f",&(p1->num),&(p1->score));
    }
    //β��ע�⣡
    tail->next=NULL;

    free(p1); //���һ���ǿգ����⣩��,�ò�����

    return head;
};



void Print(struct Student *head)
{
    struct Student *p;  //�����Ļ���Ҫ��ָ�룡
    p=head;
    int i=1;
    while(p!=NULL)
    {
        printf("node %d is:",i);

        printf("num=%d,score=%6.2f\n",p->num,p->score);
        p=p->next;  //�����Ѿ���������
        i++;
    }
    return;
}
/*

 ���ܣ�����ָ���ڵ�ĺ���(��������ָ��ѧ�ŵĽڵ�)
 ���أ�ָ�������ͷ��ָ��

*/
struct Student *InsterNode(struct Student *head,struct Student *node,int num) //node����Ҫ���������½ڵ�
{
    struct Student *p1;    //p1���浱ǰ��Ҫ���Ľڵ�ĵ�ַ

    if (head==NULL)
    {
        head=node;     //����node����Ҫ���������½ڵ�
        node->next=NULL;
        n+=1;
        return head;
    }
    p1=head;
    while(p1->num!=num&&p1->next!=NULL)
    {
        p1=p1->next;
    }

    if(p1->num==num)  //�ҵ�����Ҫ�����λ�ã�
    {
        node->next=p1->next;   //��Ȼnode����һ�ڵ���ԭp1��next
        p1->next=node;    //�������ԭp1����һ���ڵ����node
        n+=1;    //ʹ�ڵ�������һ����
    }
     else
    {
        printf ("\n%d not been found!\n", num);
    }
    return head; //��ס���صĻ��������ͷ��ָ��!

};
/*

���ܣ�ɾ��ָ���ڵ�(��������ɾ��ָ��ѧ�ŵĽڵ�)
 ���أ�ָ�������ͷ��ָ��

*/
struct Student *Del(struct Student *head,int n)
{
    struct Student *p1;    //p1���浱ǰ��Ҫ���Ľڵ��λ��
    struct Student *p2;    //p2���浱ǰ�Ѿ������Ľڵ��λ��
    if(head == NULL)
    {
        printf("\nList is NULL\n");
        return head;
    }
    //��ʼ��λ��Ҫɾ���Ľڵ�
    p1=head;
    while(p1->next != NULL && p1->num!=n)//p1�Ľڵ㲻����Ҫɾ���ģ�������Ҳ�������һ����������
    {
        p2=p1;  //p2����ס��ǰ�ڵ��λ��
        p1 = p1->next;  //p1����һ���ڵ�
    }

    if(p1->num == n)
    {
        if(p1==head)   //����ҵ��Ľڵ�Ϊ��һ������
        {
            head=p1->next;  //����ͷָ��ָ���һ���ڵ�ĺ�һ���ڵ㣬Ҳ���ǵ�2���ڵ�
        }
        else{
            p2->next=p1->next;    //����������Ľڵ㣬����ָ��ǰ�ڵ��ָ�룬ָ����һ���ڵ㣬ɾ��������ɣ�!
        }
        //ע��!!!

        free(p1);
        p1=NULL;
        printf ("\ndelete %d success!\n",n);
        n -= 1;         //�ڵ�������1��
    }

    else
    {
         printf ("\n%d not been found!\n", n);
    }
    return head;
}

int main( void )
{

    struct Student *head;
    struct Student *stu;
    int thenum,n2;
    head=Creat();
    if(head)
    {
        Print(head);
    }
    //����InsterNode,����Ҫ��������
    stu=(struct Student *)malloc(LEN);
    printf("please enter student--num,score:\n");
    scanf("%d%f",&stu->num,&stu->score);
    printf("inster behind the num:");
    scanf("%d",&thenum);
    head = InsterNode(head,stu,thenum);
    Print(head);

    //����Delɾ��ָ���ڵ㣡
    printf("Which one delete:");
    scanf("%d",&n2);
    head = Del(head,n2);
    Print(head);
}


