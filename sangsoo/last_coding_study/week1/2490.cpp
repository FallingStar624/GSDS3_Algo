#include <iostream>
using namespace std;

int a,b,c,d;
int main(){
    for(int i = 0; i <3; i++){
    cin >> a >> b >> c >> d;
    if(a+b+c+d ==1) cout <<"C\n";
    if(a+b+c+d ==2) cout <<"B\n";
    if(a+b+c+d ==3) cout <<"A\n";
    if(a+b+c+d ==4) cout <<"E\n";
    if(a+b+c+d ==0) cout <<"D\n";
    }
}
