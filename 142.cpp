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

int arr[30001];


void setunion(int Root1, int Root2)  
{  
    //add the low height tree to the high height tree.  
    if(arr[Root2]<arr[Root1])  
    {  
		arr[Root2]+=arr[Root1];
		arr[Root1] = Root2;	
	}
    else  
    {  
        arr[Root1]+=arr[Root2];
		arr[Root2] = Root1;
    }  
}  


int find(int x)  
{  
    if(arr[x]<=0)  
        return x;  
    else  
        return find(arr[x]);  
}  



int main()
{
	int n;
	cin>>n;
	

	while(n)
	{
		memset(arr,-1,sizeof(arr));
		n--;
		int a,b;
		cin>>a>>b;
		while(b)
		{
			b--;
			int c,d;
			cin>>c>>d;
			int t1=find(c);
			int t2=find(d);
			if(t1!=t2){
				setunion(t1,t2);
			}		
		}

		int min=-1;
		while(a)
		{
			a--;
			if(arr[a]<min)
				min=arr[a];
		}

		printf("%d\n",min*(-1));
	}	

	return 0;
}