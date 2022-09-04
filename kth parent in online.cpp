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
#ifndef ONLINE_JUDGE
#define       debug(x) cout << #x << " = " << x << endl
#define       debug2(x, y)             cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define       debug3(x, y, z)          cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define       debug4(a, b, c, d)       cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#endif
void init_code()
{
    ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif    
}
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
    init_code();
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
        cout << ans << nl;
    }
     
return 0;
}
