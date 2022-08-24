#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100;

vector<int> g[N];
bool vis[N];
int depth[N], low[N], par[N], isbridge[N];

bool notproceed(int x , int y)
{
    if( isbridge[ x ] && par[ x ] == y ) return 1 ;
    if( isbridge[ y ] && par[ y ] == x ) return 1 ;
    return 0 ;
}
void dfs(int u, int p, int d) {
    vis[u] = true;
    low[u] = depth[u] = d;
    for(int v : g[u]) {
        if(v == p) continue;
        if(vis[v] == 0) {
            par[v] = u;
            dfs(v, u, d+1);
            low[u] = min(low[u], low[v]);
            if(low[v] > depth[u])
            {
                isbridge[v] = 1;
                //cout << u << "..." << v << endl; //This is a bridge
            }
        }
        else low[u] = min(low[u], depth[v]);
    }
}

int main() {
    int t;
    cin >> t;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0; i<n; i++)
    {
        if(!vis[i]) dfs(i, -1, 0);
    }
    
    for(int i=0; i<n; i++)
    {
        for(auto v: g[i])
        {
            int u = i;
            if(notproceed(u, v))
            {
                //cout << u << "..." << v << endl; // (u, v) is a bridge
            }
        }
    }

    return 0;
}
