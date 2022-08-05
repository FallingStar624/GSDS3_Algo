#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[10] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
int n = 10;
int tmp[10];

void basic(void){ // O(N^2)
    for (int i=n-1; i>=0; i--){
        int mxidx = 0;
        for (int j=0; j<=i; j++){
            if (arr[mxidx] < arr[j]) mxidx = j;
        }
        int temp = arr[i];
        arr[i] = arr[mxidx]; 
        arr[mxidx] = temp;
    }
}

void bubble(void){ // O(N^2)
    for (int i=0; i<n; i++){
        for (int j=0; j<n-1; j++){
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

// arr[0:2] + arr[2:4] (mid = 2)
void merge(int st, int en){ //arr[st:mid] + arr[mid:en]
    int mid = (st+en)/2; // 2
    int lidx = st; // 0
    int ridx = mid; // 1
    for (int i=st; i<en; i++){
        if (ridx == en) tmp[i] = arr[lidx++];
        else if (lidx == mid) tmp[i] = arr[ridx++];
        else if (arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
        else if (arr[lidx] > arr[ridx]) tmp[i] = arr[ridx++];
    }
    for (int i=st; i<en; i++) arr[i] = tmp[i];

}

void merge_sort(int st, int en){ // O(NlogN)
    if (en <= st+1) return;
    int mid = (st+en)/2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st,en);
}

void quick_sort(int st, int en){ // O(NlogN)
    if (en <= st+1) return;
    int pivot = arr[st];
    int l = st+1;
    int r = en-1;
    while (1){
        while (l <= r && arr[l] <= pivot) l++;
        while (l <=r && arr[r] >= pivot) r--;
        if (l > r) break;
        swap(arr[l], arr[r]);
    }
    swap(arr[st], arr[r]);
    quick_sort(st, r);
    quick_sort(r+1, en);
}

int main(void){
    // basic();
    // bubble();
    // merge_sort(0, 10);
    quick_sort(0, 10);
    for (int i=0; i<10; i++){
        cout << arr[i] << ' ';
    }
    return 0;
} 