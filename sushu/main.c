#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,c=0;
    printf("请输入数字:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
            c++;
    }
    if(c==2)  //c++进行了俩次，一次是1，一次是它本身
        printf("是素数！\n");
    else
    {
        printf("不是素数！\n");
    }
    return 0;
}
