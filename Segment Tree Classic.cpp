const int N = 1e5+5;
int tr[4*N], a[N];

void build(int u, int b, int e)
{
    if(b==e)
    {
        tr[u] = a[b];
        return;
    }
    int mid = (b+e)/2;

    int Left = 2*u;
    int Right = 2*u+1;

    build(Left, b, mid);
    build(Right, mid+1, e);

    tr[u] = tr[Left] + tr[Right];
}
void update(int u, int b, int e, int idx, int x)
{
    if(b==e)
    {
        tr[u] = x;
        return;
    }

    int mid = (b+e)/2;

    int Left = 2*u;
    int Right = 2*u+1;

    if(idx<=mid) update(Left, b, mid, idx, x);
    else update(Right, mid+1, e, idx, x);

    tr[u] = tr[Left] + tr[Right];
}
int query(int u, int b, int e, int i, int j)
{
    if(e<i or b>j) return 0;
    if(b>=i and e<=j) return tr[u];

    int mid = (b+e)/2;
    int Left = 2*u;
    int Right = 2*u+1;

    int l = query(Left, b, mid, i, j);
    int r = query(Right, mid+1, e, i, j);

    return l+r;
}
