#include <iostream>
using namespace std;

int N;
int arr[1000010];
int tmp[1000010];

void Merge(int s, int e) {
    int m = (s + e) / 2;
    int l_i = s, r_i = m;
    for (int i = s; i < e; ++i) {
        if (r_i >= e) tmp[i] = arr[l_i++];
        else if (l_i >= m) tmp[i] = arr[r_i++];
        else if (arr[l_i] <= arr[r_i]) tmp[i] = arr[l_i++];
        else tmp[i] = arr[r_i++];
    }
    for (int i = s; i < e; ++i) arr[i] = tmp[i];
}

void MergeSort(int s, int e) {
    if (e == s + 1) return;
    int m = (s + e) / 2;
    MergeSort(s, m);
    MergeSort(m, e);
    Merge(s, e);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    MergeSort(0, N);
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << '\n';
    }

    return 0;
}