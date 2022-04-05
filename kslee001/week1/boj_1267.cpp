#include <iostream>
using namespace std;

int main(){
    int n; cin>> n;
    int temp;

    int M=0; int Y=0;

    for(int i=0; i<n; ++i){
        cin >>temp;
        Y += 10* (temp/30 + 1);
        M += 15*(temp/60 +1);
    }

    if(Y==M){
        cout << "Y M "<< Y;
    }
    else if (Y<M){
        cout << "Y " << Y;
    }
    else
        cout << "M "<< M;
}