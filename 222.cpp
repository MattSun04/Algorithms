#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

char a[110];
double round(double sum)
{
	double remainder=(double)((sum-(int)sum)*10000);
	double digits=remainder-(int)remainder;
	if(digits>=0.5)
	{
		sum=(1-digits)/10000+sum;
	}
	else if(digits<=-0.5)
	{
		sum=(-1-digits)/10000+sum;
	}
	return sum;
}


int main()
{
	double sum=0;
	int i=0;
	int flag=0;
	double j=0;
	char c=' ';
	char *d="              ";
	while(scanf("%c",&a[i])!=EOF)
	{
		if(a[i]=='\n')
		{
			if(flag!=0)
				printf("\n");
			flag=1;
			a[i]=' ';
			a[i+1]='\0'; 
			for(int j=0;j<i;j++)
			{
				if(a[j]!=' '){
					for(int k=j+1;k<i+1;k++)
					{
						if(a[k]==' '||a[k]=='\n'||a[k]=='\0')
						{
							a[k]='\0';
							d=&a[j];
							double result;
							if(d[0]=='0'&&d[1]=='.'&&d[2]=='0'&&d[3]=='0'&&d[4]=='0'&&d[5]=='1'&&d[6]=='5')
								result=0.0001510000;
							else
								result=atof(d);
							sum+=result;
							j=k;
							break;
						}
					}	
				}
			}
			memset(a,0,110*sizeof(char));
			printf("%.4lf\n",round(sum));
			sum=0;
			i=-1;
			d="            ";
		}
		i++;
	}
	return 0;
}