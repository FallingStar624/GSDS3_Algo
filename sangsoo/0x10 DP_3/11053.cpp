/*
algorithm
dp[i]는 수열 i번째 값을 마지막으로 하는 가장 긴 증가하는 부분 수열이다.
dp[i] 값을 구하기 위해서는 첫 번째 값부터 i-1번째 값(j)까지를 검사한다.
먼저 dp 배열은 자기 자신을 부분수열로 하면 최소길이가 1이므로 1로 초기화

1. j번 수열의 값이 i번 수열의 값보다 작고
2. dp[j]의 값은 현재 dp[i] 보다 같거나 커야한다.

*/

#include <iostream>
using namespace std;

int arr[1002];
int dp[1002];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >>n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i = 0 ; i < n; i++){
        //initialize 1
        dp[i] = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            // j번째 값이 i번째 값보다 작아야하고
            // dp값이 현재 가진 값보다 같거나 커야한다.
            if(arr[j] < arr[i] && dp[j] >= dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
    }

    int ans = 0;
    for(int i = 0 ; i < n; i++){
        if(ans < dp[i]) ans = dp[i];
    }

    cout << ans;
}
