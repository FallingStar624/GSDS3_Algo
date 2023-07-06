// 시간 초과
#include <bits/stdc++.h>
using namespace std;


int func(int a, int b, int c){
    int output = 1;
    while (b--){
        output *= (a%c);
        output %= c;
    }
    return output;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    cout << func(a, b, c);
}