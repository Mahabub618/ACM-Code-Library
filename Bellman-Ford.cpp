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

const int N = 1e3+3;
int v, e, dist[N];
struct Edge
{
    int x, y, weight;
};
vector<Edge> E;

inline int BellmanFord(int source)
{
    for(int i=0; i<v; i++)
    {
        if(i == source) dist[i] = 0;
        else dist[i] = inf;
    }
    bool done = false;
    for(int i=0; i<v and !done; i++)
    {
        done = true;
        for(int j=0; j<e; j++)
        {
            int so = E[j].x;
            int de = E[j].y;
            
            if(dist[so] + E[j].weight < dist[de])
            {
                dist[de] = dist[so] + E[j].weight;
                done = false;
            }
        }
    }
    if(!done) return -1;
    else return 0;
}
void init_code()
{
    ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif    
}
int main()
{
    init_code();
    int x, y, z;
    scanf("%d %d", &v, &e);
    for(int i=0; i<e; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        Edge get;
        get.x = x;
        get.y = y;
        get.weight = z;
        E.pb(get);
    }
    int src = 0; // 0-based
    int is_poosible = BellmanFord(src);
    
    if(is_poosible == -1) printf("Detect Negative Cycle\n");
    else
    {
        for(int i=0; i<v; i++)
        {
            printf("Node %d: %d\n", i, dist[i]);
        }
    }
    E.clear();
}
