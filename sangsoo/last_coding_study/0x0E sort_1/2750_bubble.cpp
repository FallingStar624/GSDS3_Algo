// bubble sort
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
    int N;
    cin >> N;
    int arr[N];

    for (int i=0; i<N; i++){
        cin >> arr[i];
    }
    bubble_sort(arr, N);
    for (int i = 0; i < N; i++)
        cout << arr[i] << endl;
}