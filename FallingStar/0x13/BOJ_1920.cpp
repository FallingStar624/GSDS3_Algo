#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int arr[100001];


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    cin >> M;
    while (M--) {
        int k;
        cin >> k;
        cout << binary_search(arr, arr+N, k) << "\n";
    }

    return 0;
}
