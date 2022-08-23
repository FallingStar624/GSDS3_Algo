// 수열 A의 ascending subset에서 maxsum 구하기
// 1st row: 1<=N<=1000
// 2nd row: 1<=num<=1000

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[1002];
int num[1002];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>num[i];
        d[i] = num[i];
    }
    int s = 0;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=i; j++){
            if (num[j]<num[i]) //continue;
            d[i] = max(d[j]+num[i], d[i]); // num[i]는 안되는 이유?
            //s += d[i];
        }
        if (d[i]>s) s = d[i];
    }

    cout << s;
    return 0;
}

// DP: table 정의 -> 점화식 -> 초기값 -> 반복문 돌면서 배열 채우기
// d[i] = max(d[i-1]+d[i], d[i])
// 11053
// https://yabmoons.tistory.com/87