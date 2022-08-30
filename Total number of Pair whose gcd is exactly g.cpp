/**********************/
/* Mahabub Rahman     */
/* Cse 10th           */
/* Comilla University */
/**********************/

#include<bits/stdc++.h>
using namespace std;
#define       ll                  long long int
#define       veci                 vector<int>
#define       vecl                 vector<long long int>
#define       pb                   push_back
#define       newline cerr << endl
#define       pii                  pair<int, int>
#define       F                    first
#define       S                    second
#define       nl                   "\n"
#define       all(v)               v.begin(), v.end()
///============ CONSTANT ===============///
#define mx9   1000000007
#define mx5   200005
#define inf   1<<30                                           //infinity value
#define eps   1e-9
#define mod   mx9
///=============== Debugging ============================///
#ifndef ONLINE_JUDGE
#define       debug(x) cout << #x << " = " << x << endl
#define       debug2(x, y)             cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define       debug3(x, y, z)          cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define       debug4(a, b, c, d)       cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#endif
void init_code()
{
    ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif    
}
const int N = 1e7+7;
int cnt[N], b[N], exact[N];
int main()
{
    init_code();
    
    int t, n, x, k = 0;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> x;
        cnt[x]++;
        k = max(k, x);
    }
    for(int i=1; i<=k; i++)
    {
        for(int j=i; j<=k; j+=i)
        {
            b[i] += cnt[j]; /// Count the number of given array which are multiple of i
        }
    }
    /// b[i] = i divisible wala array er total number
    
    for(int i=k; i>0; i--)
    {
        exact[i] = (b[i]*(b[i]-1))/2; /// Just nc2 because of finding all possible pair
        if(exact[i] == 0) continue;
        for(int j=i+i; j<=k; j+=i)
        {
            exact[i] -= exact[j]; /// gcd g er multiple oi sob boro g wala der ans thk minus kora
        }
    }
    cin >> t;
    while(t--)
    {
        cin >> x;
        cout << "The total number of pair of exactly gcd " << x << " is : " << exact[x] << endl;
    }
    
     
return 0;
}
