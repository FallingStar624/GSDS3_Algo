#include <iostream>
#include <vector>

using namespace std;

vector<int> sieve(int n){
    vector<int> primes;
    vector<bool> state(n+1, true);
    state[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(!state[i]) continue; // 소수가 아니면 지나감
        for(int j = i*i ; j <= n; j += i){ // j는 i*i 부터 i의 배수를 모두 false로 바꾼다. 5와 25 사이에 10 15 20이 있지만 이미 이전에 2 3 4로 체크함
            state[j] = false;
        }
    }
    for(int i = 2; i <= n; i++){
        if(state[i]) primes.push_back(i);
    }
    return primes;
}