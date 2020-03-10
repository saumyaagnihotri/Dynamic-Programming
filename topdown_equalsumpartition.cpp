#include <bits/stdc++.h>
using namespace std;
int equal_sum_partition(int arr[], int sum, int n)
{
    int dp[n+1][sum+1];
    for(int i=0; i<=n; ++i)
    {
        for(int j=0; j<=sum; ++j)
        {
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;
            else if(j>=arr[i-1] && i!=0) dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else if(i!=0) dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main() {
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; ++i) cin>>arr[i];
    int sum = accumulate(arr,arr+n,0);
    if(sum%2) cout<<0;
    else cout<<equal_sum_partition(arr,sum/2,n);
    
}

/*
Input :
4
5 1 4 2

Output:
1
*/