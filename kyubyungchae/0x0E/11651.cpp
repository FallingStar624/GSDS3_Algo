#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
struct coord {
    int x, y;
};
coord arr[100000];

void PrintArr();
void MergeSort(coord arr[], int len);
void MergeSortHelp(coord arr[], int first, int last);
void Merge(coord arr[], int first, int mid, int last);

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    MergeSort(arr, n);
    PrintArr();

    return 0;
}

void PrintArr() {
    
    for(int i = 0; i < n; i++) {
        cout << arr[i].x << " " << arr[i].y << "\n";
    }
}

void MergeSort(coord arr[], int len) {
    MergeSortHelp(arr, 0, len - 1);
}

void MergeSortHelp(coord arr[], int first, int last) {
    if(first == last) {
        return;
    }

    int mid = first + (last - first) / 2;
    MergeSortHelp(arr, first, mid);
    MergeSortHelp(arr, mid + 1, last);
    Merge(arr, first, mid, last);
}

void Merge(coord arr[], int first, int mid, int last) {
    int k = first;

    int len1 = mid - first + 1;
    int len2 = last - mid;

    coord sub1[len1], sub2[len2];

    for(int i = 0; i < len1; i++) {
        sub1[i] = arr[first + i];
    }

    for(int i = 0; i < len2; i++) {
        sub2[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    while(i < len1 && j < len2) {
        if(sub1[i].y < sub2[j].y) {
            arr[k] = sub1[i];
            i++;
        } else if(sub1[i].y == sub2[j].y) {
            if(sub1[i].x <= sub2[j].x) {
                arr[k] = sub1[i];
                i++;
            } else {
                arr[k] = sub2[j];
                j++;
            }
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