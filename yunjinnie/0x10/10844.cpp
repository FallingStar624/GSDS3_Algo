// 계단수: 인접한 모든 자리 수 간격 = 1
// 1st row: 1<=N<=100

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[102][10]; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    
    d[1][0]=0;
    for (int i=1; i<=9; i++){
        d[1][i] = 1;
    }

    for (int i=2; i<=n; i++){
        for (int j=0; j<=9; j++){
            d[i][j] = 0;
            if (j==0) d[i][j] = 1;
            else ;
        }
    }

    long long val=0;
    for (int i=0; i<10; i++){
        val += d[n][i]%1000000000;
    }
    cout<<val%1000000000;
    return 0;
}

// DP: table 정의 -> 점화식 -> 초기값 -> 반복문 돌면서 배열 채우기
// 1 : 1-9 -> 9 (0 1 ... 1)
// 2 : 10, 12, 21, 23 ... 98 -> 17 (1 1 2 ... 2 1)
// 3 : 101, 121, 123, ... 끝자리에 따라 앞자리 경우 정해짐
// d[n][0-9]