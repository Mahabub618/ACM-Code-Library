#include<bits/stdc++.h>
using namespace std;

unsigned long long catalan(int n)
{
    unsigned long long tot = 1;
    for(int i=2; i<=n; i++)
    {
        tot = (2*(2*i-1)*tot)/(i+1);
    }
    return tot;
}
int main()
{
    int n, ans;
    cin >> n;
    ans = catalan(n);
    cout << ans << endl;
}
