#include<bits/stdc++.h>
using namespace std;

int phi(int n)
{
    int tot = n;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            while(n%i==0) n/=i;
            tot -= tot/i;
        }
    }
    if(n>1) tot -= tot/n;

    return tot;
}
int main()
{
    int n;
    cin >> n;
    int ans = phi(n);
    cout << ans << endl;
}
