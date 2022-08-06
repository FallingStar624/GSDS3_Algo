#include <iostream>
#define X first
#define Y second
#define MAX 1000000

using namespace std;
pair<int,int> arr[MAX];
pair<int,int> sorted[MAX];
void merge(pair<int,int>* arr, int start, int mid, int end){
    int i = start;
    int j = mid+1;
    int k = start;
    while(i<=mid && j<= end){
        if(arr[i].Y < arr[j].Y) 
            sorted[k++] = arr[i++];
        else if(arr[i].Y > arr[j].Y)
            sorted[k++] = arr[j++];
        else{
            if(arr[i].X < arr[j].X)
                sorted[k++] = arr[i++];
            else
                sorted[k++] = arr[j++];
        }
    }
    while(i<=mid)
        sorted[k++] = arr[i++]; 
    while(j<=end)
        sorted[k++] = arr[j++];
    for(int Y=start; Y<=end; ++Y)
        arr[Y] = sorted[Y];
}   
void msort(pair<int,int>* arr, int start, int end){
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
    int y; int x;
    for(int i=0; i<n; ++i){
        cin >> x >> y;
        arr[i].X = x;
        arr[i].Y = y;
    }
    msort(arr, 0, n-1);
    for(int i=0; i<n; ++i) cout << arr[i].X << " " << arr[i].Y << "\n";
}


