#include <iostream>
using namespace std;

int n, m;
int arr[100001];
int dp [100001];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >>n>>m;
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }
    dp[0] = arr[0];
    // dp[i] = dp[i-1] + arr[i];
    // dp[2] = 1까지의 구간합 + arr[2]
    // x1부터 x2까지의 구간합 : x2까지의 구간합 - "x1-1"까지의 구간합
    // ex. 5 4 3 2 1 |  3부터 5까지의 구간합? (5+4+3+2+1) - (5+4)
    for(int i=1; i<n; ++i){
        dp[i] = dp[i-1] + arr[i];
    }

    for(int i=0; i<m; ++i){
        int a,b; cin >>a>>b;
        --a; --b; // index 크기 맞추기 위함
        cout << dp[b] - dp[a-1] <<"\n";
    }

}