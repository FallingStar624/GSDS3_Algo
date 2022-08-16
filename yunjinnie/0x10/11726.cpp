// 2*n을 1*2, 2*1 타일로 채우는 방법 수%10007
// 1st row: 1<=n<=1000


#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[1000];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>> n;
    d[1]=1;
    d[2]=2;
    for(int i=3; i<=n; i++){
        d[i]= (d[i-1]+d[i-2])%10007;
    }
    cout << d[n];
    
}

// DP: table 정의 -> 점화식 -> 초기값 -> 반복문 돌면서 배열 채우기
// d[n] = d[n-1] (2*1 1개) +d[n-2] (1*2 2개)
// d[1] = 1, d[2] = 2
