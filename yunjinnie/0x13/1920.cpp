// N int A[1], ..., A[N] -> X exists?
// 1st row: 1<=N<=100,000
// 2nd row: A[1], ..., A[N]
// 3rd row: 1<=M<=100,000
// 4th row: X

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100002];

int bs(int num){
    int st = 0;
    int en = n-1; // why num in local ...

    while(st<=en){
        int mid = (en-st)/2+st;
        if(arr[mid]>num){
            en = mid-1;
        }
        else if(arr[mid]<num){
            st = mid+1;
        }
        else return 1; // found
    }
    return 0; // st>en
    // if using check -> make it default

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    //int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    // vector -> begin() / end()
    sort(arr, arr+n);

    cin>>m;

    int tmp;
    while(m--){
        cin>>tmp;
        cout<< bs(tmp) << '\n';
    }
    return 0;
}

// STL binary_search function