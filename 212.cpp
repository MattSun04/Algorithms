#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;


int cal( int b, int p, int m )  
{  
    if ( p == 0 ) 
		return 1;  
    if ( p == 1 ) 
		return b;  
    int a = cal( b, p/2, m );  
    if ( p%2>0 )  
        return (((a*a)%m)*b)%m;  
    else 
		return (a*a)%m;  
}  

int main()
{
	int b,p,m;
	while(cin>>b>>p>>m)
	{
		cout<<cal(b%m,p,m)<<endl;
	}
	return 0;
}