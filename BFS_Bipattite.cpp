bool bipartite(int source)
{
    queue<int> q;
    q.push(source);
    color[source] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0; i<node[u].size(); i++)
        {
            int element = node[u][i];

            if(color[element]==-1)
            {
                if(color[u] = 0) color[element] = 1;
                else color[element] = 0;
                q.push(element);
            }
            if(color[u]==color[element])
            {
                return false;
            }
        }
    }
    return true;
}
