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
const int N = 3e5+5;
int n;
string s;
vector<int> g[N], rg[N];
bool vis[N];
int mark[N];
void add(int x, int y)
{
    g[x].pb(y);
    rg[y].pb(x);
}
stack<int> st;
void topsort(int node)
{
    vis[node] = 1;
    for(int v: g[node])
    {
        if(vis[v] == 0)
        {
            topsort(v);
        }
    }
    st.push(node);
}
void dfs(int node, int id)
{
    vis[node] = 1;
    mark[id]++;
    for(auto v: rg[node])
    {
        if(vis[v] == 0) dfs(v, id);
    }
}
int main()
{
    init_code();
    int t;
    cin >> t;
    while(t--)
    {
        while(!st.empty()) st.pop();
        cin >> n;
        for(int i=0;i <=n; i++)
        {
            g[i].clear();
            rg[i].clear();
            mark[i] = 0;
            vis[i] = 0;
        }
        cin >> s;
        
        for(int i=0; i<n; i++)
        {
            int rt = (i+1)%n;
            if(s[i] == '-')
            {
                add(i, rt);
                add(rt, i);
            }
            else if(s[i] == '<') add(rt, i);
            else add(i, rt);
        }
        for(int i=0; i<=n; i++) vis[i] = 0;
        for(int i=0; i<n; i++)
        {
            if(vis[i] == 0) topsort(i);
        }
        for(int i=0; i<=n; i++) vis[i] = 0;
        int id = 1;
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            if(vis[node]) continue;
            dfs(node, id);
            id++;
        }
        int ans = 0;
        for(int i=0; i<=n; i++)
        {
            if(mark[i] > 1) ans += mark[i];
        }
        cout << ans << nl;
    }
return 0;
}
///https://codeforces.com/contest/1428/problem/B
