#include <iostream>

using namespace std;

bool is_used[10];
int nums[10];
int N, M;

void func(int idx, int prev) {
    if (idx >= M) {
        for (int i = 0; i < M; ++i) {
            cout << nums[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int num = prev + 1; num <= N; ++num) {
        if (is_used[num]) continue;
        is_used[num] = true;
        nums[idx] = num;
        func(idx + 1, num);
        is_used[num] = false;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    func(0, 0);

    return 0;
}