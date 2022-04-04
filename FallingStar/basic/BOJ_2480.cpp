#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a==b and b==c) cout << 10000+a*1000;
    else if (a==b) cout << 1000+a*100;
    else if (b==c) cout << 1000+b*100;
    else if (c==a) cout << 1000+c*100;
    else cout << max(a,(max(b,c)))*100;
}

