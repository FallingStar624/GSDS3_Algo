#include <iostream>
using namespace std;
int n;
int memo[1000001];
int visit[1000001];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=2; i<=n; i++) {
        memo[i] = memo[i-1]+1;
        visit[i] = i-1;
        if (i%2==0) {
            if (memo[i] > memo[i/2]+1) visit[i] = i/2;
            memo[i] = min(memo[i], memo[i/2]+1);
        }
        if (i%3==0) {
            if (memo[i] > memo[i/3]+1) visit[i] = i/3;
            memo[i] = min(memo[i], memo[i/3]+1);
        }
    }
    cout << memo[n] << endl;
    while (n>0) {
        cout << n << " ";
        n = visit[n];
    }
    return 0;
}
