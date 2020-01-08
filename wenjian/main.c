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
    printf("������ѧ����������ѧ�ţ����ſγɼ�\n");
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
        printf("�����д���!\n");
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
	printf("������������ѧ�ź����ſγ̳ɼ�:\n");
	for(i=0;i<N;i++)
	{
		scanf("%s %d %f %f %f",stu[i].name,&stu[i].num,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
		stu[i].aver=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3.0;
	}
	fun();
	FILE *fp;
	if((fp=fopen("stud","r"))==NULL)
	{
		printf("erro��\n");
		exit(0);
	}
	printf("the data:\n");
	for(i=0;i<N;i++)
	{
		fread(&stu[i],sizeof(struct student),1,fp);
		printf("%-5s%-5d%5.2f%5.2f%5.2f%5.2f\n",stu[i].name,stu[i].num,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver);
	}	//������ļ��ж�ȡ����������Ļ������֤
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
		fread(&stu[i],sizeof(struct student),1,fp1);		//�ȶ�ȡԭ�������ݣ���������ʾ����Ļ��
		printf("%-5s%-2d%5.2f%5.2f%5.2f%5.2f\n",stu[i].name,stu[i].num,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver);
	}
	fclose(fp1);			//�ر��ļ�stud
	for(i=0;i<N-1;i++)		//ѡ������
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
		if(fwrite(&stu[i],sizeof(struct student),1,fp2)!=1)		//������������д���ļ�stud_sort�в��ر��ļ�
			printf("file write error!\n");
	fclose(fp2);
	if((fp2=fopen("stud_sort","rb"))==NULL)			//���´��ļ�stud_sort
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
	fclose(fp2);		//�ر��ļ�stud_sort
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
    printf("������һ��ѧ���ĳɼ�:\n");
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
	if((fp2=fopen("stud_new","rb"))==NULL)		//���´��ļ�stud_new
	{
		printf("cannot open the file\n");
		exit(0);
	}
	printf("\n������ѧ���ɼ�:\n");
	for(i=0;i<N+1;i++)
	{
		fread(&stu[i],sizeof(struct student),1,fp2);
		printf("%-5s%-2d%7.1f%7.1f%7.1f%7.1f\n",stu[i].name,stu[i].num,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].aver);
	}
	fclose(fp2);

    return 0;
}



