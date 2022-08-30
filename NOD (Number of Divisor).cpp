#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, cnt;
    cin >> n;
    int ans = 1;
    for(int i=2; i*i<=n; i++)
    {
        int cnt=1;
        while(n%i==0)
        {
            n/=i;
            cnt++;
        }
        ans *= cnt;
    }
    if(n>1) ans*=2;
    cout << ans << endl;
}
