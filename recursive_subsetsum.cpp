#include <bits/stdc++.h>
using namespace std;
int subset_sum(int arr[], int num, int n)
{
    if(num==0) return 1;
    if(n==0) return 0;
    else if(num>=arr[n-1]) return subset_sum(arr,num-arr[n-1],n-1) || subset_sum(arr,num,n-1);
    else return subset_sum(arr, num, n-1);
}
int main() {
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