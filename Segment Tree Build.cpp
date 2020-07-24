#include<bits/stdc++.h>
using namespace std;

int N = 1e5+5;
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
