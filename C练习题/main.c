#include <stdio.h>
#include <stdlib.h>
#define N 10
/*请编写函数long fun(long int x)，功能是：
将长整型数x中每一位上为奇数的数依次取出，并逆序构成一个新数返回。
例如：程序运行时输入123456789，输出：b=97531。*/
/*long fun(long);
int main()
{

	long a,b;
	printf("Enter a number:");
	scanf("%ld",&a);
	b=fun(a);
	printf("b=%ld\n",b);
	return 0;
}

long fun(long x)
{
	int i=0,m,a[20];
	long b=0,b2;
	do
	{
		m=x%10;
		if(m%2!=0)
		{
			a[i]=m;
			i=i+1;
		}
	}
	while((x/=10)!=0);
        for(i=i-1;i>=0;i--)
		    b=b*10+a[i];
   for(b2=0;b;b/=10)  //给我记住逆序输数字！!!
    b2=b2*10+b%10;

	return b2;
}*/
/*===========================
第七章：4行列转换
5 反序字符串
10 输出最长的字符串
16 十六进制转十进制
17 整数转字符串
=============================*/



