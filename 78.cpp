#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include<string>
#include <stack>
using namespace std;


int main()
{
	int n;
	scanf("%d",&n);
	while(n>0)
	{
		n--;
		char* a=new char[55];
		memset(a,0,55*sizeof(char));
		char b[55]={0};
		int index=0;
		int count=0;
		
		cin>>a;
		

		for(int i=0;a[i];i++)
		{
			char min='a'-1;
			for(int j=i;a[j];j++)
			{
				if(a[j]>min)
				{
					min=a[j];
					count=j;
				}
			}
			i=count;
			b[index]=a[count];
			index++;
		}
		b[index+1]='\0';
		printf("%s\n",b);
	}
	return 0;
}
/*

3
office
hall
1234 5 32
3
office:hall 5 5
1234 5 32:office 1 2
1234 5 32:hall 2 2



*/