// color: 1=/=2, N=/=N-1, i-1=/=i, i=/=i+1
// 1st row: # of house 2<=N<=1000
// 2nd row~: R / G / B cost <=1000
// min of cost

#include <iostream>
#include <algorithm>
// #include <bits/stdc++.h>
using namespace std;

int d[1001][3];
int n;
int r[1001], g[1001], b[1001];


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>> n;
    for (int i=0; i<n; i++){ // 0 ~ n-1 -> 0?
        cin>> r[i] >> g[i] >> b[i];
    }

    d[0][0]=r[0];
    d[0][1]=g[0];
    d[0][2]=b[0];

    for (int i=1; i<n; i++){
        d[i][0]=min(d[i-1][1], d[i-1][2])+r[i];
        d[i][1]=min(d[i-1][0], d[i-1][2])+g[i];
        d[i][2]=min(d[i-1][0], d[i-1][1])+b[i];
    }
    cout << min({d[n-1][0], d[n-1][1], d[n-1][2]}); // {} 없으면 에러

}

// DP: table 정의 -> 점화식 -> 초기값 -> 반복문 돌면서 배열 채우기
// D[i][3]: i번째 집까지 칠할 때 최소 비용, color of i=0 -> R, i=1 -> G, u=2 -> B
// D[n][0]=min(D[n-1][1], D[n-1][2])+R[n]
// D[n][1]=min(D[n-1][0], D[n-1][2])+G[n]
// D[n][2]=min(D[n-1][0], D[n-1][1])+B[n]
// D[1][0]=R[1], D[1][1]=G[1], D[1][2]=B[1]
