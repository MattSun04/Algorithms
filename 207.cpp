#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include<string>
#include <stack>
using namespace std;
/*WTF THE QUESTION*/
int arr[210][210];
int result[210];
int path[210];
int reverse_path[210];
bool visited[210];
char ** place=new char*[210];

struct Node{
    int v,x;
	Node(int d=0,int a= 0):
       v(d), x(a) {}
};
bool operator<( Node a, Node b ){
    return a.v>b.v;
}

void print_result(int n,int n2)
{
		if(n!=n2)
		{
			print_result(path[n],n2);
		}
		
			printf("%s -> ",place[n]);	
		
}
void print_revers(int n,int n2)
{
		if(n!=n2)
		{
			print_revers(reverse_path[n],n2);
		}
	
		
			printf("%s -> ",place[n]);	
}

int main()
{
	int n;
	int d;
	char c;
	priority_queue<Node> q;
	int flag=1;
	while(scanf("%d",&n)!=EOF)
	{
		
		memset(arr,0,44100*sizeof(int));
		memset(result,-1,210*sizeof(int));
		memset(visited,1,210*sizeof(bool));
		memset(path,-1,210*sizeof(int));
		memset(reverse_path,-1,210*sizeof(int));
		scanf("%c",&c);
		while( !q.empty() )
		{
			q.pop();
		}
		int initial,target;
		//place[0]="hello";
		//printf("%s",place[0]);
		int N=n;
		while(n>0)
		{
			int count=0;
			place[N-n] = (char*)malloc(sizeof(char) * 30);
			while(scanf("%c",&c))	
			{
				if(c=='\n')
					break;
				place[N-n][count]=c;
				count++;
			}
			place[N-n][count]='\0';
			n--;
		}	
		
		scanf("%d",&d);
		scanf("%c",&c);
		while(d>0)
		{
			d--;
			char *buf=(char*)malloc(sizeof(char) * 50);	
			char *s,*b,*f,*h;
			
			int a,a1;
			int count=0;
			while(scanf("%c",&c))	
			{
				if(c=='\n')
					break;
				buf[count]=c;
				count++;
			}
			buf[count]='\0';
			
			string st=buf;
			
			int i=0,start,end;
			while(buf[i])
			{
				if(buf[i]==':')
					start=i;
				i++;
			}

			char* temp=&buf[start+1];
			
			for(int j=0;j<N;j++)
			{
				a1=0;
				for(end=0;place[j][end];end++)
				{
					if(place[j][end]!=temp[end])
					{
						a1=-1;
						break;
					}
				}
				if(a1>=0)
				{
					a1=j;
					break;
				}
					
			}
			string s1=st.substr(start+1,end);
			if(s1=="office")
				initial=a1;
			else if(s1=="hall")
				target=a1;

			s=strtok(buf,":");
			for(int j=0;j<N;j++)
			{
				if(strcmp(s,place[j])==0)
				{
					a=j;
					break;
				}
			}
			string s2=s;
			if(s2=="office")
				initial=a;
			else if(s2=="hall")
				target=a;

			
			
			char* nec=&buf[start+end+1];
			f=strtok(nec," ");
			
			arr[a][a1]=atoi(f);
			if((h=strtok(NULL," "))!=NULL)
			{
				arr[a1][a]=atoi(h);
			}
			free(buf);
		}

		visited[initial]=0;
		for(int i=0;i<N;i++)
		{
			if(arr[initial][i]!=0)
			{
				q.push(Node(arr[initial][i],i));
				result[i]=arr[initial][i];
				path[i]=initial;
			}
		}
		int x=0;
		int cc=0;
		while(visited[target]!=0)
		{
			if(cc>=N)
				break;
			cc++;
			x=q.top().x;
			q.pop();
			visited[x]=0;
			for(int i=0;i<N;i++)
			{
				if(arr[x][i]!=0&&visited[i]!=0)  //x to i
				{
					if(result[i]==-1||result[i]>result[x]+arr[x][i])
					{	
						result[i]=result[x]+arr[x][i];
						q.push(Node(result[i],i));
						path[i]=x;
					}
				}
			}
		}
		int result1=result[target];
		
		
		memset(result,-1,210*sizeof(int));
		memset(visited,1,210*sizeof(bool));
		while( !q.empty() )
		{
			q.pop();
		}
		visited[target]=0;
		for(int i=0;i<N;i++)
		{
			if(arr[target][i]!=0)
			{
				q.push(Node(arr[target][i],i));
				result[i]=arr[target][i];
				reverse_path[i]=target;
			}
		}
		cc=0;
		while(visited[initial]!=0)
		{
			if(cc>=N)
				break;
			cc++;
			x=q.top().x;
			q.pop();
			visited[x]=0;
			for(int i=0;i<N;i++)
			{
				if(arr[x][i]!=0&&visited[i]!=0)
				{
					if(result[i]==-1||result[i]>result[x]+arr[x][i])
					{	result[i]=result[x]+arr[x][i];
						q.push(Node(result[i],i));
						reverse_path[i]=x;
					}
				}
			}
		}
		int cou=0;
	/*	stack<int> stack1;
		stack<int> stack2;
		cou=path[target];
		for(int i=0;i<N;i++)
		{
			stack1.push(cou);
			if(cou==initial)
				break;
			cou=path[cou];
		}
		cou=reverse_path[initial];
		for(int i=0;i<N;i++)
		{
			stack2.push(cou);
			if(cou==target)
				break;
			cou=reverse_path[cou];
		}
	*/	
		printf("%d\n",result[initial]+result1);
		print_result(path[target],initial);
		print_revers(reverse_path[initial],target);
		printf("%s\n\n",place[initial]);
		
	}
	return 0;
}
/*

3
office
hall
1234 5 32
3
office:hall 5 5
1234 5 32:office 1 2
1234 5 32:hall 2 2



*/