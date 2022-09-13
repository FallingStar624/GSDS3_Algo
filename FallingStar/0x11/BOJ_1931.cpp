#include <iostream>
#include <algorithm>
using namespace std;
int N, W;
int ropes[100001];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> ropes[i];
    }
    sort(ropes, ropes+N, greater<int>());
    W=0;
    for (int i=0; i<N; i++) {
        int tmp = ropes[i];
        W = max(W, (i+1)*tmp);
    }
    cout << W;
    return 0;
}
