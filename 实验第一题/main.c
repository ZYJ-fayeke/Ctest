#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k;
    int i,count=0,j;
    int sum;
    scanf("%d%d",&n,&k);
    int a[n];
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
        {


            sum=sum+a[i];
            if((sum>k)||(sum==k))
            {
                 count++;
                 sum=0;

            }
        }


    printf("%d\n",count);
    return 0;
}
