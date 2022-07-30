#include <iostream>
using namespace std;

void Swap(int& a, int& b) {
    int temp = a;
    a = b; 
    b = temp;
}

int Partition(int* arr, int left, int right) {
    int pivot = arr[left];
    int low = left + 1; int high = right;
    
    while (low < high) {
        while (arr[low] < pivot && low < right) { low++; }
        while (arr[high] > pivot && high > left) { high--; }
        if (low < high) { Swap(arr[low], arr[high]); }
    }
    
    if (pivot > arr[high]) { Swap(arr[left], arr[high]); }
    return high;
}

void QuickHelp(int* arr, int left, int right) {
    if (left < right) {
        int piv = Partition(arr, left, right);
        QuickHelp(arr, left, piv-1);
        QuickHelp(arr, piv+1, right);
    }
}

void QuickSort(int* arr, int len) {
    QuickHelp(arr, 0, len-1);
}

int main() {
    int N = 10;
    int test[10] = {25, 48, 5, 43, 34, 28, 3, 50, 21, 38};
    
    cout << "Before sort" << endl;
    for (int i=0;i<N;i++) { 
        cout << test[i] << " ";
    }
    cout << endl;
    cout << endl;
    
    QuickSort(test, N);
    
    cout << "After sort" << endl;
    for (int i=0;i<N;i++) { 
        cout << test[i] << " ";
    }
    cout << endl;
    
    return 0;
}