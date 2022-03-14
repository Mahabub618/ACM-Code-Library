//Floyd-Warshall algorithm
//Time-Complexity: O(V^3)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_N 305
#define INF 1e18
int n, m;

ll dist[MAX_N][MAX_N];
ll flojd[MAX_N][MAX_N];


inline void FloydWarshall()
{
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            flojd[i][j] = (dist[i][j] > 0 ? dist[i][j] : INF);
        }
        //flojd[i][i] = 0;
    }
    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (flojd[i][k] + flojd[k][j] < flojd[i][j])
                {
                    flojd[i][j] = flojd[i][k] + flojd[k][j];
                }
            }
        }
    }
}

int main()
{
    int u, v, w;
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> u >> v >> w;
        dist[u][v] = w;
        dist[v][u] = w; //If the graph is undirected
    }
    FloydWarshall();
    printf("%d\n",flojd[1][n]);
    return 0;
}
