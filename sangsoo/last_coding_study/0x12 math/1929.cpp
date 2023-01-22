#include <iostream>
using namespace std;

bool isprime(int n){
    if (n == 1) return false;
    for(int i = 2; i*i <= n; i++){
        if (n%i == 0){
            return false;
        }
    }
    return true;
};

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = n; i <= m; i++){
        if(isprime(i)) cout << i << '\n';    
    }
}