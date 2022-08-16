// 1. if x%3==0 -> /3
// 2. if x%2==0 -> /2
// 3. -1
// 1<=N<=10^6을 3가지 연산으로 1 만들기 (D[i]=i to 1) : 연산 횟수 최소값
// + 과정에 포함된 수 순서대로 출력
// DP, BFS 경로 복원

#include <iostream>
#include <algorithm>
using namespace std;

int d[1000001]; // 10^6
int bf[1000001];
int n;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    d[1]=0;
    bf[1]=0;
    // 점화식

    for (int i=2; i<=n; i++){
        // 순서 바뀌면 x
        d[i] = d[i-1]+1;
        bf[i]= i-1;

        if (i%2==0 && d[i]>d[i/2]+1) {
            d[i] = d[i/2]+1;
            bf[i] = i/2;
        }

        if (i%3==0 && d[i]>d[i/3]+1) {
            d[i] = d[i/3]+1; 
            bf[i] = i/3;
        }
    }
    cout << d[n] << '\n';

    while(n){
        if (n==-1) break;
        cout << n << ' ';
        n = bf[n];
    }
    return 0;

} 

// 추가정보 기입하는 테이블 하나 추가
// https://torbjorn.tistory.com/431
