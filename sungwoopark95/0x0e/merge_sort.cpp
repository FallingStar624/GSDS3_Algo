#include <iostream>
using namespace std;

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

void MergeSort(int* arr, int len) {
    MergeHelp(arr, 0, len-1);
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
    
    MergeSort(test, N);
    
    cout << "After sort" << endl;
    for (int i=0;i<N;i++) { 
        cout << test[i] << " ";
    }
    cout << endl;
    
    return 0;
}