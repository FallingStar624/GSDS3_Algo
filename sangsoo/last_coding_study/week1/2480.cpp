#include <iostream>
using namespace std;

int a, b, c;
int main(){
    cin >> a >> b >> c;
    if(a == b && b ==c)  cout << 10000+a*1000;
    if(a == b && b !=c)  cout << 1000+ a*100;
    if(b == c && b !=a)  cout << 1000+ b*100;
    if(c == a && c !=b)  cout << 1000+ a*100;
    if(a != b && b != c && c !=a){
        if (a>b && a>c) cout << a*100;
        if (b>a && b>c) cout << b*100;
        if (c>a && c>b) cout << c*100;
    }
}