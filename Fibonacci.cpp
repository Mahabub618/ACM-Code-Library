    /*****************************************************************\
    |     IN THE NAME OF ALLAH, MOST GRACIOUS AND MOST MERCIFUL       |
    |                                                                 |
    |     Author     : Mahabub Rahman                                 |
    |     Email      : mahabubrahman618@gmail.com                     |
    |     University : Comilla University, Bangladesh                 | 
    |                  Department of Computer Science & Engineering   |
    \*****************************************************************/
    #include<bits/stdc++.h>

    using namespace std;
    #define FastIO ios::sync_with_stdio(false); cin.tie(0);cout.tie(0)
    #define       ll                  long long int
    #define mx9   1000000007

    map<ll, ll> f;
    ll fun(ll n)
    {
        if(f.count(n)) return f[n];
        ll k = n/2;
        if(n%2==0)
        {
            return f[n] = (fun(k)*fun(k) + fun(k-1)*fun(k-1))%mx9;
        }
        else
        {
            return f[n] = (fun(k)*fun(k+1) + fun(k-1)*fun(k))%mx9;
        }
    }
    int32_t main()
    {
        //Don't see test case until get 7/8 times wrong submission..!!
        //Try to make Corner, Even, Odd or Prime case..!!
        FastIO;
        ll n;
        f[0]=f[1]=1;
        while(cin >> n)
        {
            cout << (n==0 ? 0 : fun(n-1)) << endl;
        }

    }
///Created: 2020-07-13-00.12
