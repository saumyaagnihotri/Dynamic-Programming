#include <bits/stdc++.h>
using namespace std;
/* n<=100 & w<1000 */
int static dp[102][1002];
int knapsack(int wt[], int val[], int w, int n)
{
    if(n==0 || w==0) return 0;
    if(dp[n][w]!=-1) return dp[n][w];
    if(w-wt[n-1]>=0) 
    {
        dp[n][w] = max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1), knapsack(wt,val,w,n-1));
        return dp[n][w];
    }
    else 
    {
        dp[n][w] = knapsack(wt,val,w,n-1);
        return dp[n][w];
    }
}
int main() {
    memset(dp,-1,sizeof(dp));
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