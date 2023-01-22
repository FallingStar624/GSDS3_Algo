//solution
#include <bits/stdc++.h>
using namespace std;

int arr[500002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr+N);
    int M;
    cin >> M;
    for(int i = 0; i < M; i++){
        int tst;
        cin >> tst;
        cout << binary_search(arr, arr+N, tst) << ' ';
    }
}