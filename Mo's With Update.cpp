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
int n, m, a[N], cnt[10*N], val[10*N], aux[N];
int blk_sz, cur_L, cur_R;
ll cur_ans, ans[N];
unordered_map<int, int> mp;
struct query
{
    int l, r, id, upd_cnt;
    bool operator<(const query& x) const
    {
        if(l/blk_sz == x.l/blk_sz){
            if(r/blk_sz == x.r/blk_sz) return upd_cnt < x.upd_cnt;
            else return r/blk_sz < x.r/blk_sz;
        }
        else return l/blk_sz < x.l/blk_sz;
    }
}Q[N];
struct Upd
{
    int idx, prv, nxt;
    /// idx = index of the update queries
    /// prv = array had this value before this update
    /// nxt = arry will have this value after this update
}upd[N];
void add(int k)
{
    cnt[k]++;
    if(cnt[k] == 1 and val[k]%3 == 0) cur_ans += 1LL*val[k];
}
void del(int k)
{
    cnt[k]--;
    if(cnt[k] == 0 and  val[k]%3 == 0) cur_ans -= 1LL*val[k];
}
void do_upd(int upd_idx) /// Updating the value in the Mo's range
{
    int i = upd[upd_idx].idx;
    int now = upd[upd_idx].nxt;
    if(i >= cur_L and i <= cur_R) del(a[i]);
    a[i] = now;
    if(i >= cur_L and i <= cur_R) add(a[i]);
}
void undo_upd(int upd_idx) /// Restore to the previous value in the Mo's range
{
    int i = upd[upd_idx].idx;
    int now = upd[upd_idx].prv;
    if(i >= cur_L and i <= cur_R) del(a[i]);
    a[i] = now;
    if(i >= cur_L and i <= cur_R) add(a[i]);
}
int main()
{
    init_code();
    
    int k = 0, u = 0, j = 0;
    scanf("%d %d", &n, &m);
    veci vv;
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a[i]);
        if(!mp.count(a[i]))
        {
            mp[a[i]] = ++k;
            val[k] = a[i];
            vv.pb(k);
        }
        a[i] = mp[a[i]];
        aux[i] = a[i];
    }
    for(int i=0; i<m; i++)
    {
        int t, l, r;
        scanf("%d %d %d", &t, &l, &r);
        if(t == 1)
        {
            Q[j].l = l;
            Q[j].r = r;
            Q[j].upd_cnt = u;
            Q[j].id = j;
            j++;
        }
        else
        {
            ++u;
            upd[u].idx = l;
            if(!mp.count(r))
            {
                mp[r] = ++k;
                val[k] = r;
            }
            upd[u].nxt = mp[r];
            upd[u].prv = aux[l];
            aux[l] = mp[r];
        }
    }
    blk_sz = sqrt(n);
    sort(Q, Q+j);
    int cur = 0;
    for(int i=0; i<j; i++)
    {
        int l = Q[i].l, r = Q[i].r, t = Q[i].upd_cnt;
        while(cur < t)
        {
            cur++;
            do_upd(cur);
        }
        while(cur > t)
        {
            undo_upd(cur);
            cur--;
        }
        while(cur_L > l) add(a[--cur_L]);
        while(cur_R < r) add(a[++cur_R]);
        while(cur_L < l) del(a[cur_L++]);
        while(cur_R > r) del(a[cur_R--]);
        ans[Q[i].id] = cur_ans;
    }

    for(int i=0; i<j; i++)
    {
        printf("%lld\n", ans[i]);
    }
     
return 0;
}
