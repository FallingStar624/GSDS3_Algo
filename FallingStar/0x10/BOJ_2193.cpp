#include <iostream>
using namespace std;
int n;
long long zero[91];
long long one[91];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    zero[2]=1, one[1]=1;
    for (int i=3; i<=90; i++) {
        zero[i] = zero[i-1] + one[i-1];
        one[i] = zero[i-1];
    }
    cin >> n;
    cout << zero[n]+one[n];
    return 0;
}
