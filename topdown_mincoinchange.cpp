#include <bits/stdc++.h>
using namespace std;
int min_coinchange(int coin[], int sum, int n)
{
    int dp[n+1][sum+1];
    for(int i=0; i<=sum; ++i) dp[0][i] = INT_MAX - 1;
    for(int i=1; i<=n; ++i) dp[i][0] = 0;
    for(int i=1; i<=sum; ++i)
    {
        if(i%coin[0]==0) dp[1][i] = i/coin[0];
        else dp[1][i] = INT_MAX - 1;
    }
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=sum; ++j)
        {
            if(coin[i-1]<=j) dp[i][j] = min(1 + dp[i][j-coin[i-1]], dp[i-1][j]);
            else  dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main() {
    int n,sum; cin>>n>>sum;
    int coin[n];
    for(int i=0; i<n; ++i) cin>>coin[i];
    cout<<min_coinchange(coin,sum,n);
    
}

/*

Order of the coins doesn't matter!

Input :
3 30
25 10 5

Output:
2
*/