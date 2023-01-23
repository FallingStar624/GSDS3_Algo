#include <iostream>

using namespace std;

int d[41][2];

/*
1. 테이블 정하기
d[i][k] = 숫자 i가 k(0 or 1)를 호출한 횟수
2. 점화식 찾기
d[i][k] = d[i - 1][k] + d[i - 2][k]
3. 초기값 정하기
d[0][0] = 1, d[1][1] = 1
*/

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    d[0][0] = 1;
    d[1][1] = 1;

    for(int i = 2; i <= 40; i++) {
        d[i][0] = d[i-1][0] + d[i-2][0];
        d[i][1] = d[i-1][1] + d[i-2][1];
    }

    while(t--) {
        int n;
        cin >> n;
        cout << d[n][0] << " " << d[n][1] << '\n';
    }
 
    return 0;
}