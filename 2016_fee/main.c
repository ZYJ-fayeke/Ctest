#include <stdio.h>
#include <stdlib.h>

int main()
{
    float fee(float,float,float);
    int n;
    float k;
    float addfee;
    float bas,pri;
    scanf("%d,%f",&n,&k);
    switch(n)
    {
    case 0:
        addfee=3.0;
        bas=10.0;
        break;
    case 1:
        addfee=4.0;
        bas=10.0;
        break;
    case 2:
        addfee=5.0;
        bas=15.0;
        break;
    case 3:
        addfee=6.5;
        bas=15.0;
        break;
    case 4:
        addfee=10.0;
        bas=15.0;
        break;
    default:
        printf("Error in Area!\n");
        break ;
    }
    pri=fee(addfee,bas,k);
    printf("Price:%5.2f",pri);
    return 0;
}

//º∆À„‘À∑—
float fee(float add,float b,float kio)
{
    float sum;
    if(kio<1.0)
        sum=b;
    else if(kio>1.0)
    {
        sum=b+((int)kio)*add;
    }
    return sum;
}
