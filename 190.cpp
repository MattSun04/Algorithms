#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include <stack>


using namespace std;
stack<char> s;
char a[50]={0};
int main()
{
	int n;
	char c=' ';
	char backspace=8;
	scanf("%d",&n);
	int m=n;
	scanf("%c",&c);
	scanf("%c",&c);
	while(n>0)
	{
		n--;
		int count=0;
		int i=0;
		while(1)
		{
			scanf("%c",&c);
			a[count]=c;
			if(c=='\n')
				break;
			count++;
			scanf("%c",&c);
		}
		while(a[i]!='\n')
		{
			c=a[i];
			if(c>=48 && c<=57)
			{
				printf("%c",c);
			}
			else if((c<48||c>57)&&c!=40&&c!=41)
			{
				while(1)
				{
				
					if(s.empty()||((c=='*'||c=='/')&&(s.top()!='*'&&s.top()!='/'))||((c=='+'||c=='-')&&(s.top()=='(')))
					{
						s.push(c);
						break;
					}
					else
					{
						if(s.top()!='('&&s.top()!=')')
						{
						printf("%c",s.top());
						}
						s.pop();
					}
				}
			}
			else if(c==40)
			{
				s.push(c);
			}
			else if(c==41)
			{
				while(s.top()!='(')
				{
					printf("%c",s.top());
					s.pop();
				}
				s.pop();
			}
			i++;
		}
		while(!s.empty())
		{
			if(s.top()!='('&&s.top()!=')')
			{
				printf("%c",s.top());
			}
			s.pop();
		}
		
		printf("%c",'\n');
		if(n!=0){
			printf("%c",'\n');}	
	}
	return 0;
}
/*
1
(
3
+
2
)
*
5 */