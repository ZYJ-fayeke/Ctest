#include <stdio.h>
/*int main()
{
    int length(char *p);
    char str[20];
    int len;
    printf("please input string:\n");
    scanf("%s",str);
    len=length(str);
    printf("the length of the string is : %d",len);
    return 0;
}
int length(char *p)
{
    int n=0;
    while(*p!='\0') //怎么可以用if？用if只会进行一次的计数啊！
    {
       n++;
       p++;
    }
    return n;
}*/

/*#include <string.h>
int main()
{
    void copystr(char *,char *,int);
    int m;
    char str[20],str1[20];
    printf("please input string:");
    scanf("%s",str);
    printf("which character the begin to copy?");
    scanf("%d",&m);
    copystr(str,str1,m);
    printf("result:%s",str1);
    return 0;
}
void copystr(char *str,char *str1,int m)
{
    int n=0;
    while(n<m-1)//n就相当于是str的一个标记，把指针引到要开始复制的地方！
    {
        n++;
        str++;
    }
    while(*str1!='\0')//循环条件有问题，复制到结束得停止啊!!(while(1))
    {
        *str1=*str;
        str++;//指针是要动的！！
        str1++;
    }
    *str1='\0';
}*/
/*int main()
{
    //输入设置
    int b=0,s=0,sp=0,n=0,e=0,i=0;
    char *p,str[20];
    printf("please input the string:\n");
    while((str[i]=getchar())!='\n')    //??单个字符与字符串？
        i++;
    //指针移动开始计数！
     p=&str[0];
    while(*p!='\n')
    {
        if(('A'<=*p)&&(*p<='Z'))
            b++;
        else if(('a'<=*p)&&(*p<='z'))
            s++;
        else if(*p==' ')
            sp++;
        else if((*p<='9')&&(*p>='0'))
            n++;
        else e++;
        p++;
    }
    //输出！
    printf("大写字母：%d小写字母：%d空格：%d数字：%d其他：%d",b,s,sp,n,e);
    return 0;
}*/
//整型矩阵转置

/*int main()
{
    //输入数组
    void move(int *p);
    int i,a[3][3],*p;
    printf("enter the arr:\n");
    for(i=0;i<3;i++)
        scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
    p=&a[0][0];//关键一步哦 Houho
    move(p);
    printf("new arr:");
    for(i=0;i<3;i++)
        printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);
    return 0;
}
//move函数进行转置
void move(int *p)
{
    int i,j,temp;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
    {
        temp=*(p+i*3+j);
        *(p+i*3+j)=*(p+j*3+i);
        *(p+j*3+i)=temp;
    }
}*/

/*16题 输入：输入一个字符串，内有数字和非数字字符，例如 A123x456 17960？ 302tab5876
操作：将连续的数字作为一个整数，一次存放到一数组a中，例如123存放在a【0】中，456放在a【1】中……
结果输出：统计共有多少个整数，并输出这些数*/

int main()
{
//定义一个输入的数组

char str[30],z;
int flag=0,i;
int transnum=0;  //用来储存字符串转成的数字！！
int a[20],j=0; //将数字放入的数组
char *p=str;
//int *pnum; 注意！该指针是空的，危险，调到后面直接给指向
printf("enter string:\n");
gets(str);
//指针排查，查到数字记录
i=0;
while((z=*(p+i))!='\0') //如果没有遇到结束符的话
{
    if(z>='0'&&z<='9')  //如果是数字的话,tips:别忘了>=,<=不然如果输入0,9会有bug！
    {
        transnum=transnum*10+(z-48);  //学会字符串转成数字的方法，也可以减去48（0的ASCII码为48）
        flag=1;
    }
    else
    {
         if(flag==1)  //对数字进行保存！
      {
        a[j++]=transnum;  //聪明点，一个j++，既保存了当前的数字，也免得再下一轮的时候单独给j再++
        transnum=0; //归零！
      }
      flag=0;
    }
    i++;
}
if(flag==1)
{
     a[j++]=transnum;
}
a[j]='\0';  //跳出循环，否则最后的输出会有问题！
int *pnum;
pnum=a;
printf("there are %d number:\n",j);
for(i=0;*(pnum+i)!='\0';i++)
     printf("%d ",*(pnum+i));
  return 0;
}

//创建结构体变量，计算该日在本年中是第几天

/*struct days
{
    int year;
    int month;
    int day;
}date;
int main()
{

    int days(int,int,int);
    int sum;
    printf("enter year:");
    scanf("%d",&date.year);
    printf("enter month:");
    scanf("%d",&date.month);
    printf("enter day:");
    scanf("%d",&date.day);
    sum=days(date.year,date.month,date.day);
    printf("Date is %d/%d/%d and sum is:%d\n",date.year,date.month,date.day,sum);

    return 0;
}
//判断闰年！
int days(int year,int month,int day)
{
    int i;
    int mondays[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int sum=0;
    for(i=0;i<month;i++)
        sum+=mondays[i];
    sum=sum+day;
    if(((year%4==0&&year%100!=0)||year%400==0)&&month>3)
        sum+=1;
        return sum;
}

//数据结构--学生成绩!

/*#define N 3
struct Student
{
    char num[4];
    char name[10]; //为什么你总是忘记名字它得要是个数组啊！！
    float score[3];
    float aver;
} stu[N];
int main()
{
    int i,j,k;
    float sum,averge=0,max=0;
    for(i=0;i<N;i++)
    {
        printf("input scores of the student %d\n",i+1);
        printf("No.:");
        scanf("%s",stu[i].num);
        printf("name:");
        scanf("%s",stu[i].name);
        for(j=0;j<3;j++)
        {
            printf("score%d:",j+1);
            scanf("%f",&stu[i].score[j]);  //注意：要加入取地址符！因为存入的是数据结构里面的数组！
        }
    }
    //算平均成绩最高分
    for(i=0;i<N;i++)
    {
        sum=0; //要对上一次的及时清零！
        for(j=0;j<3;j++)
             sum+=stu[i].score[j];
        stu[i].aver=sum/3.0;  //float型数据，注意严谨性！除以3.0！
        averge+=stu[i].aver;
        if(sum>max)
        {
             max=sum;
             k=i;
        }

    }
    averge/=N;
    for(i=0;i<N;i++)
    {
         printf("%5s%10s",stu[i].num,stu[i].name);
         for(j=0;j<3;j++)
             printf("%8.2f",stu[i].score[j]);
         printf("%8.2f\n",stu[i].aver);
    }
    printf("average=%8.2f\n",averge);
    printf("the best person is %6s%8s\n",stu[k].num,stu[k].name);
    printf("scores:%8.2f%8.2f%8.2f",stu[k].score[0],stu[k].score[1],stu[k].score[2]);
    return 0;
}*/

//指针字符串练习！

//int main()
//{
    //对于字符串中的存取，可以用指针也可用数组!
    /*char a[]="Now I am solo!",b[20];
    int i;
    for(i=0;*(a+i)!='\0';i++)
        *(b+i)=*(a+i);
    *(b+i)='\0';
    printf("a is %s\n",a);
    printf("b is %s\n",b); //也可用for循环逐个输出b数组中的有效字符！

    //用指针变量来解决

        char a[]="Now I am solo!",b[20],*p1,*p2;
        p1=a;
        p2=b;
        /*while(*p1!='\0')
         *p2++=*p1++;
        *p2='\0';*/
        //或者下面这一种：
       /* for(;*p1!='\0';p1++,p2++)

            *p2=*p1;
            *p2='\0';*/
        /*printf("a is:%s\n",a);
        printf("b is:%s\n",b);
    return 0;
}*/
//用函数调用实现字符串的复制（字符串指针做函数参数）
/*int main()
{
        void copy_string(char from[],char to[]);
        char a[]="I am solo!lalal";
        char b[]="so the bar where I go";
        char *from=a,*to=b;
        printf("a is %s\nb is %s\n",a,b);
        printf("copy a to b:\n");
        copy_string(from,to);  //仔细看看这个程序，指针数组混用莫得问题！
        printf("a is %s\n b is %s\n",a,b);
    return 0;
}
 void copy_string(char from[],char to[])
{
    int i=0;
    while(from[i]!='\0')
    {
        to[i]=from[i];
        i++;
    }
    to[i]='\0';
}*/
//实参为指针变量
/*int main()
{
        void copy_string(char *from,char *to);
        char *a="I am solo!lalal";
        char b[]="so the bar where I go";
        char *p=b;
        printf("a is %s\nb is %s\n",a,b);
        printf("copy a to b:\n");
        copy_string(a,p);   //实参为指针变量！
        printf("a is %s\n b is %s\n",a,b);  //输出怎么能输出个指针呢？你指针又没有给赋值！

   return 0;
}
void copy_string(char *from,char *to)
{
    while(*from!='\0')
        *to++=*from++;
    *to='\0';
}*/




