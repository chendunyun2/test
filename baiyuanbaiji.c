#include<stdio.h>
void main()
{
	int x,y,z,i;
	for(x=0;x<21;x++)
	{
		for(y=0;y<33;y++)
		{
			for(z=0;z<101;z++)
			{
				if(z%3==0)
				{
					if((x+y+z==100)&&(5*x+3*y+z/3==100))
					{
						printf("������Ϊ:%d ĸ����Ϊ:%d С����Ϊ:%d \n",x,y,z);
						break;
					}
				}
				
			}
		}
	}
}
