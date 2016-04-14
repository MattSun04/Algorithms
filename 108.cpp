#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

char* name[101]={0};
int y[100]={0};
int m[100]={0};
int d[100]={0};
int compare(int a, int b)
{
	if(y[a]>y[b])
		return 1;
	else if(y[a]<y[b])
		return 0;
	else 
		if(m[a]>m[b])
			return 1;
		else if(m[a]<m[b])
			return 0;
		else 
			if(d[a]>d[b])
				return 1;
			else if(d[a]<d[b])
				return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		*(name+i)=(char*)malloc(16*sizeof(char));
	}

	for(int i=0;i<n;i++)
	{
		scanf("%s",name[i]);
		scanf("%d",&d[i]);
		scanf("%d",&m[i]);
		scanf("%d",&y[i]);
	}
	int max=0;
	int min=0;
	for(int i=0;i<n;i++)
	{
		if(compare(i,max))
			max=i;
		if(compare(min,i))
			min=i;
	}

	printf("%s\n",*(name+max));
	printf("%s\n",*(name+min));

	return 0;
}