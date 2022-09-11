#include <iostream>
using namespace std;

// boj_15486과 비슷하게 문제를 formulate

int N, K;
int arr[105][100005]; // i번째의 가방을 선택했을 때, 무게 j에서의 최대 가치
int weight[105]; // i번째 가방을 선택했을 때의 무게
int value[105]; // i번째 가방을 선택했을 때의 가치

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> K;
    for (int i=1;i<=N;i++) {
        cin >> weight[i] >> value[i];
    }
    
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=K;j++) { 
            // i번째 가방을 선택할지 말지 
            if (weight[i] <= j) {
                if (value[i]+arr[i-1][j-weight[i]] > arr[i-1][j]) { // i번째 가방을 선택할 때 -> 
                    arr[i][j] = value[i]+arr[i-1][j-weight[i]];
                } else { // i번째 가방을 선택하지 않았을 때
                    arr[i][j] = arr[i-1][j];
                }
            } else {
                arr[i][j] = arr[i-1][j];
            }
        }
    }
    
    cout << arr[N][K] << "\n";
    
    return 0;
}