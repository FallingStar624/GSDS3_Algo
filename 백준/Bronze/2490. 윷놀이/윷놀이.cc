#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a,b,c,d;
    for(int r = 0; r < 3; r++) {
        cin>>a>>b>>c>>d;
        int sum = a+b+c+d;
        switch(sum)
        {
            case 0:
                cout<<"D\n";
                break;
            case 1:
                cout<<"C\n";
                break;
            case 2:
                cout<<"B\n";
                break;
            case 3:
                cout<<"A\n";
                break;
            case 4:
                cout<<"E\n";
                break;
        }
    }
    
}