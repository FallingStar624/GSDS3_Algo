/*
문제 : 
동전은 총 N종류
동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 
이때 필요한 동전 개수의 최솟값

Input : 
N과 K(1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)
N개의 줄에 동전의 가치 Ai가 오름차순 (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)

Output : 
K원을 만드는데 필요한 동전 개수의 최솟값
*/

// #include <algorithm>
#include <iostream>
using namespace std;

int N, K; 
int c[12];
int answer = 0;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i=0; i<N; i++){
        cin >> c[i];
    }

    for (int i=N-1; i>=0; i--){
        // int rest = K;
        if (K == 0) break;
        if (c[i] > K) continue;
        else {
            int count = K / c[i];
            answer += count;
            K = K - c[i] * count;
        }
    }

    cout << answer;

    return 0;
}