#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <stdlib.h>  

using namespace std;


char a[51][51];

int main()
{
	char c;
	bool flag=0;
	int row=0;
	int column=0;
	int N=0;
	memset(a,0,sizeof(a));
	while(scanf("%c",&c)!=EOF)
	{
		if(c=='.')
		{	
			a[row][column]='.';
			flag=0;
		}
		else if(c=='#')
		{	
			a[row][column]='#';
			flag=0;
		}
		
		column++;
	
		if(c=='\n')
		{
			if(flag==0)
			{	
				flag=1;
				row++;
				N=column-1;
				column=0;
			}
			else 
			{	
				flag=0;
				int count=0;
				
				for(int i=0;i<row;i++)
				{
					for(int j=0;j<N+1;j++)
					{
						if(a[i][j]=='#'){
							if(i>0&&a[i-1][j]=='.')
								count++;
							if(i<row-1&&a[i+1][j]=='.')
								count++;
							if(j<N&&a[i][j+1]=='.')
								count++;
							if(j>0&&a[i][j-1]=='.')
								count++;
							if(i%2==0)
							{
								if(i>0&&j>0&&a[i-1][j-1]=='.')
								count++;
								if(i<row-1&&j>0&&a[i+1][j-1]=='.')
								count++;
							}
							else 
							{
								if(i>0&&j<N&&a[i-1][j+1]=='.')
								count++;
								if(i<row-1&&j<N&&a[i+1][j+1]=='.')
								count++;
						
							}
						}
					}				
				}
				N=0;
				printf("%d\n",count);
				memset(a,0,sizeof(a));
				row=0;
				column=0;
				continue;
			}
		}
		
	
	}
	return 0;

}
/*
.#...#..

..#.##
.##.#.
#.#...

#...#.....
##..#...#.

....#.
.#....
..#..#
####..



*/