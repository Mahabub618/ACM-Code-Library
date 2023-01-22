const int N = 2e5+5;
vector<int> g[N];
int depth[N], low[N], vis[N], is_cut[N];
int n, timer;
void is_ArticulationPoint(int node)
{
    is_cut[node] = 1;
}
void dfs(int u, int p)
{
    vis[u] = 1;
    depth[u] = low[u] = timer++;
    int children = 0;
    for(auto v: g[u])
    {
        if(v == p) continue;
        if(vis[v]) low[u] = min(low[u], depth[v]);
        else
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= depth[u] and p != -1)
            {
                is_ArticulationPoint(u);
            }
            ++children;
        }
    }
    if(p == -1 and children > 1)
    {
        is_ArticulationPoint(u);
    }  
}
void find_cutpoints()
{
    timer = 0;
    for(int i=1; i<=n; i++) // 1-indexed based
    {
        vis[i] = is_cut[i] = 0;
        depth[i] = low[i] = -1;
        g[i].clear(); // Declared it into the main function, before inputting graph
    }
    for(int i=1; i<=n; i++)
    {
        if(!vis[i]) dfs(i, -1);
    }
}
/// O(V+E)
///https://www.spoj.com/problems/SUBMERGE/
