// root에서 leaf까지의 합이 최대인 경로
// 1st row: 1<=n<=500
// 2nd row~ n+1th row: int

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int maxVal;//=0;
int d[501][501];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n;
    // for문 2개로 cin
    // 다시 for문 2개 + if : leftmost, else if : mid, else: rightmost
    for (int i=0; i<n; i++){ // for row
        for (int j=0; j<=i; j++){ // for ith row
            cin>>d[i][j];
        }
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<=i; j++){
            if (j==0) d[i][j] = d[i][j] + d[i-1][j];
            else if (j==i) d[i][j] = d[i-1][j-1] + d[i][j];
            else d[i][j] = d[i][j] + max(d[i-1][j-1], d[i-1][j]);

            maxVal = max(maxVal, d[i][j]); // not with declaration (for문 밖에서)
        }
    }

    cout << maxVal;
    return 0;
}

// DP: table 정의 -> 점화식 -> 초기값 -> 반복문 돌면서 배열 채우기
// d[0][0] = 7
// d[1][0] = 3+7, d[1][1] = 8+7
// d[2][0] = 8+d[1][0], d[2][1] = 1+max(d[1][0], d[1][1]), d[2][2] = 0+d[1][1]
// ...
// https://gaeunhan.tistory.com/67