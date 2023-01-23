#include <iostream>
#include <algorithm>

using namespace std;

int scores[305];
int n;
int d[305][3]; // j개의 계단을 연속해서 밟고 i번째 계단까지 올라섰을 때 점수 합의 최댓값


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> scores[i];
    }
    if(n == 1) {
        cout << scores[1];
        return 0;
    }
    d[1][1] = scores[1];
    d[1][2] = 0;
    d[2][1] = scores[2];
    d[2][2] = scores[1] + scores[2];
    for(int i = 3; i <= n; i++) {
        d[i][1] = max(d[i-2][1], d[i-2][2]) + scores[i];
        d[i][2] = d[i-1][1] + scores[i];
    }
    cout << max(d[n][1], d[n][2]);


    return 0;
}