#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,c=0;
    printf("����������:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
            c++;
    }
    if(c==2)  //c++���������Σ�һ����1��һ����������
        printf("��������\n");
    else
    {
        printf("����������\n");
    }
    return 0;
}
