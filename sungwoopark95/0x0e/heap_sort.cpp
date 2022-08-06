#include <iostream>
using namespace std;
// Ascending sort -> use MaxHeap

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void Heapify(int* arr, int root, int last) {
    int largest = root;
    int left_child = (2*root) + 1;
    int right_child = (2*root) + 2;
    
    if (left_child < last && arr[left_child] > arr[largest]) { largest = left_child; }
    if (right_child < last && arr[right_child] > arr[largest]) { largest = right_child; }
    
    if (largest != root) {
        Swap(arr[root], arr[largest]);
        Heapify(arr, largest, last);
    }
}

void HeapSort(int* arr, int len) {
    for (int i=(len/2)-1;i>=0;i--) {
        Heapify(arr, i, len);
    }
    
    for (int i=len-1;i>0;i--) {
        Swap(arr[0], arr[i]);
        Heapify(arr, 0, --len);
    }
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
    
    HeapSort(test, N);
    
    cout << "After sort" << endl;
    for (int i=0;i<N;i++) { 
        cout << test[i] << " ";
    }
    cout << endl;
    
    return 0;
}