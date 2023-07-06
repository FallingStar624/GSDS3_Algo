// 메모리 초과
#include <bits/stdc++.h>
using namespace std;


int func(int a, int b, int c){
    if (b == 1){
        return a%c;
    }
    else
        return (func(a, b-1, c) * func(a, 1, c))%c;
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << func(a, b, c);
}