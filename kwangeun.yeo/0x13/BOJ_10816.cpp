#include <iostream>
#include <algorithm>
using namespace std;

int card[500010];

int UpperIndex(int target, int N) {
    int st = 0;
    int en = N;
    while (st < en) {
        int mid = (st + en) / 2;
        if (card[mid] > target) en = mid;
        if (card[mid] <= target) st = mid + 1;
    }
    return st;
}

int LowerIndex(int target, int N) {
    int st = 0;
    int en = N;
    while (st < en) {
        int mid = (st + en) / 2;
        if (card[mid] < target) st = mid + 1;
        if (card[mid] >= target) en = mid;
    }
    return st;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> card[i];
    }
    sort(card, card + N);

    int M;
    cin >> M;
    int target;
    for (int i = 0; i < M; ++i) {
        cin >> target;
        cout << UpperIndex(target, N) - LowerIndex(target, N) << '\n';
    }
    return 0;
}