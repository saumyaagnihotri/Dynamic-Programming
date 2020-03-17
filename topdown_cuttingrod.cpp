#include <bits/stdc++.h>
using namespace std;
int rod_cutting(int price[], int length[], int given_len,int n)
{
    int dp[n+1][given_len+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=given_len; ++j)
        {
            if(i==0) dp[i][j] = 0;
            if(j==0) dp[i][j] = 0;
            else if(length[i-1]<=j && i!=0) dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            else if(i!=0) dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][given_len];
}
int main() {
    int n, given_len; cin>>n>>given_len;
    int length[n], price[n];
    for(int i=0; i<n; ++i) cin>>length[i];
    for(int i=0; i<n; ++i) cin>>price[i];
    cout<<rod_cutting(price, length, given_len, n);
    
}

/*

Input :
8 8
1 2 3 4 5 6 7 8
1 5 8 9 10 17 17 20

Output:
22
*/