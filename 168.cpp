#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <stdlib.h>  

/*
 NETWORKING
http://acm.cs.cityu.edu.hk/oj2/index.php/p/168/getProblemStatement?act=view*/

using namespace std;


struct dist
{
	int c1;
	int c2;
	int d;
};

dist arr[10000];
int city[60];
int visited[60];

int compare (const void * a, const void * b)
{
  struct dist* f=(dist *)a;
  struct dist* e=(dist *)b;
  return ( f->d - e->d);
}

void setunion(int Root1, int Root2)  
{  
    if(city[Root2]<city[Root1])  
    {  
		city[Root2]+=city[Root1];
		city[Root1] = Root2;	
	}
    else  
    {  
        city[Root1]+=city[Root2];
		city[Root2] = Root1;
    }  
}  


int find(int x)  
{  
    if(city[x]<0)  
        return x;  
    else  
        return find(city[x]);  
}  



int main()
{
	int m,n;
	
	

	while(cin>>m)
	{
		if(m==0)
			break;
		cin>>n;
		memset(arr,0,sizeof(arr));
		memset(city,-1,sizeof(city));
		memset(visited,0,sizeof(city));
		int N=n;
		while(n)
		{
			int a,b,c;
			n--;
			cin>>a>>b>>c;
			dist temp={a,b,c};
			arr[N-n]=temp;
		}
		qsort (arr, N+1, sizeof(dist), compare);
		int max=arr[N].d;
		int visit=0;
		int length=0;
		for(int i=1;i<N+1;i++)
		{
			int t1=find(arr[i].c1);
			int t2=find(arr[i].c2);
			if(t1!=t2){
				setunion(t1,t2);
				length+=arr[i].d;
			}
			if(visited[arr[i].c1]==0)
			{
				visit++;
				visited[arr[i].c1]=1;
			}
			if(visited[arr[i].c2]==0)
			{
				visit++;
				visited[arr[i].c2]=1;
			}
			if(visit==N)
				break;
		}
		
		
		
		printf("%d\n",length);
	}	

	return 0;
}