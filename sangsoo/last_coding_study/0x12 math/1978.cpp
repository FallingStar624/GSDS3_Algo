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
    int N;
    cin >> N;
    int cnt = 0;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        if(isprime(num)) cnt++;
    }
    cout << cnt;
}