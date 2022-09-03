#include <iostream>
using namespace std;
int N, K;
int cnt=0;
int money[11];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    for (int i=1; i<N+1; i++) {
        cin >> money[i];
    }
    while (K>0) {
        cnt += K/(money[N]);
        K %= money[N];
        N--;
    }
    cout << cnt;
    return 0;
}
