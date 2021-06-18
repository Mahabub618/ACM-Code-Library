#include<bits/stdc++.h>
using namespace std;
#define SIZE_N 101
#define SIZE_MW 31

int N, tot;
int p[SIZE_N], w[SIZE_N];

int dp[SIZE_N][SIZE_MW];

void initDp()
{
    for(int i=0; i<SIZE_N; i++)
    {
        for(int j=0; j<SIZE_MW; j++) dp[i][j] = -1;
    }
}
int solve(int i, int cap)
{
    int Left, Right;
    if(dp[i][cap] >=0 ) return dp[i][cap];
    if(i==N) return dp[i][cap] = 0;

    Left = solve(i+1, cap);
    if(cap >= w[i]) Right = p[i] + solve(i+1, cap-w[i]);
    else Right = 0;

    if(Left > Right) return dp[i][cap] = Left;
    else return dp[i][cap] = Right;
}
int main()
{
    int ca, cap;
    scanf("%d", &ca);
    while(ca--)
    {
        scanf("%d", &N);
        for(int i=0; i<N; i++)
        {
            scanf("%d %d", &p[i], &w[i]);
        }
        scanf("%d", &cap);
        int ans;
        initDp();
        ans = solve(0, cap);
        printf("%d\n", ans);
    }
}

// p[i] = profit of ith item
// w[i] = weight of ith item
// cap in main function is Capacity of knapsack
