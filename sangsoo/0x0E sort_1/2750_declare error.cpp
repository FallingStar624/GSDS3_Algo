// declare error
#include <iostream>
using namespace std;

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int arr[]){
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}



int main(){
    int arr[8] = {0,1,2,3,4,5,6, 7};

    bubble_sort(arr);
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";
}