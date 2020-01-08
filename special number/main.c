#include <stdio.h>
#include <stdlib.h>

/*Perfect number 完全数*/
/*int main()
{
    int n,i,s=0;
    printf("输入数字判断还是不是完全数:");
    scanf("%d",&n);
    for(i=1;i<n;i++)  //注意：i不可以等于n
    {
        if(n%i==0)
            s=s+i;
    }
    if(s==n)
        printf("Perfect number!\n");
    else
        printf("Not perfect number\n");
    return 0;
}
*/

/*回文数*/
int main()
{
    int n,reverseN=0,remainder,n1;
    printf("请输入一个数字来判断是不是回文数:");
    scanf("%d",&n);n1=n;

    while(n!=0)
    {
        remainder=n%10;
        reverseN=reverseN*10+remainder;
        n/=10;
    }
    if(n1==reverseN)
        printf("是回文数！\n");
    else
        printf("不是回文数！\n");

    return 0;
}
