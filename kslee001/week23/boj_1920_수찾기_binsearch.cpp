#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int n, m;

bool bin_search(int* arr, int arr_size, int target){
    int start = 0;
    int end = arr_size-1;
    while(true){ // break when s > e
        int mid = start + (end-start)/2;
        int cur = arr[mid];
        if(target == cur) return true;
        if(target > cur) start = mid+1;
        if(target < cur) end = mid-1;
        if(start > end) return false;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >>n;
    for(int i=0; i<n; ++i) cin >>arr[i];
    sort(arr, arr+n);
    cin >>m;
    for(int i=0; i<m; ++i){
        int target; cin >>target;
        if(bin_search(arr, n, target)) cout << "1\n";
        else cout <<"0\n";
    }
}