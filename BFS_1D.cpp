#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
int vis[N], dis[N];
vector<int> g[N];

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = 1;

    dis[source] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v=0; v<g[u].size(); v++)
        {
            if(!vis[g[u][v]])
            {
                vis[g[u][v]] = 1;
                dis[g[u][v]] += 1;
                q.push(g[u][v]);
            }
        }
    }
}
