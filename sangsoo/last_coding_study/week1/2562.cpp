#include <iostream>
using namespace std;

int main(){
    int max = 0;
    int maxindex = 0;
    int arr[9];
    for(int i =0; i<9; i++){
        cin >> arr[i];
        if(max < arr[i]){
            max = arr[i];
            maxindex = i;
        }
    }
    cout << max << '\n' << maxindex+1;
    }