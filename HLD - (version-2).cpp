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
const int N = 5e5+50;
vector<int> tr[4*N];
veci g[N];
int a[N], st[N], et[N], timer, A[N];

void dfs(int u, int p)
{
    st[u] = ++timer;
    for(auto v: g[u])
    {
        if(v != p) dfs(v, u);
    }
    et[u] = timer;
}
void build(int u, int b, int e)
{
    if(b == e)
    {
        tr[u].pb(A[b]);
        return;
    }
    int mid = (b+e) >> 1;
    build(2*u, b, mid);
    build(2*u+1, mid+1, e);
    merge(all(tr[2*u]), all(tr[2*u+1]), back_inserter(tr[u]));
}
int query(int u, int b, int e, int i, int j, int x)
{
    if(e < i or b > j) return 0;
    if(b >= i and e <= j)
    {
        int idx = lower_bound(all(tr[u]), x) - tr[u].begin();
        //debug3(i, tr[u].size(), idx);
        return tr[u].size() - idx;
    }
    int mid = (b+e) >> 1;
    int Left = query(2*u, b, mid, i, j, x);
    int Right = query(2*u+1, mid+1, e, i, j, x);
    return Left+Right;
}

int main()
{
    init_code();
    int n, m, id, x;
    cin >> n >> m;
    for(int i=2; i<=n; i++)
    {
        cin >> x;
        g[x].pb(i);
    }
    timer = 0;
    dfs(1, -1);
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        A[st[i]] = a[i];
    }
    //debug(timer);
    build(1, 1, n);
    
    while(m--)
    {
        cin >> id >> x;
        cout << query(1, 1, n, st[id], et[id], x) << nl;
    }
     
return 0;
}
//https://toph.co/p/tree-queries
