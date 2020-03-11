#include <bits/stdc++.h>
using namespace std;
int min_subsetsum_diff(int arr[], int sum1, int sum2, int n)
{
    if(n==0) return abs(sum1-sum2);
    else return min(min_subsetsum_diff(arr, sum1+arr[n-1], sum2-arr[n-1], n-1) , min_subsetsum_diff(arr, sum1, sum2, n-1));
}
int main() {
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; ++i) cin>>arr[i];
    int sum2 = accumulate(arr,arr+n,0);
    cout<<min_subsetsum_diff(arr,0,sum2,n);
    
}

/*
Input :
4
5 1 4 5

Output:
3

*/