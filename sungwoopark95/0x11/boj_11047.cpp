#include <iostream>
using namespace std;

int N, K, answer;
int coins[12];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> K;
    for (int i=1;i<=N;i++) { cin >> coins[i]; }
    
    for (int i=N;i>=1;i--) {
        if (coins[i] <= K) {
            // 맨 처음 만나게 되는 동전은 K보다 작거나 같은 가장 큰 가치를 가진 동전
            while (K >= coins[i]) {
                answer++;
                K -= coins[i];
            }
        }
        else { continue; }
    }

    cout << answer << "\n";
    
    return 0;
}