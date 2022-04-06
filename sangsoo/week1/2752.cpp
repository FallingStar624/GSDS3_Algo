#include <iostream>
using namespace std;
int a, b, c;
int main(){
    cin >> a >> b >> c;
    if(a > b && a > c){
        if(b >c) cout << c << " " << b << " " << a ;
        else cout << b << " " << c << " " <<a;
    }
    if(b > c && b > a){
        if(a > c) cout << c << " " << a << " " << b;
        else cout << a << " " << c << " " <<b;
    }
    if(c > b && c > a){
        if(b > a) cout << a << " " << b << " " << c;
        else cout << b << " " << a << " " << c;
    }
}