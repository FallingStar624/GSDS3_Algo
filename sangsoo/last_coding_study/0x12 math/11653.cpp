#include <iostream>

using namespace std;    

int main(){
    int n;
    cin >> n;
    int N = n;
    int tmp = 0;
    for (int i = 2; i<=n; i++){
        while(N % i == 0){
            N /= i;
            cout << i << '\n';
            tmp++;
        }
    }
    if(tmp == 0 && n != 1) cout << n;
}