#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n] = {};
    int* bottom = arr;
    int* top = arr+n-1;

    int* cur = bottom;

    int now;
    for(int i=0; i<n; ++i){
        cin >>now;
        if(now ==0){
            cur= cur-1;
            *cur = 0;
        }
        else{
            *cur = now;
            cur = cur+1;
        }
    }
    int sum = 0;
    for(int i=0; i<n; ++i){
        sum = sum+arr[i];
    }
    cout << sum;
}