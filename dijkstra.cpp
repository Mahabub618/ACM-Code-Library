#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+100;
vector<pair<int, int> > g[N];
int dis[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        int u, v, w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    priority_queue<pair<int, int> > pq;

    for(int i=1; i<=n; i++) dis[i] = 1e9+9;

    int src = 1;//One-indexed base.
    dis[src] = 0;
    pq.push({-dis[src], src});

    while(pq.size()>0)
    {
        auto t = pq.top();
        pq.pop();

        int u = t.second, d = -t.first;

        if(dis[u]<d) continue;
        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i].first, w = g[u][i].second;

            if(dis[v]>dis[u]+w)
            {
                dis[v] = dis[u]+w;
                pq.push({-dis[v], v});
            }
        }
    }
    return 0;
}
