#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
#define pb push_back

vector<int> g[N];
int timer, n, m;
void dfs(int u, vector<int> &disc, vector<int> &low, stack<int> &mystack, vector<bool> &presentStack)
{
    disc[u] = low[u] = timer;
    timer++;
    mystack.push(u);
    presentStack[u] = true;
    
    for(auto v: g[u])
    {
        if(disc[v] == -1)
        {
            dfs(v, disc, low, mystack, presentStack);
            low[u] = min(low[u], low[v]);
        }
        else if(presentStack[v]) low[u] = min(low[u], disc[v]); // (u, v) are back-edge
        else
        {
            // (u, v) are cross-edge
        }
    }
    if(low[u] == disc[u])
    {
        cout << "SCC is: ";
        while(mystack.top() != u)
        {
            cout << mystack.top() << ' ';
            presentStack[mystack.top()] = false;
            mystack.pop();
        }
        cout << mystack.top() << "\n";
        presentStack[mystack.top()] = false;
        mystack.pop();
    }
}
void Tarjan()
{
    vector<int> disc(n, -1), low(n, -1);
    vector<bool> presentStack(n, false);
    stack<int> mystack;
    
    for(int i=0; i<n; i++)
    {
        if(disc[i] == -1) dfs(i, disc, low, mystack, presentStack);
    }
}
int main()
{
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u); // For bi-directional
    }
    Tarjan();
}
