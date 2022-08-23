#include <iostream>
using namespace std;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int arr[n+1][n+1];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i=n; i>0; i--) {
        for (int j=i; j>0; j--) {
            arr[i-1][j] += max(arr[i][j], arr[i][j+1]);
        }
    }
    cout << arr[1][1];
    return 0;
}
