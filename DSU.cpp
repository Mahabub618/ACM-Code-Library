#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5+5;
int par[N], sz[N];
int Root(int u)
{
    if(par[u] == u) return u;
    else
    {
        par[u] = Root(par[u]);
        return par[u];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=1; i<=n; i++) par[i] = i, sz[i] = 1;
    for(int i=1; i<=m; i++)
    {
        int u, v;
        cin >> u >> v;
        int ru = Root(u);
        int rv = Root(v);
        if(ru == rv) continue;
        else
        {
            if(sz[ru] > sz[rv])
            {
                par[rv] = ru;
                sz[ru] += sz[rv];
            }
            else
            {
                par[ru] = rv;
                sz[rv] += sz[ru];
            }
        }
    }
return 0;
}
