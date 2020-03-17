#include <bits/stdc++.h>
using namespace std;
int static dp[102][102];
int LCS(string s1, string s2, int n, int m)
{
    if(n==0 || m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    else if(s1[n-1]==s2[m-1]) 
    {
        dp[n][m] = 1 + LCS(s1,s2,n-1,m-1);
        return dp[n][m];
    }
    else 
    {
        dp[n][m] = max(LCS(s1,s2,n-1,m), LCS(s1,s2,n,m-1));
        return dp[n][m];
    }
}
int main() {
    memset(dp,-1,sizeof(dp));
    string s1,s2; cin>>s1>>s2;
    int n = s1.length(), m = s2.length();
    cout<<LCS(s1,s2,n,m);
    
}

/*
Input :
AGGTAB
GXTXAYB

Output:
4
*/