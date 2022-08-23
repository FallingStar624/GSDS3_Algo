#include <iostream>
using namespace std;

/*
좀 병맛인게.. 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 -> 이거를 써줘야 통과함... 
algorithm
 누적합으로 시간 줄여야함.
 dp[i] = dp[i-1] + arr[i];

*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int arr[100002];
    int a, b, ans;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    int dp[100002];
    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = dp[1]+arr[2];
    for(int i = 3; i <= N; i++){
        dp[i] = dp[i-1] + arr[i];
    }
    for(int i = 0; i < M; i++){
        // a = 0, b = 0; ans = 0; // initialize
        cin >> a >> b;
        // cout << "dp[" << b << "] = " << dp[b] << endl;
        // cout << "dp[" << a-1 << "] = " << dp[a-1] << endl;
        ans = dp[b] - dp[a-1];
        cout << ans << '\n';
    }
}