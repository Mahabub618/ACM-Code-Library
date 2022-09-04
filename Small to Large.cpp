#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5+5;
set<int> s[N];
int buck[N], a[N], score[N];
vector<int> g[N];
void dfs(int u, int p)
{
    buck[u] = u;
    for(auto v: g[u])
    {
        if(v != p) dfs(v, u);
    }
    s[buck[u]].insert(a[u]);
    for(auto v: g[u])
    {
        if(v != p)
        {
            if(s[buck[u]].size() < s[buck[v]].size()) swap(buck[u], buck[v]);
        }
        for(auto x: s[buck[v]]) s[buck[u]].insert(x);
    }
    score[u] = s[buck[u]].size();
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, -1);
    for(int i=1; i<=n; i++)
    {
        cout << "Number of distinct value in " << i << " th node: " << score[i] << '\n';
    }

return 0;
}
// Number of distinct value in a subtree
