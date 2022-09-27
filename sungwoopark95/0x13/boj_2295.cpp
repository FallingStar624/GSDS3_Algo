#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long sum_max;
long long U[1005];
long long itm_sum[1000010];

bool search(long long* arr, int start, int end, int target) {
    while (start <= end) {
        int mid = start + ((end-start)/2);
        if (arr[mid] < target) { start = mid + 1; }
        else if (arr[mid] > target) { end = mid - 1; }
        else { return 1; }
    }
    return 0;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) { cin >> U[i]; }

    int idx = 0;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            itm_sum[idx++] = U[i] + U[j];
        }
    }
    
    sort(itm_sum, itm_sum+idx);
    
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            if (U[j] >= U[i]) {
                int place = search(itm_sum, 0, idx-1, U[j]-U[i]);
                if (place && sum_max < U[j]) { sum_max = U[j]; } 
            }
        }
    }
    
    cout << sum_max << "\n";
    return 0;
}