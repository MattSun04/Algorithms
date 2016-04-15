# define PI  3.14159265358979323846 
#include <stdio.h>
#include <iostream>
#include <queue>
#include <math.h>
#include <string.h>
using namespace std;

struct point
{
	int centerx;
	int centery;
	int radius;
};
point d[200];



void calculate()
{



}

int main()
{
	int n;
	
	while (cin >> n)
	{
		memset(d, 0, sizeof(d));
		if (n == 0)
			break;
		int count = 0;
		while (n > 0)
		{
			int a, b,c;
			cin >> a >> b>>c;
			point p = { a, b, c };
			d[count] = p;
			count++;
			n--;
		}
	
		double pre_sum=0;
		int c = 0;
		while (c<1440)
		{
			double angel = c*0.25*PI/180;
			double x = 500*cos(angel);
			double y = 500*sin(angel);
			double sum = 0;
			for (int i = 0; i < count; i++)
			{
				double s = 500;
				double b = fabs(-y*d[i].centerx + x*d[i].centery);
				double distance = b / s;
				if (distance < d[i].radius&&d[i].centerx*x+d[i].centery*y>0)
				{
					sum += 2 * sqrt(d[i].radius*d[i].radius - distance*distance);
				}
			}
			if (sum > pre_sum)
				pre_sum = sum;
			c++;
		}
		printf("%.3lf\n", pre_sum);
		
	}


	return 0;
}