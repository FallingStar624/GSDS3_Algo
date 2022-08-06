#include <iostream>
using namespace std;

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void SelectionSort(int* arr, int len) {
    for (int i=0;i<len;i++) {
        int smallest = i;
        for (int j=i;j<len;j++) {
            if (arr[j] < arr[smallest]) { smallest = j; }
        }
        if (arr[smallest] < arr[i]) {
            Swap(arr[i], arr[smallest]);
        }
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
    
    SelectionSort(test, N);
    
    cout << "After sort" << endl;
    for (int i=0;i<N;i++) { 
        cout << test[i] << " ";
    }
    cout << endl;
    
    return 0;
}