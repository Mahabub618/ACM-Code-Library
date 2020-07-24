#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int tr[4*N], a[N];

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
