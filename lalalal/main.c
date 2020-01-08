#include <stdio.h>

/*int main()
{
    char *forment;
    int a=9,b=8;
    forment="a=%d,b=%d\n";
    printf(forment,a,b);
    return 0;
}*/
//课本练习题

/*int main()
{
    int max(int,int);
    int min(int,int);
    int (*p)(int,int);
    int a,b,n,key;
    printf("please input a and b");
    scanf("%d%d",&a,&b);
    printf("please choose 1 or 2:");
    scanf("%d",&n);
    if(n==1) p=max;//将函数的入口地址给p
    else if(n==2) p=min;
    key=(*p)(a,b);//调用函数的语句
    printf("a=%d,b=%d\n",a,b);
    if(n==1)
        printf("max=%d",key);
    else printf("min=%d",key);
    return 0;
}
int max(int x,int y)
{
    int temp;
    temp=x;
    if(x<y)
        temp=y;
    return temp;
}
int min(int x,int y)
{
    int z;
    z=x;
    if(x>y)
        z=y;
    return z;
}*/
//课后练习题第三题：

/*int main()

{
    void change(int *p,int);
    void output(int *p);
    int p[10],i;  //最最重要的：用数组名当指针更省事！
    printf("please input 10 numbers:");
    for(i=0;i<10;i++)
        scanf("%d",&p[i]);
    changeit(p);
    output(p);
    return 0;
}
void changeit(int *p)
{
    int *min,*max,*z,temp;//
    min=max=p;
    for(z=p+1;z<p+10;z++)
        if(*p<*min) min=p;
    temp=p[0];   //刚开始你没有处理好俩者的交换！
    p[0]=*min;
    *min=temp;
    for(z=p+1;z<p+10;z++)
        if(*p>*max) max=p;
    temp=p[9];
    p[9]=*max;
    *max=temp;
}
void output(int *p) //直接将数组传入output函数，不用纠结元素和函数的链接关系
{
    int i;
  for(i=0;i<10;i++)
    printf("%d\t",*p++);
    printf("\n");
}*/
//课后习题第五题：

/*void  main(){
    int a[120] = {0}, i = 0, leaveman = 0, flag= 0, *p,n,k;
    printf("please input the number of the people:");
     scanf("%d",&n);
     p = a;
     printf("please enter 'k':");
     scanf("%d",&k);
     while (1)
        {          //循环报数
             if(*p == 0)
              {
                  if (leaveman == (n - 1))
                    break; //如果仅剩一人
                  flag++;         //报数
                  flag %= k;      //最大为k，到了k就从0开始
                 if(flag == 0)
                    {
                        *p = 1;
                       leaveman++;
                    } //为0(即3)出局
               }
            p++;
            if (p == a + n)
                p = a;  //最最注意的：不然要注意是指针指的位置（地址）可是要变化的啊！！循环转向下一人(画草稿容易明白）
        }
      printf("Last man is : No.%d\n", p + 1 - a);
 }*/
//学号、姓名、成绩、平均分、优秀率

/*int main()
{
     void  ascr1(float (*pscr)[5] ,char (*pcourse)[12]); //注意函数中形参的命名！！不能直接*psrc！
     void change(float (*pscr)[5],char (*pname)[8],int *pnum,float aver[4]);
    void  avscorce(float (*pscr)[5],float *paver);
    void exce(float aver[4],float (*pscr)[5],char (*pname)[8],int *pnum);
    char course[5][12]={"course 1","course 2","course 3","course 4","course 5"}; //用数组写五门课程名称
    char name[4][8]={"Lihua","Marry","Linda","Lelie"};
    int i,j,*pnum;
    char (*pcourse)[12],(*pname)[8];
    int num[4]={1111,1112,1113,1114};
    float scr[4][5]={{96,97,79,91,95},{78,80,67,58,65},{67,87,66,98,63},{70,40,77,88,71}};
    float (*pscr)[5],*paver;
    float  aver[4];
    pnum=num;  //一维数组存放编号
    pscr=scr;  //二维数组存放学生成绩
    pcourse=course;  //一维数组存放课程名字
    pname=name;  //一维数组存放学生姓名
    paver=aver;  //要使指针指向数组！
    printf("学号:");
    printf("姓名：");
    for(i=0;i<5;i++)
         printf(",%-8s",course[i]);
    printf("\n");

    for(i=0;i<4;i++)
    {
        printf("%-5d",num[i]);
        printf("%s",name[i]);

        for(j=0;j<5;j++)
        {
             printf("%-10.2f",scr[i][j]);
        }
        printf("\n");
    }
    ascr1(pscr,pcourse);
    avscorce(pscr,paver);
    exce(paver,pscr,pname,pnum);
    change(pscr,pname,pnum,aver);
    return 0;
}
void avscorce( float (*pscr)[5],float *paver)
{
    int i,j;
    float sum,ave;
    for(i=0;i<4;i++)
    {
        sum=0.0;//这一个小小小的错误，你知道你改了多长时间吗？一个半小时 ！你是个傻子，
        for(j=0;j<5;j++)
            sum += *(*(pscr+i)+j);
        ave=sum/5;
       *(paver+i)=ave;
    }


}
 void ascr1(float (*pscr)[5],char (*pcourse)[12])
{
    int i;
    float sum=0.0,ave;
    for(i=0;i<4;i++)
    {
        sum += *(*(pscr+i));

    }
    ave=sum/4;

    printf("第一门课程%s的平均分：%f",*pcourse,ave);

}
void exce(float aver[4],float (*pscr)[5],char (*pname)[8],int *pnum)
{
    int i,j,sign;
    printf("\n平均成绩在90分以上或者每门课程都在85分以上的人有:\n");
    for(i=0;i<4;i++)
    {
        sign=0;
        for(j=0;j<5;j++)
           if(*(*(pscr+i)+j)>85.0)
             sign++;
        if((sign==5)||(aver[i]>90))
          {
             printf("%-5d",*(pnum+i));
             printf("%s\n",*(pname+i));
             for(j=0;j<5;j++)
                 printf("%15.2f",*(*(pscr+i)+j));
             printf("\n平均成绩是:%11.2f",aver[i]);
          }
    }
}
void change(float (*pscr)[5],char (*pname)[8],int *pnum,float aver[4])
{
    int i,j,temp,k,h;
    int temp1;
    int temp2;
    printf("\nplease enter a number:");
    scanf("%d",&k);
    h=k-1;
    if(k!=5)
    {
        for(i=0;i<4;i++)
      {
          for(j=i+1;j<5;j++)
          {
               if( *(*(pscr+i)+h) < *(*(pscr+(j))+h))
             {

                temp= *(*(pscr+i)+h);
                temp2=*(pnum+i);
               *(*(pscr+i)+h)=*(*(pscr+j)+h);
               *(pnum+i)=*(pnum+j);
               *(*(pscr+j)+h)=temp;
               *(pnum+j)=temp2;
             }
        }
      }
      for(i=0;i<4;i++)
      {
        printf("%-10.2f", *(*(pscr+i)+h));
        printf("%-5d",*(pnum+i));
        printf("\n");
       }
    }
    else if(k==5)
    {
        for(i=0;i<3;i++)
        {
            for(j=i+1;j<4;j++)
            {
                 if(aver[i] < aver[j])

               {
                temp1= aver[i];
                temp2=*(pnum+i);
                aver[i]=aver[j];
                *(pnum+i)=*(pnum+(i+1));
                aver[j]=temp1;
                *(pnum+(i+1))=temp2;
               }
            }

        }
        for(i=0;i<4;i++)
      {
        printf("%-10.2f",aver[i]);
        printf("%-5d",*(pnum+i));
        printf("\n");
       }
    }

}*/
//数据结构

int main()
{

        /*struct student
        {
            long int num;
            char name[20];
            char sex;
            char addr[20];
        }a={10101,"keke",'L',"123 Beijing Road"};//定义结构变量的同时给她赋初值！

    printf("N0.:%ld\nname:%s\nsex:%c\naddress:%s\n",a.num,a.name,a.sex,a.addr);*/
    /*struct student
    {
        int num;
        char name[20];
        float score;
    }student1,student2;  //定义俩个结构变量！！
    scanf("%d%s%f",&student1.num,student1.name,&student1.score); //在name前面没有&的原因：数组名本身就代表地址，不需要画蛇添足再加&
    scanf("%d%s%f",&student2.num,student2.name,&student2.score);
    printf("The higher score is:\n");
    if(student1.score>student2.score)
        printf("%d %s %6.2f\n",student1.num,student1.name,student1.score);
    else if(student1.score<student2.score)
        printf("%d %s %6.2f\n",student2.num,student2.name,student2.score);
    else{
         printf("%d %s %6.2f\n",student1.num,student1.name,student1.score);
          printf("%d %s %6.2f\n",student2.num,student2.name,student2.score);
    }

    return 0;*/
    //主函数中输入M,N 调用move函数
    void move (int a[20],int n,int m);
    int a[20],m,n,i;
    printf("please input a number 'n':");
    scanf("%d",&n);
    printf("please input %d number:",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);  //若在这里直接写入a[20]的话，程序出现问题！
    printf("please input a number 'm':");
    scanf("%d",&m);
    move(a,n,m); //函数调用的时候，数组的写法注意！
    printf("answer:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
void move(int a[20],int n,int m)
{
    int *p,alast;
    alast=*(a+n-1);
    for(p=a+n-1;p>a;p--)
        *p=*(p-1);
    *a=alast;
    m--;
    if(m>0) move(a,n,m);
}








