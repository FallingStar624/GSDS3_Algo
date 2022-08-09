// https://www.acmicpc.net/problem/5648 역원소정렬
/* memory usage : 10^6 * (2 arrays) * (4 bytes per integer variable)
                = 8,000,000 bytes
                = 8 Mb
*/
#include <iostream>
using lint = long long;
using namespace std;

int n;
lint arr[1000000];
lint sorted[1000000];

void init(){
    cin >> n;
    string input;
    char c;
    int converted;

    for(int i=0; i<n; ++i){
        cin >> input;
        string reversed = "";
        bool flag = false;
        for(int j= input.size()-1; j>=0; --j){
            c = input[j];
            converted = (int) c-48;
            if(flag == false && converted == 0) continue;
            else{
                reversed += c;
                flag = true;
            }
        }
        lint reversed_int = stoll(reversed);
        arr[i] = reversed_int;
    }
}

void merge(lint arr[], int start, int mid, int end){
    int i = start;
    int j = mid+1;
    int k = start;
    while(i <= mid && j <= end){
        if(arr[i] < arr[j])
            sorted[k++] = arr[i++];
        else
            sorted[k++] = arr[j++];
    }
    while(i<=mid)
        sorted[k++] = arr[i++];
    while(j<=end)
        sorted[k++] = arr[j++];
    for(int x=0; x<=end; ++x)
        arr[x] = sorted[x];
}
void msort(lint arr[], int start, int end){
    if(start >= end) return;
    
    int mid = start + (end-start)/2;
    msort(arr, start, mid);
    msort(arr, mid+1, end);
    merge(arr, start, mid, end);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    msort(arr, 0, n-1);
    for(int i=0; i<n-1; ++i){
        cout << arr[i] << "\n";
    } 
    cout << arr[n-1];
}