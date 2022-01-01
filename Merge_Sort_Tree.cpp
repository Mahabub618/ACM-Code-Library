#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> tr[4*N];
int a[N];

void build(int u, int b, int e)
{
    if(b == e)
    {
        tr[u].push_back(a[b]);
        return;
    }
    int mid = (b+e)>>1;
    build(2*u, b, mid);
    build(2*u+1, mid+1, e);
    merge(tr[2*u].begin(), tr[2*u].end(), tr[2*u+1].begin(), tr[2*u+1].end(), back_inserter(tr[u]));
}

int query(int u, int b, int e, int i, int j, int x, int y)
{
    if(e < i or b > j) return 0;
    if(b >= i and e <= j) return (upper_bound(tr[u].begin(), tr[u].end(), y) - lower_bound(tr[u].begin(), tr[u].end(), x));

    int mid = (b+e)>>1;
    int left_sum = query(2*u, b, mid, i, j, x, y);
    int right_sum = query(2*u+1, mid+1, e, i, j, x, y);

    return left_sum+right_sum;
}

int main()
{
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++)
    {
        int n, m, x, y, p, q;
        cin >> n >> m;
        for(int i=1; i<=n; i++) cin >> a[i];
        build(1, 1, n);
        cout << "Case " << cas << ":" << endl;
        while(m--)
        {
            cin >> x >> y >> p >> q;
            cout << query(1, 1, n, x, y, p, q) << endl;

        }

    }
}
