#include <iostream>
#include <algorithm>

using namespace std;

bool is_used[10];
int nums[10];
int res[10];
int N, M;

void func(int idx, int prev_idx) {
    if (idx >= M) {
        for (int i = 0; i < M; ++i) {
            cout << res[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = prev_idx + 1; i < N; ++i) {
        if (is_used[i]) continue;
        is_used[i] = true;
        res[idx] = nums[i];
        func(idx + 1, i);
        is_used[i] = false;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    sort(nums, nums + N);
    func(0, -1);

    return 0;
}