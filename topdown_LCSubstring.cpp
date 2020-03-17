#include <bits/stdc++.h>
using namespace std;
int LCSubstring(string s1, string s2, int n, int m)
{
    int dp[n+1][m+1];
    for(int i=0; i<=n; ++i) dp[i][0] = 0;
    for(int i=0; i<=m; ++i) dp[0][i] = 0;
    
    int ans = INT_MIN;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1]; 
            else dp[i][j] = 0;
            ans = max(ans,dp[i][j]);
        }
    }
    return ans;
}
int main() {
    string s1,s2; cin>>s1>>s2;
    int n = s1.length(), m = s2.length();
    cout<<LCSubstring(s1,s2,n,m);
    
}

/*
Input :
abcde
abgce

Output:
2
*/