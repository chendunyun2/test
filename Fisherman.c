#include<stdio.h>

int main(int agrc,char* agrv[])
{
	int month,day,i;
	printf("Please enter month and date(The format is:month-day):");
	int a[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	scanf("%d-%d",&month,&day);
	int sum = 0;
	for(i=0;i<month-1;i++)
	{
		sum+=a[i];
	}
	int number = sum + day;
	if(number%5>0&&number%5<4)
	{
		printf("The fisherman is fishing\n");
	}
	else
	{
		printf("The fisherman was drying his net\n");
	}
}