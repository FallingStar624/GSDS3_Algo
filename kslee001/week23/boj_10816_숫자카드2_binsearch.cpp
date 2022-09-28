#include <bits/stdc++.h>
using namespace std;

int a[500005];
int n;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a,a+n);
  int m;
  cin >> m;
  while(m--){
    int t;
    cin >> t;
    cout << upper_bound(a,a+n,t)-lower_bound(a,a+n,t) << '\n';
  }
}

// #include <iostream>
// #include <algorithm>
// using namespace std;

// bool bin_search(int* arr, int arr_size, int target){
//     int start = 0;
//     int end = arr_size-1;
//     while(start<=end){ // break when s > e
//         int mid = start + (end-start)/2;
//         int cur = arr[mid];
//         if(target == cur) return true;
//         if(target > cur) start = mid+1;
//         if(target < cur) end = mid-1;
//     }
//     return false;
// }

// int lower_idx(int* arr, int arr_size, int target){
//     int start = 0;
//     int end=arr_size;
//     while(start < end){
//         int mid = start + (end-start)/2;
//         if(target<=arr[mid]) end   = mid;
//         else                 start = mid+1;
//     }
//     return start;
// }

// int upper_idx(int* arr, int arr_size, int target){
//     int start = 0;
//     int end=arr_size;
//     while(start < end){
//         int mid = start + (end-start)/2;
//         if(target<arr[mid]) end   = mid;
//         else                start = mid+1;
//     }
//     return start;
// }


// int n, m;
// int arr[500000];
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cin >>n;
//     for(int i=0; i<n; ++i) cin>>arr[i];
//     sort(arr, arr+n);

//     cin >>m;
//     for(int i=0; i<m; ++i){
//         int cur;
//         cin >>cur;
//         cout << upper_idx(arr, cur, n) - lower_idx(arr, cur, n) <<"\n";
//     }

// }