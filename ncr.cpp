#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll nck[2001][2001];
int n, m;
void ncr()
{
    for(int i=0; i<=2000; i++)
    {
        nck[i][0] = 1;
        for(int j=1; j<=i; j++)
        {
            nck[i][j] = nck[i-1][j] + nck[i-1][j-1];
        }
    }
}
int main()
{
    ncr();
    cin >> n >> m;
    cout << nck[n][m] << endl;
}
