void bfs(int u)
{
    for(int i=1; i<=n; i++) dis[i] = INT_MAX;
    dis[u] = 0;
    deque<int> q;

    q.push(u);
    while(!q.empty())
    {
        int u = q.front();
        q.pop_front();

        for(int i=0; i<g[u][i].size(); i++)
        {
            int v = g[u][i].first;
            int w = g[u][i].second;

            if(dis[v]>dis[u]+w)
            {
                dis[v] = dis[u]+w;
                if(w==0) q.push_front(v);
                else q.push_back(v);
            }
        }
    }
}
