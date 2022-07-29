#include <iostream>
#include <algorithm>
#include <time.h>
#include <random>
#include <chrono>
using namespace std;
using namespace chrono;

string InsertionSort(int* arr, int len);
string SelectionSort(int* arr, int len);
string MergeSort(int* arr, int len);
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

    // average case
    shuffle(test, test+N, default_random_engine(24790));
    cout << "Average case" << endl;
    TimeSpent(InsertionSort, test, N);
    TimeSpent(SelectionSort, test, N);
    TimeSpent(MergeSort, test, N);

    return 0;
}

void TimeSpent(string (*func)(int*, int), int* arr, int len) {
    steady_clock::time_point begin = steady_clock::now();
    string name = func(arr, len);
    steady_clock::time_point end = steady_clock::now();
    cout << "Time consumed for " << name << "\t: " << (double)duration_cast<milliseconds>(end - begin).count() / (double)1000 << " seconds." << endl;
}

string InsertionSort(int* arr, int len) {
    for (int i=1;i<len;i++) {
        for (int j=i;j>0;j--) {
            if (arr[j-1] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
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
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
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