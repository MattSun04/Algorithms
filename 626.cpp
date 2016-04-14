#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#define MODE 1000000007

using namespace std;

int values[10000];
int solutions[1000002];
int main()
{
	int n;
	int m;

	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&m);
		memset(values,0,10000*sizeof(int));
		memset(solutions,0,1000002*sizeof(int));

		int i=0;
		for(i=0;pow(m,i)<=n;i++)
		{}
		
		solutions[0] = 1;
    
		for(int j=0;j<i;j++)
		{
			values[j]=(int)pow(m,j);
		}

		for (int k= 0; k < i; k++)
		{
			for (int j = values[k]; j <= n; j++)
			{
				solutions[j] =(solutions[j]+solutions[j - values[k]])%MODE;
			
			}
		}

		printf("%d\n",solutions[n]);
	}
	return 0;
}