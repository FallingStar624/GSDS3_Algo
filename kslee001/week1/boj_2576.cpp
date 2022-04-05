#include <iostream>
using namespace std;

int main(){
    int arr[7];
    int smallest = 101;
    for(int i=0; i<7; ++i){
        int temp; cin>>temp;
        if(temp%2 != 0){
            arr[i] = temp;
            if(temp <smallest)
                smallest = temp;
        }
        else
            arr[i] = 0;
    }
    int sum= 0;
    for (int i=0; i<7; ++i){
        sum += arr[i];
    }
    
    if(sum ==0)
        cout << -1;
    else{
        cout << sum << "\n";
        cout << smallest;
    }

}