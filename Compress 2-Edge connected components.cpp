/**********************/
/* Mahabub Rahman     */
/* Cse 10th           */
/* Comilla University */
/**********************/

#include<bits/stdc++.h>
using namespace std;
#define       ll                  long long int
#define       veci                 vector<int>
#define       vecl                 vector<long long int>
#define       pb                   push_back
#define       newline cerr << endl
#define       pii                  pair<int, int>
#define       F                    first
#define       S                    second
#define       nl                   "\n"
#define       all(v)               v.begin(), v.end()
///============ CONSTANT ===============///
#define mx9   1000000007
#define mx5   200005
#define inf   1<<30                                           //infinity value
#define eps   1e-9
#define mod   mx9
///=============== Debugging ============================///
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
///=============================================///
void init_code()
{
    ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif    
}

const int N = 1e6 + 100;

vector<pii> g[N];
bool vis[N];
int depth[N], low[N], is_bridge[N], col[N], timer;
int n, m;
void dfs(int u, int p) {
    vis[u] = 1;
    low[u] = depth[u] = timer++;
    for(auto vv: g[u])
    {
        int v = vv.F, id = vv.S;
        if(v == p) continue;
        if(vis[v]) low[u] = min(low[u], depth[v]);
        else
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > depth[u]) is_bridge[id] = 1;
        }
    }
}
void assign_color(int u, int c)
{
    col[u] = c;
    for(auto vv: g[u])
    {
        int to = vv.F, id = vv.S;
        if(is_bridge[id]) continue;
        if(col[to] != -1) continue;
        assign_color(to, c);
    }
}
vector<veci> bridge;
vector<pii> edges;
void build_tree()
{
    int c = 1;
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
        int u = col[edges[i].F] , v = col[edges[i].S];
        if(is_bridge[i] and u != v)
        {
            //debug(u, v);
            bridge[u].pb(v);
            bridge[v].pb(u);
        }
    }
    
}
int dis[N], st, en, mx;
void dfs2(int u, int p, int d, int bit)
{
    vis[u] = 1;
    dis[u] = d;
    if(mx < dis[u])
    {
        mx = dis[u];
        bit == 1 ? st = u : en = u;
    }
    for(auto v: bridge[u])
    {
        if(v == p) continue;
        dfs2(v, u, d+1, bit);
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
    memset(vis, false, sizeof vis);
    mx = 0;
    dfs2(1, -1, 0, 0);
    memset(vis, false, sizeof vis);
    memset(dis, 0, sizeof dis);
    mx = 0;
    dfs2(en, -1, 0, 1);
    cout << mx << nl;

    return 0;
}
/// https://codeforces.com/contest/1000/problem/E
