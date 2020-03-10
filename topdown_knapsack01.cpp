#include <bits/stdc++.h>
using namespace std;
int knapsack(int wt[], int val[], int w, int n)
{
    int dp[n+1][w+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=w; ++j)
        {
            if(i==0 || j==0) dp[i][j] = 0;
            else if(wt[i-1]<=j) dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][w];
}
int main() {
    int n,w; cin>>n>>w;
    int wt[n], val[n];
    for(int i=0; i<n; ++i) cin>>wt[i];
    for(int i=0; i<n; ++i) cin>>val[i];
    cout<<knapsack(wt,val,w,n);
    
}

/*
Input :
5 10
2 1 4 5 3
10 20 15 12 40

Output:
85
*/