#include <bits/stdc++.h>
using namespace std;
int countofsubset_sum(int arr[], int num, int n)
{
    int dp[n+1][num+1];
    for(int i=0; i<=n; ++i)
    {
        for(int j=0; j<=num; ++j)
        {
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 1;
            else if(j>=arr[i-1] and i!=0) dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else if(i!=0) dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][num];
}
int main() {
    int n,num; cin>>n>>num;
    int arr[n], val[n];
    for(int i=0; i<n; ++i) cin>>arr[i];
    cout<<countofsubset_sum(arr,num,n);
    
}

/*
Input :
5 10
2 5 1 9 8

Output:
2
*/