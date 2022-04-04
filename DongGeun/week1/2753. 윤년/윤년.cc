#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a;
    cin >> a;
    if(a % 4 == 0)
    {
        if(a % 400 == 0)
            cout << 1;
        else if(a % 100 == 0)  
            cout << 0;
        else  
            cout << 1;  
    }
    else  cout << 0;
}