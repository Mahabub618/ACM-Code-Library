void bfs(int u)
{
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    par[u] = -1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v: g[u])
        {
            if(!vis[v])
            {
                vis[v] = 1;
                dis[v] = dis[u]+1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}
vector<int> v;
void shortest_path(int src)
{
    while(src!=-1)
    {
        v.push_back(src);
        src = par[src];
    }
}
