#include <bits/stdc++.h>
#define MAXSIZE 5000000
using namespace std;

int find_min(long arr[], int start, int end);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, L;
    cin >> N >> L;
    long array[N], x;
    for (int i=0;i<N;i++) {
        cin >> x;
        array[i] = x;
    }

    int min_idx;
    for (int i=0;i<N;i++) {
        if ((i-L+1) < 0) {
            min_idx = find_min(array, 0, i);
            
        } else {
            min_idx = find_min(array, i-L+1, i);
            // cout << array[min_idx] << " ";
        }
        cout << array[min_idx] << " ";
    }
    cout << "\n";

    return 0;
}

int find_min(long arr[], int start, int end) {
    int min = start;
    for (int i=start;i<=end;i++) {
        if (arr[i] < arr[min]) {
            min = i;
        }
    }
    return min;
}