void bfs(int i, int j, int row, int col)
{
    queue<pair<int, int> > q;
    pair<int, int> pa;

    q.push({i, j});
    vis[i][j] = 1;

    while(!q.empty())
    {
        pa = q.front();
        q.pop();

        int x = pa.first;
        int y = pa.second;

        for(int k=0; k<4; k++)
        {
            int row1 = x + fx[k];
            int col1 = y+ fy[k];

            int res = ok(row, col, row1, col1);

            if(res==1)
            {
                vis[row1][col1] = 1;
                q.push({row1, col1});
            }
        }
    }
}
