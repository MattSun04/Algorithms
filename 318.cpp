/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 21609
 * Submitted at:  2016-02-20 21:32:09
 *
 * User ID:       271
 * Username:      53062476
 * Problem ID:    318
 * Problem Name:  Obstacle Course
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int array[125][125];
int result[125][125];
bool visited[125][125];
struct Node{
    int v,x, y;
	Node(int d=0,int a= 0,int b= 0 ):
       v(d), x(a), y(b) {}
};
bool operator<( Node a, Node b ){
    return a.v>b.v;
}
int main()
{
	int n;
	int number=0;
	priority_queue<Node> q;
	while(scanf("%d",&n))
	{
		if(n==0)
		{
			break;
		} 
		while( !q.empty() )
		{
			 q.pop();
		}
		number++;
		int N=n;
		
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				result[i][j]=-1;
				visited[i][j]=1;
			}
		}

		
		while(n>0)
		{
			int count=0;
			n--;
			while(count<N)
			{
				count++;
				scanf("%d",&array[N-n-1][count-1]);
			}
		}
		
		result[0][0]=array[0][0];
		result[0][1]=array[0][1]+array[0][0];
		result[1][0]=array[1][0]+array[0][0];
		visited[0][0]=0;
		q.push( Node(result[0][1],0,1) );
		q.push( Node(result[1][0],1,0) );
		while(visited[N-1][N-1]!=0)
		{
			int min=126;
			int x=0,y=0;
			x=q.top().x;
			y=q.top().y;
			q.pop();
			visited[x][y]=0;
			if(x+1<N&&visited[x+1][y]==1)
			{
				if(result[x+1][y]==-1||result[x+1][y]>result[x][y]+array[x+1][y])
				{	result[x+1][y]=result[x][y]+array[x+1][y];
					q.push( Node(result[x+1][y],x+1,y) );
				}
			}
			if(y+1<N&&visited[x][y+1]==1)
			{
				if(result[x][y+1]==-1||result[x][y+1]>result[x][y]+array[x][y+1])
				{result[x][y+1]=result[x][y]+array[x][y+1];
				q.push( Node(result[x][y+1],x,y+1) );}
			}
			if(x-1>=0&&visited[x-1][y]==1)
			{
				if(result[x-1][y]==-1||result[x-1][y]>result[x][y]+array[x-1][y])
				{result[x-1][y]=result[x][y]+array[x-1][y];
				q.push( Node(result[x-1][y],x-1,y) );}
			}
			if(y-1>=0&&visited[x][y-1]==1)
			{
				if(result[x][y-1]==-1||result[x][y-1]>result[x][y]+array[x][y-1])
				{	result[x][y-1]=result[x][y]+array[x][y-1];
					q.push( Node(result[x][y-1],x,y-1) );}
			}
		}
		printf("Problem %d: %d\n",number,result[N-1][N-1]);	
	}
	return 0;
}
/*

3
5 5 4
3 9 1
3 2 7
5
3 7 2 0 1
2 8 0 9 1
1 2 1 8 1
9 8 9 2 0
3 6 5 1 5
7
9 0 5 1 1 5 3
4 1 2 1 6 5 3
0 7 6 1 6 8 5
1 1 7 8 3 2 3
9 4 0 7 6 4 1
5 8 3 2 4 8 3
7 4 8 4 8 3 4
3
2 3 3
1 2 2
0 0 1
0 


*/