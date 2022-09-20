#include <iostream>
using namespace std;

int main(){
    int N, K, tmp;
    cin >> N >> K;
    int coin_arr[12] = {0,};
    int num_arr[12] = {0,};
    for(int i=0; i<N; i++){
        cin >> coin_arr[i];
    }
    tmp = K;
    for (int i = N-1; i >= 0 ; i--){
        if(tmp >= coin_arr[i]){
            num_arr[i] = tmp/coin_arr[i];
            tmp -= num_arr[i]*coin_arr[i];
        }
    }
    int out = 0;
    for(int i = 0; i < N; i++){
        out += num_arr[i];
    }
    cout << out;
}