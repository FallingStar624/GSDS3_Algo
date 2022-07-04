#include <iostream>
#define MAX 20
using namespace std;

int N, S;
int seq[MAX];
int sum = 0;
int cnt = 0; // 경우의 수

void func(int cur, int sum) {
    // sum: 현재까지의 합
    // cur: 전체 수열에서 현위치
    if (cur == N) { // 주어진 수열을 모두 사용한 경우
        if (sum == S) { cnt++; }
        return;
    }
    func(cur+1, sum); // 현재 sequence 값을 더하지 않은 경우
    func(cur+1, sum+seq[cur]); // 현재 sequence 값을 더한 경우
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> S;
    for (int i=0;i<N;i++) {
        cin >> seq[i];
    }
    func(0, 0);
    if (S == 0) { cnt--; } // 공집합인 하나의 경우를 제외 -> 1만 빼주는 작업으로
    cout << cnt;
    
    return 0;
}