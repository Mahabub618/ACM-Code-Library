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
#define       debug2(x, y)             cout << #x << ": " << x << "  " << #y << ": " << y << endl;
#define       debug3(x, y, z)          cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define       debug4(a, b, c, d)       cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#endif
void init_code()
{
    ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);

    /*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif  */
}
const int N = 2e3+3;
vector<int> g[N];
int dis[N], deg[N];
int main()
{
    init_code();
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++)
    {
        int n, m, idx = 0;
        string a, b;
        cin >> n;
        unordered_map<string, int> Map;
        unordered_map<int, string> key;
        priority_queue<pii> pq;
        for(int i=0; i<n; i++)
        {
            cin >> a >> m;
            if(Map[a] == 0) Map[a] = ++idx, key[idx] = a;
            if(m == 0)
            {
                dis[Map[a]] = 0;
                pq.push({-dis[Map[a]], Map[a]});
            }

            while(m--)
            {
                cin >> b;
                if(Map[b] == 0) Map[b] = ++idx, key[idx] = b;
                g[Map[b]].pb(Map[a]);
                deg[Map[a]]++;
            }
        }
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int u = top.S, d = -top.F;
            debug(key[u]);
            for(int i=0; i<g[u].size(); i++)
            {
                int v = g[u][i];
                deg[v]--;
                debug2(key[v], deg[v]);
                dis[v] = max(dis[v], dis[u]+1);
                if(!deg[v]) pq.push({-dis[v], v});
            }
        }
        int q;
        string s;
        cin >> q;
        cout << "Case " << cs << ":\n";
        while(q--)
        {
            cin >> s;
            cout << dis[Map[s]] << nl;
        }

        for(int i=0; i<N; i++)
        {
            g[i].clear();
            dis[i] = 0;
        }
    }

return 0;
}
//https://toph.co/p/tasks
