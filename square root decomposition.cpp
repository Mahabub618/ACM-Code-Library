const int N = 1e5+5;
int n, m, a[N], block_sum[N];
int blk_sz;

void pre_calculate()
{
    for(int i = 0; i < n; i++)
    {
        block_sum[i/blk_sz] += a[i];
    }
}

int query(int l, int r)
{
    int lb = l/blk_sz;
    int rb = r/blk_sz;
    int sum = 0;
    if(lb == rb)
    {
        for(int i = l; i <= r; i++) sum += a[i];
    }
    else
    {
        for(int i = lb+1; i <= rb-1; i++) sum += block_sum[i];
        for(int i = l; i <= (lb+1)*blk_sz - 1; i++) sum += a[i];
        for(int i = rb*blk_sz; i <= r; i++) sum += a[i];
    }

    return sum;
}

/// For Range Update

void update(int l, int r, int x)
{
    int lb = l/blk_sz;
    int rb = r/blk_sz;

    if(lb == rb)
    {
        for(int i = l; i <= r; i++) a[i] += x;
    }
    else
    {
        for(int i = lb+1; i <= rb-1; i++) to_add[i] += x;
        for(int i = l; i <= (lb+1)*blk_sz - 1; i++) a[i] += x;
        for(int i = rb*blk_sz; i <= r; i++) a[i] += x;
    }
}

/// For Point Update

void update(int idx, int x)
{
    block_sum[idx/blk_sz] += -a[idx] + x;
    a[idx] = x;
}
