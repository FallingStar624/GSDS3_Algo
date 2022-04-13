#include <iostream>

using namespace std;

int occur[2][6];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int K;

    cin >> N >> K;

    int arr[N][2];

    for(int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    int answer = 0;
    for(int i = 0; i < N; i++) {

        if(occur[arr[i][0]][arr[i][1] - 1] >= K) {
            occur[arr[i][0]][arr[i][1] - 1] = 0;
            answer++;
        }

        occur[arr[i][0]][arr[i][1] - 1]++;
        
        
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 6; j++) {
            if(occur[i][j]) {
                answer++;
            }
        }
    }
    
    cout << answer;


    return 0;
}