#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[500002];
int test[500002];

int find_left_idx(int target, int n, int arr[]){
    int st = 0; int en = n;
    while (st < en){
        int mid = st + (en-st)/2;
        if (arr[mid] >= target) en = mid;
        else st = mid + 1;
    }
    return st;
}

int find_right_idx(int target, int n, int arr[]){
    int st = 0; int en = n;
    while (st < en){
        int mid = st + (en-st)/2 ;
        if (arr[mid] > target) en = mid;
        else st = mid + 1;
    }
    return st;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i <N; i++) cin >> arr[i];
    cin >> M;
    for(int i = 0; i <M; i++) cin >> test[i];
    sort(arr, arr+N);
    for (int i = 0; i <M; i++) 
        cout << find_right_idx(test[i], N, arr)-find_left_idx(test[i], N, arr) << " ";

}