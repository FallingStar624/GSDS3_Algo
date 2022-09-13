/*
문제 : 
수열에서 가장 긴 증가하는 부분 수열 구하기

Input : 
수열 A의 크기 N (1 ≤ N ≤ 1,000)
수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

Output : 수열 A의 가장 긴 증가하는 부분 수열의 길이
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[1002];
int d[1002]; // 각 칸이 마지막일때, 가장 긴 증가하는 부분 수열의 길이

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i]; 
    }

    d[0] = 1;
    for (int i=1; i<N; i++){
        d[i] = 1;
        for (int j=i-1; j>=0; j--){
            if (A[i] > A[j] && d[j]+1 > d[i]) {
                d[i] = d[j] + 1;
            }
        }
    }

    int answer = 0;
    for (int i=0; i<N; i++){
        // cout << d[i] << ' '; // for test
        if (answer < d[i]) answer = d[i];
    }
    cout << answer;

    return 0;
}