#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <stdlib.h>  


using namespace std;


struct dist
{
	int c1;
	int c2;
	long long int d;
};

dist arr[1000010];
int city[510];
int compare (const void * a, const void * b)
{
  struct dist* f=(dist *)a;
  struct dist* e=(dist *)b;
  long long int a1=f->d;
  long long int a2=e->d;
  if(a1>a2)
	  return 1;
  else if(a1==a2)
	  return 0;
  else 
	  return -1;
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
	
	while(cin>>m>>n)
	{
		if(m==0&&n==0)
			break;
		memset(arr,0,sizeof(arr));
		memset(city,-1,sizeof(city));
		dist t={0,0,-2147483648};
		arr[0]=t;
		int N=n;
		while(n)
		{
			long long int a,b,c;
			n--;
			cin>>a>>b>>c;
			dist temp={a,b,c};
			arr[N-n]=temp;
		}
		qsort (arr, N+1, sizeof(dist), compare);
		int max=arr[N].d;
		
		for(int i=N;i>0;i--)
		{
			if(arr[i].d<max)
				break;
			int t1=find(arr[i].c1);
			int t2=find(arr[i].c2);
			if(t1!=t2){
				setunion(t1,t2);
			}	
		}
		int min=-1;
		while(m>0)
		{
			if(city[m]<min)
				min=city[m];
			m--;
		}
		
		
		printf("%d\n",min*(-1));
	}	

	return 0;
}
/*
4 5
1 2 -2147483644
1 3 -2147483644
1 4 -2147483647
2 3 -2147483644
3 4 -2147483647

4 5
1 2 100
1 3 100
1 4 1
2 3 100
3 4 1
9 14
1 2 9
6 9 8
2 4 9
2 3 9
4 5 1
4 3 9
5 9 2
9 8 9
7 8 9
7 9 5
6 7 9
5 6 4
5 8 7
7 5 9


*/