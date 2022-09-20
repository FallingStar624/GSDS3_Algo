#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[52];
int B[52];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    sort(A, A + N);
    sort(B, B + N, greater<int>());
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += (A[i] * B[i]);
    }
    cout << sum;

    return 0;
}