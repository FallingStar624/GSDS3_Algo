#include <iostream>
#define Y first
#define X second
#define MAX 1000000

using namespace std;
pair<int,string> arr[MAX];
pair<int,string> sorted[MAX];
void merge(pair<int,string>* arr, int start, int mid, int end){
    int i = start;
    int j = mid+1;
    int k = start;
    while(i<=mid && j<= end){
        if(arr[i].Y <= arr[j].Y) 
            sorted[k++] = arr[i++];
        else if(arr[i].Y > arr[j].Y)
            sorted[k++] = arr[j++];
    }
    while(i<=mid)
        sorted[k++] = arr[i++]; 
    while(j<=end)
        sorted[k++] = arr[j++];
    for(int x=start; x<=end; ++x)
        arr[x] = sorted[x];
}   
void msort(pair<int,string>* arr, int start, int end){
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
    int age; string name;
    for(int i=0; i<n; ++i){
        cin >> age >> name;
        arr[i].Y = age;
        arr[i].X = name;
    }
    msort(arr, 0, n-1);
    for(int i=0; i<n; ++i) cout << arr[i].Y << " " << arr[i].X << "\n";
}


