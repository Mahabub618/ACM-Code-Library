const int N = 1e6 + 100;
int n, m;
vector<pii> g[N];
bool vis[N];
int depth[N], low[N], par[N], isbridge[N], col[N], timer;
vector<pii> edges;
void dfs(int u, int p)
{
    vis[u] = 1;
    depth[u] = low[u] = timer++;
    for(auto v: g[u])
    {
        int to = v.F, id = v.S;
        if(to == p) continue;
        if(vis[to]) low[u] = min(low[u], depth[to]);
        else
        {
            dfs(to, u);
            low[u] = min(low[u], low[to]);
            if(low[to] > depth[u]) isbridge[id] = 1;
        }
    }
}
void assign_color(int u, int c)
{
    col[u] = c;
    for(auto v: g[u])
    {
        int to = v.F, id = v.S;
        if(isbridge[id]) continue;
        if(col[to] != -1) continue;
        assign_color(to, c);
    }
}
vector<veci> bridge;
void build_tree()
{
    int c = 0;
    memset(col, -1, sizeof col);
    for(int i=1; i<=n; i++)
    {
        if(col[i] == -1)
        {
            assign_color(i, c);
            c++;
        }
    }
    bridge.clear(); bridge.resize(c+5);
    for(int i=0; i<m; i++)
    {
        int u = col[edges[i].F], v = col[edges[i].S];
        if(isbridge[i] and u != v)
        {
            bridge[u].pb(v);
            bridge[v].pb(u);
        }
    }
}

int main() {

    init_code();
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
        edges.pb({u, v});
    }
    timer = 0;
    dfs(1, -1);
    build_tree();
    if(bridge.size() <= 2) cout << "YES\n";
    else
    {
        bool ok = true;
        for(int i=0; i<bridge.size(); i++)
        {
            if(bridge[i].size() > 2) ok = false;
        }
        ok == true ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}
