#include <stdio.h>

//1212  ����13����Χ��һȦ���ӵ�һ���˿�ʼ˳�򱨺�1��2��3������3���˳�
#define N 13
struct person
{
    int number;
    int pnext;
} a[N+1];

int main()
{
    int i,count,h;
    for(i=1;i<=N;i++)
    {
        if(i==N)
            a[i].pnext=1;
        else
            a[i].pnext=i+1;
        a[i].number=i;

    }
    printf("\n");
    count=0;
    h=N;
    printf("leaveman:\n");
    while(count<N-1)
    {
        i=0;
        while(i!=3)
        {
            h=a[h].pnext;  //����������!!!
            if(a[h].number)
                i++;
        }
        printf("%4d",a[h].number);
        a[h].number=0;
        count++;
    }
    printf("\nthe last one:");
    for(i=1;i<=N;i++)
        if(a[i].number)
        printf("%4d",a[i].number);
        printf("\ntimes:%3d",count+1);
        printf("\n");
   return 0;
}

