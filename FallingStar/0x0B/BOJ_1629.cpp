#define ll long long
#include <iostream>

using namespace std;
ll A, B, C;


ll recur(ll b) {
    if (b==0) return 1;
    if (b==1) return A%C;
    ll half = recur(b/ (ll)2)%C;
    if (b%2 == 0) {
        return (half%C*half%C)%C;
    } else {
        return (half%C*half%C*A%C)%C;
    }
}

int main() {
    cin >> A >> B >> C;
    cout << recur(B)%C;
    return 0;
}
