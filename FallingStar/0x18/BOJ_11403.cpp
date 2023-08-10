#include <iostream>
#define INF 987654321
using namespace std;

int n, tmp;
int arr[101][101];

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> tmp;
            if (tmp == 0) tmp = INF;
            arr[i][j] = tmp;
        }
    }
    for (int k=0; k<n; k++) {
        for (int i=0; i<n ;i++) {
            for (int j=0; j<n; j++) {
                if (arr[i][k] + arr[k][j] < arr[i][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            tmp = arr[i][j];
            if (tmp < 987654321) {
                cout << 1 << ' ';
            } else {
                cout << 0 << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}

