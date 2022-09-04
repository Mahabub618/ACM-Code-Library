const int N = 1e5+5;
vector<pii> ans;
vector<int> path, offline_query[N], g[N];
void dfs(int u, int p)
{
    path.pb(u);
    for(auto k: offline_query[u])
    {
        int n = path.size();
        ans.pb({u, path[n-k-1]});
    }
    for(auto v: g[u])
    {
        if(v != p) dfs(v, u);
    }
    path.pop_back();
}
