#include <iostream>
using namespace std;

int N;
int arr[2000000];

void Merge(int* arr, int start, int mid, int last) {
    int k = start;
    int len1 = (mid+1) - start;
    int len2 = last - mid;
    int sub1[len1], sub2[len2];
    
    for (int i=0;i<len1;i++) { 
        sub1[i] = arr[start+i]; 
    }
    
    for (int i=0;i<len2;i++) {
        sub2[i] = arr[mid+1+i];
    }
    
    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (sub1[i] > sub2[j]) { arr[k] = sub2[j++]; }
        else { arr[k] = sub1[i++]; }
        k++;
    }
    
    if (i == len1) {
        for (int x=j;x<len2;x++) { 
            arr[k++] = sub2[x]; 
        }
    } else {
        for (int x=i;x<len1;x++) {
            arr[k++] = sub1[x];
        }
    }
}

void MergeHelp(int* arr, int start, int last) {
    if (start == last) { return; }
    int mid = start + ((last-start)/2);
    MergeHelp(arr, start, mid);
    MergeHelp(arr, mid+1, last);
    Merge(arr, start, mid, last);
}

void MergeSort(int* arr, int len) {
    MergeHelp(arr, 0, len-1);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    MergeSort(arr, N);
    
    for (int i=0;i<N;i++) {
        cout << arr[i] << "\n";
    }
    
    return 0;
}