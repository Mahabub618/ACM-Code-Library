#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5+5, LOG = 20;
int rmq[N][LOG];
int n, a[N], lg[N];
void pre_process()
{
    for(int i=1; i<=n; i++) rmq[i][0] = a[i];
    for(int j=1; j<=lg[n]; j++)
    {
        for(int i=1; i+(1<<j)-1 <= n; i++)
        {
            rmq[i][j] = max(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=2; i<N; i++) lg[i] = lg[i/2]+1;
}
int query(int i, int j)
{
    int k = lg[j-i+1];
    return max(rmq[i][k], rmq[j-(1<<k)+1][k]);
}
int main()
{
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i]; // 1-based
    pre_process();
    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        int mx = query(l, r);
        cout << mx << '\n';
    }
    
return 0;
}
