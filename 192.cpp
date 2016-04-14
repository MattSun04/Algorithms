

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

struct mobile
{
	int lw;
	int ld;
	int rw;
	int rd;
};
stack<mobile> s;

int judge(mobile m1)
{
	while(!s.empty())
	{
		if(s.top().lw==0)
		{	
			s.top().lw=m1.lw+m1.rw;				
		}
		else if(s.top().rw==0)
		{
			s.top().rw=m1.lw+m1.rw;
		}
		if(s.top().lw!=0&&s.top().rw!=0)
		{
			if(s.top().lw*s.top().ld==s.top().rw*s.top().rd)
			{	
				mobile m2=s.top();
				s.pop();
				judge(m2);
				return 1;
			}
			else 
				return 1;
		}
		else 
			return 1;
	}
	return 1;
}


int main()
{
	mobile m1={0,0,0,0};
	mobile m2={0,0,0,0};
	int n;
	bool v=1;
	char c=' ';
	char *d=new char[15];
	scanf("%d",&n);
	scanf("%c",&c);
	string st;
	getline(cin,st);
	while(n>0)
	{
		v=1;
		n--;
		memset(d,0,15*sizeof(char));
		
		int count=0;
		while(!s.empty())
		{
			s.pop();
		}
		while(getline(cin,st))
		{
			if(st=="")
				break;
			char *temp=&st[0];
			
			
				m1.lw=atoi(strtok(temp," "));	
				m1.ld=atoi(strtok(NULL," "));
				m1.rw=atoi(strtok(NULL," "));
				m1.rd=atoi(strtok(NULL," "));
			
		
				if(m1.lw==0 || m1.rw==0)
						s.push(m1);
				else if(m1.ld==0||m1.rd==0)
					v=0;
				else if(m1.lw*m1.ld!=m1.rw*m1.rd) 
				{
					v=0;
				}
				else
				{
					if(judge(m1)==0)
					{
						v=0;
					}
				}		
			
		}
			
			    count=0;
				
				if(s.empty()&&v==1)
				{
					if(n==0)
							printf("YES\n");
					else
							printf("YES\n\n");
					
				}
				else
				{	
					if(n==0)
							printf("NO\n");
					else
							printf("NO\n\n");
					
				}
				
			
			
	}
	

	return 0;
}
/*


5

0 2 0 4
0 3 0 1
1 1 1 1
2 4 4 2
1 6 3 2 

2 3 3 2
3 3 3 3
4 4 4 4
5 5 5 5

0 0 0 0

0 2 0 2
0 3 0 4
0 3 2 3
1 1 1 1
1 4 2 2
0 4 0 3
1 6 2 3
2 2 2 2

0 2 0 2
0 3 0 4
0 3 0 3
1 1 1 1
1 1 1 1
1 4 0 2
1 1 1 1
0 4 0 3
0 3 1 6
1 1 1 1
0 2 2 2
1 1 1 1

*/