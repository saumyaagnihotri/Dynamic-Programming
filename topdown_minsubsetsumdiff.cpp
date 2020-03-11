#include <bits/stdc++.h>
using namespace std;
int min_subsetsum_diff(int arr[], int num, int n)
{
    int dp[n+1][num+1];
    for(int i=0; i<=n; ++i)
    {
        for(int j=0; j<=num; ++j)
        {
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;
            else if(j>=arr[i-1] and i!=0) dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else if(i!=0) dp[i][j] = dp[i-1][j];
        }
    }
    int ans = INT_MAX;
    for(int j=num/2; j>=0; --j)
    {
        if(dp[n][j]) 
        {
            ans = min(ans, num - 2*j);
            break;
        }
    }
    return ans;
}
int main() {
    int n,num; cin>>n;
    int arr[n], val[n];
    for(int i=0; i<n; ++i) cin>>arr[i];
    num = accumulate(arr,arr+n,0);
    cout<<min_subsetsum_diff(arr,num,n);
    
}

/*
Input :
4
5 1 4 5
Output:
3

*/