#include <iostream>
using namespace std;

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int arr[], int n){

    for(int i=0; i<n; i++)
        for(int j=0; j<n-1; j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}



int main(){
    int arr[] = {-2, 45, 0, 11, -9};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}