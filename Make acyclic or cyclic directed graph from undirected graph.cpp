const int N = 1e6+6;
vector<int>g[N];
int vis[N], depth[N];
vector<pair<int,int>> edges;
void dfs(int u, int p, int d)
{
    vis[u] = 1;
    depth[u] = d;
    for(auto v: g[u])
    {
        if(v == p) continue;
        if(vis[v] == 0)
        {
            dfs(v, u, d+1);
            edges.push_back({u, v});
        }
        else
        {
            if(depth[u] > depth[v])
            {
                edges.push_back({u, v}); /// For acyclic push({v, u})
            }
        }
    }
}
/// https://codeforces.com/contest/118/problem/E
