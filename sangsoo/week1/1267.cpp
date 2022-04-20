#include <iostream>
using namespace std;

int n;
int Y = 0;
int M = 0;
int arr[20];
int main(){
    cin >> n;
    for(int i = 0; i<n ; i++){
        cin >> arr[i];
    }
    for(int i =0 ; i<n ; i++){
        Y += (arr[i]/30+1)*10;
        M += (arr[i]/60+1)*15;
    }
    if(Y<M) cout << "Y " << Y;
    else if(Y>M) cout << "M " << M;
    else if(Y==M) cout << "Y M " << Y;
    return 0;
}