#include <iostream>
using namespace std;

int smallest(int arr[], int start, int length);

int main() {
    int size = 5;
    int avg = 0;
    int median, num, small_idx, arrtemp;
    int nums[size];

    for (int i=0;i<size;i++) {
        cin >> num;
        nums[i] = num;
        avg += num;
    }

    // selection sort
    for (int j=0;j<size;j++) {
        small_idx = smallest(nums, j, size);
        if (nums[j] > nums[small_idx]) {
            arrtemp = nums[j];
            nums[j] = nums[small_idx];
            nums[small_idx] = arrtemp;
        }
    }
    median = nums[size / 2];
    avg = avg / 5;

    cout << avg << endl;
    cout << median << endl;

    return 0;
}

int smallest(int arr[], int start, int length) {
    int temp = start;
    for(int i=start;i<length;i++) {
        if (arr[temp] > arr[i]) {
            temp = i;
        }
    }
    return temp;
}