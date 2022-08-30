#include<bits/stdc++.h>
using namespace std;
#define SIZE1 101
#define SIZE2 50001

int N, tot;
int coin[SIZE1];
int dp[SIZE1][SIZE2];

void initDp()
{
    for(int i=0; i<SIZE1; i++)
    {
        for(int j=0; j<SIZE2; j++) dp[i][j] = -1;
    }
}
int solve(int i, int sum)
{
    if(dp[i][sum]>=0) return dp[i][sum];
    if(i==N)
    {
        int summ = tot-sum;
        return dp[i][sum] = abs(sum-summ);
    }
    int Left = solve(i+1, sum);
    int Right = solve(i+1, sum+coin[i]);

    if(Left>Right) return dp[i][sum] = Right;
    else return dp[i][sum] = Left;
}
int main()
{
    int ca;
    scanf("%d", &ca);
    while(ca--)
    {
        tot = 0;
        scanf("%d", &N);
        for(int i=0; i<N; i++)
        {
            scanf("%d", &coin[i]);
            tot += coin[i];
        }
        initDp();
        int dif = solve(0, 0);
        printf("%d\n", dif);
    }
}
