#include <stdio.h>

/*int main()
{
    char *forment;
    int a=9,b=8;
    forment="a=%d,b=%d\n";
    printf(forment,a,b);
    return 0;
}*/
//�α���ϰ��

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
    if(n==1) p=max;//����������ڵ�ַ��p
    else if(n==2) p=min;
    key=(*p)(a,b);//���ú��������
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
//�κ���ϰ������⣺

/*int main()

{
    void change(int *p,int);
    void output(int *p);
    int p[10],i;  //������Ҫ�ģ�����������ָ���ʡ�£�
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
    temp=p[0];   //�տ�ʼ��û�д�������ߵĽ�����
    p[0]=*min;
    *min=temp;
    for(z=p+1;z<p+10;z++)
        if(*p>*max) max=p;
    temp=p[9];
    p[9]=*max;
    *max=temp;
}
void output(int *p) //ֱ�ӽ����鴫��output���������þ���Ԫ�غͺ��������ӹ�ϵ
{
    int i;
  for(i=0;i<10;i++)
    printf("%d\t",*p++);
    printf("\n");
}*/
//�κ�ϰ������⣺

/*void  main(){
    int a[120] = {0}, i = 0, leaveman = 0, flag= 0, *p,n,k;
    printf("please input the number of the people:");
     scanf("%d",&n);
     p = a;
     printf("please enter 'k':");
     scanf("%d",&k);
     while (1)
        {          //ѭ������
             if(*p == 0)
              {
                  if (leaveman == (n - 1))
                    break; //�����ʣһ��
                  flag++;         //����
                  flag %= k;      //���Ϊk������k�ʹ�0��ʼ
                 if(flag == 0)
                    {
                        *p = 1;
                       leaveman++;
                    } //Ϊ0(��3)����
               }
            p++;
            if (p == a + n)
                p = a;  //����ע��ģ���ȻҪע����ָ��ָ��λ�ã���ַ������Ҫ�仯�İ�����ѭ��ת����һ��(���ݸ��������ף�
        }
      printf("Last man is : No.%d\n", p + 1 - a);
 }*/
//ѧ�š��������ɼ���ƽ���֡�������

/*int main()
{
     void  ascr1(float (*pscr)[5] ,char (*pcourse)[12]); //ע�⺯�����βε�������������ֱ��*psrc��
     void change(float (*pscr)[5],char (*pname)[8],int *pnum,float aver[4]);
    void  avscorce(float (*pscr)[5],float *paver);
    void exce(float aver[4],float (*pscr)[5],char (*pname)[8],int *pnum);
    char course[5][12]={"course 1","course 2","course 3","course 4","course 5"}; //������д���ſγ�����
    char name[4][8]={"Lihua","Marry","Linda","Lelie"};
    int i,j,*pnum;
    char (*pcourse)[12],(*pname)[8];
    int num[4]={1111,1112,1113,1114};
    float scr[4][5]={{96,97,79,91,95},{78,80,67,58,65},{67,87,66,98,63},{70,40,77,88,71}};
    float (*pscr)[5],*paver;
    float  aver[4];
    pnum=num;  //һά�����ű��
    pscr=scr;  //��ά������ѧ���ɼ�
    pcourse=course;  //һά�����ſγ�����
    pname=name;  //һά������ѧ������
    paver=aver;  //Ҫʹָ��ָ�����飡
    printf("ѧ��:");
    printf("������");
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
        sum=0.0;//��һ��ССС�Ĵ�����֪������˶೤ʱ����һ����Сʱ �����Ǹ�ɵ�ӣ�
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

    printf("��һ�ſγ�%s��ƽ���֣�%f",*pcourse,ave);

}
void exce(float aver[4],float (*pscr)[5],char (*pname)[8],int *pnum)
{
    int i,j,sign;
    printf("\nƽ���ɼ���90�����ϻ���ÿ�ſγ̶���85�����ϵ�����:\n");
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
             printf("\nƽ���ɼ���:%11.2f",aver[i]);
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
//���ݽṹ

int main()
{

        /*struct student
        {
            long int num;
            char name[20];
            char sex;
            char addr[20];
        }a={10101,"keke",'L',"123 Beijing Road"};//����ṹ������ͬʱ��������ֵ��

    printf("N0.:%ld\nname:%s\nsex:%c\naddress:%s\n",a.num,a.name,a.sex,a.addr);*/
    /*struct student
    {
        int num;
        char name[20];
        float score;
    }student1,student2;  //���������ṹ��������
    scanf("%d%s%f",&student1.num,student1.name,&student1.score); //��nameǰ��û��&��ԭ������������ʹ����ַ������Ҫ���������ټ�&
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
    //������������M,N ����move����
    void move (int a[20],int n,int m);
    int a[20],m,n,i;
    printf("please input a number 'n':");
    scanf("%d",&n);
    printf("please input %d number:",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);  //��������ֱ��д��a[20]�Ļ�������������⣡
    printf("please input a number 'm':");
    scanf("%d",&m);
    move(a,n,m); //�������õ�ʱ�������д��ע�⣡
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








