#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    int total = N * K;
    int arr[total];
    int out[N];

    for (int i=0;i<total;i++) {
        // 초기화
        if (i < N) {
            arr[i] = i+1;
        } else {
            arr[i] = 0;
        }
    }
    
    int curr = N;
    for (int i=0;i<total;i++) {
        if ((i+1) % K != 0) {
            arr[curr] = arr[i];
            curr++;
        } else {
            out[i/K] = arr[i];
        }
    }

    cout << '<';
    for (int k=0;k<N;k++) {
        if (k < (N-1)) {
            cout << out[k] << ", ";
        }
        else {
            cout << out[k] << '>';
        }
    }
    cout << "\n";

    return 0;
}