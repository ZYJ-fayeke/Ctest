#include <stdio.h>
#include <stdlib.h>
int days(int y,int m,int d);
int main()
{
    int year,month,day;
    printf("enter year,month and day:");
    scanf("%d %d %d",&year,&month,&day);
    printf("this is %d day in this year!\n",days(year,month,day));
    return 0;
}
int days(int y,int m,int d)

{
    int i,sum=d;
    int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    for(i=1;i<m;i++)
        sum+=a[i];
    if(m>2&&((y%4==0&&y%100!=0)||y%400==0))//考虑闰年的情况
        sum++;
    return sum;
}


