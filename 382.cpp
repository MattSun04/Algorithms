#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <queue>  
#include <algorithm>  
using namespace std;  
  
int INF = 1000000;  
  
int resi[202];    //residual and visited
int c[202][202], f[202][202];   //   capacity flow
int p[202];      //path

int calculate(int op, int ed, int n)  
{  
     int total_flow = 0; 
	queue<int> q;  
    memset(f, 0, sizeof(f));  
    memset(p, 0, sizeof(p));  
   
  
    //bfs
    while (1) 
	{  
        memset(resi, 0, sizeof(resi));  
        q.push(op);  
        resi[op] = INF;   
        while (!q.empty())
		{  
            int u = q.front();  
            q.pop();  
            for (int v = 0; v < n; v++)   
            {
				if (resi[v]==0 && c[u][v] > f[u][v])
				{  
                    p[v] = u;  
                    q.push(v);  
                    resi[v] = min(resi[u], c[u][v] - f[u][v]);  
                }
			}
        }  
  
        if (resi[ed] == 0) 
			return total_flow;  
  
        // update  
        for (int u = ed; u != op; u = p[u]) 
		{  
            f[u][p[u]] -= resi[ed];  
            f[p[u]][u] += resi[ed];  
        }  
		total_flow += resi[ed];  
    }  
}  
  
int main() {  
    int n,en, b, d, u, v, cast;  
    while (cin>>n) {  
        memset(c, 0, sizeof(c));  
        for (int i = 1; i <= n; i++)  
			scanf("%d", &c[i][i + n]);  
  
        cin>>en;
        while (en--) 
		{  
            cin>>u>>v>>cast;
            c[u + n][v] = cast;  
        }  
  
       
        cin>>b>>d;
        while (b--) 
		{  
            cin>>u; 
            c[0][u] = INF;  
        }  
        while (d--) 
		{  
            cin>>u;  
            c[u + n][2 * n + 1] = INF;  
        }  
  
        printf("%d\n", calculate(0, 2 * n + 1, 2 * n + 2));  
    }  
  
    return 0;  
}  