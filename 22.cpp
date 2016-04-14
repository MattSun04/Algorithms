#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
#include<queue>
using namespace std;

bool prime[10001];
bool visited[10001];
struct num
{
	int a;
	int level;
};

queue<num> q;

int main()
{
	
	memset(prime,0,10000*sizeof(bool));
	
	for(int i=1001;i<10000;i=i+2)
	{
        int s=(int)sqrt(i);
        for(int j=s;j>1;j--){
            if(i%j==0){
              prime[i]=1;
			  break;
            } 
		}
	}
	int n;
	int in,out;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int degree=-1;
		while(!q.empty())
		{
			q.pop();
		}
		memset(visited,0,10000*sizeof(bool));
		cin>>in>>out;
		num begin={in,0};	
		visited[in]=1;
		q.push(begin);
		while(!q.empty())
		{
			num test=q.front();
			if(test.a==out)
			{
				degree=test.level;
				break;
			}
			q.pop();
			int d1=test.a%10;
			int d2=(test.a%100-d1)/10;
			int d3=(test.a%1000-d2*10-d1)/100;
			int d4=(test.a-d3*100-d2*10-d1)/1000;
			//lowest bit
			for(int i=1;i<10;i=i+2)
			{
				if(i==5)
					continue;
				if(prime[test.a-d1+i]==0 && visited[test.a-d1+i]==0)
				{
					visited[test.a-d1+i]=1;
					num inter={test.a-d1+i,test.level+1};
					q.push(inter);
				}
			}
			for(int i=0;i<10;i++)
			{
				if(prime[test.a-d2*10+i*10]==0 && visited[test.a-d2*10+i*10]==0)
				{
					visited[test.a-d2*10+i*10]=1;
					num inter={test.a-d2*10+i*10,test.level+1};
					q.push(inter);
				}
			}
			for(int i=0;i<10;i++)
			{
				if(prime[test.a-d3*100+i*100]==0 && visited[test.a-d3*100+i*100]==0)
				{
					visited[test.a-d3*100+i*100]=1;
					num inter={test.a-d3*100+i*100,test.level+1};
					q.push(inter);
				}
			}
			for(int i=1;i<10;i++)
			{
				if(prime[test.a-d4*1000+i*1000]==0 && visited[test.a-d4*1000+i*1000]==0)
				{
					visited[test.a-d4*1000+i*1000]=1;
					num inter={test.a-d4*1000+i*1000,test.level+1};
					q.push(inter);
				}
			}
		}
		if(degree==-1)
			cout<<"Impossible"<<endl;
		else 
			cout<<degree<<endl;
		
	}
	return 0;
}

/*test case




7
1033 8179
1373 8017
1033 10331033 1035
1373 8017
1033 8179
1373 8017



*/