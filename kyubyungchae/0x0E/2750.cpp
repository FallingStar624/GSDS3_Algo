#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1000];

void PrintArr();
void MergeSort(int arr[], int len);
void MergeSortHelp(int arr[], int first, int last);
void Merge(int arr[], int first, int mid, int last);
void print() {
    for(int i = 0; i< n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    MergeSort(arr, n);
    PrintArr();

    return 0;
}

void PrintArr() {
    
    for(int i = 0; i < n; i++) {
        cout << arr[i] << "\n";
    }
}

void MergeSort(int arr[], int len) {
    MergeSortHelp(arr, 0, len - 1);
}

void MergeSortHelp(int arr[], int first, int last) {
    if(first == last) {
        return;
    }

    int mid = first + (last - first) / 2;
    MergeSortHelp(arr, first, mid);
    MergeSortHelp(arr, mid + 1, last);
    Merge(arr, first, mid, last);
}

void Merge(int arr[], int first, int mid, int last) {
    int k = first;

    int len1 = mid - first + 1;
    int len2 = last - mid;

    int sub1[len1], sub2[len2];

    for(int i = 0; i < len1; i++) {
        sub1[i] = arr[first + i];
    }

    for(int i = 0; i < len2; i++) {
        sub2[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    while(i < len1 && j < len2) {
        if(sub1[i] <= sub2[j]) {
            arr[k] = sub1[i];
            i++;
        } else {
            arr[k] = sub2[j];
            j++;
        }
        k++;
    }

    while(i < len1) {
        arr[k] = sub1[i];
        i++;
        k++;
    }

    while(j < len2) {
        arr[k] = sub2[j];
        j++;
        k++;
    }
}