#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
	int n;
	string a;
	scanf("%d",&n);
	int v_num;

	while(n>0)
	{
		n--;
		v_num=0;
		int steps=0;
		int position=0;
		cin>>a;
		int length=0;
		length = a.length();
		
		int i=length;
		int j,k;   
		int max=0;
		int pre=0,pri=length-1;
		for(int h=0;h<length;h++)
		{
			if(a[h]=='A')
			{
				v_num++;
			}
		}
		for(j=0;j<i;j++)
		{
			if(a[j]=='A')
			{
				for(k=j;k<i;k++)
				{
					if(a[k]!='A')
						break;
				}
				if(max<k-j)
				{	
					max=k-j;
					pre=j;
					pri=k-1;
				}
				j=k;
			}
			
		}
		int temp=0;
		for(int m=0;m<i;m++)
		{
				if(a[m]!='A')
				{
					
					if(a[m]<='N')
						temp+=a[m]-'A';
					else
						temp+='Z'-a[m]+1;
				}
		}

		if(length==1)
		{
			steps=temp;
		}
		else if(length==1)
		{
			steps=temp+1;
		}
		else if(temp==0)
		{	
			steps=0;
		}
		else if((pre>max/2&&(length-pri)%length>max/2)||(pre-1<0||pri+1>length))
		{
			int start,end;
			
			for(start=1;start<i;start++)
			{
				if(a[start]!='A')
					break;
			}
			for(end=length-1;end>=0;end--)
			{
				if(a[end]!='A')
					break;
			}
			if(start>=length-end)
			{
				temp+=length-start;
			}
			else
				temp+=end;
			steps+=temp;
		}
		else if(pre<(length-pri)%length&&pre<=max/2)		
		{
			steps+=(pre-1)*2+length-pri-1+temp;
		}

		else if((length-pri)%length<pre&&(length-pri)%length<=max/2)
		{
			steps+=pre-1+2*(length-pri-1)+temp;
		}
		
		
		printf("%d\n",steps);
	}



	return 0;
}