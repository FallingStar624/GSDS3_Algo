#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n = 3;
    int arr[n];
    for(int i=0; i<n; ++i){
        int a; cin>>a;
        arr[i] = a;
    }

    for(int i=1; i<n; ++i){
        int right = i;
        int left = i-1;
        while(arr[right]<arr[left] && left>=0){
            swap(&arr[right], &arr[left]);
            left--;
            right--;
        }
    }
    for(int i=0; i<n; ++i){
        cout << arr[i];
        if(i!=n-1)
            cout << " ";
    }
}