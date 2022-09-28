#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int arr[500000];

int lower_idx(int target, int len) {
    int st=0;
    int en=len;
    while (st<en) {
        int mid = (st+en)/2;
        if (arr[mid]>=target) {
            en = mid;
        } else {
            st = mid+1;
        }
    }
    return st;
}

int upper_idx(int target, int len) {
    int st=0;
    int en=len;
    while (st<en) {
        int mid = (st+en)/2;
        if (arr[mid]>target) {
            en = mid;
        } else {
            st = mid+1;
        }
    }
    return st;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=0; i<N; i++) {cin>>arr[i];}
    sort(arr, arr+N);
    cin >> M;
    while (M--) {
        int tgt;
        cin >> tgt;
        int l_idx = lower_idx(tgt, N);
        int u_idx = upper_idx(tgt, N);
        cout << u_idx - l_idx << " ";
    }
    return 0;
}
