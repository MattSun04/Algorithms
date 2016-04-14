#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>

using namespace std;


bool island[52][52];
bool visited[52][52];

struct num
{
	int a;
	int b;
};


void DFS(num in)
{
	visited[in.a][in.b]=1;
	num test;
	if(!visited[in.a+1][in.b]&&island[in.a+1][in.b]==1)
	{
		test.a=in.a+1;
		test.b=in.b;
		DFS(test);
	}
	if(!visited[in.a][in.b+1]&&island[in.a][in.b+1]==1)
	{
		test.a=in.a;
		test.b=in.b+1;
		DFS(test);
	}
	if(!visited[in.a+1][in.b+1]&&island[in.a+1][in.b+1]==1)
	{
		test.a=in.a+1;
		test.b=in.b+1;
		DFS(test);
	}
	if(!visited[in.a+1][in.b-1]&&island[in.a+1][in.b-1]==1)
	{
		test.a=in.a+1;
		test.b=in.b-1;
		DFS(test);
	}
	if(!visited[in.a][in.b-1]&&island[in.a][in.b-1]==1)
	{
		test.a=in.a;
		test.b=in.b-1;
		DFS(test);
	}
	if(!visited[in.a-1][in.b+1]&&island[in.a-1][in.b+1]==1)
	{
		test.a=in.a-1;
		test.b=in.b+1;
		DFS(test);
	}
	if(!visited[in.a-1][in.b]&&island[in.a-1][in.b]==1)
	{
		test.a=in.a-1;
		test.b=in.b;
		DFS(test);
	}
	if(!visited[in.a-1][in.b-1]&&island[in.a-1][in.b-1]==1)
	{
		test.a=in.a-1;
		test.b=in.b-1;
		DFS(test);
	}
}


int main()
{
	int m,n;
	num in;
	while (scanf("%d%d",&m,&n))
	{
		int count=0;
		if(m==0&&n==0)
			break;
		memset(island,0,52*52*sizeof(bool));
		memset(visited,0,52*52*sizeof(bool));
		for(int i=1;i<n+1;i++)
		{
			for(int j=1;j<m+1;j++)
			{
				scanf("%d",&island[i][j]);			
			}			
		}
		
		for(int i=1;i<n+1;i++)
		{
			for(int j=1;j<m+1;j++)
			{
				if(visited[i][j]==0&&island[i][j]==1)
				{
					count++;
					in.a=i;
					in.b=j;
					DFS(in);	
				}
			}			
		}
		cout<<count<<endl;	
	}
	return 0;
}


/*test case
1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
3 3
0 1 0
1 0 0
1 0 0
1 1
1
0 0 

*/