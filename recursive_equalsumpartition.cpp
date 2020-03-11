#include <bits/stdc++.h>
using namespace std;
int equal_sum_partition(int arr[], int sum1, int sum2, int n)
{
    if(n==0) return 0;
    if(sum1==sum2) return 1;
    else if(sum1>sum2) return 0;
    else return equal_sum_partition(arr, sum1+arr[n-1], sum2-arr[n-1], n-1) || equal_sum_partition(arr, sum1, sum2, n-1);
}
int main() {
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; ++i) cin>>arr[i];
    int sum2 = accumulate(arr,arr+n,0);
    cout<<equal_sum_partition(arr,0,sum2,n);
    
}

/*
Input :
4
5 1 4 2

Output:
1
*/