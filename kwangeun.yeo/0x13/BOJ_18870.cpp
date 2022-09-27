#include <iostream>
#include <algorithm>
using namespace std;

int N;
int coord[1000010];
int coord_sorted[1000010];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> coord[i];
        coord_sorted[i] = coord[i];
    }
    sort(coord_sorted, coord_sorted + N);

    int unique_cnt = 1;
    for (int i = 1; i < N; ++i) {
        if (coord_sorted[i - 1] == coord_sorted[i]) continue;
        coord_sorted[unique_cnt++] = coord_sorted[i];
    }

    for (int i = 0; i < N; ++i) {
        cout << lower_bound(coord_sorted, coord_sorted + unique_cnt, coord[i]) - coord_sorted << ' ';
    }
    return 0;
}