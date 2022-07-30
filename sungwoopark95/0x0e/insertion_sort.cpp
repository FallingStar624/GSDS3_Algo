#include <iostream>
using namespace std;

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void InsertionSort(int* arr, int len) {
    for (int i=1;i<len;i++) {
        for (int j=i;j>0;j--) {
            if (arr[j-1] > arr[j]) {
                Swap(arr[j], arr[j-1]);
            }
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
    
    InsertionSort(test, N);
    
    cout << "After sort" << endl;
    for (int i=0;i<N;i++) { 
        cout << test[i] << " ";
    }
    cout << endl;
    
    return 0;
}