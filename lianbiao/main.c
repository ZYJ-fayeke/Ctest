#include <stdio.h>
#include <stdlib.h>

#define LEN sizeof(struct Student)


struct Student
{
    int num;
    float score;
    struct Student *next;
};

int n;  //节点总数



struct Student *Creat(void)
{
    struct Student *head,*p1,*tail;
    n=0;
    head=p1=tail=NULL;

    p1=(struct student *) malloc(LEN); //(struct Student *)是强制转化
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
        n=n+1; //第一个节点
        if(n==1)  //头部
        {
            head=p1;tail=p1;
            tail->next=NULL;
        }
        else{
            tail->next=p1;
        }
        tail=p1;  //尾部移到下一个节点

        //创建下一个节点！
        p1=( struct Student *)malloc(LEN);
        if(p1==NULL)
        {
            printf("creat error!\n");
            return NULL;
        }

        printf("please enter %d node's : num score:",n+1);
        scanf("%d%f",&(p1->num),&(p1->score));
    }
    //尾部注意！
    tail->next=NULL;

    free(p1); //最后一个是空（虚拟）的,用不到！

    return head;
};



void Print(struct Student *head)
{
    struct Student *p;  //遍历的话，要用指针！
    p=head;
    int i=1;
    while(p!=NULL)
    {
        printf("node %d is:",i);

        printf("num=%d,score=%6.2f\n",p->num,p->score);
        p=p->next;  //链表已经连起来了
        i++;
    }
    return;
}
/*

 功能：插入指定节点的后面(此例中是指定学号的节点)
 返回：指向链表表头的指针

*/
struct Student *InsterNode(struct Student *head,struct Student *node,int num) //node就是要插入的这个新节点
{
    struct Student *p1;    //p1保存当前需要检查的节点的地址

    if (head==NULL)
    {
        head=node;     //？？node就是要插入的这个新节点
        node->next=NULL;
        n+=1;
        return head;
    }
    p1=head;
    while(p1->num!=num&&p1->next!=NULL)
    {
        p1=p1->next;
    }

    if(p1->num==num)  //找到了需要插入的位置！
    {
        node->next=p1->next;   //显然node的下一节点是原p1的next
        p1->next=node;    //而插入后，原p1的下一个节点就是node
        n+=1;    //使节点总数加一个！
    }
     else
    {
        printf ("\n%d not been found!\n", num);
    }
    return head; //记住返回的还是链表表头的指针!

};
/*

功能：删除指定节点(此例中是删除指定学号的节点)
 返回：指向链表表头的指针

*/
struct Student *Del(struct Student *head,int n)
{
    struct Student *p1;    //p1保存当前需要检查的节点的位置
    struct Student *p2;    //p2保存当前已经检查过的节点的位置
    if(head == NULL)
    {
        printf("\nList is NULL\n");
        return head;
    }
    //开始定位需要删除的节点
    p1=head;
    while(p1->next != NULL && p1->num!=n)//p1的节点不是需要删除的，并且它也不是最后一个，继续找
    {
        p2=p1;  //p2保存住当前节点的位置
        p1 = p1->next;  //p1后移一个节点
    }

    if(p1->num == n)
    {
        if(p1==head)   //如果找到的节点为第一个，则
        {
            head=p1->next;  //就让头指针指向第一个节点的后一个节点，也就是第2个节点
        }
        else{
            p2->next=p1->next;    //如果是其他的节点，则让指向当前节点的指针，指向下一个节点，删除到此完成！!
        }
        //注意!!!

        free(p1);
        p1=NULL;
        printf ("\ndelete %d success!\n",n);
        n -= 1;         //节点总数减1个
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
    //测试InsterNode,还需要创建链表啊
    stu=(struct Student *)malloc(LEN);
    printf("please enter student--num,score:\n");
    scanf("%d%f",&stu->num,&stu->score);
    printf("inster behind the num:");
    scanf("%d",&thenum);
    head = InsterNode(head,stu,thenum);
    Print(head);

    //测试Del删除指定节点！
    printf("Which one delete:");
    scanf("%d",&n2);
    head = Del(head,n2);
    Print(head);
}


