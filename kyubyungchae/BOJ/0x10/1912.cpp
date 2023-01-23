#include <iostream>
#include <algorithm>

using namespace std;

/*
1. d[i] i 번째까지 연속된 수의 합 중 최대값
2. d[i] = max(d[i], d[i-1] + arr[i])
*/

int d[100001];
int arr[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        d[i] = arr[i];
    }

    for(int i = 1; i <= n; i++) {
        d[i] = max(d[i], d[i-1] + arr[i]);
    }

    cout << *max_element(d + 1, d + n + 1);

    return 0;
}

