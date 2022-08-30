#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll bigmod(ll a, ll b, ll m)
{
    if(b==0) return 1%m;
    ll x = bigmod(a, b/2, m);
    x = (x*x)%m;
    if(b&1) x = (x*a)%m;
    return x;
}
int main()
{
    ll n, m, ans;
    cin >> n >> m;
    ans = bigmod(n, m-2, m);
    cout << ans << endl;
}
