#include <iostream>

using namespace std;


/*
1. d[N][i] N자리 이친수 중에서 i(0 or 1)로 끝나는 개수
2. d[N] = d[N-1]

0로 끝 -> 0 또는 1 붙임
1로 끝 -> 1 붙임

3. 초기값
d[1] = 1
d[2] = 1

*/

long long d[92][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    d[1][0] = 0;
    d[1][1] = 1;

    for(int i = 2; i <= n; i++) {
        d[i][0] = d[i-1][0] + d[i-1][1];
        d[i][1] = d[i-1][0];
    }

    cout << d[n][0] + d[n][1];

    return 0;
}