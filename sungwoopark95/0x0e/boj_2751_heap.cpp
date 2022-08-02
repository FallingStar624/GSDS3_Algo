#include <iostream>
using namespace std;

int N;
int arr[2000000];

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void Heapify(int* arr, int root, int last) {
    int left = (root*2) + 1;
    int right = (root*2) + 2;
    int largest = root;
    
    if (arr[left] > arr[largest] && left < last) { largest = left; }
    if (arr[right] > arr[largest] && right < last) { largest = right; }
    
    if (largest != root) {
        Swap(arr[largest], arr[root]);
        Heapify(arr, largest, last);
    }
}

void HeapSort(int* arr, int len) {
    // build heap
    for (int i=(len/2)-1;i>=0;i--) {
        Heapify(arr, i, len);
    }
    
    // popout
    for (int i=len-1;i>0;i--) {
        Swap(arr[i], arr[0]);
        Heapify(arr, 0, --len);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    HeapSort(arr, N);
    
    for (int i=0;i<N;i++) {
        cout << arr[i] << "\n";
    }
    
    return 0;
}