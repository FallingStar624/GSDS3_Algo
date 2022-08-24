#include <iostream>
using namespace std;

/*
0 ~ 10까지 찍어봤을 때의 결과
1 0
0 1
1 1
1 2
2 3
3 5
5 8
8 13
13 21
21 34
34 55
-> cnt[i][0]은 1번째부터, cnt[i][1]은 0번째부터 시작되는 피보나치 수열
-> 피보나치 수열 2개 만드는 문제
*/

int T;
int N;
int cnt[100][2];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> T;
    
    cnt[0][0] = 1, cnt[0][1] = 0;
    cnt[1][0] = 0, cnt[1][1] = 1;
    cnt[2][0] = 1, cnt[2][1] = 1;
    while(T--) {
        cin >> N;
        for (int i=3;i<=N;i++) {
            cnt[i][0] = cnt[i-1][0] + cnt[i-2][0];
            cnt[i][1] = cnt[i-1][1] + cnt[i-2][1];
        }
        cout << cnt[N][0] << " " << cnt[N][1] << "\n";
    }
    
    return 0;
}