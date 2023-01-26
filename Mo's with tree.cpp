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
const int N = 4e5+5, M = 20;
int n, m, depth[N], par[N][M], ID[N], vis[N], val[N], st[N], en[N], cur;
int a[N], v_idx[N], blk_sz, inc_node[N], dec_node[N];
ll blk_sum[632], sum[N], answer[N];
vector<int> g[N], shorten_r;
struct query{
    int l, r, le, ri, lc, id;
    bool operator<(const query &q) const{
        if(q.l/blk_sz != l/blk_sz) return l < q.l;
        return r < q.r;
    }
}Q[N];
void dfs(int u, int p, int level)
{
    par[u][0] = p;
    st[u] = ++cur;
    ID[cur] = u;
    depth[u] = level;
    for(auto v: g[u])
    {
        if(v != p) dfs(v, u, level+1);
    }
    en[u] = ++cur;
    ID[cur] = u;
}
int kth_parent(int u, int k)
{
    for(int b = M-1; b>=0; b--)
    {
        if((k>>b)&1) u = par[u][b];
    }
    return u;
}
int LCA(int u, int v)
{
    if(depth[u] < depth[v]) swap(u, v);
    int dif = depth[u] - depth[v];
    u = kth_parent(u, dif);
    if(u == v) return v;
    else
    {
        for(int k = M-1; k>=0; k--)
        {
            if(par[u][k] != par[v][k] and par[u][k] != 0)
            {
                u = par[u][k];
                v = par[v][k];
            }
        }
        return par[v][0];
    }
}
ll qsum(int id)
{
    ll tot = 0LL;
    for(int i=0; i<id/blk_sz; i++) tot += blk_sum[i];
    for(int i=id/blk_sz*blk_sz; i<=id; i++) tot += sum[i];
    return tot;
}
void add(int k)
{
    //debug2(add, k);
    sum[k] += shorten_r[k];
    blk_sum[k/blk_sz] += shorten_r[k];
}
void del(int k)
{
    //debug2(del, k);
    sum[k] -= shorten_r[k];
    blk_sum[k/blk_sz] -= shorten_r[k];
}
void check(int x){
    //debug3(x, v_idx[x], a[x]);
    // If (x) occurs twice, then don't consider it's value 
    if (vis[x] and --val[v_idx[x]] == 0 ) del(v_idx[x]);
    else if (!vis[x] and val[v_idx[x]]++ == 0) add(v_idx[x]);
    vis[x] ^= 1;
    //debug2(x, v_idx[x]);
}
void MO()
{
    int curL = Q[0].l, curR = Q[0].l-1;
    for (int i = 0; i < m; i++){
        while (curL < Q[i].l) check(ID[curL++]);
        while (curL > Q[i].l) check(ID[--curL]);
        while (curR < Q[i].r) check(ID[++curR]);
        while (curR > Q[i].r) check(ID[curR--]);
 
        int u = ID[curL], v = ID[curR];
 
        // Case 2
        if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc);
 
        answer[Q[i].id] = qsum(Q[i].ri)-(Q[i].le > 0 ? qsum(Q[i].le-1) : 0);
 
        if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc);
    }   
    for(int i=0; i<m; i++) cout << answer[i] << nl;
}
int main()
{
    init_code();
     cin >> n;
     blk_sz = sqrt(n);
     for(int i=1; i<n; i++)
     {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
     }
     shorten_r.resize(n);
     for(int i=1; i<=n; i++)
     {
        cin >> a[i];
        shorten_r[i-1] = a[i];
     }
     sort(all(shorten_r));
     for(int i=1; i<=n; i++)
     {
        int x = a[i];
        int pos = lower_bound(all(shorten_r), x)-shorten_r.begin();
        //debug(pos);
        v_idx[i] = pos;
     }
     cur = 0;
     dfs(1, 0, 0);
     //par[1][0] = 1;
     for(int k=1; k<M; k++)
     {
        for(int u=1; u<=n; u++)
        {
            if(par[u][k-1] == 0) par[u][k] = 0;
            else par[u][k] = par[par[u][k-1]][k-1];
        }
     }
     cin >> m;
     for(int i=0; i<m; i++)
     {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        l = lower_bound(all(shorten_r), l)-shorten_r.begin();
        r = upper_bound(all(shorten_r), r)-shorten_r.begin()-1;
        //debug2(l, r);
        if(l > r)
        {
            answer[i] = 0;
            continue;
        }
        int lca = LCA(u, v);
        //debug(lca);
        
        Q[i].lc = lca;
        Q[i].id = i;
        Q[i].le = l;
        Q[i].ri = r;
        if(st[u] > st[v]) swap(u, v);
        if(lca == u) Q[i].l = st[u], Q[i].r = st[v];
        else Q[i].l = en[u], Q[i].r = st[v];
     }
     sort(Q, Q+m);
     MO();
return 0;
}
//https://www.spoj.com/problems/COT2/ (Better Implementation)
//Prob link: https://toph.co/contests/training/ucyhd4j
//Algo link: https://codeforces.com/blog/entry/43230
