#include <bits/stdc++.h>
using namespace std;
int ways_coinchange(int coin[], int sum, int n)
{
    int dp[n+1][sum+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=sum; ++j)
        {
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;
            else if(coin[i-1]<=j && i!=0) dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j];
            else if(i!=0) dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main() {
    int n,sum; cin>>n>>sum;
    int coin[n];
    for(int i=0; i<n; ++i) cin>>coin[i];
    cout<<ways_coinchange(coin,sum,n);
    
}

/*

Order of the coins doesn't matter!

Input :
3 4
1 2 3

Output:
4
*/