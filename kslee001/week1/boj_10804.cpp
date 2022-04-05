#include <iostream>
using namespace std;



void arr_swap(int arr[], int a, int b){
    int sub_array[b-a+1];
    for(int i=0; i<b-a+1; ++i){
        sub_array[i] = arr[b-1-i];
    }

    for(int i=a-1; i<=b-1; ++i){
        arr[i] = sub_array[i-a];
    }
}


int main(){

    int arr[20];
    for(int i=0; i<20; ++i)
        arr[i] = i+1;

    int a, b; 
    a = 5; b= 10;
    // cin >>a>>b;

    arr_swap(arr, 5, 10);

    for(int i=0; i<20; ++i){
        cout << arr[i] << " ";
    }
    
}