#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;
    int max,min;
    scanf("%d%d",&x,&y);
    max=measure(x,y);
    printf("最大公约数为:%d",max);
   return 0;
}

int measure(int x, int y)

{

	int z = y;

	while(x%y!=0)

	{

		z = x%y;

		x = y;

		y = z;

	}

	return z;

}
