/*#include <stdio.h>
#include <stdlib.h>
#define N 2
struct Student
   {
       char name[10];
       int num;
       int score[3];
       float ave;
   }stud[N];


int main()
{
    FILE *fp;
    int i,j,sum;
    printf("请输入学生的姓名，学号，三门课成绩\n");
    for(i=0;i<N;i++)
    {
         sum=0;
         scanf("%s%d%d%d%d\n",stud[i].name,&stud[i].num,&stud[i].score[0],&stud[i].score[1],&stud[i].score[2]);
         for(j=0;j<3;j++)
             sum+=stud[i].score[j];

        stud[i].ave=sum/3.0;
    }

    if((fp = fopen("stud.txt","w")) == NULL)
    {
        printf("输入有错误!\n");
        exit(0);
    }
    //fp = fopen("stud.txt","w");
    for(i=0;i<N;i++)
        fwrite(&stud[i],sizeof(struct Student),1,fp);
    fclose(fp);
    fp = fopen("stud.txt","r");
    for(i=0;i<N;i++)
    {
        fread(&stud[i],sizeof(struct Student),1,fp);
        printf("%-10s%-5d%-5d%-5d%-5d%-5f\n",stud[i].name,stud[i].num,stud[i].score[0],stud[i].score[1],stud[i].score[2],stud[i].ave);
    }
    fclose(fp);
    return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>
#define N 5
struct student
{
	char name[10];
	int num;
	float score[3];
	float aver;
}stu[N];
void fun()
{
	FILE *fp;
	int i;
	if((fp=fopen("stud","w"))==NULL)
	{
		printf("erro!\n");
		exit(0);
	}
	for(i=0;i<N;i++)
	{
		if((fwrite(&stu[i],sizeof(struct student),1,fp))!=1)
			printf("error!\n");
	}
	fclose(fp);
}
int main()
{
	int i;
	printf("请输入姓名、学号和三门课程成绩:\n");
	for(i=0;i<N;i++)
	{
		scanf("%s %d %f %f %f",stu[i].name,&stu[i].num,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
		stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
	}
	fun();
	FILE *fp;
	if((fp=fopen("stud","r"))==NULL)
	{
		printf("erro！\n");
		exit(0);
	}
	printf("the data:\n");
	for(i=0;i<N;i++)
	{
		fread(&stu[i],sizeof(struct student),1,fp);
		printf("%-5s%-5d%5.2f%5.2f%5.2f%5.2f\n",stu[i].name,stu[i].num,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver);
	}	//输出从文件中读取的数据在屏幕上以验证
	fclose(fp);
	return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>
#define N 5
struct student
{
	char name[10];
	int num;
	float score[3];
	float aver;
}stu[N];
int main()
{
	FILE *fp1,*fp2;
	int i,j,k;
	struct student stu0;

	if((fp1 = fopen("stud","rb"))==NULL)
	{
		printf("cannot open stud!\n");
		exit(0);
	}
	printf("the original date:\n");

	for(i=0;i<N;i++)
	{
		fread(&stu[i],sizeof(struct student),1,fp1);		//先读取原来的数据，并将其显示在屏幕上
		printf("%-5s%-2d%5.2f%5.2f%5.2f%5.2f\n",stu[i].name,stu[i].num,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver);
	}
	fclose(fp1);			//关闭文件stud
	for(i=0;i<N-1;i++)		//选择排序法
	{
		k=i;
		for(j=i+1;j<N;j++)
			if(stu[j].aver<stu[k].aver)
				k=j;
		if(i!=k)
			{
				stu0=stu[i];
				stu[i]=stu[k];
				stu[k]=stu0;
			}
	}
	if((fp2=fopen("stud_sort","wb"))==NULL)
	{
		printf("cannot open stud_sort!\n");
		exit(0);
	}
	for(i=0;i<N;i++)
		if(fwrite(&stu[i],sizeof(struct student),1,fp2)!=1)		//将排序后的数据写到文件stud_sort中并关闭文件
			printf("file write error!\n");
	fclose(fp2);
	if((fp2=fopen("stud_sort","rb"))==NULL)			//重新打开文件stud_sort
	{
		printf("cannot open stud_sort!\n");
		exit(0);
	}
	printf("\nthe sorted data:\n");
	for(i=0;i<N;i++)
	{
		fread(&stu[i],sizeof(struct student),1,fp2);
		printf("%5s%-2d%7.1f%7.1f%7.1f%7.1f\n",stu[i].name,stu[i].num,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver);
	}
	fclose(fp2);		//关闭文件stud_sort
	return 0;
	}*/

#include <stdio.h>
#include <stdlib.h>
#define N 5
struct student
{
	char name[10];
	int num;
	float score[3];
	float aver;
}stu[N+1],stu0;
int main()
{
    FILE *fp1,*fp2;
    int i,j,k;

    if((fp1 = fopen("stud_sort","rb")) == NULL)
    {
        printf("erro!");
        exit(0);
    }
    for(i=0;i<N;i++)
    {
        fread(&stu[i],sizeof(struct student),1,fp1);
		printf("%5s%-2d%7.1f%7.1f%7.1f\n",stu[i].name,stu[i].num,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
    }
    fclose(fp1);
    printf("请输入一个学生的成绩:\n");
    scanf("%s %d %f %f %f",stu[N].name,&stu[N].num,&stu[N].score[0],&stu[N].score[1],&stu[N].score[2]);
    stu[N].aver=(stu[N].score[0]+stu[N].score[1]+stu[N].score[2])/3.0;
    for(i=0;i<5;i++)
    {
        k=i;
        for(j=i+1;j<N+1;j++)
          if(stu[j].aver<stu[k].aver)
				k=j;
		  if(i!=k)
			{
                stu0=stu[i];
				stu[i]=stu[k];
				stu[k]=stu0;
			}
    }
   if((fp2=fopen("stud_new","wb")) == NULL)
	{
		printf("cannot open the file!\n");
		exit(0);
	}
	for(i=0;i<N+1;i++)
	{
		if(fwrite(&stu[i],sizeof(struct student),1,fp2)!=1)
	}			printf("file write error\n");

	fclose(fp2);
	if((fp2=fopen("stud_new","rb"))==NULL)		//重新打开文件stud_new
	{
		printf("cannot open the file\n");
		exit(0);
	}
	printf("\n插入后的学生成绩:\n");
	for(i=0;i<N+1;i++)
	{
		fread(&stu[i],sizeof(struct student),1,fp2);
		printf("%-5s%-2d%7.1f%7.1f%7.1f%7.1f\n",stu[i].name,stu[i].num,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver);
	}
	fclose(fp2);

    return 0;
}



