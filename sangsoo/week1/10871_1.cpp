#include <iostream>
using namespace std;
int a = 0, b = 0, c = 0;

int main(){
    cin >> a >> b;
    for (int i = 1; i <= a; i++){
        cin >> c;
        if(c<b)
        cout << c << " ";
    }
}