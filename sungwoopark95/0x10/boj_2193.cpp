#include <iostream>
using namespace std;

int N;
long long cnt[93][2];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    cnt[1][0] = 0; cnt[1][1] = 1;
    cnt[2][0] = 1; cnt[2][1] = 0;
    cnt[3][0] = 1; cnt[3][1] = 1;
    
    for (int i=4;i<=N;i++) {
        cnt[i][0] = cnt[i-1][0] + cnt[i-2][0];
        cnt[i][1] = cnt[i-1][1] + cnt[i-2][1];
    }
    
    cout << cnt[N][0] + cnt[N][1] << "\n";
    
    return 0;
}