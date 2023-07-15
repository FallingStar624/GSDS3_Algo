#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int arr[100002];
int test[100002];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    cin >> M;
    for (int i = 0; i < M; i++) cin >> test[i];
    sort(arr, arr+N);
    for (int i = 0; i < M; i++) cout << binary_search(arr, arr+N, test[i]) << "\n";
}