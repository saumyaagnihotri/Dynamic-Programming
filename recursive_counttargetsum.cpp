#include <bits/stdc++.h>
using namespace std;
int count_targetsum(int arr[], int num, int cur_sum, int n)
{
    if(n==0) return num==cur_sum;
    else return count_targetsum(arr, num, cur_sum + arr[n-1], n-1) + count_targetsum(arr, num, cur_sum - arr[n-1], n-1);
}

int main() {
    int n,num; cin>>n>>num;
    int arr[n];
    for(int i=0; i<n; ++i) cin>>arr[i];
    cout<<count_targetsum(arr,num,0,n);
    
}

/*
Input :
4 6
3 3 3 3
Output:
4

*/