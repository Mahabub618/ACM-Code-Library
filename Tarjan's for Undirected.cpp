const int N = 1e4+4;
int disc[N], low[N], vis[N], col, color[N], deg[N], timer;
vector<int> g[N];
stack<int> st;

void Tarjan(int u, int p)
{
    disc[u] = low[u] = ++timer;
    st.push(u);
    vis[u] = 1;
    for(auto v: g[u])
    {
        if(v == p) continue;
        if(vis[v]) low[u] = min(low[u], disc[v]);
        else
        {
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == disc[u])
    {
        ++col;
        while(!st.empty())
        {
            int val = st.top();
            st.pop();
            color[val] = col;
            if(u == val) break;
        }
    }
}
