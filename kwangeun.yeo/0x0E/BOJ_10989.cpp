#include <iostream>
using namespace std;

int nums[10001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        nums[tmp]++;
    }
    for (int i = 1; i <= 10000; ++i) {
        for (int j = 0; j < nums[i]; j++) {
            cout << i << '\n';
        }
    }
    return 0;
}