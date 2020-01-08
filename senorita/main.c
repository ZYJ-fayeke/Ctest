#include<stdio.h>

int old_pos,old_val,pos,val=9;

void t_save(int n,int v)
{
	old_pos=pos;
	old_val=val;
	pos=n;
	val=v;
}

int input(char a[])
{
	char c;
	int pre=0,len=0,find=0,dis;
	printf("Please input a sentence which contains 8-12 words.\n");
	while((c=getchar())!='\n')
		if(c!=' ' && pre==0)
		{
			a[len++]=c;
			pre=1;
			if (c<'a') c+=32;
			if(!find && len>1)
			{
				if(c>='i' && c<='r')
				{
					t_save(len-1,c-'i');
					find=1;
				}
				else
				{
					dis=(c<'i')?'i'-c:c-'r';
					if(dis<val)
                        t_save(len-1,dis);
				}
			}
		}
		else if(c==' ')
			pre=0;
	if(pos==len-1)
	{
		pos=old_pos;
		val=old_val;
	}
	return(len);
}

void convert(char b[],char a[],int n)
{
	int i,j;
	for(j=0,i=pos+1;i<n;i++)
		b[j++]=(a[i]>='a')?a[i]-32:a[i];
	b[j++]='0'+val;
	for(i=0;i<pos;i++)
		b[j++]=(a[i]>='a')?a[i]:a[i]+32;
	b[j]='\0';
}

void main()
{
	char a[12],b[13];
	int len;
	len=input(a);
	//a[len]='\0';
	//printf("%d\n",len);
	//puts(a);
	convert(b,a,len);
	printf("The password is: %s\n",b);
}
