#include <stdio.h>
#include <stdlib.h>

int sort(const char *p1,char *p2)
{
    const char *f;
    char *s;
    int count=0;
    while(*p1!='\0')
    {
        f=p1;
        s=p2;
        while((*f==*s)!='\0')  //ѭ������������Ҫдif������
        {
            f++;
            s++;
        }
       if(*s=='\0')
        {
            count++;
        }
        p1++;
    }
    return count;
}

int main()
{
    /*char f[100],s[100];
    printf("���븸�ַ�����\n");
    scanf("%s",f);
    const char *sourcestr=f;
    printf("�������ַ�����\n");
    scanf("%s",s);
    char *sub=s;*/
    const char *sourcestr="jb is yummy i love jb jb";
    char *sub="jb";
    int n=0;
    n=sort(sourcestr,sub);

    printf("Count:%d\n",n+1);

    return 0;
}


