// time over
#include <iostream>

using namespace std;

// function to swap elements
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// function to rearrange array(find the partition point)
int partition(int arr[], int low, int high){

    // select the rightmost element as pivot
    int pivot = arr[high];

    // pointer for greater element
    int i = low -1;

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++){
        if(arr[j] <= pivot){
            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // swap pivot with the greater element at i
    swap(&arr[i+1], &arr[high]);

    // return the partition point
    return (i+1);
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(arr, low, high);

        // recursive call on the left of pivot
        quickSort(arr, low, pi-1);

        // recursive call on the right of pivot
        quickSort(arr, pi+1, high);
    }
}

// Driver code
int main(){
    int N;
    cin >> N;
    int data[N];

    for(int i=0; i<N; i++){
        cin >> data[i];
    }

    quickSort(data, 0, N-1);

    for(int i=0; i<N; i++){
        cout << data[i] << endl;
    }
}
