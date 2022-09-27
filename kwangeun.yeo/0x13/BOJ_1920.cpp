#include <iostream>
#include <algorithm>
using namespace std;

int A[100010];

int BinarySearch(int target, int len) {
    int st = 0;
    int en = len - 1;
    while (st <= en) {
        int mid = (st + en) / 2;
        if (A[mid] == target) return 1;
        if (A[mid] > target) en = mid - 1;
        else if (A[mid] < target) st = mid + 1;
    }
    return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A, A + N);
    
    int M;
    cin >> M;
    int target;
    for (int i = 0; i < M; ++i) {
        cin >> target;
        cout << BinarySearch(target, N) << '\n';
    }

    return 0;
}