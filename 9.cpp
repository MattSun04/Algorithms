#define _CRT_SECURE_NO_WARNINGS
#define REMAIN 0
#define INSERT 1
#define DELETE 2
#define MODIFY 3
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>


using namespace std;

struct p
{
	int cost;
	int operation;
};



p d[50][50];
int main()
{
	string a;
	string a1;
	int operation;
	
	while(cin>>a>>a1)
	{
		int length=0;
		memset(d,0,2500*sizeof(p));
		if(a=="#")
			break;
		int max1=a.length();
		int max2=length=a1.length();
		
		for(int i=0;i<max1+1;i++)
		{
			p p1={i,0};
			d[0][i]=p1;
		}
		for(int i=0;i<max2+1;i++)
		{
			p p1={i,0};
			d[i][0]=p1;
		}
		for(int i = 1 ;i < max2 + 1 ;i++)
		{
			for(int j = 1 ;j< max1 + 1; j++)
			 {
				 int temp=0;
				 if(a[j-1]!=a1[i-1])
					 temp=1;
				 if(d[i-1][j-1].cost+temp<=d[i][j-1].cost+1&&d[i-1][j-1].cost+temp<=d[i-1][j].cost+1)
				 {
						p p1={d[i-1][j-1].cost+temp,MODIFY};
					 d[i][j]=p1;
				 }
				 else if(d[i][j-1].cost<=d[i-1][j].cost)
				 {
					p p1={d[i][j-1].cost+1,INSERT};
					d[i][j]=p1;
				 }
				 else
				 {	 
					 p p1={d[i-1][j].cost+1,DELETE};
					 d[i][j]=p1;
				 }

			 }
			
		}
		printf("%d",d[max2][max1].cost);

	}

		
	


	return 0;
}