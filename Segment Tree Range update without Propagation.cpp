const int N = 2e5+5;
int tr[4*N], a[N];
void build(int u, int b, int e)
{
    if(b == e)
    {
        tr[u] = a[b];
        return;
    }
    int mid = (b+e) >> 1;
    build(2*u, b, mid);
    build(2*u+1, mid+1, e);
    tr[u] = tr[2*u] + tr[2*u+1];
}
void update(int u, int b, int e, int i, int j, int x) // Range update
{
    if(b > j or e < i) return;
    if(b >= i and e <= j)
    {
        tr[u] += x;
        return;
    }
    int mid = (b+e)>>1;
    update(2*u, b, mid, i, j, x);
    update(2*u+1, mid+1, e, i, j, x);
    tr[u] = tr[2*u] + tr[2*u+1];
}
int query(int u, int b, int e, int i, int j)
{
    if(e < i or b > j) return 0;
    if(b >= i and e <= j) return tr[u];
    int mid = (b+e) >> 1;
    int Left = query(2*u, b, mid, i, j);
    int Right = query(2*u+1, mid+1, e, i, j);
    return Left + Right;
}
