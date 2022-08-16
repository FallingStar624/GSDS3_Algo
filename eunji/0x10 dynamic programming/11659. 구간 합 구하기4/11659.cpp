/*
문제 : 
수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램

Input : 
1 ≤ N ≤ 100,000
1 ≤ M ≤ 100,000
1 ≤ i ≤ j ≤ N

Output : 
총 M개의 줄에 입력으로 주어진 i번째 수부터 j번째 수까지 합
*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int N, M;
int D[100002];
int input[100002];
int answer[100002];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i=1; i<=N; i++){
        cin >> input[i];
    }    

    D[0] = 0;
    D[1] = input[1];
    for (int i=2; i<=N; i++){
        D[i] = D[i-1] + input[i];
    }

    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        answer[i] = D[b]-D[a-1];
    }

    for (int i=0; i<M; i++) {
        cout << answer[i] << '\n';
    }    

    return 0;
}