#include <iostream>
using namespace std;


int main(){
    char s = '*'; char b = ' ';
    int c;
    int n; cin>>n;

    for(int i=0; i<n; ++i){
        c = n-i;
        for(int j=0; j<c-1; ++j) cout << b;
        for(int j=0; j<=n-c; ++j) cout << s;
        for(int j=0; j<i; ++j) cout << s;
        // for(int j=0; j<=n-c; ++j) cout << b;

        if(i!=n-1) cout << "\n";

    }


}