#include <iostream>
using namespace std;

void __sorting(int* arr, int start, int mid, int end){
    int num_l = mid-start+1; // left array에 들어갈 원소 개수
    int num_r = end-mid;   // right array에 들어갈 원소 개수
    int left_array[num_l];
    int right_array[num_r];
    int origin_idx = start;
    for(int i=0; i<num_l; ++i){
        left_array[i] = arr[origin_idx];
        origin_idx ++;
    }
    for(int i=0; i<num_r; ++i){
        right_array[i] = arr[origin_idx];
        origin_idx ++;
    }
    int l = 0; int r = 0; int o = start;
    while (l<num_l && r<num_r){
        if(left_array[l] < right_array[r]){
            arr[o] = left_array[l];
            l++;
        }
        else{
            arr[o] = right_array[r];
            r++;
        }
        o++;
    }
    while (l<num_l){
        arr[o] = left_array[l];
        l++; o++;
    }
    while (r<num_r){
        arr[o] = right_array[r];
        r++; o++;
    }    
}
void mergesort(int* arr, int start, int end){
    if(start>=end)   return;
    int mid = start + (end-start)/2;
    mergesort(arr, start, mid);
    mergesort(arr, mid+1, end);
    __sorting(arr, start,mid, end);
}
int bin_search(int* arr, int start, int end, int target){
    if (start<=end){
        int mid = start + (end-start)/2;
        if (arr[mid] == target){
            return mid;
        }
        if (arr[mid] > target){
            return bin_search(arr, start, mid-1, target);
        };
        if (arr[mid] < target){
            return bin_search(arr, mid+1, end, target);
        }
    }
    return -1;
}


int main(){
    int n; cin>>n;
    int arr[n];
    int input;
    for(int i=0; i<n; ++i){
        cin >> input;
        arr[i] = input;
    }
    mergesort(arr, 0, n-1);
    int target; cin >>target;   
    
    int cnt = 0;
    int first; int second;
    int mid = n/2+1 ;
    for(int i=0; i<n; ++i){
        first = arr[i];
        second = target-first;
        // find second value
        if(bin_search(arr, 0, n-1, second) != -1) cnt ++;
    }
    cout << cnt/2;
}