#include <iostream>
#include <algorithm>

using namespace std;
int arr_g[100002];
int test[100002];
int my_binary_search(int target, int n, int arr[]){
    int st = 0; int en = n-1; 
    while (st <= en){
        int mid = st + (en-st)/2;
        if (target > arr[mid]) st = mid+1; 
        else if (target < arr[mid]) en = mid-1;
        else return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int N; int M;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr_g[i];
    cin >> M;
    for (int i = 0; i < M; i++) cin >> test[i];
    sort(arr_g, arr_g+N);
    for (int i = 0; i < M; i++){
        cout << my_binary_search(test[i], N, arr_g) << '\n';
    }
}