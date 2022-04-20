#include <iostream>
using namespace std;

int smallest(int arr[], int start, int length);

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int arr[3] = {a, b, c};

    // selection sort
    int small_idx;
    int arr_temp;
    for (int i=0;i<3;i++) {
        small_idx = smallest(arr, i, 3);
        if (arr[i] > arr[small_idx]) {
            arr_temp = arr[i];
            arr[i] = arr[small_idx];
            arr[small_idx] = arr_temp;
        }
    }

    for (int i=0;i<3;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int smallest(int arr[], int start, int length) {
    int temp = start;
    for (int i=start;i<length;i++) {
        if (arr[temp] > arr[i]) {
            temp = i;
        }
    }
    return temp;
}