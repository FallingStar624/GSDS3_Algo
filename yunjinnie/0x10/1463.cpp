// 1. if x%3==0 -> /3
// 2. if x%2==0 -> /2
// 3. -1
// 1<=N<=10^6을 3가지 연산으로 1 만들기 (D[i]=i to 1) : 연산 횟수 최소값
// BFS: dist 배열 -> 초기값 1


#include <iostream>
#include <algorithm>
using namespace std;

int d[1000000];
int n;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    d[1]=0;
    // 점화식
    for (int i=2; i<=n; i++){
        // 순서 바뀌면 x
        d[i] = d[i-1]+1;
        if (i%2==0) d[i] = min(d[i], d[i/2]+1);
        if (i%3==0) d[i] = min(d[i], d[i/3]+1); 
        // else if 틀림-> 무조건 두 if문 모두 통과해야 함: https://okky.kr/article/209530
        // d[i] = min(d[i], d[i-1]+1);
    }
    cout << d[n];

}

// DP: table 정의 -> 점화식 -> 초기값 -> 반복문 돌면서 배열 채우기
// 점화식: D[n] = min(D[n/3]+1, D[n/2]+1, D[n-1]+1)
// 초기값: D[1] = 0
