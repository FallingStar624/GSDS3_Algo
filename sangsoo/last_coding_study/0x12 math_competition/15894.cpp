#include <iostream>
using namespace std;

int arr[123460];

int out(int x){
    int cnt = 0;
    for(int i=x; i<2*x; i++){
        if(arr[i]) cnt++;
    }
    return cnt;
}

int main(){
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    for(int i = 4; i < 12457; i++){
        for(int j = 2; j*j <= i; j++){
            if(i % j == 0){
                arr[i] = 0;
                break;
            }
            else{
                arr[i] = 1;
            }
        }
    }

    while(1){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        cout << out(n) << '\n';
    }
}
