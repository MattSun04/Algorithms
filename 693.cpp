#include<string.h>
#include<stdio.h>
#include<iostream>

using namespace std;

int calculation(int n)
{
	if(n==1)
		return 2;
	return 3*calculation(n-1)+2;
}

int main()
{
	int a;
	while(cin>>a)
	{
		cout<<calculation(a)<<endl;

	}
	return 0;
}