#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<math.h>
#define MODE 1000000007

using namespace std;

int solution[1001][1001];
int main()
{
	
	 
	 char * a = (char *)malloc(sizeof(char) * 1001);
	 char * b = (char *)malloc(sizeof(char) * 1001);
	 while(cin.getline(a,1001))
	{
		cin.getline(b,1001);
		int n=0,m=0;
		while(1)
		{
			if(b[n]=='\0')
				break;
			n++;
		}
		while(1)
		{
			if(a[m]=='\0')
				break;
			m++;
		}
		for(int i=1;i<=m;i++)
		{	
			for(int j=1;j<=n;j++)
			{
				if(a[i-1]==b[j-1])
					solution[i][j]=solution[i-1][j-1]+1;
				else 
				{
					if(solution[i-1][j]>=solution[i][j-1])
						solution[i][j]=solution[i-1][j];
					else
						solution[i][j]=solution[i][j-1];
				}
			}
		}

		printf("%d\n",solution[m][n]);

		memset(solution,0,1002001*sizeof(int));
		memset(a,0,1001*sizeof(char));
		memset(b,0,1001*sizeof(char));
	}
	return 0;
}