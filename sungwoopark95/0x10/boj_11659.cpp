#include <iostream>
using namespace std;

int N, M;
int arr[100002];
int D[100002];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N >> M;
    for (int i=0;i<N;i++) { cin >> arr[i]; }
    
    D[1] = arr[0];
    for (int k=2;k<=N;k++) {
        D[k] = D[k-1] + arr[k-1];
    }
    
    while (M--) {
        int i, j;
        cin >> i >> j;
        cout << D[j] - D[i-1] << "\n";
    }

    return 0;
}