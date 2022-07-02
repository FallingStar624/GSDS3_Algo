#include <iostream>

using namespace std;

int N, S;
int cnt;
int nums[22];

void func(int idx, int sum) {
    if (idx >= N) {
        if (sum == S) cnt++;
        return;
    }

    func(idx + 1, sum);
    func(idx + 1, sum + nums[idx]);
}

int main() {
    freopen("input.txt", "r", stdin);
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> S;
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    cnt = (S == 0) ? -1 : 0;
    func(0, 0);
    cout << cnt;

    return 0;
}