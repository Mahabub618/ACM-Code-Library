#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> cnt;
    map<int, int>::iterator it;
    int ans = 1;
    for(int i=2; i*i<=n; i++)
    {
        while(n%i==0)
        {
            n/=i;
            cnt[i]++;
        }
    }
    if(n>1) cnt[n]++;
    for(it = cnt.begin(); it!=cnt.end(); it++)
    {
        int x = it->first;
        int y = it->second+1;
        int m = 1;

        while(y--) m*=x;
        m--;
        m/=(x-1);
        ans *= m;
    }
    cout << ans << endl;
}
/// Theory: N = p1^e1 * p2^e2 * p3^e3 ...
/// Total Sum of Divisor = (p1^(e1+1)-1) * (p2^(e2+1)-1) * (p3^(e3+1)-1) .... / (p1-1) * (p2-1) * (p3-1) .....
