#include <iostream>
#include <algorithm>

using namespace std;

int N;
int U[1010];
int two[1000 * 1000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> U[i];
    }
    int idx = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            two[idx++] = U[i] + U[j];
        }
    }
    sort(two, two + idx);
    int max_num = -1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int target = U[i] - U[j];
            if (binary_search(two, two + idx, target)) {
                max_num = max(max_num, U[i]);
            }
        }
    }
    cout << max_num;

    return 0;
}