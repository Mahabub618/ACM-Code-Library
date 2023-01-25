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
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("Error.txt", "w", stderr);
    // #endif    
}
string s;
const int N = 1e5+5;
struct info
{
    ll cnt[3][3];
};
info tr[4*N];
info Merge(info l, info r)
{
    info ret;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            ret.cnt[i][j] = l.cnt[i][j] + r.cnt[i][j];
            for(int m=i; m<j; m++)
            {
                ret.cnt[i][j] += l.cnt[i][m]*r.cnt[m+1][j];
            }
        }
    }
    return ret;
}
void build(int u, int b, int e)
{
    if(b == e)
    {
        if(s[b-1] == 's')
        {
            //debug(u);
            tr[u].cnt[0][0] = tr[u].cnt[2][2] = 1;
        }
        else if(s[b-1] == 'm') tr[u].cnt[1][1] = 1;
        return;
    }
    int mid = (b+e)>>1;
    build(2*u, b, mid);
    build(2*u+1, mid+1, e);
    tr[u] = Merge(tr[2*u], tr[2*u+1]);
}
info query(int u, int b, int e, int i, int j)
{
    if(e < i or b > j) return {0, 0};
    if(b >= i and e <= j) return tr[u];
    
    int mid = (b+e)>>1;
    info l = query(2*u, b, mid, i, j);
    info r = query(2*u+1, mid+1, e, i, j);
    return Merge(l, r);
}
int main()
{
    init_code();
    cin >> s;
    int len = s.size();
    build(1, 1, len);
    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        info res = query(1, 1, len, l, r);
        cout << res.cnt[0][2] << nl;
    }
    
return 0;
}
/// https://www.spoj.com/problems/MOZHSLS/
/// https://codeforces.com/problemset/problem/380/C
