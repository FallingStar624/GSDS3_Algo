#include <iostream>
using namespace std;

int main(){
    int N,X;
    cin >> N >> X;
    int arr[N];
    for(int i = 0; i <N; i++){
        cin >> arr[i];
    }
    for(int j = 0; j < N; j++ ){
        if(arr[j]<X)
        cout <<arr[j]<<" ";
    }
}