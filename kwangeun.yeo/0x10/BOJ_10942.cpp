#include <iostream>
using namespace std;

int N, M;
int nums[2002];
bool D[2002][2002];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> nums[i];
    }

    for (int len = 1; len <= N; ++len) {
        for (int s = 1; s <= N; ++s) {
            int e = s + len - 1;
            if (e > N) break;
            if (len == 1) D[s][e] = true;
            else if (len == 2) D[s][e] = (nums[s] == nums[e]);
            else {
                D[s][e] = D[s + 1][e - 1] && (nums[s] == nums[e]);
            }
        }
    }

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int s, e;
        cin >> s >> e;
        cout << (D[s][e] ? 1 : 0) << '\n';
    }
    return 0;
}