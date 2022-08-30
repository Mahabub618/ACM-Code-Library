#include<bits/stdc++.h>
using namespace std;

vector<int> prime;
void prime_factorization(int n)
{
    while(n%2==0)
    {
        prime.push_back(2);
        n /= 2;
    }
    for(int i=3; i*i<=n; i+=2)
    {
        while(n%i==0)
        {
            prime.push_back(i);
            n/=i;
        }
    }
    if(n>2) prime.push_back(n);
}
int32_t main()
{
    int n;
    cin >> n;
    prime_factorization(n);
    for(int i=0; i<prime.size(); i++)
    {
        cout << prime[i] << ' ';
    }
    cout << endl;
    return 0;
}
