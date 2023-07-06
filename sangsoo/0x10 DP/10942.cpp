#include <bits/stdc++.h>
using namespace std;

int arr[2002];
int dp[2002][2002];
int N, S, E, M;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cin >> M;
    // 길이가 1인 경우
    for (int i = 0; i < N; i++){
        dp[i][i] = 1;
        // 길이가 2인 경우
        if(i != 0)
            if(arr[i] == arr[i-1])
                dp[i-1][i] = 1;
    }

    // 길이가 3이상인 경우
    for (int i = 0; i < N; i++){  // 수열의 길이 i 
        for (int j = 0; j < N-i; j++){ // 수열의 시작점 j
            if(arr[j] == arr[j+i] && dp[j+1][j+i-1] == 1){
                dp[j][j+i] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++){
        cin >> S >> E;
        cout << dp[S-1][E-1] << '\n';
    }
    return 0;
}