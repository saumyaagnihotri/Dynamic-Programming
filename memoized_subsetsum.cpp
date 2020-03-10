#include <bits/stdc++.h>
using namespace std;
/* n<=100 & num<=1000 */
int static dp[102][1002];
int subset_sum(int arr[], int num, int n)
{
    if(num==0) return 1;
    if(n==0) return 0;
    if(dp[n][num]!=-1) return dp[n][num];
    else if(num>=arr[n-1]) 
    {
        dp[n][num] = subset_sum(arr,num-arr[n-1],n-1) || subset_sum(arr,num,n-1);
        return dp[n][num];
    }
    else 
    {
        dp[n][num] = subset_sum(arr, num, n-1);
        return dp[n][num];
    }
}
int main() {
    memset(dp,-1,sizeof(dp));
    int n,num; cin>>n>>num;
    int arr[n], val[n];
    for(int i=0; i<n; ++i) cin>>arr[i];
    cout<<subset_sum(arr,num,n);
    
}

/*
Input :
5 39
21 13 4 5 3

Output:
1
*/