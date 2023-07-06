#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1001];
int sum[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    sum[0] = arr[0];
    for (int i = 1; i < n; i++){
        sum[i] = sum[i-1] + arr[i];
    }
    for (int i = 0; i < n; i++){
        total += sum[i];
    }
    cout << total ;
}