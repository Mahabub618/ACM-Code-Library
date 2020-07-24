#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
tr[4*N], a[N];

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
