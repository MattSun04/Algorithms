#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

bool visited[25][25][25][25];
struct cup
{
	int a;
	int b;
	int c;
	int d;
	int level;
};
queue<cup> q;

int main()
{
	int degree;
	struct cup capacity;
	int target;
	
	while(scanf("%d%d%d%d%d",&capacity.a,&capacity.b,&capacity.c,&capacity.d,&target)!=EOF)
	{
	//cin>>capacity.a>>capacity.b>>capacity.c>>capacity.d>>target;
	while(!q.empty())
		q.pop();
	
	bool found=false;
	memset(visited,0,sizeof(visited));
	visited[0][0][0][0]=1;
	cup i={0,0,0,0,0};
	q.push(i);
	degree=-1;
	while(!q.empty())
	{
		cup test=q.front();
		q.pop();
		if(!visited[0][test.b][test.c][test.d])
		{
			cup changed={0,test.b,test.c,test.d,test.level+1};
			q.push(changed);
			if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
			{		degree=changed.level; break;}
			visited[changed.a][changed.b][changed.c][changed.d]=1;
		}
		if(!visited[capacity.a][test.b][test.c][test.d])
		{
			cup changed={capacity.a,test.b,test.c,test.d,test.level+1};
			q.push(changed);
			if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
			{		degree=changed.level; break;}
			visited[changed.a][changed.b][changed.c][changed.d]=1;
		}

		if(!visited[test.a][0][test.c][test.d])
		{
			cup changed={test.a,0,test.c,test.d,test.level+1};
			q.push(changed);
			if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
			{		degree=changed.level; break;}
			visited[changed.a][changed.b][changed.c][changed.d]=1;
		}
		if(!visited[test.a][capacity.b][test.c][test.d])
		{
			cup changed={test.a,capacity.b,test.c,test.d,test.level+1};
			q.push(changed);
			if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
			{		degree=changed.level; break;}
			visited[changed.a][changed.b][changed.c][changed.d]=1;
		}

		if(!visited[test.a][test.b][0][test.d])
		{
			cup changed={test.a,test.b,0,test.d,test.level+1};
			q.push(changed);
			if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
			{		degree=changed.level; break;}
			visited[changed.a][changed.b][changed.c][changed.d]=1;
		}

		if(!visited[test.a][test.b][capacity.c][test.d])
		{
			cup changed={test.a,test.b,capacity.c,test.d,test.level+1};
			q.push(changed);
			if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
			{		degree=changed.level; break;}
			visited[changed.a][changed.b][changed.c][changed.d]=1;
		}
		if(!visited[test.a][test.b][test.c][0])
		{
			cup changed={test.a,test.b,test.c,0,test.level+1};
			q.push(changed);
			if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
			{		degree=changed.level; break;}
			visited[changed.a][changed.b][changed.c][changed.d]=1;
		}


		if(!visited[test.a][test.b][test.c][capacity.d])
		{
			cup changed={test.a,test.b,test.c,capacity.d,test.level+1};
			q.push(changed);
			if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
			{		degree=changed.level; break;}
			visited[changed.a][changed.b][changed.c][changed.d]=1;
		}
		/////////////*************************************************************************************/
		if(test.a<capacity.a)
		{
			if(test.b>0)
			{
				if(test.a+test.b>=capacity.a)
				{
					if(!visited[capacity.a][test.b-capacity.a+test.a][test.c][test.d])
					{
						cup changed={capacity.a,test.b-capacity.a+test.a,test.c,test.d,test.level+1};
						q.push(changed);
						if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
						{		degree=changed.level; break;}
						visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
				else
				{
					if(!visited[test.a+test.b][0][test.c][test.d])
					{
					cup changed={test.a+test.b,0,test.c,test.d,test.level+1};
					q.push(changed);
					if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
					{		degree=changed.level; break;}
					visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
			}
			if(test.c>0)
			{
				if(test.a+test.c>=capacity.a)
				{
					if(!visited[capacity.a][test.b][test.c-capacity.a+test.a][test.d])
					{
						cup changed={capacity.a,test.b,test.c-capacity.a+test.a,test.d,test.level+1};
						q.push(changed);
						if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
						{		degree=changed.level; break;}
						visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
				else
				{
					if(!visited[test.a+test.c][test.b][0][test.d])
					{
					cup changed={test.a+test.c,test.b,0,test.d,test.level+1};
					q.push(changed);
					if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
					{		degree=changed.level; break;}
					visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
			}
			if(test.d>0)
			{
				if(test.a+test.d>=capacity.a)
				{
					if(!visited[capacity.a][test.b][test.c][test.d-capacity.a+test.a])
					{
					cup changed={capacity.a,test.b,test.c,test.d-capacity.a+test.a,test.level+1};
					q.push(changed);
					if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
					{		degree=changed.level; break;}
					visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
				else
				{
					if(!visited[test.a+test.d][test.b][test.c][0])
					{
					cup changed={test.a+test.d,test.b,test.c,0,test.level+1};
					q.push(changed);
					if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
						{		degree=changed.level; break;}
					visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
			}

		}


		// pour into b
		if(test.b<capacity.b)
		{
			

			if(test.a>0)
			{
				if(test.a+test.b>=capacity.b)
				{
					if(!visited[test.a-capacity.b+test.b][capacity.b][test.c][test.d])
					{
						cup changed={test.a-capacity.b+test.b,capacity.b,test.c,test.d,test.level+1};
						q.push(changed);
						if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
						{		degree=changed.level; break;}
						visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
				else
				{
					if(!visited[0][test.a+test.b][test.c][test.d])
					{
					cup changed={0,test.a+test.b,test.c,test.d,test.level+1};
					q.push(changed);
					if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
					{		degree=changed.level; break;}
					visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
			}
			if(test.c>0)
			{
				if(test.b+test.c>=capacity.b)
				{
					if(!visited[test.a][capacity.b][test.c-capacity.b+test.b][test.d])
					{
						cup changed={test.a,capacity.b,test.c-capacity.b+test.b,test.d,test.level+1};
						q.push(changed);
						if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
						{		degree=changed.level; break;}
						visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
				else
				{
					if(!visited[test.a][test.b+test.c][0][test.d])
					{
					cup changed={test.a,test.b+test.c,0,test.d,test.level+1};
					q.push(changed);
					if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
					{		degree=changed.level; break;}
					visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
			}
			if(test.d>0)
			{
				if(test.b+test.d>=capacity.b)
				{
					if(!visited[test.a][capacity.b][test.c][test.d-capacity.b+test.b])
					{
					cup changed={test.a,capacity.b,test.c,test.d-capacity.b+test.b,test.level+1};
					q.push(changed);
					if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
					{		degree=changed.level; break;}
					visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
				else
				{
					if(!visited[test.a][test.b+test.d][test.c][0])
					{
					cup changed={test.a,test.b+test.d,test.c,0,test.level+1};
					q.push(changed);
					if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
						{		degree=changed.level; break;}
					visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
			}


		}
		//*******************************************************************
		if(test.c<capacity.c)
		{
			
			if(test.a>0)
			{
				if(test.a+test.c>=capacity.c)
				{
					if(!visited[test.a-capacity.c+test.c][test.b][capacity.c][test.d])
					{
						cup changed={test.a-capacity.c+test.c,test.b,capacity.c,test.d,test.level+1};
						q.push(changed);
						if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
						{		degree=changed.level; break;}
						visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
				else
				{
					if(!visited[0][test.b][test.c+test.a][test.d])
					{
					cup changed={0,test.b,test.c+test.a,test.d,test.level+1};
					q.push(changed);
					if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
					{		degree=changed.level; break;}
					visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
			}
			if(test.b>0)
			{
				if(test.b+test.c>=capacity.c)
				{
					if(!visited[test.a][test.b-capacity.c+test.c][capacity.c][test.d])
					{
						cup changed={test.a,test.b-capacity.c+test.c,capacity.c,test.d,test.level+1};
						q.push(changed);
						if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
						{		degree=changed.level; break;}
						visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
				else
				{
					if(!visited[test.a][0][test.b+test.c][test.d])
					{
					cup changed={test.a,0,test.b+test.c,test.d,test.level+1};
					q.push(changed);
					if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
					{		degree=changed.level; break;}
					visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
			}
			if(test.d>0)
			{
				if(test.c+test.d>=capacity.c)
				{
					if(!visited[test.a][test.b][capacity.c][test.d-capacity.c+test.c])
					{
					cup changed={test.a,test.b,capacity.c,test.d-capacity.c+test.c,test.level+1};
					q.push(changed);
					if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
					{		degree=changed.level; break;}
					visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
				else
				{
					if(!visited[test.a][test.b][test.c+test.d][0])
					{
					cup changed={test.a,test.b,test.c+test.d,0,test.level+1};
					q.push(changed);
					if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
						{		degree=changed.level; break;}
					visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
			}

		}



		//*************************************
		if(test.d<capacity.d)
		{
			
			if(test.a>0)
			{
				if(test.a+test.d>=capacity.d)
				{
					if(!visited[test.a-capacity.d+test.d][test.b][test.c][capacity.d])
					{
						cup changed={test.a-capacity.d+test.d,test.b,test.c,capacity.d,test.level+1};
						q.push(changed);
						if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
						{		degree=changed.level; break;}
						visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
				else
				{
					if(!visited[0][test.b][test.c][test.d+test.a])
					{
					cup changed={0,test.b,test.c,test.d+test.a,test.level+1};
					q.push(changed);
					if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
					{		degree=changed.level; break;}
					visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
			}
			if(test.b>0)
			{
				if(test.b+test.d>=capacity.d)
				{
					if(!visited[test.a][test.b-capacity.d+test.d][test.c][capacity.d])
					{
						cup changed={test.a,test.b-capacity.d+test.d,test.c,capacity.d,test.level+1};
						q.push(changed);
						if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
						{		degree=changed.level; break;}
						visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
				else
				{
					if(!visited[test.a][0][test.c][test.b+test.d])
					{
					cup changed={test.a,0,test.c,test.b+test.d,test.level+1};
					q.push(changed);
					if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
					{		degree=changed.level; break;}
					visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
			}
			if(test.c>0)
			{
				if(test.c+test.d>=capacity.d)
				{
					if(!visited[test.a][test.b][test.c-capacity.d+test.d][capacity.d])
					{
					cup changed={test.a,test.b,test.c-capacity.d+test.d,capacity.d,test.level+1};
					q.push(changed);
					if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
					{		degree=changed.level; break;}
					visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
				else
				{
					if(!visited[test.a][test.b][0][test.c+test.d])
					{
					cup changed={test.a,test.b,0,test.c+test.d,test.level+1};
					q.push(changed);
					if(changed.a==target || changed.b==target || changed.c==target ||changed.d==target)
						{		degree=changed.level; break;}
					visited[changed.a][changed.b][changed.c][changed.d]=1;
					}
				}
			}	
		}	
	}
	
	cout<<degree<<endl;
	
	}
	return degree;
}