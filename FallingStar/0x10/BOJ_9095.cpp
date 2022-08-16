#include <iostream>
using namespace std;
int tc, n;
int memo[12];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i=0; i<11; i++) {
        if (i==0) {memo[i]=1; continue;}
        if (i==1) {memo[i]=1; continue;}
        if (i==2) {memo[i]=2; continue;}
        memo[i] = memo[i-2] + memo[i-1] + memo[i-3];
    }
    cin >> tc;
    for (int t=0; t<tc; t++) {
        cin >> n;
        cout << memo[n] << endl;
    }

    return 0;
}
