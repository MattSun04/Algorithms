//mattsun
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#define MAX 102
using namespace std;

int arr[MAX][MAX];
int sum[MAX][MAX];;
/* uva 108 maximum sum of a rectangular*/


int main()
{
    int n;
    int i,j;
    int maxSum=-100000;
	while(~scanf("%d",&n)){
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++) {
                scanf("%d",&arr[i][j]);
                sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i][j]; 
            }
        }
     
        for(int i=1; i<n+1; i++){
            for(int j=0; j<i; j++){
                int t;
                int min=0;
                for(int k=1; k<=n; k++){ 
                    t=sum[i][k]-sum[j][k]-min;
                    if(t>maxSum) maxSum=t;
                    if(sum[i][k]-sum[j][k] < min)
                        min=sum[i][k]-sum[j][k];
                }
            }
        }
		printf("%d\n",maxSum);
    }
   	return 0;
}


/* wrong part
int main()
{
	
	
    int size;
    scanf("%d",&size);

    int *array = (int*)malloc(size*size*sizeof(int));
    for(int i=0;i<size*size;i++)
    {
        scanf("%d",&array[i]);
       printf("array[%d]=%d\n",i,array[i]);
    }
	if(size<=0 || size>100)
	{
		return 0;
	}

	int max=array[0];
    int part_sum=0;
	for(int s=1;s<size+1;s++) //size for rows
	{
		for(int j=0;j+s<size+1;j++)   //initial rows
		{
			int sum=0;
			for(int k=0;k<size;k++)   //initial column
			{
				int part_sum=0;
				for(int n=0;n<s;n++)
				{
					part_sum=part_sum+array[k+(j+n)*size];
				}
				if(part_sum<0)
				{
					if(sum>max)
						max=sum;
					sum=0;
				}
				else if(k==size-1)
				{
					sum=sum+part_sum;
					if(sum>max)
						max=sum;
					sum=0;
				}
				else 
					sum+=part_sum;
			}
		}
	}
	free(array);
	printf("%d",max);
	return max;
}
*/