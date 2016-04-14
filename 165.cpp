#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <stdlib.h>  
#include <math.h> 
/* uva 534
 http://acm.cs.cityu.edu.hk/oj2/index.php/p/165/getProblemStatement?act=view*/

using namespace std;


struct dist
{
	int c1;
	int c2;
	double d;
};
struct point
{
	int x;
	int y;
};

point sh[202];
dist arr[20002];
int city[202];

int compare (const void * a, const void * b)
{
  struct dist* f=(dist *)a;
  struct dist* e=(dist *)b;
  if((double)f->d > (double)e->d)
	  return 1;
  else if(f->d == e->d)
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
	int flag=0;
	

	while(cin>>n)
	{
		flag++;
		if(n==0)
			break;
		
		memset(sh,0,sizeof(sh));
		memset(arr,0,sizeof(arr));
		memset(city,-1,sizeof(city));
		
		int N=n;
		while(n)
		{
			int a,b,c;
			cin>>a>>b;
			point temp={a,b};
			sh[N-n]=temp;
			n--;
		}
		int count=0;
		for (int i = 0; i < N; i++)  {
        for (int j = i+1; j < N; j++) {  
			dist temp={i,j,0};
			temp.d = sqrt((sh[i].x-sh[j].x)*(sh[i].x-sh[j].x)+(sh[i].y-sh[j].y)*(sh[i].y-sh[j].y));  	 
			arr[count]=temp;
			count++;
        }  
		}
		qsort(arr, N*(N-1)/2, sizeof(dist), compare);
		
		int t=0;
		for(t=0;t<N*(N-1)/2;t++)
		{
			int t1=find(arr[t].c1);
			int t2=find(arr[t].c2);
			int t3=find(0);
			int t4=find(1);
			if(t3==t4)
				break;
			if(t1!=t2){
				setunion(t1,t2);	
			}
		}



		printf("Scenario #%d\n",flag);
		printf("Frog Distance = %.3lf\n\n",arr[t-1].d);
	}	

	return 0;
}