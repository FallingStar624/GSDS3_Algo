#include <bits/stdc++.h>
using namespace std;

void func(int a, int b, int n){
    if(n == 1) cout << a << ' ' << b << '\n';
    else{
        func(a, 6-a-b, n-1);
        cout << a << ' ' << b << '\n';
        func(6-a-b, b, n-1);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, n, k;
    cin >> a >> b >> n;
    func(a, b, n);
    cin >> k;
    cout << (1<<k) -1 << '\n';
}