#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin >> n;
    int d = 2;
    if (n == 1) return 0;
    while(n != 1){
        while (n % d == 0){
            n /= d;
            cout << d << '\n';
        }
        d += 1;
    }
}