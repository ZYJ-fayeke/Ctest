#include <stdio.h>
#include <stdlib.h>
#define N 10
/*���д����long fun(long int x)�������ǣ�
����������x��ÿһλ��Ϊ������������ȡ���������򹹳�һ���������ء�
���磺��������ʱ����123456789�������b=97531��*/
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
   for(b2=0;b;b/=10)  //���Ҽ�ס���������֣�!!
    b2=b2*10+b%10;

	return b2;
}*/
/*===========================
�����£�4����ת��
5 �����ַ���
10 �������ַ���
16 ʮ������תʮ����
17 ����ת�ַ���
=============================*/



