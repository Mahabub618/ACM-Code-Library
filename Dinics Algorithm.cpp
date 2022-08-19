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
#define inf   1<<30  

const int N = 1e5+5;
int nodes = N, src, dest;
ll dist[N], work[N];
int cost1[N], cost2[N];

struct Edge
{
    int to, rev;
    long long f, cap;
};
vector<Edge> g[N];
vector<pii> gg[N];
void addEdge(int s, int t, long long cap)
{
    Edge a = {t, (int)g[t].size(), 0, cap};
    Edge b = {s, (int)g[s].size(), 0, 0}; // For bidirectional
    g[s].push_back(a);
    g[t].push_back(b);
}
bool dinic_bfs()
{
    queue<int> q;
    fill(dist, dist+nodes, -1);
    q.push(src);
    dist[src] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int j=0; j<g[u].size(); j++)
        {
            Edge &e = g[u][j];
            int v = e.to;
            if(dist[v] < 0 and e.f < e.cap)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[dest] >= 0;
}
ll dinic_dfs(int u, ll f)
{
    if(u == dest) return f;
    for(ll &i = work[u]; i<g[u].size(); i++)
    {
        Edge &e = g[u][i];
        if(e.cap <= e.f) continue;
        int v = e.to;
        if(dist[v] == dist[u] + 1)
        {
            ll df = dinic_dfs(v, min(f, e.cap-e.f));
            if(df > 0)
            {
                e.f += df;
                g[v][e.rev].f -= df;
                return df;
            }
        }
    }
    return 0;
}
ll Flow(int s, int d)
{
    src = s;
    dest = d;
    ll tot = 0;
    while(dinic_bfs())
    {
        fill(work, work+nodes, 0);
        while(ll sum = dinic_dfs(src, inf)) tot += sum;
    }
    return tot;
}
// void init_code()
// {
//     ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("Error.txt", "w", stderr);
//     #endif    
// }
int main()
{
    //init_code();
    int n, m, u, v, w;
    scanf("%d %d", &n, &m);
    int source = 1, sink = n;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w); // If graph is bi-directional
    }
    
    ll mx_flow = Flow(source, sink);
    
    printf("%lld\n", mx_flow);
    
}
