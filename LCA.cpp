#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5+5;
int depth[N], par[N][20];
vector<int> g[N];
int kth_parent(int u, int k)
{
    for(int b = 20; b>=0; b--)
    {
        if((k >> b) & 1) u = par[u][b];
    }
    return u;
}
int LCA(int u, int v)
{
    if(depth[u] < depth[v]) swap(u, v);
    int dif = depth[u]-depth[v];
    u = kth_parent(u, dif);
    if(u == v) return v;
    else
    {
        for(int k=20; k>=0; k--)
        {
            if(par[u][k] != par[v][k] and par[u][k] != -1)
            {
                u = par[u][k];
                v = par[v][k];
            }
        }
        return par[v][0];
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i=1; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int q;
    cin >> q;
    
    while(q--)
    {
        int u, v;
        cin >> u >> v;
        int lca = LCA(u, v);
        cout << lca << '\n';
    }
     
return 0;
}
