#include <bits/stdc++.h>
using namespace std;
int knapsack(int wt[], int val[], int w, int n)
{
    if(n==0 || w==0) return 0;
    if(w-wt[n-1]>=0) return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1), knapsack(wt,val,w,n-1));
    else return knapsack(wt,val,w,n-1);
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