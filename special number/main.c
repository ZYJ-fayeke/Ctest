#include <stdio.h>
#include <stdlib.h>

/*Perfect number ��ȫ��*/
/*int main()
{
    int n,i,s=0;
    printf("���������жϻ��ǲ�����ȫ��:");
    scanf("%d",&n);
    for(i=1;i<n;i++)  //ע�⣺i�����Ե���n
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

/*������*/
int main()
{
    int n,reverseN=0,remainder,n1;
    printf("������һ���������ж��ǲ��ǻ�����:");
    scanf("%d",&n);n1=n;

    while(n!=0)
    {
        remainder=n%10;
        reverseN=reverseN*10+remainder;
        n/=10;
    }
    if(n1==reverseN)
        printf("�ǻ�������\n");
    else
        printf("���ǻ�������\n");

    return 0;
}
