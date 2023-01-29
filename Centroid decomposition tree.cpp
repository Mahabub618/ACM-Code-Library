/**********************/
/* Mahabub Rahman     */
/* Cse 10th           */
/* Comilla University */
/**********************/

#include<bits/stdc++.h>
using namespace std;
#define       ll                  long long int
#define       pb                   push_back
#define       nl                   "\n"
#define inf   1e18                                           //infinity value
///=============================================///
const int N = 2e5+5;
vector<int> adj[N]; 
ll lvl[N], p[N], del[N], a[N], st[N], en[N], up[N][20], Timer;
ll ans[N], sub[N], LOG;
    
void dfs(int x,int par=-1) {
    st[x] = ++Timer;
    up[x][0] = par;
    for(int i=1; i<=LOG; i++) {
        up[x][i] = up[up[x][i-1]][i-1];
    }
    for(auto to: adj[x]) {
        if(to == par)
            continue;
        lvl[to] = lvl[x]+1;
        dfs(to,x);
    }
    en[x] = ++Timer;
}
 
bool IsAncestor(int u, int v) {
    return st[u] <= st[v] && en[u] >= en[v];
}
 
ll Lca(ll x,ll y) {
    if (IsAncestor(x, y))
        return x;
    if (IsAncestor(y, x))
        return y;
    for (int i = LOG; i >= 0; --i) {
        if (!IsAncestor(up[x][i], y))
            x = up[x][i];
    }
    return up[x][0];
}
 
ll Dist(int x,int y) {
    return (lvl[x] + lvl[y] - (2*lvl[Lca(x,y)]));
}
 
void GetSubtree(int x,int par=-1) {
    sub[x] = 1;
    for(auto to:adj[x]) {
        if(to == par || del[to]) continue;
        GetSubtree(to,x);
        sub[x] += sub[to];
    }
}
 
int GetCentroid(int x,int Cnt) {
    for(auto to: adj[x]) {
        if(del[to]) continue;
        if(sub[to] >  Cnt/2) 
        {
            sub[x] -= sub[to];
            return GetCentroid(to, Cnt);
        }
    }
    return x;
}
 
void BuildCentroidTree(int x,int par=-1) {
    GetSubtree(x,par);
    ll Centroid = GetCentroid(x,sub[x]);
 
    p[Centroid] = par;
    del[Centroid] = true;
    for(auto to : adj[Centroid]) {
        if(del[to]) continue;
        BuildCentroidTree(to, Centroid);
    }
}
void update(int u) {
    ans[u] = 0;
    int to = u;
    while(to != -1)
    {
        ll d = Dist(to, u);
        ans[to] = min(ans[to], d);
        to = p[to];
    }
}
ll query(int u) {
    ll ret = 1e18;
    int to = u;
    while(to != -1)
    {
        ret = min(ret, ans[to]+Dist(u, to));
        to = p[to];
    }
    return ret;
}
int main() {
    int n, m;
    cin >> n >> m;
    LOG = ceil(log2(n));
    for(int i=1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=1; i<=n; i++) ans[i] = inf;
    lvl[1] = 0;
    Timer = 0;
    dfs(1, 1);
    BuildCentroidTree(1);
    update(1);
    while(m--)
    {
        int t, x;
        cin >> t >> x;
        if(t == 2) cout << query(x) << nl;
        else update(x);
    }
}
/// https://codeforces.com/contest/342/problem/E
