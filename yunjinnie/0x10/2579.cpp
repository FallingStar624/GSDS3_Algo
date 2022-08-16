// 1 step or 2 steps
// 1-1-1은 안됨, 시작점 포함 x, 도착점 포함
// 1st row: # of stairs <300
// 2nd row~: score

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int s[301];
int d[301][3];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> s[i];
    }
    d[1][1]=s[1];
    d[1][2]=0; // 실제로는 불가능, for default
    d[2][1]=s[2];
    d[2][2]=s[1]+s[2];

    if(n==1) {
        cout<<s[1];
        return 0; // 없으면 에러
    }
    for (int i=3; i<=n; i++){
        d[i][1] = max(d[i-2][1], d[i-2][2]) + s[i];
        d[i][2] = d[i-1][1]+s[i];
    }

    cout<<max(d[n][1], d[n][2]);
    return 0;

}

// DP: table 정의 -> 점화식 -> 초기값 -> 반복문 돌면서 배열 채우기
// D[1]=10, D[2]=20, D[3]=15 -> 1-1-1 제한 조건 투입 불가
// D[i][j] ... j개 연속(1이라면 i-2번째 계단 밟음, 2라면 i-1번째 계단 밟음), i번째 계단 (i는 반드시)
// D[n][1] = max(D[n-2][1], D[n-2][2]) + score[n]
// D[n][2] = D[n-1][1] + score[n] -> 연속해서 3개는 안됨


// 1차원으로도 풀 수 있음 -> 밟지 않을 계단의 합을 최소화