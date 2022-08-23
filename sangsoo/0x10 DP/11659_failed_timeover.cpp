#include <iostream>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int arr[100002];
    int a, b, ans;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < M; i++){
        a = 0, b = 0; ans = 0; // initialize
        cin >> a >> b;
        for(int j = a; j <= b; j++){
            ans += arr[j];
        }
        cout << ans << '\n';
    }
}