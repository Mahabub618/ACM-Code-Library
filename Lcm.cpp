#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b)
{
    if(a%b==0) return b;
    return gcd(b, a%b);
}
ll lcm(ll a, ll b)
{
    return ((a*b)/__gcd(a, b));
}
int main()
{
    ll x, y;
    cin >> x >> y;
    ll ans = lcm(x, y);
    cout << ans << endl;
}
