#include <iostream>

using namespace std;
int N, M;
bool chk[10];
int nums[10];

void func(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < cnt; ++i) {
            cout << nums[i] << ' ';
        }
        cout << '\n';
    }

    for (int num = 1; num <= N; ++num) {
        if (chk[num]) continue;
        chk[num] = true;
        nums[cnt] = num;
        func(cnt + 1);
        chk[num] = false;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    func(0);

    return 0;
}