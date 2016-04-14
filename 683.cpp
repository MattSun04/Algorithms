#include<string.h>
#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int a,b,c,d;
	while(cin>>a>>b>>c>>d)
	{
		int remain_d=c;
		int remain_n=b;
		int count=0;
		a=a-1;
		while(remain_n>0)
		{
			if(remain_d>=a)
			{
				remain_n=remain_n-(a+1)*d;
				remain_d=remain_d-a;
			}
			else if(remain_d>0&&remain_d<a)
			{
				remain_n=remain_n-(remain_d+1)*d;
				remain_d=0;
			}
			else 
				remain_n=remain_n-d;
			count++;
		}
		cout<<count<<endl;
	}

	return 0;
}