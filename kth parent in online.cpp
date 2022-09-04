/**********************/
/* Mahabub Rahman     */
/* Cse 10th           */
/* Comilla University */
/**********************/

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5+5;
int par[N][20];
vector<int> g[N];
void dfs(int u, int p)
{
    par[u][0] = p;
    for(auto v: g[u])
    {
        if(v!=p) dfs(v, u);
    }
}
int kth_parent(int u, int k)
{
    for(int b=20; b>=0; b--)
    {
        if((k>>b)&1) u = par[u][b];
    }
    return u;
}
int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, -1);
    for(int k=1; k<20; k++)
    {
        for(int u=1; u<=n; u++) // 1-based
        {
            if(par[u][k-1] == -1) par[u][k] = -1; // if the parent of a current node is -1
                                                  // obviously the parent of parent node will be -1
            else par[u][k] = par[par[u][k-1]][k-1];
        }
    }
    
    int q;
    cin >> q;

    while(q--)
    {
        int node, k; // kth parent of node
        cin >> node >> k;
        int ans = kth_parent(node, k);
        cout << ans << '\n';
    }
     
return 0;
}
