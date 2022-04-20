#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
int n, x;
int arr[100005];
char chk[MAX + 5];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        chk[arr[i]]++;
    }
    cin >> x;

    int pairs = 0;
    for (int i = 0; i < n; ++i) {
        int pair = x - arr[i];
        if (pair > 0 && pair <= MAX && pair != arr[i] && chk[pair]) {
            pairs++;
        }
    }
    cout << pairs / 2;

    return 0;
}