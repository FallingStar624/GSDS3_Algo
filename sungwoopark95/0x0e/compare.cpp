#include <iostream>
#include <algorithm>
#include <time.h>
#include <random>
#include <chrono>
using namespace std;
using namespace chrono;

void Swap(int& a, int& b);
string InsertionSort(int* arr, int len);
string SelectionSort(int* arr, int len);
string MergeSort(int* arr, int len);
string HeapSort(int* arr, int len);
string QuickSort(int* arr, int len);
void MergeHelp(int* arr, int start, int last);
void Merge(int* arr, int start, int mid, int last);
void TimeSpent(string (*func)(int*, int), int* arr, int len);

int main() {
    int N = 50000;
    int test[N];
    for (int i=0;i<N;i++) {
        test[i] = N-i; //worst case
    }

    // worst case
    cout << "Worst case" << endl;
    TimeSpent(InsertionSort, test, N);
    TimeSpent(SelectionSort, test, N);
    TimeSpent(MergeSort, test, N);
    TimeSpent(HeapSort, test, N);
    TimeSpent(QuickSort, test, N);

    // average case
    shuffle(test, test+N, default_random_engine(24790));
    cout << "Average case" << endl;
    TimeSpent(InsertionSort, test, N);
    TimeSpent(SelectionSort, test, N);
    TimeSpent(MergeSort, test, N);
    TimeSpent(HeapSort, test, N);
    TimeSpent(QuickSort, test, N);

    return 0;
}

void TimeSpent(string (*func)(int*, int), int* arr, int len) {
    steady_clock::time_point begin = steady_clock::now();
    string name = func(arr, len);
    steady_clock::time_point end = steady_clock::now();
    cout << "Time consumed for " << name << "\t: " << (double)duration_cast<milliseconds>(end - begin).count() / (double)1000 << " seconds." << endl;
}

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

string InsertionSort(int* arr, int len) {
    for (int i=1;i<len;i++) {
        for (int j=i;j>0;j--) {
            if (arr[j-1] > arr[j]) {
                Swap(arr[j], arr[j-1]);
            }
        }
    }
    return __func__;
}

string SelectionSort(int* arr, int len) {
    for (int i=0;i<len;i++) {
        int smallest = i;
        for (int j=i;j<len;j++) {
            if (arr[j] < arr[smallest]) { smallest = j; }
        }
        if (arr[smallest] < arr[i]) {
            Swap(arr[i], arr[smallest]);
        }
    }
    return __func__;
}

void Merge(int* arr, int start, int mid, int last) {
    int k = start; 
    int len1 = (mid+1) - start; 
    int len2 = last - mid;
    int sub1[len1];
    int sub2[len2];
    
    for (int i=0;i<len1;i++) { sub1[i] = arr[start+i]; }
    for (int j=0;j<len2;j++) { sub2[j] = arr[mid+1+j]; }
    
    int m = 0; int l = 0;    
    while (m < len1 && l < len2) {
        if (sub1[m] > sub2[l]) { arr[k] = sub2[l++]; } 
        else { arr[k] = sub1[m++]; }
        k++;
    }
    
    if (m == len1) {
        for (int x=l;x<len2;x++) { arr[k++] = sub2[x]; }
    } else {
        for (int x=m;x<len1;x++) { arr[k++] = sub1[x]; }
    }
    
}

void MergeHelp(int* arr, int start, int last) {
    if (start == last) { return; }
    int mid = (start+last) / 2;
    MergeHelp(arr, start, mid);
    MergeHelp(arr, mid+1, last);
    
    Merge(arr, start, mid, last);
}

string MergeSort(int* arr, int len) {
    MergeHelp(arr, 0, len-1);
    return __func__;
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

string QuickSort(int* arr, int len) {
    QuickHelp(arr, 0, len-1);
    return __func__;
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

string HeapSort(int* arr, int len) {
    for (int i=(len/2)-1;i>=0;i--) {
        Heapify(arr, i, len);
    }
    
    for (int i=len-1;i>0;i--) {
        Swap(arr[0], arr[i]);
        len--;
        Heapify(arr, 0, len);
    }
    return __func__;
}