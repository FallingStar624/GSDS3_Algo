#include <iostream>
using namespace std;
#define MAX 1000000
int arr[MAX];
int sorted[MAX];
void merge(int* arr, int start, int mid, int end){
    int i = start;
    int j = mid+1;
    int k = start;
    while(i<=mid && j<= end){
        if(arr[i] <= arr[j]) 
            sorted[k++] = arr[i++];
        else 
            sorted[k++] = arr[j++];
    }
    while(i<=mid)
        sorted[k++] = arr[i++]; 
    while(j<=end)
        sorted[k++] = arr[j++];
    for(int x=start; x<=end; ++x)
        arr[x] = sorted[x];
}   
void msort(int* arr, int start, int end){
    if(start>=end) return;
    int mid = (start+end)/2;
    msort(arr, start, mid);
    msort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    int n; cin >>n;
    for(int i=0; i<n; ++i) cin>>arr[i];
    msort(arr, 0, n-1);
    for(int i=0; i<n; ++i) cout << arr[i] << "\n";
}
