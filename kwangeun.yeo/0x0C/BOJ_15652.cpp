#include <iostream>

using namespace std;

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

    for (int num = prev; num <= N; ++num) {
        nums[idx] = num;
        func(idx + 1, num);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    func(0, 1);

    return 0;
}