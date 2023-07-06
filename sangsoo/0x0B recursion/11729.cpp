#include <bits/stdc++.h>
using namespace std;

void func(int n, int a, int b, int c){ // n개 원판 a->b
    if (n > 1){
        func(n-1, a, c, b);
        cout << a  << " " << b << '\n';
        func(n-1, c, b, a);
    }
    else{
        cout << a << " " << b << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << (1<<n) -1 << '\n';
    func(n, 1, 3, 2);
}