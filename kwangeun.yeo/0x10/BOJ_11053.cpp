#include <iostream>
using namespace std;

int nums[1002];
int D[1002];
int N;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
        D[i] = 1;
    }
    int ret = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] <= nums[j]) continue;
            D[i] = max(D[i], D[j] + 1);
        }
        ret = max(ret, D[i]);
    }
    cout << ret;

    return 0;
}