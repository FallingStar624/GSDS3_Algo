// pinary number : 0으로 시작 x (1로 시작)
// 1이 두 번 연속으로 나타나지 x (11 x)
// ex. 1, 10, 101, 1000, 1001
// 1st row : 1<=N<=90 -> 최대 90자리, long long
// n자리 pn

#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long d[91];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    d[1] = 1;
    d[2] = 1;
    for (int i=3; i<=n; i++) d[i] = d[i-1]+d[i-2];

    cout<< d[n];
    return 0;

}

// DP: table 정의 -> 점화식 -> 초기값 -> 반복문 돌면서 배열 채우기
// d[1] = 1
// d[2] = 1
// d[3] = 2
// d[4] = 1000, 1001, 1010 = 3
// d[5] = 10000, 10001, 10010, 10100, 10101 = 5
// d[n] = d[n-1]+d[n-2]