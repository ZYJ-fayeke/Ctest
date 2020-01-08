#include <stdio.h>
//#include <stdlib.h>

//1210  快速排序
/*int a[101],n;

void quickshort(int left,int right)
{
    int i,j,temp,t;

    if(left>=right)
        return ;

    i=left;
    j=right;
    temp=a[left];

    while(i<j)
    {
        while(a[j]>=temp && i<j)
            j--;

        while(a[i]<=temp && i<j)
            i++;

        if(i<j)  //意思是若出现不符合上述while条件就要进行if，交换
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[left]=a[i];
    a[i]=temp;

    quickshort(left,i-1);  //不明白的地方记下哈哈哈
    quickshort(i+1,right);
}
int main()
{
    int i;
    printf("input number:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    quickshort(0,n-1); //函数调用
    for(i=0;i<n;i++)
        printf("%5d",a[i]);

    return 0;
}*/
//1216 ---指针课后题
/*将一个5*5的矩阵最大的元素放在中心，4个角放4个较小的元素*/
/*int main()
{
    void change(int *p);
    int a[5][5],*p,i,j;
    printf("please input 5*5 arr:\n");
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            scanf("%d",&a[i][j]);
    p=&a[0][0];
    change( p );  //只需要写出指针变量名字就可，不需要加*
    printf("now new arr:\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            printf("%3d",a[i][j]);
        printf("\n");
    }

    return 0;
}

//定义函数交换位置
void change(int *p)
{
   int i,j,temp;
   int *pmin,*pmax;

   pmin=p;
   pmax=p;
   for(i=0;i<5;i++)
    for(j=i;j<5;j++)  //细节问题
   {
       if(*pmax<*(p+i*5+j)) pmax=p+i*5+j;  //注意了！没交换地址没写*，一般情况也就简单的交换值就可
       if(*pmin>*(p+i*5+j)) pmin=p+i*5+j;
   }
   //找出最大值
   temp=*(p+12);
   *(p+12)=*pmax;
   *pmax=temp;

   temp=*p;  //准备将最小值给左上角
   *p=*pmin;
   *pmin=temp;
   //前方高能
   pmin=p+1;//呼应代码80行，思想要灵活一点啊少年
   for(i=0;i<5;i++)
    for(j=0;j<5;j++)
    if((*pmin>*(p+5*i+j))&&(p+5*i+j)!=p)  pmin=p+i*5+j;

    //找出第三个小值
   temp=*pmin;
   *pmin=*(p+4);  //!!!按列看
   *(p+4)=temp;
   pmin=p+1;
   for(i=0;i<5;i++)
    for(j=0;j<5;j++)
    if((*pmin>*(p+5*i+j))&&((p+5*i+j)!=p)&&((p+5*i+j)!=(p+4)))  pmin=p+i*5+j;

    //最后一个小值
    temp=*pmin;
   *pmin=*(p+20);
   *(p+20)=temp;
   pmin=p+1;
   for(i=0;i<5;i++)
    for(j=i;j<5;j++)
    if((*pmin>*(p+5*i+j))&&((p+5*i+j)!=p)&&((p+5*i+j)!=(p+4))&&((p+5*i+j)!=(p+20)))  pmin=p+i*5+j;
   temp=*pmin;
   *pmin=*(p+24);
   *(p+24)=temp;
}*/


